/***************************************************************************//**
 *
 * @file main.c
 *
 * @brief Sleep example.
 *
 * Copyright (C) 2020 Eta Compute, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This is part of revision 1.0.0a6 of the Tensai Software Development Kit.
 *
 ******************************************************************************/

#include <stdio.h>
#include "eta_bsp.h"
#include "ei_run_classifier.h"

static const float features[] = {
    // copy raw features here (for example from the 'Live classification' page)
    // see https://docs.edgeimpulse.com/docs/running-your-impulse-ecm3532

    -7.4268, 1.7083, 7.7680, -6.5805, 2.7928, 7.6519, -6.8342, 4.0270, 7.0330, -6.3638, 4.2569, 7.5226, -6.4787, 4.7142, 7.6315, -7.1670, 4.8542, 7.4675, -6.2465, 4.5657, 7.8051, -6.0478, 4.3646, 7.4029, -6.2106, 4.1719, 7.0461, -6.2668, 3.6978, 5.9951, -6.4320, 2.7725, 5.6850, -6.4811, 1.7777, 6.0897, -6.5410, 1.1396, 6.4141, -6.7301, 1.0702, 6.3817, -7.2089, 1.5060, 5.8526, -6.9887, 2.5223, 5.7497, -6.9061, 3.0215, 5.9544, -7.1754, 3.4333, 5.9340, -7.2520, 3.1101, 6.1711, -7.3239, 2.8204, 6.1675, -7.4986, 2.5929, 5.9759, -7.6842, 2.1668, 5.8490, -7.6974, 1.8495, 5.5282, -7.8518, 1.8567, 5.2876, -8.1391, 1.9597, 5.1044, -8.5317, 2.1428, 5.2409, -8.5665, 2.5630, 5.4360, -8.3163, 2.5283, 5.5773, -8.8346, 2.3990, 5.4815, -8.7975, 2.1979, 5.1703, -9.9659, 1.8136, 4.9763, -10.2065, 1.3635, 5.4217, -10.3418, 0.5351, 6.5302, -10.6039, 0.3771, 7.2784, -10.6087, 0.6129, 7.6974, -10.9990, 1.2534, 7.5477, -10.7200, 2.0435, 7.0809, -10.0042, 3.0071, 6.4081, -9.7013, 3.4010, 6.0837, -9.4463, 3.9923, 5.3343, -8.8657, 4.0701, 4.7010, -8.7376, 3.5207, 4.1168, -8.2815, 2.7043, 3.8247, -8.3797, 1.9190, 3.7062, -8.3163, 1.2067, 3.8271, -8.1918, 0.6979, 3.8607, -8.0601, 0.5363, 3.8259, -7.6100, 0.4453, 3.5781, -7.8877, 0.4286, 3.3674, -8.7556, 0.7626, 3.2130, -8.7915, 1.0738, 4.4412, -9.5457, 1.1504, 5.7820, -10.0114, 1.1744, 6.7325, -10.2292, 1.3300, 7.1180, -10.7248, 1.5048, 7.6782, -11.0816, 1.4126, 8.0960, -11.3102, 1.3228, 8.3534, -11.7160, 1.1396, 8.3402, -11.7591, 0.8212, 8.1738, -11.7352, 0.9337, 8.1726, -10.8481, 1.1600, 8.3917, -10.8637, 1.1600, 8.1295, -10.7990, 1.4784, 7.8458, -9.5529, 1.7107, 7.7895, -9.1075, 2.2470, 7.1419, -8.8801, 2.6037, 6.9061, -7.6902, 2.7677, 6.4955, -6.7708, 2.7473, 6.1579, -6.7720, 2.8922, 5.8981, -6.4165, 2.8970, 5.9544, -6.3758, 3.0957, 6.2034, -5.1439, 2.6432, 6.6499, -5.7006, 2.3595, 6.7409, -3.5015, 1.7250, 7.8362, -3.9433, 1.7609, 7.8733, -3.2501, 1.7681, 7.7548, -2.6971, 1.5862, 6.9971, -3.5003, 1.8591, 6.5015, -1.9800, 1.9178, 6.6607, -2.7869, 2.3152, 6.0071, -0.9373, 2.6133, 6.3937, -1.4269, 2.7043, 5.2972, -1.1971, 2.9425, 5.6826, -0.6596, 2.9137, 5.3151, -1.9070, 2.8012, 6.3518, -1.0092, 2.6193, 8.0469, -1.6448, 2.5786, 8.8466, -0.8188, 2.5582, 9.8474, -0.5902, 2.2649, 9.6774, -1.3910, 1.9884, 9.2093, -1.0331, 1.5838, 9.0609, -0.3711, 1.3252, 8.9364, 0.3364, 0.8691, 8.4731, 0.0335, 0.1245, 7.3406, 0.5543, -0.4106, 6.8187, 1.2558, -0.8452, 6.4620, 1.7047, -1.0487, 6.3015, 2.3427, -1.0319, 6.6152, 2.5570, -0.8787, 7.0318, 2.9102, -0.3926, 6.8821, 3.3519, 0.1149, 6.5960, 3.8211, 0.5722, 5.8347, 3.6356, 0.8224, 5.0314, 3.6595, 0.4645, 4.9799, 3.3399, -0.3472, 5.1104, 2.1464, -1.5119, 5.7676, 1.7921, -2.0566, 6.3973, 1.6628, -3.0179, 7.1946, 0.8260, -3.7014, 7.6363, 1.0032, -4.2689, 7.9272, 0.4860, -4.2246, 7.9416, 0.1760, -4.7692, 6.9947, -0.2167, -5.1188, 6.8690, -0.4238, -5.3917, 6.9204, -1.1756, -5.8574, 7.1730, -2.1488, -5.3175, 8.1451, -2.0770, -5.3738, 9.3206, -3.0957, -5.2349, 9.9407, -3.0849, -5.3726, 10.4914, -2.8156, -5.7832, 10.6147, -3.0502, -6.0142, 10.1993, -3.2094, -5.6156, 9.8964, -2.8599, -4.3407, 8.9998, -2.9880, -3.3615, 8.1044, -3.0023, -2.7857, 7.8063
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
    uint32_t ui32I;

    //
    // Initialize and power up.
    //
    EtaBspInit();

    //
    // Setup M3 Frequency to 20MHz for this example
    //
    EtaCspBuckM3FrequencySet(20000, eBuckStableWait);

    //
    // Clear the terminal window and print the first message.
    //
    EtaUtilsStdioTerminalClear();

    while (1) {

        EtaUtilsStdioPrintf("Edge Impulse standalone inferencing (Eta Compute ECM3532)\n");
        ei_printf("%F\n", 3.21f);

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
            EtaUtilsStdioPrintf("%d", static_cast<int>(result.classification[ix].value) * 1000);
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
            EtaUtilsStdioPrintf(", ");
    #else
            if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
                EtaUtilsStdioPrintf(", ");
            }
    #endif
        }
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        EtaUtilsStdioPrintf("%d", static_cast<int>(result.anomaly) * 1000);
    #endif
        EtaUtilsStdioPrintf("]\n");

        // And wait 2 seconds
        EtaCspRtcTmrDelayMs(2000);
    }
}
