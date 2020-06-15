/***************************************************************************//**
 *
 * @file eta_bsp_display.c
 *
 * @brief This file contains display module implementation.
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
 * @addtogroup ecm3532display-bsp Display
 * @ingroup ecm3532evb-bsp
 * @{
 ******************************************************************************/

#include "eta_bsp_display.h"

/***************************************************************************//**
 *
 * EtaBspDisplayInit - Initialize the display.
 *
 ******************************************************************************/
void
EtaBspDisplayInit(void)
{
    tNhd0216Cfg sCfg;

    //
    // Configure the I2C pins.
    //
    EtaCspSocCtrlPadMuxSet(ETA_BSP_DISP_SCL, eSocCtrlPadMux1);
    EtaCspSocCtrlPadMuxSet(ETA_BSP_DISP_SDA, eSocCtrlPadMux1);

    //
    // Initialize the I2C.
    //
    if(EtaCspI2cInit(ETA_BSP_DISP_I2C_NUM,
                     ETA_BSP_DISP_I2C_SPEED) != eEtaSuccess)
    {
        EtaUtilsStdioPrintf("Error: I2C Init failed.\r\n");
    }

    //
    // Fill in the dispaly configuration.
    //
    sCfg.iMode = ETA_BSP_DISP_MODE;
    sCfg.iI2cInstance = ETA_BSP_DISP_I2C_NUM;
    sCfg.ui8I2cAddress = ETA_BSP_DISP_I2C_ADDR;

    //
    // Initialize the display.
    //
    EtaDevicesNhd0216Init(&sCfg);
}

/***************************************************************************//**
 *
 * EtaBspDisplayStringPrint - TODO
 *
 * @param pcStr TODO
 * @param iLine TODO
 *
 ******************************************************************************/
void
EtaBspDisplayStringPrint(char *pcStr, tBspDisplayLine iLine)
{
    EtaDevicesNhd0216StringPrint(pcStr, iLine, 0);
}

/***************************************************************************//**
 *
 * EtaBspDisplayStringClearAndPrint - Clear the display first then print.
 *
 * @param pcStr TODO
 * @param iLine TODO
 *
 ******************************************************************************/
void
EtaBspDisplayStringClearAndPrint(char *pcStr, tBspDisplayLine iLine)
{
    //
    // Clear.
    //
    EtaBspDisplayClear();

    //
    // Print.
    //
    EtaDevicesNhd0216StringPrint(pcStr, iLine, 0);
}

/***************************************************************************//**
 *
 * EtaBspDisplayClear - Clear the display.
 *
 ******************************************************************************/
void
EtaBspDisplayClear(void)
{
    EtaDevicesNhd0216Clear();
}

