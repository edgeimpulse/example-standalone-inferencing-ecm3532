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

#include "eta_bsp.h"

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
    // Is this the first time running the example?
    //
    if(g_bBspIsColdStart)
    {
        //
        // Setup M3 Frequency to 20MHz for this example
        //
        EtaCspBuckM3FrequencySet(20000, true);

        //
        // Clear the terminal window and print the first message.
        //
        EtaUtilsStdioTerminalClear();
        EtaUtilsStdioPrintf("%s Example - in %s\r\n", PROJ_NAME,
                            g_bBspIsRunInFlash ? "Flash" : "SRAM");
    }

    else
    {
        //
        // Restore power state.
        //
        EtaCspPwrDefaultsRestore();
        EtaCspPwrOff(ePwrDomainBuckDsp);

        //
        // Print that we are awake.
        //
        EtaUtilsStdioPrintf("Awake!\r\n");

    }

    //
    // Let the user know that the device is active.
    //
    EtaUtilsStdioPrintf("Active for 10s");

    //
    // Loop and print.
    //
    ui32I = 4;
    while(ui32I--)
    {
        //
        // Delay 2 seconds and print a ".".
        //
        EtaCspRtcTmrDelayMs(2000);
        EtaUtilsStdioPrintf(".");
    }

    //
    // Let the user know that the device is sleeping.
    //
    EtaUtilsStdioPrintf("Sleeping for 10s.\r\n");

    //
    // Sleep for 10 seconds.
    //
    // This function configured the RTC to wake the device after the specified
    // number of milliseconds.  Upon wake up the device will come back around
    // through the reset vector.
    //
    EtaBspPowerM3SleepMs(10 * 1000);
}
