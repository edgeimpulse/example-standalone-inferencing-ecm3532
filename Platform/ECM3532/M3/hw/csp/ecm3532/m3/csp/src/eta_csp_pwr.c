/***************************************************************************//**
 *
 * @file eta_csp_pwr.c
 *
 * @brief This file contains eta_csp_pwr module implementations.
 *
 * Copyright (C) 2018 Eta Compute, Inc
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
 * This is part of revision 1.0.0b1 of the Tensai Chip Support Package.
 *
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup ecm3532pwr-m3 Power
 * @ingroup ecm3532csp-m3
 * @{
 ******************************************************************************/

#include "eta_chip.h"
#include "eta_chip.h"
#include "eta_csp.h"
#include "eta_csp_buck.h"
#include "eta_csp_pwr.h"
#include "eta_csp_rtc.h"

/***************************************************************************//**
 *
 *  EtaCspPwrForceGet - Return the set of Force bits that are turned on.
 *
 *  @return a set of force conditions that are asserted within always on block.
 *
 *  NOTE the enums are one hot encoded so that they can be ORed together. The
 *  return value can be ANDed with enums to break out individual members of the
 *  set.
 *
 ******************************************************************************/
uint32_t
EtaCspPwrForceGet(void)
{
    //
    // Build the set to return in this work variable.
    //
    uint32_t ui32Work = 0;

    //
    // Shadow copy... read once, use many times.
    //
    reg_rtc_pwr_set_t sregShadow;
    sregShadow.V = REG_RTC_PWR.V;

    //
    // Now break out each potential member of the set.
    //
    if(sregShadow.BF.PERIPH_FORCE)
    {
        ui32Work |= ePwrDomainPeriph;
    }
    if(sregShadow.BF.M3_SRAM0_FORCE)
    {
        ui32Work |= ePwrDomainSram0;
    }
    if(sregShadow.BF.M3_SRAM1_FORCE)
    {
        ui32Work |= ePwrDomainSram1;
    }
    if(sregShadow.BF.M3_SRAM23_FORCE)
    {
        ui32Work |= ePwrDomainSram23;
    }
    if(sregShadow.BF.M3_SRAM4567_FORCE)
    {
        ui32Work |= ePwrDomainSram4567;
    }
    if(sregShadow.BF.M3_FLASH_FORCE)
    {
        ui32Work |= ePwrDomainFlash;
    }
    if(sregShadow.BF.MEM_BUCK_FORCE)
    {
        ui32Work |= ePwrDomainBuckMem;
    }
    if(sregShadow.BF.M3_BUCK_FORCE)
    {
        ui32Work |= ePwrDomainBuckM3;
    }

    //
    // Now that we assembled the set, simply return it.
    //
    return ui32Work;
}

/***************************************************************************//**
 *
 *  EtaCspPwrForce - Force the desired domain(s).
 *
 *  @param iDomain domain to force, these can be ORed together for efficiency.
 *
 ******************************************************************************/
void
EtaCspPwrForce(tPwrDomain iDomain)
{
    //
    // Shadow copy. Build it here then send it once.
    //
    reg_rtc_pwr_set_t sregShadow;
    sregShadow.V = 0;

    //
    // Force the desired domain(s).
    //
    if(iDomain & ePwrDomainPeriph)
    {
            sregShadow.BF.PERIPH_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram0)
    {
            sregShadow.BF.M3_SRAM0_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram1)
    {
            sregShadow.BF.M3_SRAM1_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram23)
    {
            sregShadow.BF.M3_SRAM23_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram4567)
    {
            sregShadow.BF.M3_SRAM4567_FORCE = 1;
    }

    if(iDomain & ePwrDomainFlash)
    {
            sregShadow.BF.M3_FLASH_FORCE = 1;
    }

    if(iDomain & ePwrDomainBuckMem)
    {
            sregShadow.BF.MEM_BUCK_FORCE = 1;
    }

    if(iDomain & ePwrDomainBuckM3)
    {
            sregShadow.BF.M3_BUCK_FORCE = 1;
    }

    //
    // Set any and all comers into the actual register.
    //
    REG_RTC_PWR_SET.V = sregShadow.V;

    //
    // Ensure the writes are complete before returning.
    //
    EtaCspRtcFence();
}

/***************************************************************************//**
 *
 *  EtaCspPwrRelease - Release the desired domain.
 *
 *  @param iDomain domain to release, these can be ORed together for efficiency.
 *
 ******************************************************************************/
void
EtaCspPwrRelease(tPwrDomain iDomain)
{
    //
    // Shadow copy. Build it here then send it once.
    //
    reg_rtc_pwr_set_t sregShadow;
    sregShadow.V = 0;

    //
    //! Release the desired domain(s).
    //
    if(iDomain & ePwrDomainPeriph)
    {
            sregShadow.BF.PERIPH_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram0)
    {
            sregShadow.BF.M3_SRAM0_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram1)
    {
            sregShadow.BF.M3_SRAM1_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram23)
    {
            sregShadow.BF.M3_SRAM23_FORCE = 1;
    }

    if(iDomain & ePwrDomainSram4567)
    {
            sregShadow.BF.M3_SRAM4567_FORCE = 1;
    }

    if(iDomain & ePwrDomainFlash)
    {
            sregShadow.BF.M3_FLASH_FORCE = 1;
    }

    if(iDomain & ePwrDomainBuckMem)
    {
            sregShadow.BF.MEM_BUCK_FORCE = 1;
    }

    if(iDomain & ePwrDomainBuckM3)
    {
            sregShadow.BF.M3_BUCK_FORCE = 1;
    }

    //
    // Clear any and all comers into the actual register.
    //
    REG_RTC_PWR_CLEAR.V = sregShadow.V;

    //
    // Ensure the writes are complete before returning.
    //
    EtaCspRtcFence();
}


/***************************************************************************//**
 *
 *  EtaCspPwrOnGet - Return the set of Power On bits that are turned on.
 *
 *  @return a set of power on bits that are asserted within always on block.
 *
 *  NOTE the enums are one hot encoded so that they can be ORed together. The
 *  return value can be ANDed with enums to break out individual members of the
 *  set.
 *
 *
 ******************************************************************************/
uint32_t
EtaCspPwrOnGet(void)
{
    //
    // Build the set to return in this work variable.
    //
    uint32_t ui32Work = 0;

    //
    // Shadow copy... read once, use many times.
    //
    reg_rtc_pwr_set_t sregShadow;
    sregShadow.V = REG_RTC_PWR.V;

    //
    // Now break out each potential member of the set.
    //
    if(sregShadow.BF.PERIPH)
    {
        ui32Work |= ePwrDomainPeriph;
    }
    if(sregShadow.BF.M3_SRAM0)
    {
        ui32Work |= ePwrDomainSram0;
    }
    if(sregShadow.BF.M3_SRAM1)
    {
        ui32Work |= ePwrDomainSram1;
    }
    if(sregShadow.BF.M3_SRAM23)
    {
        ui32Work |= ePwrDomainSram23;
    }
    if(sregShadow.BF.M3_SRAM4567)
    {
        ui32Work |= ePwrDomainSram4567;
    }
    if(sregShadow.BF.M3_FLASH)
    {
        ui32Work |= ePwrDomainFlash;
    }
    if(sregShadow.BF.DSP_BUCK)
    {
        ui32Work |= ePwrDomainBuckDsp;
    }
    if(sregShadow.BF.DSP)
    {
        ui32Work |= ePwrDomainDsp;
    }
    if(sregShadow.BF.ADC)
    {
        ui32Work |= ePwrDomainAdc;
    }

    //
    // Now that we assembled the set, simply return it.
    //
    return ui32Work;
}

/***************************************************************************//**
 *
 *  EtaCspPwrOn - Turn on the desired domain.
 *
 *  @param iDomain domain to turn on, these can be ORed together for efficiency.
 *
 ******************************************************************************/
void
EtaCspPwrOn(tPwrDomain iDomain)
{
    //
    // Shadow copy. Build it here then send it once.
    //
    reg_rtc_pwr_set_t sregShadow;
    sregShadow.V = 0;

    if(iDomain & ePwrDomainPeriph)
    {
            sregShadow.BF.PERIPH = 1;
    }

    if(iDomain & ePwrDomainSram0)
    {
            sregShadow.BF.M3_SRAM0 = 1;
    }

    if(iDomain & ePwrDomainSram1)
    {
            sregShadow.BF.M3_SRAM1 = 1;
    }

    if(iDomain & ePwrDomainSram23)
    {
            sregShadow.BF.M3_SRAM23 = 1;
    }

    if(iDomain & ePwrDomainSram4567)
    {
            sregShadow.BF.M3_SRAM4567 = 1;
    }

    if(iDomain & ePwrDomainFlash)
    {
            sregShadow.BF.M3_FLASH = 1;
    }

    if(iDomain & ePwrDomainBuckDsp)
    {
            sregShadow.BF.DSP_BUCK = 1;
    }

    if(iDomain & ePwrDomainDsp)
    {
            sregShadow.BF.DSP = 1;
    }

    if(iDomain & ePwrDomainAdc)
    {
            sregShadow.BF.ADC = 1;
    }

    //
    // The following power domains can not be turned off or on directly.
    //
    // ePwrDomainBuckMem:
    // ePwrDomainBuckM3:

    //
    // Set any and all comers into the actual register.
    //
    REG_RTC_PWR_SET.V = sregShadow.V;

    //
    // Ensure the writes are complete before returning.
    //
    EtaCspRtcFence();
}

/***************************************************************************//**
 *
 *  EtaCspPwrOff - Power off the desired domain.
 *
 *  @param iDomain domain to be powered off.
 *
 ******************************************************************************/
void
EtaCspPwrOff(tPwrDomain iDomain)
{
    //
    // Shadow copy. Build it here then send it once.
    //
    reg_rtc_pwr_set_t sregShadow;
    sregShadow.V = 0;

    if(iDomain & ePwrDomainPeriph)
    {
            sregShadow.BF.PERIPH = 1;
    }

    if(iDomain & ePwrDomainSram0)
    {
            sregShadow.BF.M3_SRAM0 = 1;
    }

    if(iDomain & ePwrDomainSram1)
    {
            sregShadow.BF.M3_SRAM1 = 1;
    }

    if(iDomain & ePwrDomainSram23)
    {
            sregShadow.BF.M3_SRAM23 = 1;
    }

    if(iDomain & ePwrDomainSram4567)
    {
            sregShadow.BF.M3_SRAM4567 = 1;
    }

    if(iDomain & ePwrDomainFlash)
    {
            sregShadow.BF.M3_FLASH = 1;
    }

    if(iDomain & ePwrDomainBuckDsp)
    {
            sregShadow.BF.DSP_BUCK = 1;
    }

    if(iDomain & ePwrDomainDsp)
    {
            sregShadow.BF.DSP = 1;
    }

    if(iDomain & ePwrDomainAdc)
    {
            sregShadow.BF.ADC = 1;
    }

    //
    // The following power domains can not be turned off or on directly.
    //
    // ePwrDomainBuckMem:
    // ePwrDomainBuckM3:

    //
    // Set any and all comers into the actual register.
    //
    REG_RTC_PWR_CLEAR.V = sregShadow.V;

    //
    // Ensure the writes are complete before returning.
    //
    EtaCspRtcFence();
}

/***************************************************************************//**
 *
 *  EtaCspPwrDefaultsRestore - Restore the default power configuration.
 *
 ******************************************************************************/
void
EtaCspPwrDefaultsRestore(void)
{
    //
    // Turn off DSP and ADC.
    //
    REG_W2(RTC_PWR_CLEAR,
           ADC, 1,
           DSP, 1);

    //
    // Turn off any forced on things. Turn off DSP and ADC.
    //
    REG_W9(RTC_PWR_CLEAR,
           MEM_BUCK_FORCE, 1,
           M3_BUCK_FORCE, 1,
           M3_SRAM0_FORCE, 1,
           M3_SRAM1_FORCE, 1,
           M3_SRAM23_FORCE, 1,
           M3_SRAM4567_FORCE, 1,
           PERIPH_FORCE, 1,
           M3_FLASH_FORCE, 1,
           GPIO_FROZEN, 1);

    //
    // Turn on any SRAM banks that might be off.
    // The M3, MEM and AO bucks have to be on already.
    //
    REG_W4(RTC_PWR_SET,
           M3_SRAM0, 1,
           M3_SRAM1, 1,
           M3_SRAM23, 1,
           M3_SRAM4567, 1);

    //
    // Make sure flash is re-enabled.
    //
    REG_WS3(RTC_PWR_SET, FLASH_V25, FLASH_VREF, M3_FLASH);
    REG_WS1(RTC_PWR_CLEAR, FLASH_PDM);
}

/***************************************************************************//**
 *
 *  EtaCspPwrSocShutdown - Shutdown the M3.
 *
 ******************************************************************************/
void
EtaCspPwrSocShutdown(void)
{
    //
    // Always warn the buck CSP before power down.
    //
    EtaCspBuckPrePowerDown();

    //
    // Perform a power down of the M3 and all SRAM, FLASH, BOOTROM and
    // peripheral block hardware; except any SRAM or peripheral block that is
    // forced to remain on.
    //
    REG_W1(RTC_PWR_SET, POWER_DOWN, 1);

    //
    // Now sit here and wait to go to sleep.
    //
    while(1)
    {
    }
}

/***************************************************************************//**
 *
 * EtaCspPwrWakePinGet - return the state of the wake pin
 *
 * @return True if the wake pin is pulled high. False otherwise.
 *
 ******************************************************************************/
bool
EtaCspPwrWakePinGet(void)
{
    return REG_RTC_PWR.BF.WAKE_PIN_STATE;
}

/***************************************************************************//**
 *
 * EtaCspPwrFlashPwrUpCompleteGet- return flash power up complete state
 *
 * @return True if the Flash Power Up cycle is complete.
 *
 ******************************************************************************/
bool
EtaCspPwrFlashPwrUpCompleteGet(void)
{
    return REG_RTC_PWR.BF.FLASH_PWR_UP_CMPLT;
}

/***************************************************************************//**
 *
 * EtaCspPwrFlashV25Set - Flash 2.5V on or off
 *
 * @param bOn - true turns it on. false turns it off.
 *
 ******************************************************************************/
void
EtaCspPwrFlashV25Set(bool bOn)
{
    if(bOn)
    {
        REG_RTC_PWR_SET.BF.FLASH_V25 = 1;
    }
    else
    {
        REG_RTC_PWR_CLEAR.BF.FLASH_V25 = 1;
    }
}


/***************************************************************************//**
 *
 * EtaCspPwrFlashV25Get - return state of flash 2.5V switch
 *
 * @return True if the Flash 2.5V is on.
 *
 ******************************************************************************/
bool
EtaCspPwrFlashV25Get(void)
{
    return REG_RTC_PWR.BF.FLASH_V25;
}

/***************************************************************************//**
 *
 * EtaCspPwrFlashPDMSet - Flash PDM on or off
 *
 * @param bOn - true turns it on. false turns it off.
 *
 ******************************************************************************/
void EtaCspPwrFlashPDMSet(bool bOn)
{
    if(bOn)
    {
        REG_RTC_PWR_SET.BF.FLASH_PDM = 1;
    }
    else
    {
        REG_RTC_PWR_CLEAR.BF.FLASH_PDM = 1;
    }
}

/***************************************************************************//**
 *
 * EtaCspPwrFlashPDMGet - return state of flash PDM switch
 *
 * @return True if the Flash PDM is on.
 *
 ******************************************************************************/
bool
EtaCspPwrFlashPDMGet(void)
{
    return REG_RTC_PWR.BF.FLASH_PDM;
}


/***************************************************************************//**
 *
 * EtaCspPwrFlashVREFSet - turn Flash VREF on or off.
 *
 * @param bOn - true turns it on. false turns it off.
 *
 ******************************************************************************/
void
EtaCspPwrFlashVREFSet(bool bOn)
{
    if(bOn)
    {
        REG_RTC_PWR_SET.BF.FLASH_VREF = 1;
    }
    else
    {
        REG_RTC_PWR_CLEAR.BF.FLASH_VREF = 1;
    }
}

/***************************************************************************//**
 *
 * EtaCspPwrFlashVREFGet - return state of Flash VREF
 *
 * @return True if the Flash VREF is on.
 *
 ******************************************************************************/
bool
EtaCspPwrFlashVREFGet(void)
{
    return REG_RTC_PWR.BF.FLASH_VREF;
}

/***************************************************************************//**
 *
 * EtaCspPwrDspPwrStateGet - return power state of DSP.
 *
 * @return True if the DSP Power is on.
 *
 ******************************************************************************/
bool
EtaCspPwrDspPwrStateGet(void)
{
    return REG_RTC_PWR.BF.DSP_PWR_STATE;
}

/***************************************************************************//**
 *
 * EtaCspPwrAdcPwrStateGet - return power state of the ADC.
 *
 * @return True if the ADC power is on.
 *
 ******************************************************************************/
bool
EtaCspPwrAdcPwrStateGet(void)
{
    return REG_RTC_PWR.BF.ADC_PWR_STATE;
}

/***************************************************************************//**
 *
 * EtaCspPwrGpioFrozenGet - return state of the GPIO Frozen Bit.
 *
 * @return True if the GPIO pins are Frozen after a power back up condition.
 *
 ******************************************************************************/
bool
EtaCspPwrGpioFrozenGet(void)
{
    return REG_RTC_PWR.BF.GPIO_FROZEN;
}

/***************************************************************************//**
 *
 * EtaCspPwrGpioFrozenClear - turn off the GPIO FROZEN.
 *
 * NOTE: Any write to the RTC_PWR register will clear this bit.  This function
 * will only clear the bit and not do any thing else. It uses the register clear
 * address.
 ******************************************************************************/
void
EtaCspPwrGpioFrozenClear(void)
{
    REG_RTC_PWR_CLEAR.BF.GPIO_FROZEN = 1;
}



