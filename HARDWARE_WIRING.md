# Multiscope Portable Health Monitor - Hardware Wiring & Pinout Guide
## System Pinout Specification
| Module | Pin | ESP32 Pin | Voltage | Description |
| :--- | :--- | :--- | :--- | :--- |
| **MAX30102** | SDA / SCL | GPIO 21 / 22 | 3.3V | Optical PPG Red & IR Telemetry |
| **MAX30205** | SDA / SCL | GPIO 21 / 22 | 3.3V | 0.1°C Body Temperature Sensor |
| **SSD1306**  | SDA / SCL | GPIO 21 / 22 | 3.3V | 128x64 Monochrome OLED Display |
| **Alert LED**| Anode (+) | GPIO 2 | 3.3V | Heartbeat Systolic Peak Indicator |
| **Buzzer**   | Signal    | GPIO 4 | 3.3V | Vital Anomaly Warning Alarm |
