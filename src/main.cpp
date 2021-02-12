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
    -4.0000, -6.3800, 1.0100, -3.6100, -7.2000, 1.8600, -3.6100, -7.2000, 1.8600, -3.7100, -7.4300, 1.6200, -2.6000, -6.4200, -0.0400, -1.8100, -5.7300, -0.2200, -1.1100, -6.1800, 0.3600, -0.7500, -6.3600, 0.6100, 0.0400, -5.6100, -0.3600, 0.0400, -5.6100, -0.3600, 1.2000, -5.2900, -1.7000, 0.9300, -4.9100, -2.0500, 1.1600, -5.4300, -1.2600, 1.9000, -5.1000, -1.4600, 3.0700, -4.0400, -3.1000, 4.2900, -3.8000, -3.7200, 4.2900, -3.8000, -3.7200, 5.3900, -4.6100, -3.3500, 6.2000, -4.6100, -3.6300, 8.3300, -3.9200, -4.8200, 10.3500, -3.7400, -4.8700, 11.4300, -4.0500, -4.9500, 11.4300, -4.0500, -6.4300, 12.4600, -3.5000, -6.4300, 14.2500, -3.3300, -7.6200, 15.5200, -3.4100, -7.7900, 15.4000, -3.2200, -8.0800, 15.2300, -3.1900, -8.5800, 14.0400, -3.2900, -8.2500, 14.0400, -3.2900, -8.2500, 12.9400, -3.6300, -7.8900, 12.7600, -4.0400, -7.7900, 11.8500, -4.8700, -6.7400, 11.1500, -5.1700, -6.1400, 10.3600, -5.6000, -5.2000, 10.1100, -5.6300, -4.9700, 10.1100, -5.6300, -4.9700, 9.8300, -4.7600, -5.7500, 9.4100, -4.1200, -6.4500, 8.2500, -4.9400, -4.8800, 7.2500, -5.2600, -4.8200, 4.6900, -5.1500, -2.8600, 3.1400, -5.6100, -1.5400, 3.1400, -5.6100, -1.5400, 3.9300, -6.2200, -2.2500, 2.6700, -6.1500, -2.2900, 0.1300, -5.7500, -1.9800, -1.7700, -5.8300, -1.3000, -1.8500, -6.4400, -0.7000, -1.5000, -6.1400, -1.3500, -1.5000, -6.1400, -1.3500, -1.2100, -5.6000, -1.9500, -2.9100, -5.5200, -1.3600, -4.9300, -5.9400, 0.0600, -5.2600, -7.0500, 1.3200, -4.4300, -7.0500, 0.8100, -3.9700, -5.8900, -0.2200, -3.9700, -5.8900, -0.2200, -4.1600, -5.6900, 0.0200, -5.6300, -6.0100, 1.2900, -6.4300, -5.9300, 2.5900, -5.6600, -5.5900, 1.9800, -7.0900, -4.9900, 2.0800, -8.9100, -5.0200, 3.0700, -8.9100, -5.0200, 3.0700, -8.9300, -5.2800, 3.2900, -10.6300, -4.3200, 2.4500, -11.4500, -3.9900, 2.1100, -12.6600, -3.8700, 2.1400, -14.2200, -3.9200, 2.1200, -14.8200, -4.2300, 1.9100, -14.8200, -4.2300, 1.9100, -15.2600, -3.9600, 1.6800, -16.2400, -4.0000, 1.6700, -17.2800, -4.0400, 1.6200, -17.7800, -4.1500, 1.2800, -18.1900, -4.1500, 1.1700, -17.7200, -4.5800, 1.2900, -17.7200, -4.5800, 1.2900, -16.9500, -4.8000, 1.6900, -15.8700, -4.5000, 1.6100, -14.5400, -4.4500, 1.5300, -13.1600, -4.5400, 1.4900, -12.4100, -4.3000, 1.1600, -11.3600, -4.1800, 0.8300, -11.3600, -4.1800, 0.8300, -10.9700, -4.7100, 1.6000, -9.9400, -4.4000, 1.1900, -8.5400, -4.1600, 0.2800, -7.8500, -4.6100, 0.4300, -7.1500, -5.0700, 0.7300, -6.6300, -5.3600, 0.9100, -6.6300, -5.3600, 0.9100, -6.1700, -5.1000, 0.2000, -5.5100, -4.7700, -0.4000, -4.6600, -5.0500, -0.3600, -3.6200, -4.9300, -0.6300, -2.2000, -4.8600, -1.5900, -2.2000, -4.8600, -1.5900, -1.3300, -4.8000, -2.2100, -1.0800, -5.3600, -2.2300, -0.8700, -5.6600, -2.0600, -0.1300, -5.3900, -2.3400, 0.8600, -4.5300, -3.2000, 1.6600, -4.1700, -3.5500, 1.6600, -4.1700, -3.5500, 2.9800, -4.5800, -4.1100, 2.8100, -5.1500, -4.0100, 3.6400, -5.1300, -3.6500, 5.5600, -5.1200, -3.5800, 6.1500, -5.0300, -3.5300, 6.3200, -5.1100, -3.6400, 6.3200, -5.1100, -3.6400, 6.5900, -4.7700, -4.4300, 6.9200, -4.0700, -4.9200, 7.1700, -4.4700, -4.4800, 8.1900, -4.4800, -4.4700, 9.7500, -4.0000, -4.9300, 11.0900, -3.4000, -5.5500, 11.0900, -3.4000, -5.5500, 11.5000, -3.8300, -5.8400, 11.0500, -4.6200, -5.7100, 10.9900, -5.4000, -5.5900, 12.0800, -5.4900, -6.2600, 12.9800, -5.4600, -6.6600
};

#if EI_CLASSIFIER_USE_QUANTIZED_DSP_BLOCK == 1
static float SCALING_FACTOR = 1.0f;
int raw_feature_get_data(size_t offset, size_t length, int16_t *out_ptr) {
    for (size_t ix = 0; ix < length; ix++) {
        float scaled_float = features[offset + ix] * SCALING_FACTOR;
        numpy::float_to_int16(&scaled_float, &out_ptr[ix], 1);
    }
    return 0;
}
#else
int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}
#endif

/**
 * Printf wrappers used in the Edge Impulse Inferencing SDK
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

void ei_printf_float(float f)
{
    float n = f;

    static double PRECISION = 0.00001;
    static int MAX_NUMBER_STRING_SIZE = 32;

    char s[MAX_NUMBER_STRING_SIZE];

    if (n == 0.0) {
        strcpy(s, "0");
    }
    else {
        int digit, m, m1;
        char *c = s;
        int neg = (n < 0);
        if (neg) {
            n = -n;
        }
        // calculate magnitude
        m = log10(n);
        if (neg) {
            *(c++) = '-';
        }
        if (m < 1.0) {
            m = 0;
        }
        // convert the number
        while (n > PRECISION || m >= 0) {
            double weight = pow(10.0, m);
            if (weight > 0 && !isinf(weight)) {
                digit = floor(n / weight);
                n -= (digit * weight);
                *(c++) = '0' + digit;
            }
            if (m == 0 && n > 0) {
                *(c++) = '.';
            }
            m--;
        }
        *(c) = '\0';
    }

    EtaCspUartPuts(&g_sUart1, s);
}



/***************************************************************************//**
 *
 * main - The main entry point.
 *
 ******************************************************************************/
int main(void)
{
    // Initialize and power up.
    EtaBspInit();
    EtaCspBuckM3FrequencySet(80000, eBuckStableWait);
    EtaUtilsStdioTerminalClear();

#if defined(EI_CLASSIFIER_COMPILED) && EI_CLASSIFIER_COMPILED == 1
    #error "This platform does not support the EON compiler. Export with EON compiler disabled."
#endif

#if EI_CLASSIFIER_USE_QUANTIZED_DSP_BLOCK == 1
    if (ei_dsp_blocks_i16_size != 1 || ei_dsp_blocks_i16[0].extract_fn != (int (*)(ei::signal_i16_t*, ei::matrix_i32_t*, void*, float))&extract_spectral_analysis_features) {
        ei_printf("ERR: EI_CLASSIFIER_USE_QUANTIZED_DSP_BLOCK is only supported with a single spectral analysis DSP block\n");
        return 1;
    }
    SCALING_FACTOR = ((ei_dsp_config_spectral_analysis_t*)ei_dsp_blocks_i16[0].config)->scale_axes;
    // set scaling factor to 1, as we're scaling in the signal
    ((ei_dsp_config_spectral_analysis_t*)ei_dsp_blocks_i16[0].config)->scale_axes = 1;
#endif

    while (1) {
        ei_printf("Edge Impulse standalone inferencing (Eta Compute ECM3532)\n");

        if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
            ei_printf("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
                EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
            return 1;
        }

        ei_impulse_result_t result = { 0 };

        // the features are stored into flash, and we don't want to load everything into RAM at the same time
        // so we use a signal to wrap around the data
#if EI_CLASSIFIER_USE_QUANTIZED_DSP_BLOCK == 1
        signal_i16_t features_signal;
#else
        signal_t features_signal;
#endif
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
#if EI_CLASSIFIER_USE_QUANTIZED_DSP_BLOCK == 1
        EI_IMPULSE_ERROR res = run_classifier_i16(&features_signal, &result, true);
#else
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, true);
#endif
        ei_printf("run_classifier returned: %d\n", res);

        if (res != 0) return 1;

        ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
            result.timing.dsp, result.timing.classification, result.timing.anomaly);

        // print the predictions
        ei_printf("[");
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            ei_printf_float(result.classification[ix].value);
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
            ei_printf(", ");
    #else
            if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
                ei_printf(", ");
            }
    #endif
        }
    #if EI_CLASSIFIER_HAS_ANOMALY == 1
        ei_printf_float(result.anomaly);
    #endif
        ei_printf("]\n");

        // And wait 5 seconds
        EtaCspRtcTmrDelayMs(5000);
    }
}
