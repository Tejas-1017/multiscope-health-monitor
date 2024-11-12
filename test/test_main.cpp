#include <unity.h>
#include "../include/dsp_filter.h"
#include "../include/health_sensors.h"
void setUp(void) {}
void tearDown(void) {}
void test_dc_removal(void) {
    DCRemovalFilter dc(0.95f);
    float out = 0.0f;
    for (int i = 0; i < 50; i++) out = dc.step(1000.0f);
    TEST_ASSERT_FLOAT_WITHIN(50.0f, 0.0f, out);
}
int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_dc_removal);
    return UNITY_END();
}
