#ifndef HEALTH_SENSORS_H
#define HEALTH_SENSORS_H
#include <stdint.h>
#define MAX30102_I2C_ADDR       0x57
#define MAX30205_I2C_ADDR       0x48
#define SSD1306_OLED_ADDR       0x3C
#define I2C_SDA_PIN             21
#define I2C_SCL_PIN             22
#define ALERT_LED_PIN           2
#define BUZZER_PIN              4
#define BPM_MIN_NORMAL          55.0f
#define BPM_MAX_NORMAL          105.0f
#define SPO2_MIN_HEALTHY        94.0f
#define TEMP_FEVER_THRESHOLD_C  37.8f
struct VitalSignsData {
    float heartRateBPM;
    float bloodOxygenSpO2;
    float bodyTemperatureC;
    float perfusionIndex;
    bool isFingerDetected;
    bool isArrhythmiaDetected;
    uint32_t timestampMs;
};
#endif
