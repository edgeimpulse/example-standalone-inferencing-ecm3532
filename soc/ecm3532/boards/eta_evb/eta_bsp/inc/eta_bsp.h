/***************************************************************************//**
 *
 * @file eta_bsp.h
 *
 * @brief This file contains eta_bsp module definitions.
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

/***************************************************************************//**
 * @addtogroup ecm3532boards-evb
 * @addtogroup ecm3532evb-bsp
 *
 * @defgroup ecm3532evb-bsp BSP (Board Support Package)
 *
 * @ingroup ecm3532boards-evb
 * @ingroup ecm3532evb-bsp
 * @{
 ******************************************************************************/

#ifndef __ETA_BSP_H__
#define __ETA_BSP_H__

#include <string.h>
#include <stdio.h>
#include <stdint.h>

// SoC files.
#include "eta_chip.h"
#include "eta_csp_inc.h"

// BSP files.
#include "eta_bsp_button.h"
#include "eta_bsp_display.h"
#include "eta_bsp_led.h"
#include "eta_bsp_power.h"

// Utils
#include "eta_utils_stdio.h"


#ifdef __cplusplus
extern "C" {
#endif

#define ETA_BSP_NUM_LEDS               (4U)
#define ETA_BSP_LED0                   (eGpioBit0) // GPIO #
#define ETA_BSP_LED1                   (eGpioBit1) // GPIO #
#define ETA_BSP_LED2                   (eGpioBit2) // GPIO #
#define ETA_BSP_LED3                   (eGpioBit25) // GPIO #
#define ETA_BS_LED_MASK                ((1 << ETA_BSP_LED0) | \
                                        (1 << ETA_BSP_LED1) | \
                                        (1 << ETA_BSP_LED2) | \
                                        (1 << ETA_BSP_LED3))
#define ETA_BSP_LED_POLARITY_LOW_IS_ON false

#define ETA_BSP_NUM_BUTTONS (2U)
#define ETA_BSP_BUTTON0     (eGpioBit10)      // GPIO #
#define ETA_BSP_BUTTON1     (eGpioBit11)      // GPIO #

#define ETA_BSP_DISP_MODE      eNhd0216ModeI2c
#define ETA_BSP_DISP_I2C_NUM   eI2C1
#define ETA_BSP_DISP_I2C_ADDR  0x3C << 1
#define ETA_BSP_DISP_I2C_SPEED eI2cClk400kHz
#define ETA_BSP_DISP_SDA       eGpioBit8
#define ETA_BSP_DISP_SCL       eGpioBit9

#define ETA_BSP_USE_UART0         (1U)
#define ETA_BSP_USE_UART1         (1U)
#define ETA_BSP_USE_UART_DSP      (1U)
#define ETA_BSP_GPIO_UART1A_RX    (eGpioBit19) // GPIO #
#define ETA_BSP_GPIO_UART1A_TX    (eGpioBit20) // GPIO #
#define ETA_BSP_GPIO_UART1A_CTS   (eGpioBit21) // GPIO #
#define ETA_BSP_GPIO_UART1A_RTS   (eGpioBit22) // GPIO #
#define ETA_BSP_GPIO_UART1B_RX    (eGpioBit3)  // GPIO #
#define ETA_BSP_GPIO_UART1B_TX    (eGpioBit7)  // GPIO #
#define ETA_BSP_GPIO_UART1B_CTS   (eGpioBit5)  // GPIO #
#define ETA_BSP_GPIO_UART1B_RTS   (eGpioBit4)  // GPIO #
#define ETA_BSP_GPIO_UART_DSPA_TX (eGpioBit7) // GPIO #
#define ETA_BSP_GPIO_UART_DSPB_TX (eGpioBit20) // GPIO #

//
// Define Legal Values for UART Selections
//
typedef enum
{
    eBspPrintfNone         = -1,
    eBspPrintfUart0Primary =  0,
    eBspPrintfUart1Primary =  1, // UART_TX on GPIO[20], UART_RX on
                                 // GPIO[19], UART_RTS GPIO[22], UART_CTS
                                 // GPIO[21]
    eBspPrintfUart1Secondary =  2, // UART_TX on GPIO[7], UART_RX on
                                   // GPIO[3], UART_RTS GPIO[4], UART_CTS
                                   // GPIO[5]
    eBspPrintfUartDspPrimary   =  3,   // UART_TX on GPIO[20]
    eBspPrintfUartDspSecondary =  4, // UART_TX on GPIO[7]
}
tBspPrintfUart;

// define which UART should be used for printf (UART0, UART1, UARTDSP
#define ETA_BSP_PRINTF_UART     (eBspPrintfUart0Primary)
#define ETA_BSP_DSP_PRINTF_UART (eBspPrintfNone)

//
// Use this function from startup code.
//
extern void *startup_get_my_pc(void);

//
// Return true if executing from flash.
//
#define ETA_BSP_IS_EXEC_FROM_FLASH() \
    ((((uint32_t)startup_get_my_pc()) & 0xFF000000u) == 0x01000000)

//
// The global UART structures.
//
extern tUart g_sUart0;
extern tUart g_sUart1;

//
//! Global BSP cold start variable.
//
extern bool g_bBspIsColdStart;

//
//! Global BSP run from flash variable.
//
extern bool g_bBspIsRunInFlash;

/*******************************************************************************
 *
 * External function definitions
 *
 ******************************************************************************/

//
// Initialize the BSP.
//
extern void EtaBspInit(void);

//
// Initialize the UARTs.
//
extern void EtaBspUartInit(tUartBaud iBaud);

//
// Deinitialize the BSP.
//
extern void EtaBspDeInit(void);

#ifdef __cplusplus
}
#endif

#endif // __ETA_BSP_H__

