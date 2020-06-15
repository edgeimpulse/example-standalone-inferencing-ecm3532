/* Edge Impulse inferencing library
 * Copyright (c) 2020 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "eta_bsp.h"
#include "ei_run_classifier.h"
#include "printf.h"

static const float features[] = {
    // copy raw features here (for example from the 'Live classification' page)
    // see https://docs.edgeimpulse.com/docs/running-your-impulse-ecm3532

    2.2600, -1.2700, -1.5300, 1.9500, -1.7500, -1.1900, 1.7900, -2.8500, 0.6500, 1.9100, -2.9100, 2.3500, 1.9100, -2.9100, 2.3500, 1.9900, -2.4100, 3.5900, 1.2700, -0.3800, 2.5200, 1.5300, 0.9900, 2.7300, 2.0200, 0.3000, 4.1400, 1.2400, -0.9500, 5.8300, 0.7400, -1.2500, 6.8400, 0.7400, -1.2500, 6.8400, 0.3100, -0.4200, 6.1200, 1.1300, 0.2500, 8.0100, 1.9600, 0.7400, 10.2900, 1.4600, 0.8700, 9.3800, 0.1200, -0.3400, 9.1400, 0.5500, -1.2900, 12.6500, 0.5500, -1.2900, 12.6500, 1.1000, -1.0500, 14.3300, 0.8300, -0.4800, 12.2600, 0.1900, -0.7900, 11.1900, -0.0500, -0.8100, 12.9700, -0.4500, -0.3500, 17.0500, -0.1000, 0.8300, 17.1800, -0.1000, 0.8300, 17.1800, -0.6000, 0.4200, 14.1100, -0.9000, 0.9200, 12.1500, -0.6000, 1.4200, 14.1400, -0.6200, 1.3100, 15.6600, -0.4800, 1.8700, 14.5600, -0.4300, 1.5300, 13.2100, -0.4300, 1.5300, 13.2100, -0.7800, 1.1400, 12.7500, -0.9100, 1.2100, 13.0900, -0.1600, 1.2200, 14.3900, -0.2900, 1.4000, 13.6000, -1.0200, 1.3800, 13.1400, -1.3400, 0.3400, 14.9300, -1.3400, 0.3400, 14.9300, -1.0000, -1.2300, 19.1200, -1.1200, -3.4000, 19.9800, -1.2800, -2.9000, 19.9800, -1.2400, -1.8300, 19.9800, -1.6200, -2.3900, 19.9800, -1.3900, -1.9000, 19.9800, -1.3900, -1.9000, 19.9800, -1.5300, -1.6200, 19.9800, -1.4700, -0.6200, 19.3400, -1.0400, 1.1900, 17.5700, -1.0400, 1.6700, 15.1700, -1.0600, 1.9200, 12.6000, -0.5100, 3.3900, 12.1800, -0.5100, 3.3900, 12.1800, 0.1600, 3.3500, 14.2200, -0.4200, 1.8600, 13.8700, -0.7000, 1.4700, 10.9600, 0.0000, 2.0200, 8.0200, 0.8800, 2.7000, 6.6000, 1.1700, 2.2400, 7.5300, 1.1700, 2.2400, 7.5300, 0.8600, 0.7700, 9.3000, 1.1300, 0.6500, 9.8600, 0.7000, 0.7600, 6.6400, 0.0000, 0.6500, 2.3700, 0.3300, 0.5600, 0.9900, 0.3300, 0.5600, 0.9900, 1.0200, 0.3000, 1.5100, 0.6200, -0.5900, 1.2600, 0.6800, -1.4500, 1.1200, 0.6900, -2.6900, -0.0900, 0.9100, -2.7700, -1.8600, 1.5000, -2.4300, -2.2100, 1.5000, -2.4300, -2.2100, 2.0400, -3.0300, 0.7100, 2.3600, -2.7900, 3.4400, 2.6200, -2.0500, 3.0800, 2.6000, -1.9000, 0.8300, 2.2700, -2.4700, -0.8600, 2.1600, -3.1600, -1.0300, 2.1600, -3.1600, -1.0300, 2.6200, -2.4300, 0.8500, 3.0000, -1.5500, 2.2800, 2.5900, -0.5700, 2.5000, 1.4900, -0.4300, 1.3700, 0.8600, -0.3800, 2.5600, 1.4900, 0.7300, 4.6100, 1.4900, 0.7300, 4.6100, 1.5300, 1.4200, 4.7200, 1.0800, 1.6100, 4.6600, -0.0700, 1.2600, 5.4800, 0.6200, 1.2700, 8.5500, 1.3700, 0.7600, 11.1200, 1.1400, 0.4600, 10.8000, 1.1400, 0.4600, 10.8000, 0.6400, 1.5400, 10.0600, 0.3400, 0.5300, 10.9900, 0.7600, 1.0000, 14.3200, 0.6400, 2.5200, 15.9600, 0.4300, 2.6400, 17.3400, -0.5500, 1.2500, 13.2400, -0.5500, 1.2500, 13.2400, 0.2300, 2.8200, 14.0200, 0.1300, 3.6500, 15.3500, 0.2300, 3.7600, 16.5700, -0.2900, 2.9500, 15.0900, -0.6000, 3.7800, 15.0900, -0.1100, 4.4300, 15.5600, -0.1100, 4.4300, 15.5600, -0.6600, 3.3100, 16.1400, -0.8000, 2.6700, 16.0700, 0.0900, 3.9500, 16.8200, -0.5600, 4.1900, 16.9800, -0.3700, 3.6100, 19.5200, -0.0300, 1.5200, 19.9800, -0.0300, 1.5200, 19.9800, -0.4200, -0.2900, 19.9800, -0.5100, -0.1200, 19.3700, -0.2500, 0.4800, 19.3000, -0.2500, 0.4300, 19.5900, -0.2700, 0.5000, 19.3400, -0.2700, 0.5000, 17.6800, -0.3400, 1.2800, 17.6800, -0.3200, 2.7600, 15.9600, -0.2200, 3.3800, 14.8100

};

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

/**
 * Printf wrapper used in the Edge Impulse Inferencing SDK
 */
void ei_printf(const char *format, ...)
{
    char print_buf[1024] = { 0 };

    va_list args;
    va_start(args, format);
    int r = vsnprintf(print_buf, sizeof(print_buf), format, args);
    va_end(args);

    if (r > 0) {
        EtaCspUartPuts(&g_sUart1, print_buf);
    }
}


/***************************************************************************//**
 *
 * main - The main entry point.
 *
 ******************************************************************************/
int
main(void)
{
    // Initialize and power up.
    EtaBspInit();
    EtaCspBuckM3FrequencySet(20000, eBuckStableWait);
    EtaUtilsStdioTerminalClear();

    while (1) {
        EtaUtilsStdioPrintf("Edge Impulse standalone inferencing (Eta Compute ECM3532)\n");

        if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
            EtaUtilsStdioPrintf("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
                EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
            return 1;
        }

        ei_impulse_result_t result = { 0 };

        // the features are stored into flash, and we don't want to load everything into RAM
        signal_t features_signal;
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, true);
        EtaUtilsStdioPrintf("run_classifier returned: %d\n", res);

        if (res != 0) return 1;

        EtaUtilsStdioPrintf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);

        // print the predictions
        EtaUtilsStdioPrintf("[");
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            int v = static_cast<int>(result.classification[ix].value * 10000.0f);
            if (v == 10000) {
                EtaUtilsStdioPrintf("1.0000");
            }
            else {
                EtaUtilsStdioPrintf("0.%d", v);
            }
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
            EtaUtilsStdioPrintf(", ");
    #else
            if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
                EtaUtilsStdioPrintf(", ");
            }
    #endif
        }
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        EtaUtilsStdioPrintf("%d", static_cast<int>(result.anomaly * 1000.0f));
    #endif
        EtaUtilsStdioPrintf("]\n");

        // And wait 2 seconds
        EtaCspRtcTmrDelayMs(5000);
    }
}
