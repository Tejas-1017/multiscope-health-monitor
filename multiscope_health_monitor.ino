#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "include/health_sensors.h"
#include "include/dsp_filter.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);
ButterworthFilter ppgFilter;
DCRemovalFilter dcRemover(0.95f);
PPGPeakDetector peakDetector;
VitalSignsData currentVitals;
uint8_t waveBuffer[128];
uint8_t waveIdx = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    Wire.setClock(400000);
    pinMode(ALERT_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    if (display.begin(SSD1306_SWITCHCAPVCC, SSD1306_OLED_ADDR)) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(10, 20);
        display.println(F("MULTISCOPE HEALTH"));
        display.display();
    }
    currentVitals.heartRateBPM = 72.0f;
    currentVitals.bloodOxygenSpO2 = 98.5f;
    currentVitals.bodyTemperatureC = 36.6f;
    for (int i = 0; i < 128; i++) waveBuffer[i] = 42;
    Serial.println(F("[SYSTEM] Multiscope Health Monitor Initialized."));
}

void loop() {
    static uint32_t lastSample = 0;
    static float phase = 0.0f;
    uint32_t now = millis();
    if (now - lastSample >= 10) {
        lastSample = now;
        phase += 0.0628f;
        float rawAC = (sin(phase) + 0.35f * sin(2.0f * phase + 0.4f)) * 800.0f;
        float rawSignal = 85000.0f + rawAC;
        float filtered = ppgFilter.step(dcRemover.step(rawSignal));
        float bpm = currentVitals.heartRateBPM;
        if (peakDetector.processSample(filtered, now, bpm)) {
            currentVitals.heartRateBPM = bpm;
            digitalWrite(ALERT_LED_PIN, HIGH);
        } else {
            digitalWrite(ALERT_LED_PIN, LOW);
        }
        int yPlot = 42 - (int)(filtered * 0.035f);
        if (yPlot < 22) yPlot = 22;
        if (yPlot > 62) yPlot = 62;
        waveBuffer[waveIdx] = (uint8_t)yPlot;
        waveIdx = (waveIdx + 1) % 128;
    }
}
