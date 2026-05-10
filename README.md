# Multiscope Portable Health Monitor 🩺

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=cplusplus)](https://isocpp.org)
[![ESP32](https://img.shields.io/badge/Hardware-ESP32%20WROOM-red?logo=espressif)](https://espressif.com)
[![Sensors](https://img.shields.io/badge/Biomedical-MAX30102%20%7C%20MAX30205-00F3FF)]()
[![DSP](https://img.shields.io/badge/Signal_Processing-Butterworth_IIR-9D00FF)]()
[![Dashboard](https://img.shields.io/badge/UI-Gradio%20Interactive-orange?logo=gradio)](https://gradio.app)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A clinical-grade, portable multi-parameter biomedical monitoring system built on the **ESP32** microcontroller. Features real-time optical Photoplethysmography (PPG) digital filtering, SpO2 pulse oximetry calculation, non-contact body temperature acquisition, on-device SSD1306 OLED waveform rendering, and an interactive Gradio web telemetry dashboard.

---

## 🌟 Key Engineering Highlights

- 🩸 **Dual-Wavelength PPG Acquisition**: Samples Red (660nm) and IR (880nm) optical absorption at **100 Hz** via **MAX30102**.
- 🔬 **Real-Time DSP Bandpass Filter**: 2nd-order digital Butterworth IIR filter ($0.5\text{ Hz} - 5.0\text{ Hz}$) removes baseline drift.
- 💓 **Dynamic Peak Detection**: Adaptive thresholding algorithm with refractory lockout prevents false dicrotic notch counting ($\pm 1\text{ BPM}$ accuracy).
- 🌡️ **Clinical Body Temperature**: $0.1^\circ\text{C}$ resolution human body temperature telemetry via **MAX30205**.
- 💻 **Gradio Web Telemetry Dashboard**: Real-time interactive Plotly waveform streaming and vital anomaly simulation.

---

## 👤 Author
**Tejas Rohit Kharkar**  
AI & Embedded Systems Engineer | [LinkedIn](https://linkedin.com/in/tejas-kharkar-tech) | [GitHub](https://github.com/Tejas-1017)
