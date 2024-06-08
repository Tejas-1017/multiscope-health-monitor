#ifndef DSP_FILTER_H
#define DSP_FILTER_H
#include <stdint.h>
class ButterworthFilter {
private: float v[3];
public:
    ButterworthFilter();
    void reset();
    float step(float x);
};
class DCRemovalFilter {
private: float w, alpha;
public:
    DCRemovalFilter(float alphaVal = 0.95f);
    void reset();
    float step(float x);
};
class PPGPeakDetector {
private:
    float dynamicThreshold;
    uint32_t lastPeakTimeMs, refractoryPeriodMs;
    float bpmHistory[8];
    uint8_t historyIdx;
public:
    PPGPeakDetector();
    bool processSample(float filteredSample, uint32_t currentTimeMs, float &outBPM);
};
#endif
