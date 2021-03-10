/* Include ------------------------------------------------------------------ */
#include "config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "gpio_hal.h"
#include "timer_hal.h"
#include "uart_hal.h"
#include <stdint.h>

#include "ei_run_classifier.h"
#include "ei_classifier_porting.h"

extern "C" {
#include "eta_bsp.h"
}

#define TASK_STACK_SIZE  2048

/** UART used for edge impulse communication */
tUart etaUart;

static const float features[] = {
    // copy raw features here (for example from the 'Live classification' page)
    // see https://docs.edgeimpulse.com/docs/running-your-impulse-ecm353
};

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

static void vInferTask(void *pvParameters)
{

    while (1) {
        ei_printf("Edge Impulse standalone inferencing (Eta Compute ECM3532)\n");

        if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
            ei_printf("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
                EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
            return;
        }

        ei_impulse_result_t result = { 0 };

        // the features are stored into flash, and we don't want to load everything into RAM at the same time
        // so we use a signal to wrap around the data
        signal_t features_signal;
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, true);
        ei_printf("run_classifier returned: %d\n", res);

        if (res != 0) return;

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

int main(void)
{
    EtaCspTimerDelayMs(2000);
    EtaCspUartInit(&etaUart, (tUartNum)CONFIG_DEBUG_UART, eUartBaud115200, eUartFlowControlNone);
    EtaCspTimerDelayMs(500);

	xTaskCreate(vInferTask, "standalone inference", TASK_STACK_SIZE,
                NULL, tskIDLE_PRIORITY + 3, NULL);

    /* Start the scheduler. */
	vTaskStartScheduler();
}