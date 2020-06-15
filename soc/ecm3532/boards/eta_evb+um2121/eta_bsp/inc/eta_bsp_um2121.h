/***************************************************************************//**
 *
 * @file eta_bsp_um2121.h
 *
 * @brief This file contains eta_bsp module definitions for the evb + um2121.
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
 * @addtogroup ecm3532boards-evb-um2121
 * @addtogroup ecm3532evb-um2121-bsp
 *
 * @defgroup ecm3532evb-um2121-bsp BSP (Board Support Package)
 *
 * @ingroup ecm3532boards-evb-um2121
 * @ingroup ecm3532evb-um2121-bsp
 * @{
 ******************************************************************************/

#ifndef __ETA_BSP_UM2121_H__
#define __ETA_BSP_UM2121_H__

#ifdef __cplusplus
extern "C" {
#endif

//
// Include the BSP for the EVB.
//
#include "../../../eta_evb/eta_bsp/inc/eta_bsp.h"

//
// Include the lsm6dso accel + gyro sensor.
//
#include "eta_devices_lsm6dso.h"

#define ETA_BSP_LSM6DSO_I2C_NUM   (1U)
#define ETA_BSP_LSM6DSO_I2C_ADDR  0xD6
#define ETA_BSP_LSM6DSO_I2C_SPEED eI2cClk400kHz
#define ETA_BSP_LSM6DSO_SDA       eGpioBit8
#define ETA_BSP_LSM6DSO_SCL       eGpioBit9

/*******************************************************************************
 *
 * External function definitions.
 *
 ******************************************************************************/
extern void EtaBspUm2121Init(void);

#ifdef __cplusplus
}
#endif

#endif // __ETA_BSP_UM2121_H__

