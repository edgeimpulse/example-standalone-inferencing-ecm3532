/***************************************************************************//**
 *
 * @file eta_bsp_um2121.c
 *
 * @brief This file contains eta_bsp module implementation for the evb + um2121.
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
 * This is part of revision 1.0.0a3 of the Tensai Software Development Kit.
 *
 ******************************************************************************/

/***************************************************************************//**
 * @ingroup ecm3532evb-um2121-bsp
 * @{
 ******************************************************************************/

#include "eta_bsp_um2121.h"

/***************************************************************************//**
 *
 * EtaBspUm2121Init - Initialize the ECM3532EVB and the UM2121 BSP.
 *
 ******************************************************************************/
void
EtaBspUm2121Init(void)
{
    tLsm6dsoCfg sLsm6dsoCfg;

    //
    // Call the evb BSP init.
    //
    EtaBspInit();

    //
    // Configure the I2C pins.
    //
    EtaCspSocCtrlPadMuxSet(ETA_BSP_LSM6DSO_SCL, eSocCtrlPadMux1);
    EtaCspSocCtrlPadMuxSet(ETA_BSP_LSM6DSO_SDA, eSocCtrlPadMux1);

    //
    // Initialize the I2C.
    //
    if(EtaCspI2cInit(ETA_BSP_LSM6DSO_I2C_NUM,
                     ETA_BSP_LSM6DSO_I2C_SPEED) != eEtaSuccess)
    {
        EtaUtilsStdioPrintf("Error: I2C Init failed.\r\n");
    }

    //
    // Initialize the lsm6dso
    //
    sLsm6dsoCfg.iI2cInstance = ETA_BSP_LSM6DSO_I2C_NUM;
    sLsm6dsoCfg.ui8I2cAddress = ETA_BSP_LSM6DSO_I2C_ADDR;
    EtaDevicesLsm6dsoInit(&sLsm6dsoCfg);
}

