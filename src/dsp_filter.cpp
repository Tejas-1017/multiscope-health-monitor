#include "dsp_filter.h"
#include <cmath>
ButterworthFilter::ButterworthFilter() { reset(); }
void ButterworthFilter::reset() { v[0] = v[1] = v[2] = 0.0f; }
float ButterworthFilter::step(float x) {
    v[0] = v[1]; v[1] = v[2];
    v[2] = (0.06745527388907189600f * x) + (-0.73035623080000000000f * v[0]) + (1.66270275880000000000f * v[1]);
    return (v[2] - 2.0f * v[1] + v[0]);
}
DCRemovalFilter::DCRemovalFilter(float alphaVal) : alpha(alphaVal), w(0.0f) {}
void DCRemovalFilter::reset() { w = 0.0f; }
float DCRemovalFilter::step(float x) {
    float prev_w = w; w = x + alpha * prev_w; return w - prev_w;
}
PPGPeakDetector::PPGPeakDetector() : dynamicThreshold(150.0f), lastPeakTimeMs(0), refractoryPeriodMs(350), historyIdx(0) {
    for (int i = 0; i < 8; i++) bpmHistory[i] = 72.0f;
}
bool PPGPeakDetector::processSample(float filteredSample, uint32_t currentTimeMs, float &outBPM) {
    if (filteredSample > dynamicThreshold && (currentTimeMs - lastPeakTimeMs > refractoryPeriodMs)) {
        uint32_t interval = currentTimeMs - lastPeakTimeMs;
        lastPeakTimeMs = currentTimeMs;
        if (interval > 300 && interval < 2000) {
            bpmHistory[historyIdx] = 60000.0f / (float)interval;
            historyIdx = (historyIdx + 1) % 8;
            float sum = 0; for (int i = 0; i < 8; i++) sum += bpmHistory[i];
            outBPM = sum / 8.0f;
            return true;
        }
    }
    return false;
}
