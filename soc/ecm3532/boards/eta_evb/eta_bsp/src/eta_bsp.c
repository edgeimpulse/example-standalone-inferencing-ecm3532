/***************************************************************************//**
 *
 * @file eta_bsp.c
 *
 * @brief This file contains eta_bsp module implementation.
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
 * @ingroup ecm3532evb-bsp
 * @{
 ******************************************************************************/

#include "eta_bsp.h"

//
//! The global UART structures.
//
tUart g_sUart0;
tUart g_sUart1;

//
//! Global BSP cold start variable.
//
bool g_bBspIsColdStart;

//
//! Global BSP run from flash variable.
//
bool g_bBspIsRunInFlash;

/***************************************************************************//**
 *
 * EtaBspInit - Initialize the BSP.
 *
 ******************************************************************************/
void
EtaBspInit(void)
{
    //
    // Determine if this is the first time through the example.
    //
    g_bBspIsColdStart = (EtaCspRtcRestartModeGet() == eRestartCold);

    //
    // Is this running in Flash?
    //
    g_bBspIsRunInFlash = ETA_BSP_IS_EXEC_FROM_FLASH();

    //
    // Do the standard CSP init.
    //
    EtaCspInit();

    //
    // Standard peripheral initializations
    //
    EtaCspGpioInit();

    //
    // Release the GPIOs after a power down.
    //
    EtaCspGpioRelease();

    //
    // Initialize the bucks.
    //
    EtaCspBuckInit();

    //
    // Initialize the timer.
    //
    EtaCspTimerInitMs();

#ifdef USE_SEGGER_RTT_PRINTF
    //
    // Initialize the SEGGER RTT.
    //
    SEGGER_RTT_ConfigUpBuffer(0, "Printf", NULL, 0,
                              SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
#else
    //
    // Initialize the UART to 115200 baud.
    //
    EtaBspUartInit(eUartBaud115200);
#endif

    //
    // Initialize the LEDs.
    //
    EtaBspLedsInit();

    //
    // Initialize the buttons.
    //
    EtaBspButtonInit();

    //
    // Initialize the display.
    //
    EtaBspDisplayInit();

    //
    // Enable the weak pull on SPIO0 MISO to keep from floating.
    //
    REG_W1(RTC_SPI0_CTRL, SPI0_MISO_RE, 1);

    //
    // Initialize the default HFO tune.
    //
    EtaCspHfoTuneDefaultInit();

#if defined(SRAM) || defined(FLASH_BOOT_SRAM)

    //
    // Indicate power up should be a warm start to SRAM.
    //
    EtaCspRtcRestartModeSet(eRestartWarmSramHfoTune);
#else

    //
    // Indicate power up should be a warm start to flash.
    //
    EtaCspRtcRestartModeSet(eRestartWarmFlashNoTrimNoHfoTune);
#endif
}

/***************************************************************************//**
 *
 * EtaBspUartInit - Initialize the BSP UARTs.
 *
 * @param iBaud is the desired baud rate for the UARTs.
 *
 ******************************************************************************/
void
EtaBspUartInit(tUartBaud iBaud)
{
    //
    // Init UART0 and UART1.
    //
    EtaCspUartInit(&g_sUart0, eUartNum0, iBaud, eUartFlowControlNone);
    EtaCspUartInit(&g_sUart1, eUartNum1, iBaud, eUartFlowControlNone);

    //
    // Setup pins for UART1.
    //
    EtaCspUartPinSelect(&g_sUart1, ETA_BSP_GPIO_UART1B_TX, ETA_BSP_GPIO_UART1B_RX,
                        ETA_BSP_GPIO_UART1B_RTS, ETA_BSP_GPIO_UART1B_CTS);

    //
    // Use UART0 as the Printf terminal.
    //
    EtaCspIoPrintfRedirect(&g_sUart1);


}

/***************************************************************************//**
 *
 * EtaBspDeInit - Deinitialize the BSP.
 *
 ******************************************************************************/
void
EtaBspDeInit(void)
{
    //
    // Wait for and turn the UARTs off.
    //
    EtaCspUartTxWait(&g_sUart0);
    EtaCspUartTxWait(&g_sUart1);
}
