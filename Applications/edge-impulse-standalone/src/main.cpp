/* Include ------------------------------------------------------------------ */
#include "config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "gpio_hal.h"
#include "timer_hal.h"
#include "uart_hal.h"
#include <stdint.h>
#include "ei_classifier_porting.h"
extern "C" {
#include "eta_bsp.h"
#include "executor_public.h"
}
extern "C" {
    #include "executor_public.h"
    void infer(const q7_t *pIn0, q7_t *pOut0);
}
#define TASK_STACK_SIZE  2048
#define APP_LED (CONFIG_APP_LED_GPIO)
/** UART used for edge impulse communication */
tUart etaUart;
#define EI_CLASSIFIER_TFLITE_INPUT_SCALE         0.15670588612556458
#define EI_CLASSIFIER_TFLITE_INPUT_ZEROPOINT     -1
#define EI_CLASSIFIER_TFLITE_OUTPUT_SCALE        0.00390625
#define EI_CLASSIFIER_TFLITE_OUTPUT_ZEROPOINT    -128
static void vInferTask(void *pvParameters)
{
#if defined(EI_CLASSIFIER_COMPILED) && EI_CLASSIFIER_COMPILED == 1
    #error "This platform does not support the EON compiler. Export with EON compiler disabled."
#endif

    while (1) {
        float input_f[] = { -2.0698, -19.9800, 19.9700, 13.8355, 13.6798, 0.1949, -1.2427 };
        int8_t input[7];
        int8_t output[4];
        for (size_t ix = 0; ix < 7; ix++) {
            float f = input_f[ix];
            input[ix] = static_cast<int8_t>(round(f / EI_CLASSIFIER_TFLITE_INPUT_SCALE) + EI_CLASSIFIER_TFLITE_INPUT_ZEROPOINT);
        }        
        infer(input, output);
        ei_printf("Output:\n");
        for (size_t ix = 0; ix < 4; ix++) {
            int8_t v_in = output[ix];
            float v = static_cast<float>(v_in - EI_CLASSIFIER_TFLITE_OUTPUT_ZEROPOINT) * EI_CLASSIFIER_TFLITE_OUTPUT_SCALE;
            ei_printf("%u: %f %d\n", ix, v, output[ix]);
        }
        // And wait 5 seconds
        EtaCspRtcTmrDelayMs(5000);
    }
}
int main(void)
{
    EtaCspTimerDelayMs(2000);
    EtaCspUartInit(&etaUart, (tUartNum)CONFIG_DEBUG_UART, eUartBaud115200, eUartFlowControlNone);
    EtaCspTimerDelayMs(500);
// #if (EI_CLASSIFIER_INFERENCING_ENGINE == EI_CLASSIFIER_TENSAIFLOW)
	ExecInit();
// #endif
	xTaskCreate(vInferTask, "Executor_Compiler_Test", TASK_STACK_SIZE,
                NULL, tskIDLE_PRIORITY + 3, NULL);
    	/* Start the scheduler. */
	vTaskStartScheduler();
}