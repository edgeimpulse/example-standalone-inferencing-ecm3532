/*********************************************************************************
**  File Name: ioreg_tb.h
**
** This file defines the C macros for the verilog registers, bit fields,
** and enumeration values
**
**  Chip: ngc18 Device: tb
**  Short Description: The chip simulation Test Bench programmable Registers.
**  bus type  = APB	device size = 512 bytes.
**
**
*********************************************************************************
*********************************************************************************
*********************************************************************************
****      WARNING: This file is automatically generated from python          ****
****               DO NOT ATTEMPT TO MODIFY IT DIRECTLY                      ****
*********************************************************************************
*********************************************************************************
*********************************************************************************
**
**
**
**
*********************************************************************************
**  Python Source File Version Information
**  File Name:./src/ioreg_tb.src
**  File Modification Date:Mon Jan  6 20:04:03 2020
**  Generation Date:January 06, 2020
********************************************************************************/

#ifndef IO_TB_H
#define IO_TB_H
////////////////////////////////////////////////////////////////////////////////
//  Address constants for each register
////////////////////////////////////////////////////////////////////////////////

#define  IO_TB_PUTCHAR_ADDRESS  (0x400f0000)
#define  IO_TB_PROGRESS_ADDRESS  (0x400f0004)
#define  IO_TB_ERROR_ADDRESS  (0x400f0008)
#define  IO_TB_FINISH_ADDRESS  (0x400f0010)
#define  IO_TB_BOOT_MODEA_ADDRESS  (0x400f0018)
#define  IO_TB_BOOT_MODEB_ADDRESS  (0x400f001c)
#define  IO_TB_RUNTIME_OPTION_ADDRESS  (0x400f0020)
#define  IO_TB_RUNTIME_RANDOM_SEED_ADDRESS  (0x400f0024)
#define  IO_TB_NON_VOL_REG_ADDRESS  (0x400f0028)
#define  IO_TB_DBG_READONLY_ADDRESS  (0x400f0040)
#define  IO_TB_DEBUG2_ADDRESS  (0x400f0044)
#define  IO_TB_DEBUG3_ADDRESS  (0x400f0048)
#define  IO_TB_DEBUG4_ADDRESS  (0x400f004c)
#define  IO_TB_DUMP_TCF_ADDRESS  (0x400f0050)
#define  IO_TB_INC_NUMBER_PASSED_ADDRESS  (0x400f0054)
#define  IO_TB_INC_NUMBER_FAILED_ADDRESS  (0x400f0058)
#define  IO_TB_GPIO_PAD_INPUT_ADDRESS  (0x400f2000)
#define  IO_TB_GPIO_PAD_DATA_OUT_ADDRESS  (0x400f2004)
#define  IO_TB_GPIO_PAD_DATA_ENABLE_ADDRESS  (0x400f2008)
#define  IO_TB_GPIO_PAD_CLOCK_ENABLE_ADDRESS  (0x400f200c)
#define  IO_TB_GPIO_RESET_PIN_ADDRESS  (0x400f2010)
#define  IO_TB_GPIO_RESET_LENGTH_ADDRESS  (0x400f2014)
#define  IO_TB_GPIO_PULL_POLARITY_ADDRESS  (0x400f2018)
#define  IO_TB_GPIO_IS_HIGHZ_ADDRESS  (0x400f201c)
#define  IO_TB_GPIO_WAKE_PIN_ADDRESS  (0x400f2020)
#define  IO_TB_GPIO_PM_SET_ADDRESS  (0x400f2024)
#define  IO_TB_GPIO_SAFE_INPUT_ADDRESS  (0x400f2028)
#define  IO_TB_GPIO_IS_X_ADDRESS  (0x400f202c)
#define  IO_TB_ADC_OFFSET_ADDRESS  (0x400f3000)
#define  IO_TB_ADC_EXPECT_ADDRESS  (0x400f3004)
#define  IO_TB_ADC_RAW_ADDRESS  (0x400f3008)
#define  IO_TB_UART_XACTOR_CFG_ADDRESS  (0x400f5000)
#define  IO_TB_SPIFLASH_CTRL_ADDRESS  (0x400f6000)
#define  IO_TB_I2C_SEEPROM_CTRL_ADDRESS  (0x400f6004)
#define  IO_TB_DSP_UART_CTRL_ADDRESS  (0x400f7000)
#define  IO_TB_DSP_UART_STATUS_ADDRESS  (0x400f7004)
#define  IO_TB_DSP_UART_FIFO_RD_ADDRESS  (0x400f7008)
#define  IO_TB_DSP_UART_CLKCOUNT_ADDRESS  (0x400f700c)
#define  IO_TB_FPANEL_UART_CTRL_ADDRESS  (0x400f7010)
#define  IO_TB_FPANEL_UART_STATUS_ADDRESS  (0x400f7014)
#define  IO_TB_FPANEL_UART_FIFO_RD_ADDRESS  (0x400f7018)
#define  IO_TB_FPANEL_UART_CLKCOUNT_ADDRESS  (0x400f701c)
#define  IO_TB_PDM_XACTOR_ADDRESS  (0x400f7020)
#define  IO_TB_I2S_XACTOR_CTRL_ADDRESS  (0x400f7030)
#define  IO_TB_I2S_XACTOR_STATUS_ADDRESS  (0x400f7034)
#define  IO_TB_I2S_XACTOR_CLKCOUNT_ADDRESS  (0x400f7038)
#define  IO_TB_I2S_XACTOR_TX_L_PUSH_ADDRESS  (0x400f7040)
#define  IO_TB_I2S_XACTOR_TX_R_PUSH_ADDRESS  (0x400f7044)
#define  IO_TB_I2S_XACTOR_RX_L_POP_ADDRESS  (0x400f7048)
#define  IO_TB_I2S_XACTOR_RX_R_POP_ADDRESS  (0x400f704c)
#define  IO_TB_UART_SWITCH_CTRL_ADDRESS  (0x400f7050)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_ADDRESS  (0x400f7070)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_ADDRESS  (0x400f7074)
#define  IO_TB_SPI_MASTER_XACTOR_TX_PUSH_ADDRESS  (0x400f7078)
#define  IO_TB_SPI_MASTER_XACTOR_RX_POP_ADDRESS  (0x400f707c)
#define  IO_TB_SPI2C_MUX_SEL_ADDRESS  (0x400f7080)
#define  IO_TB_OTHER_MUX_SEL_ADDRESS  (0x400f7084)
#define  IO_TB_GPIO_DATA_OE_ADDRESS  (0x400f70c0)
#define  IO_TB_GPIO_DATA_OUT_ADDRESS  (0x400f70c4)
#define  IO_TB_GPIO_DATA_IN_ADDRESS  (0x400f70c8)
#define  IO_TB_OTHER_DATA_OE_ADDRESS  (0x400f70cc)
#define  IO_TB_OTHER_DATA_OUT_ADDRESS  (0x400f70d0)
#define  IO_TB_OTHER_DATA_IN_ADDRESS  (0x400f70d4)
#define  IO_TB_POWER_CTRL_ADDRESS  (0x400f70d8)
#define  IO_TB_BOOTMODE_CTRL_ADDRESS  (0x400f70dc)
#define  IO_TB_DSP_JTAG_DEBUG_ADDRESS  (0x400f70e0)
#define  IO_TB_DSP_JTAG_DEBUG_ADDRESS  (0x400f70e0)
#define  IO_TB_SYS_SPI2C_CTRL_ADDRESS  (0x400f70e4)
#define  IO_TB_SOCCTRL_PMIC_DIG_CSR_ADDRESS  (0x400f9000)
#define  IO_TB_SOCCTRL_PMIC_DIG_DBG_ADDRESS  (0x400f9004)
#define  IO_TB_SOCCTRL_PMIC_DIG_LOADED_ADDRESS  (0x400f9008)
#define  IO_TB_SOCCTRL_PMIC_M3_CSR_ADDRESS  (0x400f900c)
#define  IO_TB_SOCCTRL_PMIC_M3_DBG_ADDRESS  (0x400f9010)
#define  IO_TB_SOCCTRL_PMIC_M3_LOADED_ADDRESS  (0x400f9014)
#define  IO_TB_SOCCTRL_PMIC_ADC_CSR_ADDRESS  (0x400f9018)
#define  IO_TB_SOCCTRL_PMIC_ADC_LDO_CSR_ADDRESS  (0x400f9018)
#define  IO_TB_SOCCTRL_PMIC_ADC_DBG_ADDRESS  (0x400f901c)
#define  IO_TB_SOCCTRL_PMIC_ADC_LOADED_ADDRESS  (0x400f9020)
#define  IO_TB_SOCCTRL_PMIC_DSP_CSR_ADDRESS  (0x400f9024)
#define  IO_TB_SOCCTRL_PMIC_DSP_DBG_ADDRESS  (0x400f9028)
#define  IO_TB_SOCCTRL_PMIC_DSP_LOADED_ADDRESS  (0x400f902c)
#define  IO_TB_SOCCTRL_PMIC_READIES_ADDRESS  (0x400f902c)
#define  IO_TB_SOCCTRL_PMIC_AO_CSR_ADDRESS  (0x400f9034)
#define  IO_TB_SOCCTRL_PMIC_AO_DBG_ADDRESS  (0x400f9038)
#define  IO_TB_SOCCTRL_PMIC_AO_LOADED_ADDRESS  (0x400f903c)
#define  IO_TB_SOCCTRL_PMIC_MEM_CSR_ADDRESS  (0x400f9040)
#define  IO_TB_SOCCTRL_PMIC_MEM_DBG_ADDRESS  (0x400f9044)
#define  IO_TB_SOCCTRL_PMIC_MEM_LOADED_ADDRESS  (0x400f9048)
#define  IO_TB_DSPJTAG_CMD_ADDRESS  (0x400fa000)
#define  IO_TB_DSPJTAG_RSTN_ADDRESS  (0x400fa004)
#define  IO_TB_DSPJTAG_INSTR_ADDRESS  (0x400fa008)
#define  IO_TB_DSPJTAG_WRDATA_ADDRESS  (0x400fa00c)
#define  IO_TB_DSPJTAG_RDDATA_ADDRESS  (0x400fa010)
#define  IO_TB_TRISTATE_EN_N_ADDRESS  (0x400fa014)
#define  IO_TB_ANALYZER_CTRL_ADDRESS  (0x400fc000)
#define  IO_TB_ANALYZER_TOG_ADDRESS  (0x400fc004)
#define  IO_TB_ANALYZER_ERR_ADDRESS  (0x400fc008)
#define  IO_TB_TEMP_SENSE_TEMP_ADDRESS  (0x400fd000)
#define  IO_TB_TEMP_SENSE_FREQ_ADDRESS  (0x400fd004)


////////////////////////////////////////////////////////////////////////////////
//  Shift and Mask constants for each register
////////////////////////////////////////////////////////////////////////////////

#define  IO_TB_PUTCHAR_ASCII_SHIFT  (0)
#define  IO_TB_PUTCHAR_ASCII_MASK  (0xff)

#define  IO_TB_PROGRESS_VALUE_SHIFT  (0)
#define  IO_TB_PROGRESS_VALUE_MASK  (0xffffffff)

#define  IO_TB_ERROR_VALUE_SHIFT  (0)
#define  IO_TB_ERROR_VALUE_MASK  (0xffffffff)

#define  IO_TB_FINISH_RETURN_CODE_SHIFT  (0)
#define  IO_TB_FINISH_RETURN_CODE_MASK  (0xffffffff)

#define  IO_TB_BOOT_MODEA_VALUE_SHIFT  (0)
#define  IO_TB_BOOT_MODEA_VALUE_MASK  (0xffffffff)

#define  IO_TB_BOOT_MODEB_VALUE_SHIFT  (0)
#define  IO_TB_BOOT_MODEB_VALUE_MASK  (0xffffffff)

#define  IO_TB_RUNTIME_OPTION_VALUE_SHIFT  (0)
#define  IO_TB_RUNTIME_OPTION_VALUE_MASK  (0xffffffff)

#define  IO_TB_RUNTIME_RANDOM_SEED_VALUE_SHIFT  (0)
#define  IO_TB_RUNTIME_RANDOM_SEED_VALUE_MASK  (0xffffffff)

#define  IO_TB_NON_VOL_REG_VALUE_SHIFT  (0)
#define  IO_TB_NON_VOL_REG_VALUE_MASK  (0xffffffff)

#define  IO_TB_DBG_READONLY_VALUE_SHIFT  (0)
#define  IO_TB_DBG_READONLY_VALUE_MASK  (0xffffffff)

#define  IO_TB_DEBUG2_VALUE_SHIFT  (0)
#define  IO_TB_DEBUG2_VALUE_MASK  (0xffffffff)

#define  IO_TB_DEBUG3_VALUE_SHIFT  (0)
#define  IO_TB_DEBUG3_VALUE_MASK  (0xffffffff)

#define  IO_TB_DEBUG4_VALUE_SHIFT  (0)
#define  IO_TB_DEBUG4_VALUE_MASK  (0xffffffff)

#define  IO_TB_DUMP_TCF_VALUE_SHIFT  (0)
#define  IO_TB_DUMP_TCF_VALUE_MASK  (0xffffffff)

#define  IO_TB_INC_NUMBER_PASSED_VALUE_SHIFT  (0)
#define  IO_TB_INC_NUMBER_PASSED_VALUE_MASK  (0xffffffff)

#define  IO_TB_INC_NUMBER_FAILED_VALUE_SHIFT  (0)
#define  IO_TB_INC_NUMBER_FAILED_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_PAD_INPUT_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_PAD_INPUT_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_PAD_DATA_OUT_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_PAD_DATA_OUT_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_PAD_DATA_ENABLE_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_PAD_DATA_ENABLE_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_PAD_CLOCK_ENABLE_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_PAD_CLOCK_ENABLE_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_RESET_PIN_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_RESET_PIN_VALUE_MASK  (0x1)

#define  IO_TB_GPIO_RESET_LENGTH_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_RESET_LENGTH_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_PULL_POLARITY_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_PULL_POLARITY_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_IS_HIGHZ_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_IS_HIGHZ_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_WAKE_PIN_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_WAKE_PIN_VALUE_MASK  (0x1)

#define  IO_TB_GPIO_PM_SET_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_PM_SET_VALUE_MASK  (0x1)
#define  IO_TB_GPIO_PM_SET_FORCE_SHIFT  (0)
#define  IO_TB_GPIO_PM_SET_FORCE_MASK  (0x1)

#define  IO_TB_GPIO_SAFE_INPUT_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_SAFE_INPUT_VALUE_MASK  (0xffffffff)

#define  IO_TB_GPIO_IS_X_VALUE_SHIFT  (0)
#define  IO_TB_GPIO_IS_X_VALUE_MASK  (0xffffffff)

#define  IO_TB_ADC_OFFSET_VALUE_SHIFT  (0)
#define  IO_TB_ADC_OFFSET_VALUE_MASK  (0xffffffff)

#define  IO_TB_ADC_EXPECT_VALUE_SHIFT  (0)
#define  IO_TB_ADC_EXPECT_VALUE_MASK  (0xffffffff)

#define  IO_TB_ADC_RAW_VALUE_SHIFT  (0)
#define  IO_TB_ADC_RAW_VALUE_MASK  (0xffffffff)

#define  IO_TB_UART_XACTOR_CFG_USE_UART1ALT_SHIFT  (6)
#define  IO_TB_UART_XACTOR_CFG_USE_UART1ALT_MASK  (0x40)
#define  IO_TB_UART_XACTOR_CFG_ONE_STOP_SHIFT  (5)
#define  IO_TB_UART_XACTOR_CFG_ONE_STOP_MASK  (0x20)
#define  IO_TB_UART_XACTOR_CFG_CTS_RTS_POLARITY_SHIFT  (4)
#define  IO_TB_UART_XACTOR_CFG_CTS_RTS_POLARITY_MASK  (0x10)
#define  IO_TB_UART_XACTOR_CFG_BAUD_CODE_SHIFT  (2)
#define  IO_TB_UART_XACTOR_CFG_BAUD_CODE_MASK  (0xc)
#define  IO_TB_UART_XACTOR_CFG_CTS_DISABLE_SHIFT  (1)
#define  IO_TB_UART_XACTOR_CFG_CTS_DISABLE_MASK  (0x2)
#define  IO_TB_UART_XACTOR_CFG_BYP_EN_SHIFT  (0)
#define  IO_TB_UART_XACTOR_CFG_BYP_EN_MASK  (0x1)

#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL_SHIFT  (29)
#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL_MASK  (0xe0000000)
#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL__NOTHING  (0)
#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL__SPI0_to_SPI1  (1)
#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL__SPI0_to_SPI2  (2)
#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL__SPI0_to_SPI2_ALT  (3)
#define  IO_TB_SPIFLASH_CTRL_LOOPBACK_CTRL__SPI1_to_SPI0  (4)
#define  IO_TB_SPIFLASH_CTRL_SPI2_ALT_SHIFT  (28)
#define  IO_TB_SPIFLASH_CTRL_SPI2_ALT_MASK  (0x10000000)
#define  IO_TB_SPIFLASH_CTRL_INVERT_CS_SHIFT  (24)
#define  IO_TB_SPIFLASH_CTRL_INVERT_CS_MASK  (0xf000000)
#define  IO_TB_SPIFLASH_CTRL_SPI2_MOSI_MISO_LB_SHIFT  (23)
#define  IO_TB_SPIFLASH_CTRL_SPI2_MOSI_MISO_LB_MASK  (0x800000)
#define  IO_TB_SPIFLASH_CTRL_SPI2_MISO_SHIFT  (22)
#define  IO_TB_SPIFLASH_CTRL_SPI2_MISO_MASK  (0x400000)
#define  IO_TB_SPIFLASH_CTRL_SPI2_SCLK_SHIFT  (21)
#define  IO_TB_SPIFLASH_CTRL_SPI2_SCLK_MASK  (0x200000)
#define  IO_TB_SPIFLASH_CTRL_SPI2_MOSI_SHIFT  (20)
#define  IO_TB_SPIFLASH_CTRL_SPI2_MOSI_MASK  (0x100000)
#define  IO_TB_SPIFLASH_CTRL_SPI2_CS_SHIFT  (16)
#define  IO_TB_SPIFLASH_CTRL_SPI2_CS_MASK  (0xf0000)
#define  IO_TB_SPIFLASH_CTRL_SPI1_MOSI_MISO_LB_SHIFT  (15)
#define  IO_TB_SPIFLASH_CTRL_SPI1_MOSI_MISO_LB_MASK  (0x8000)
#define  IO_TB_SPIFLASH_CTRL_SPI1_MISO_SHIFT  (14)
#define  IO_TB_SPIFLASH_CTRL_SPI1_MISO_MASK  (0x4000)
#define  IO_TB_SPIFLASH_CTRL_SPI1_SCLK_SHIFT  (13)
#define  IO_TB_SPIFLASH_CTRL_SPI1_SCLK_MASK  (0x2000)
#define  IO_TB_SPIFLASH_CTRL_SPI1_MOSI_SHIFT  (12)
#define  IO_TB_SPIFLASH_CTRL_SPI1_MOSI_MASK  (0x1000)
#define  IO_TB_SPIFLASH_CTRL_SPI1_CS_SHIFT  (8)
#define  IO_TB_SPIFLASH_CTRL_SPI1_CS_MASK  (0x300)
#define  IO_TB_SPIFLASH_CTRL_SPI0_MOSI_MISO_LB_SHIFT  (7)
#define  IO_TB_SPIFLASH_CTRL_SPI0_MOSI_MISO_LB_MASK  (0x80)
#define  IO_TB_SPIFLASH_CTRL_SPI0_MISO_SHIFT  (6)
#define  IO_TB_SPIFLASH_CTRL_SPI0_MISO_MASK  (0x40)
#define  IO_TB_SPIFLASH_CTRL_SPI0_SCLK_SHIFT  (5)
#define  IO_TB_SPIFLASH_CTRL_SPI0_SCLK_MASK  (0x20)
#define  IO_TB_SPIFLASH_CTRL_SPI0_MOSI_SHIFT  (4)
#define  IO_TB_SPIFLASH_CTRL_SPI0_MOSI_MASK  (0x10)
#define  IO_TB_SPIFLASH_CTRL_SPI0_CS_SHIFT  (0)
#define  IO_TB_SPIFLASH_CTRL_SPI0_CS_MASK  (0xf)

#define  IO_TB_I2C_SEEPROM_CTRL_I2C2_RESET_SHIFT  (9)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C2_RESET_MASK  (0x200)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C2_CONNECT_SHIFT  (8)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C2_CONNECT_MASK  (0x100)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1ALT_RESET_SHIFT  (7)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1ALT_RESET_MASK  (0x80)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1ALT_CONNECT_SHIFT  (6)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1ALT_CONNECT_MASK  (0x40)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1_RESET_SHIFT  (5)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1_RESET_MASK  (0x20)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1_CONNECT_SHIFT  (4)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C1_CONNECT_MASK  (0x10)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0ALT_RESET_SHIFT  (3)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0ALT_RESET_MASK  (0x8)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0ALT_CONNECT_SHIFT  (2)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0ALT_CONNECT_MASK  (0x4)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0_RESET_SHIFT  (1)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0_RESET_MASK  (0x2)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0_CONNECT_SHIFT  (0)
#define  IO_TB_I2C_SEEPROM_CTRL_I2C0_CONNECT_MASK  (0x1)

#define  IO_TB_DSP_UART_CTRL_RESET_FIFO_SHIFT  (8)
#define  IO_TB_DSP_UART_CTRL_RESET_FIFO_MASK  (0x100)
#define  IO_TB_DSP_UART_CTRL_EN_GPIO20_SHIFT  (2)
#define  IO_TB_DSP_UART_CTRL_EN_GPIO20_MASK  (0x4)
#define  IO_TB_DSP_UART_CTRL_EN_GPIO7_SHIFT  (1)
#define  IO_TB_DSP_UART_CTRL_EN_GPIO7_MASK  (0x2)
#define  IO_TB_DSP_UART_CTRL_EN_XACTOR_SHIFT  (0)
#define  IO_TB_DSP_UART_CTRL_EN_XACTOR_MASK  (0x1)

#define  IO_TB_DSP_UART_STATUS_FIFO_ENTRIES_SHIFT  (16)
#define  IO_TB_DSP_UART_STATUS_FIFO_ENTRIES_MASK  (0xffff0000)
#define  IO_TB_DSP_UART_STATUS_RX_STATE_SHIFT  (8)
#define  IO_TB_DSP_UART_STATUS_RX_STATE_MASK  (0xff00)
#define  IO_TB_DSP_UART_STATUS_CURR_UART_SHIFT  (3)
#define  IO_TB_DSP_UART_STATUS_CURR_UART_MASK  (0x8)
#define  IO_TB_DSP_UART_STATUS_UFLOW_SHIFT  (2)
#define  IO_TB_DSP_UART_STATUS_UFLOW_MASK  (0x4)
#define  IO_TB_DSP_UART_STATUS_OFLOW_SHIFT  (1)
#define  IO_TB_DSP_UART_STATUS_OFLOW_MASK  (0x2)
#define  IO_TB_DSP_UART_STATUS_HAS_DATA_SHIFT  (0)
#define  IO_TB_DSP_UART_STATUS_HAS_DATA_MASK  (0x1)

#define  IO_TB_DSP_UART_FIFO_RD_RX_BYTE_SHIFT  (0)
#define  IO_TB_DSP_UART_FIFO_RD_RX_BYTE_MASK  (0xff)

#define  IO_TB_DSP_UART_CLKCOUNT_BCLK_COUNTER_SHIFT  (23)
#define  IO_TB_DSP_UART_CLKCOUNT_BCLK_COUNTER_MASK  (0xff800000)
#define  IO_TB_DSP_UART_CLKCOUNT_BCLK_SAMPLE_COUNT_SHIFT  (0)
#define  IO_TB_DSP_UART_CLKCOUNT_BCLK_SAMPLE_COUNT_MASK  (0x1ffff)

#define  IO_TB_FPANEL_UART_CTRL_RESET_FIFO_SHIFT  (8)
#define  IO_TB_FPANEL_UART_CTRL_RESET_FIFO_MASK  (0x100)
#define  IO_TB_FPANEL_UART_CTRL_EN_GPIO27_SHIFT  (3)
#define  IO_TB_FPANEL_UART_CTRL_EN_GPIO27_MASK  (0x8)
#define  IO_TB_FPANEL_UART_CTRL_EN_GPIO20_SHIFT  (2)
#define  IO_TB_FPANEL_UART_CTRL_EN_GPIO20_MASK  (0x4)
#define  IO_TB_FPANEL_UART_CTRL_EN_GPIO6_SHIFT  (1)
#define  IO_TB_FPANEL_UART_CTRL_EN_GPIO6_MASK  (0x2)
#define  IO_TB_FPANEL_UART_CTRL_EN_XACTOR_SHIFT  (0)
#define  IO_TB_FPANEL_UART_CTRL_EN_XACTOR_MASK  (0x1)

#define  IO_TB_FPANEL_UART_STATUS_FIFO_ENTRIES_SHIFT  (16)
#define  IO_TB_FPANEL_UART_STATUS_FIFO_ENTRIES_MASK  (0xffff0000)
#define  IO_TB_FPANEL_UART_STATUS_RX_STATE_SHIFT  (8)
#define  IO_TB_FPANEL_UART_STATUS_RX_STATE_MASK  (0xff00)
#define  IO_TB_FPANEL_UART_STATUS_CURR_UART_SHIFT  (3)
#define  IO_TB_FPANEL_UART_STATUS_CURR_UART_MASK  (0x8)
#define  IO_TB_FPANEL_UART_STATUS_UFLOW_SHIFT  (2)
#define  IO_TB_FPANEL_UART_STATUS_UFLOW_MASK  (0x4)
#define  IO_TB_FPANEL_UART_STATUS_OFLOW_SHIFT  (1)
#define  IO_TB_FPANEL_UART_STATUS_OFLOW_MASK  (0x2)
#define  IO_TB_FPANEL_UART_STATUS_HAS_DATA_SHIFT  (0)
#define  IO_TB_FPANEL_UART_STATUS_HAS_DATA_MASK  (0x1)

#define  IO_TB_FPANEL_UART_FIFO_RD_RX_BYTE_SHIFT  (0)
#define  IO_TB_FPANEL_UART_FIFO_RD_RX_BYTE_MASK  (0xff)

#define  IO_TB_FPANEL_UART_CLKCOUNT_BCLK_COUNTER_SHIFT  (23)
#define  IO_TB_FPANEL_UART_CLKCOUNT_BCLK_COUNTER_MASK  (0xff800000)
#define  IO_TB_FPANEL_UART_CLKCOUNT_BCLK_SAMPLE_COUNT_SHIFT  (0)
#define  IO_TB_FPANEL_UART_CLKCOUNT_BCLK_SAMPLE_COUNT_MASK  (0x1ffff)

#define  IO_TB_PDM_XACTOR_DATA_PATTERN_SHIFT  (20)
#define  IO_TB_PDM_XACTOR_DATA_PATTERN_MASK  (0xf00000)
#define  IO_TB_PDM_XACTOR_CKO_DLY_SHIFT  (16)
#define  IO_TB_PDM_XACTOR_CKO_DLY_MASK  (0xf0000)
#define  IO_TB_PDM_XACTOR_PDM0_ALT_EN_SHIFT  (2)
#define  IO_TB_PDM_XACTOR_PDM0_ALT_EN_MASK  (0x4)
#define  IO_TB_PDM_XACTOR_PDM1_EN_SHIFT  (1)
#define  IO_TB_PDM_XACTOR_PDM1_EN_MASK  (0x2)
#define  IO_TB_PDM_XACTOR_PDMO_EN_SHIFT  (0)
#define  IO_TB_PDM_XACTOR_PDMO_EN_MASK  (0x1)

#define  IO_TB_I2S_XACTOR_CTRL_I2S_DIN_INVERT_SHIFT  (9)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_DIN_INVERT_MASK  (0x200)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_LOOPBACK_SHIFT  (8)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_LOOPBACK_MASK  (0x100)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_DOUT_EN_SHIFT  (7)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_DOUT_EN_MASK  (0x80)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_DIN_EN_SHIFT  (6)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_DIN_EN_MASK  (0x40)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_LRCLK_EN_SHIFT  (5)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_LRCLK_EN_MASK  (0x20)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_BCLK_EN_SHIFT  (4)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_BCLK_EN_MASK  (0x10)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_64BIT_MODE_SHIFT  (3)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_64BIT_MODE_MASK  (0x8)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_FIFO_CLR_SHIFT  (2)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_FIFO_CLR_MASK  (0x4)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_CLK_COUNT_RST_SHIFT  (1)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_CLK_COUNT_RST_MASK  (0x2)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_XACTOR_EN_SHIFT  (0)
#define  IO_TB_I2S_XACTOR_CTRL_I2S_XACTOR_EN_MASK  (0x1)

#define  IO_TB_I2S_XACTOR_STATUS_RX_R_ACCESS_IN_PROG_SHIFT  (19)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_ACCESS_IN_PROG_MASK  (0x80000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_ACCESS_IN_PROG_SHIFT  (18)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_ACCESS_IN_PROG_MASK  (0x40000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_ACCESS_IN_PROG_SHIFT  (17)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_ACCESS_IN_PROG_MASK  (0x20000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_ACCESS_IN_PROG_SHIFT  (16)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_ACCESS_IN_PROG_MASK  (0x10000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_FIFO_UFLOW_SHIFT  (14)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_FIFO_UFLOW_MASK  (0x4000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_FIFO_OFLOW_SHIFT  (13)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_FIFO_OFLOW_MASK  (0x2000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_FIFO_HAS_DATA_SHIFT  (12)
#define  IO_TB_I2S_XACTOR_STATUS_RX_R_FIFO_HAS_DATA_MASK  (0x1000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_FIFO_UFLOW_SHIFT  (14)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_FIFO_UFLOW_MASK  (0x4000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_FIFO_OFLOW_SHIFT  (13)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_FIFO_OFLOW_MASK  (0x2000)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_FIFO_HAS_DATA_SHIFT  (12)
#define  IO_TB_I2S_XACTOR_STATUS_RX_L_FIFO_HAS_DATA_MASK  (0x1000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_FIFO_UFLOW_SHIFT  (14)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_FIFO_UFLOW_MASK  (0x4000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_FIFO_OFLOW_SHIFT  (13)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_FIFO_OFLOW_MASK  (0x2000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_FIFO_HAS_SPACE_SHIFT  (12)
#define  IO_TB_I2S_XACTOR_STATUS_TX_R_FIFO_HAS_SPACE_MASK  (0x1000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_FIFO_UFLOW_SHIFT  (14)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_FIFO_UFLOW_MASK  (0x4000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_FIFO_OFLOW_SHIFT  (13)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_FIFO_OFLOW_MASK  (0x2000)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_FIFO_HAS_SPACE_SHIFT  (12)
#define  IO_TB_I2S_XACTOR_STATUS_TX_L_FIFO_HAS_SPACE_MASK  (0x1000)

#define  IO_TB_I2S_XACTOR_CLKCOUNT_BCLK_COUNTER_SHIFT  (23)
#define  IO_TB_I2S_XACTOR_CLKCOUNT_BCLK_COUNTER_MASK  (0xff800000)
#define  IO_TB_I2S_XACTOR_CLKCOUNT_BCLK_SAMPLE_COUNT_SHIFT  (0)
#define  IO_TB_I2S_XACTOR_CLKCOUNT_BCLK_SAMPLE_COUNT_MASK  (0x3fffff)

#define  IO_TB_I2S_XACTOR_TX_L_PUSH_DATA_SHIFT  (0)
#define  IO_TB_I2S_XACTOR_TX_L_PUSH_DATA_MASK  (0xffffffff)

#define  IO_TB_I2S_XACTOR_TX_R_PUSH_DATA_SHIFT  (0)
#define  IO_TB_I2S_XACTOR_TX_R_PUSH_DATA_MASK  (0xffffffff)

#define  IO_TB_I2S_XACTOR_RX_L_POP_DATA_SHIFT  (0)
#define  IO_TB_I2S_XACTOR_RX_L_POP_DATA_MASK  (0xffffffff)

#define  IO_TB_I2S_XACTOR_RX_R_POP_DATA_SHIFT  (0)
#define  IO_TB_I2S_XACTOR_RX_R_POP_DATA_MASK  (0xffffffff)

#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP_SHIFT  (16)
#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP_MASK  (0xff0000)
#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP__NOTHING  (0)
#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP__UART0_FTDI_CHD  (1)
#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP__UART0_FTDI_CHD_UART1_FTDI_CHC  (2)
#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP__UART0_FTDI_CHD_UART1_ALT_FTDI_CHC  (3)
#define  IO_TB_UART_SWITCH_CTRL_IN2CHIP__LOOPBACK  (4)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D_SHIFT  (8)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D_MASK  (0xff00)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__NOTHING  (0)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__UART0  (1)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__UART1  (2)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__UART1_ALT  (3)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__GPIO20  (4)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__GPIO7  (5)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__GPIO6  (6)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__GPIO26  (7)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_D__UART0_TX  (7)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C_SHIFT  (0)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C_MASK  (0xff)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__NOTHING  (0)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__UART0  (1)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__UART1  (2)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__UART1_ALT  (3)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__GPIO20  (4)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__GPIO7  (5)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__GPIO6  (6)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__GPIO26  (7)
#define  IO_TB_UART_SWITCH_CTRL_OUT2FTDI_CH_C__UART0_TX  (7)

#define  IO_TB_SPI_MASTER_XACTOR_CTRL_CLK_PERIOD_SHIFT  (8)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_CLK_PERIOD_MASK  (0xff00)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI2ALT_SHIFT  (7)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI2ALT_MASK  (0x80)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI2_SHIFT  (6)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI2_MASK  (0x40)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI1_SHIFT  (5)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI1_MASK  (0x20)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI0_SHIFT  (4)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DRIVE_SPI0_MASK  (0x10)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DELAY_START_SHIFT  (2)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_DELAY_START_MASK  (0x4)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_MASTER_SOFT_RESET_SHIFT  (1)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_MASTER_SOFT_RESET_MASK  (0x2)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_MASTER_START_SHIFT  (0)
#define  IO_TB_SPI_MASTER_XACTOR_CTRL_MASTER_START_MASK  (0x1)

#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_ACCESS_IN_PROG_SHIFT  (17)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_ACCESS_IN_PROG_MASK  (0x20000)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_ACCESS_IN_PROG_SHIFT  (16)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_ACCESS_IN_PROG_MASK  (0x10000)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_FIFO_UFLOW_SHIFT  (6)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_FIFO_UFLOW_MASK  (0x40)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_FIFO_OFLOW_SHIFT  (5)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_FIFO_OFLOW_MASK  (0x20)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_FIFO_HAS_DATA_SHIFT  (4)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_RX_FIFO_HAS_DATA_MASK  (0x10)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_FIFO_UFLOW_SHIFT  (2)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_FIFO_UFLOW_MASK  (0x4)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_FIFO_OFLOW_SHIFT  (1)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_FIFO_OFLOW_MASK  (0x2)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_FIFO_HAS_SPACE_SHIFT  (0)
#define  IO_TB_SPI_MASTER_XACTOR_STATUS_TX_FIFO_HAS_SPACE_MASK  (0x1)

#define  IO_TB_SPI_MASTER_XACTOR_TX_PUSH_DATA_SHIFT  (0)
#define  IO_TB_SPI_MASTER_XACTOR_TX_PUSH_DATA_MASK  (0xffffffff)

#define  IO_TB_SPI_MASTER_XACTOR_RX_POP_DATA_SHIFT  (0)
#define  IO_TB_SPI_MASTER_XACTOR_RX_POP_DATA_MASK  (0xffffffff)

#define  IO_TB_SPI2C_MUX_SEL_SPI2C_9_SEL_SHIFT  (18)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_9_SEL_MASK  (0xc0000)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_8_SEL_SHIFT  (16)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_8_SEL_MASK  (0x30000)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_7_SEL_SHIFT  (14)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_7_SEL_MASK  (0xc000)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_6_SEL_SHIFT  (12)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_6_SEL_MASK  (0x3000)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_5_SEL_SHIFT  (10)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_5_SEL_MASK  (0xc00)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_4_SEL_SHIFT  (8)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_4_SEL_MASK  (0x300)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_3_SEL_SHIFT  (6)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_3_SEL_MASK  (0xc0)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_2_SEL_SHIFT  (4)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_2_SEL_MASK  (0x30)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_1_SEL_SHIFT  (2)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_1_SEL_MASK  (0xc)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_0_SEL_SHIFT  (0)
#define  IO_TB_SPI2C_MUX_SEL_SPI2C_0_SEL_MASK  (0x3)

#define  IO_TB_OTHER_MUX_SEL_TEST_CLK_SEL_SHIFT  (16)
#define  IO_TB_OTHER_MUX_SEL_TEST_CLK_SEL_MASK  (0x30000)
#define  IO_TB_OTHER_MUX_SEL_PDM1_SEL_SHIFT  (14)
#define  IO_TB_OTHER_MUX_SEL_PDM1_SEL_MASK  (0xc000)
#define  IO_TB_OTHER_MUX_SEL_PDM0_SEL_SHIFT  (12)
#define  IO_TB_OTHER_MUX_SEL_PDM0_SEL_MASK  (0x3000)
#define  IO_TB_OTHER_MUX_SEL_PDM0_GPIO_SEL_SHIFT  (10)
#define  IO_TB_OTHER_MUX_SEL_PDM0_GPIO_SEL_MASK  (0xc00)
#define  IO_TB_OTHER_MUX_SEL_DEBUG_SEL_SHIFT  (8)
#define  IO_TB_OTHER_MUX_SEL_DEBUG_SEL_MASK  (0x300)
#define  IO_TB_OTHER_MUX_SEL_CODEC_SEL_SHIFT  (6)
#define  IO_TB_OTHER_MUX_SEL_CODEC_SEL_MASK  (0xc0)
#define  IO_TB_OTHER_MUX_SEL_AUDIO_CLK_SEL_SHIFT  (4)
#define  IO_TB_OTHER_MUX_SEL_AUDIO_CLK_SEL_MASK  (0x30)
#define  IO_TB_OTHER_MUX_SEL_ANALOG_SEL_SHIFT  (2)
#define  IO_TB_OTHER_MUX_SEL_ANALOG_SEL_MASK  (0xc)
#define  IO_TB_OTHER_MUX_SEL_ADC_MUX_SEL_SHIFT  (0)
#define  IO_TB_OTHER_MUX_SEL_ADC_MUX_SEL_MASK  (0x3)

#define  IO_TB_GPIO_DATA_OE_DATA_SHIFT  (0)
#define  IO_TB_GPIO_DATA_OE_DATA_MASK  (0xffffffff)

#define  IO_TB_GPIO_DATA_OUT_DATA_SHIFT  (0)
#define  IO_TB_GPIO_DATA_OUT_DATA_MASK  (0xffffffff)

#define  IO_TB_GPIO_DATA_IN_DATA_SHIFT  (0)
#define  IO_TB_GPIO_DATA_IN_DATA_MASK  (0xffffffff)

#define  IO_TB_OTHER_DATA_OE_WAKE_SHIFT  (12)
#define  IO_TB_OTHER_DATA_OE_WAKE_MASK  (0x1000)
#define  IO_TB_OTHER_DATA_OE_UART0_TX_SHIFT  (11)
#define  IO_TB_OTHER_DATA_OE_UART0_TX_MASK  (0x800)
#define  IO_TB_OTHER_DATA_OE_UART0_RX_SHIFT  (10)
#define  IO_TB_OTHER_DATA_OE_UART0_RX_MASK  (0x400)
#define  IO_TB_OTHER_DATA_OE_UART0_RTS_SHIFT  (9)
#define  IO_TB_OTHER_DATA_OE_UART0_RTS_MASK  (0x200)
#define  IO_TB_OTHER_DATA_OE_UART0_CTS_SHIFT  (8)
#define  IO_TB_OTHER_DATA_OE_UART0_CTS_MASK  (0x100)
#define  IO_TB_OTHER_DATA_OE_SWDIO_SHIFT  (7)
#define  IO_TB_OTHER_DATA_OE_SWDIO_MASK  (0x80)
#define  IO_TB_OTHER_DATA_OE_SWDCLK_SHIFT  (6)
#define  IO_TB_OTHER_DATA_OE_SWDCLK_MASK  (0x40)
#define  IO_TB_OTHER_DATA_OE_SPI0_SCLK_SHIFT  (5)
#define  IO_TB_OTHER_DATA_OE_SPI0_SCLK_MASK  (0x20)
#define  IO_TB_OTHER_DATA_OE_SPI0_MOSI_SHIFT  (4)
#define  IO_TB_OTHER_DATA_OE_SPI0_MOSI_MASK  (0x10)
#define  IO_TB_OTHER_DATA_OE_SPI0_MISO_SHIFT  (3)
#define  IO_TB_OTHER_DATA_OE_SPI0_MISO_MASK  (0x8)
#define  IO_TB_OTHER_DATA_OE_RESET_N_SHIFT  (2)
#define  IO_TB_OTHER_DATA_OE_RESET_N_MASK  (0x4)
#define  IO_TB_OTHER_DATA_OE_POR_N_SHIFT  (1)
#define  IO_TB_OTHER_DATA_OE_POR_N_MASK  (0x2)
#define  IO_TB_OTHER_DATA_OE_GPIO_PM_MODE_SHIFT  (0)
#define  IO_TB_OTHER_DATA_OE_GPIO_PM_MODE_MASK  (0x1)

#define  IO_TB_OTHER_DATA_OUT_WAKE_SHIFT  (12)
#define  IO_TB_OTHER_DATA_OUT_WAKE_MASK  (0x1000)
#define  IO_TB_OTHER_DATA_OUT_UART0_TX_SHIFT  (11)
#define  IO_TB_OTHER_DATA_OUT_UART0_TX_MASK  (0x800)
#define  IO_TB_OTHER_DATA_OUT_UART0_RX_SHIFT  (10)
#define  IO_TB_OTHER_DATA_OUT_UART0_RX_MASK  (0x400)
#define  IO_TB_OTHER_DATA_OUT_UART0_RTS_SHIFT  (9)
#define  IO_TB_OTHER_DATA_OUT_UART0_RTS_MASK  (0x200)
#define  IO_TB_OTHER_DATA_OUT_UART0_CTS_SHIFT  (8)
#define  IO_TB_OTHER_DATA_OUT_UART0_CTS_MASK  (0x100)
#define  IO_TB_OTHER_DATA_OUT_SWDIO_SHIFT  (7)
#define  IO_TB_OTHER_DATA_OUT_SWDIO_MASK  (0x80)
#define  IO_TB_OTHER_DATA_OUT_SWDCLK_SHIFT  (6)
#define  IO_TB_OTHER_DATA_OUT_SWDCLK_MASK  (0x40)
#define  IO_TB_OTHER_DATA_OUT_SPI0_SCLK_SHIFT  (5)
#define  IO_TB_OTHER_DATA_OUT_SPI0_SCLK_MASK  (0x20)
#define  IO_TB_OTHER_DATA_OUT_SPI0_MOSI_SHIFT  (4)
#define  IO_TB_OTHER_DATA_OUT_SPI0_MOSI_MASK  (0x10)
#define  IO_TB_OTHER_DATA_OUT_SPI0_MISO_SHIFT  (3)
#define  IO_TB_OTHER_DATA_OUT_SPI0_MISO_MASK  (0x8)
#define  IO_TB_OTHER_DATA_OUT_RESET_N_SHIFT  (2)
#define  IO_TB_OTHER_DATA_OUT_RESET_N_MASK  (0x4)
#define  IO_TB_OTHER_DATA_OUT_POR_N_SHIFT  (1)
#define  IO_TB_OTHER_DATA_OUT_POR_N_MASK  (0x2)
#define  IO_TB_OTHER_DATA_OUT_GPIO_PM_MODE_SHIFT  (0)
#define  IO_TB_OTHER_DATA_OUT_GPIO_PM_MODE_MASK  (0x1)

#define  IO_TB_OTHER_DATA_IN_WAKE_SHIFT  (12)
#define  IO_TB_OTHER_DATA_IN_WAKE_MASK  (0x1000)
#define  IO_TB_OTHER_DATA_IN_UART0_TX_SHIFT  (11)
#define  IO_TB_OTHER_DATA_IN_UART0_TX_MASK  (0x800)
#define  IO_TB_OTHER_DATA_IN_UART0_RX_SHIFT  (10)
#define  IO_TB_OTHER_DATA_IN_UART0_RX_MASK  (0x400)
#define  IO_TB_OTHER_DATA_IN_UART0_RTS_SHIFT  (9)
#define  IO_TB_OTHER_DATA_IN_UART0_RTS_MASK  (0x200)
#define  IO_TB_OTHER_DATA_IN_UART0_CTS_SHIFT  (8)
#define  IO_TB_OTHER_DATA_IN_UART0_CTS_MASK  (0x100)
#define  IO_TB_OTHER_DATA_IN_SWDIO_SHIFT  (7)
#define  IO_TB_OTHER_DATA_IN_SWDIO_MASK  (0x80)
#define  IO_TB_OTHER_DATA_IN_SWDCLK_SHIFT  (6)
#define  IO_TB_OTHER_DATA_IN_SWDCLK_MASK  (0x40)
#define  IO_TB_OTHER_DATA_IN_SPI0_SCLK_SHIFT  (5)
#define  IO_TB_OTHER_DATA_IN_SPI0_SCLK_MASK  (0x20)
#define  IO_TB_OTHER_DATA_IN_SPI0_MOSI_SHIFT  (4)
#define  IO_TB_OTHER_DATA_IN_SPI0_MOSI_MASK  (0x10)
#define  IO_TB_OTHER_DATA_IN_SPI0_MISO_SHIFT  (3)
#define  IO_TB_OTHER_DATA_IN_SPI0_MISO_MASK  (0x8)
#define  IO_TB_OTHER_DATA_IN_RESET_N_SHIFT  (2)
#define  IO_TB_OTHER_DATA_IN_RESET_N_MASK  (0x4)
#define  IO_TB_OTHER_DATA_IN_POR_N_SHIFT  (1)
#define  IO_TB_OTHER_DATA_IN_POR_N_MASK  (0x2)
#define  IO_TB_OTHER_DATA_IN_GPIO_PM_MODE_SHIFT  (0)
#define  IO_TB_OTHER_DATA_IN_GPIO_PM_MODE_MASK  (0x1)

#define  IO_TB_POWER_CTRL_UNLOCK_SHIFT  (16)
#define  IO_TB_POWER_CTRL_UNLOCK_MASK  (0xffff0000)
#define  IO_TB_POWER_CTRL_VDD_IO_REG_EN_N_SHIFT  (0)
#define  IO_TB_POWER_CTRL_VDD_IO_REG_EN_N_MASK  (0x1)

#define  IO_TB_BOOTMODE_CTRL_DISABLE_SHIFT  (4)
#define  IO_TB_BOOTMODE_CTRL_DISABLE_MASK  (0x10)
#define  IO_TB_BOOTMODE_CTRL_BOOTMODE_SHIFT  (0)
#define  IO_TB_BOOTMODE_CTRL_BOOTMODE_MASK  (0xf)

#define  IO_TB_DSP_JTAG_DEBUG_LOOPBACK_SHIFT  (17)
#define  IO_TB_DSP_JTAG_DEBUG_LOOPBACK_MASK  (0x20000)
#define  IO_TB_DSP_JTAG_DEBUG_OVERRIDE_SHIFT  (16)
#define  IO_TB_DSP_JTAG_DEBUG_OVERRIDE_MASK  (0x10000)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_IN_SHIFT  (8)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_IN_MASK  (0x100)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_IN_SHIFT  (7)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_IN_MASK  (0x80)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_IN_SHIFT  (6)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_IN_MASK  (0x40)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_IN_SHIFT  (5)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_IN_MASK  (0x20)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDO_IN_SHIFT  (4)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDO_IN_MASK  (0x10)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_OUT_SHIFT  (3)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_OUT_MASK  (0x8)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_OUT_SHIFT  (2)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_OUT_MASK  (0x4)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_OUT_SHIFT  (1)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_OUT_MASK  (0x2)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_OUT_SHIFT  (0)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_OUT_MASK  (0x1)

#define  IO_TB_DSP_JTAG_DEBUG_LOOPBACK_SHIFT  (17)
#define  IO_TB_DSP_JTAG_DEBUG_LOOPBACK_MASK  (0x20000)
#define  IO_TB_DSP_JTAG_DEBUG_OVERRIDE_SHIFT  (16)
#define  IO_TB_DSP_JTAG_DEBUG_OVERRIDE_MASK  (0x10000)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_IN_SHIFT  (8)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_IN_MASK  (0x100)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_IN_SHIFT  (7)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_IN_MASK  (0x80)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_IN_SHIFT  (6)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_IN_MASK  (0x40)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_IN_SHIFT  (5)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_IN_MASK  (0x20)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDO_IN_SHIFT  (4)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDO_IN_MASK  (0x10)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_OUT_SHIFT  (3)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TRST_N_OUT_MASK  (0x8)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_OUT_SHIFT  (2)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TDI_OUT_MASK  (0x4)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_OUT_SHIFT  (1)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TMS_OUT_MASK  (0x2)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_OUT_SHIFT  (0)
#define  IO_TB_DSP_JTAG_DEBUG_DSP_TCLK_OUT_MASK  (0x1)

#define  IO_TB_SYS_SPI2C_CTRL_DSP_TDI_OUT_SHIFT  (8)
#define  IO_TB_SYS_SPI2C_CTRL_DSP_TDI_OUT_MASK  (0x100)
#define  IO_TB_SYS_SPI2C_CTRL_SYS_SPI_ADC_RST_N_SHIFT  (2)
#define  IO_TB_SYS_SPI2C_CTRL_SYS_SPI_ADC_RST_N_MASK  (0x4)
#define  IO_TB_SYS_SPI2C_CTRL_SYS_SPI_SYS_DISP_RST_N_SHIFT  (1)
#define  IO_TB_SYS_SPI2C_CTRL_SYS_SPI_SYS_DISP_RST_N_MASK  (0x2)
#define  IO_TB_SYS_SPI2C_CTRL_ENABLE_SYS_SIDEBAND_CTRL_SHIFT  (0)
#define  IO_TB_SYS_SPI2C_CTRL_ENABLE_SYS_SIDEBAND_CTRL_MASK  (0x1)

#define  IO_TB_SOCCTRL_PMIC_DIG_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_DIG_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_DIG_DBG_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_DIG_DBG_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_DIG_LOADED_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_DIG_LOADED_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_M3_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_M3_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_M3_DBG_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_M3_DBG_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_M3_LOADED_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_M3_LOADED_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_ADC_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_ADC_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_ADC_LDO_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_ADC_LDO_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_ADC_DBG_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_ADC_DBG_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_ADC_LOADED_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_ADC_LOADED_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_DSP_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_DSP_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_DSP_DBG_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_DSP_DBG_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_DSP_LOADED_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_DSP_LOADED_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_READIES_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_READIES_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_AO_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_AO_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_AO_DBG_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_AO_DBG_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_AO_LOADED_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_AO_LOADED_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_MEM_CSR_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_MEM_CSR_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_MEM_DBG_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_MEM_DBG_VALUE_MASK  (0xffffffff)

#define  IO_TB_SOCCTRL_PMIC_MEM_LOADED_VALUE_SHIFT  (0)
#define  IO_TB_SOCCTRL_PMIC_MEM_LOADED_VALUE_MASK  (0xffffffff)

#define  IO_TB_DSPJTAG_CMD_VALUE_SHIFT  (0)
#define  IO_TB_DSPJTAG_CMD_VALUE_MASK  (0xffffffff)

#define  IO_TB_DSPJTAG_RSTN_VALUE_SHIFT  (0)
#define  IO_TB_DSPJTAG_RSTN_VALUE_MASK  (0xffffffff)

#define  IO_TB_DSPJTAG_INSTR_VALUE_SHIFT  (0)
#define  IO_TB_DSPJTAG_INSTR_VALUE_MASK  (0xffffffff)

#define  IO_TB_DSPJTAG_WRDATA_VALUE_SHIFT  (0)
#define  IO_TB_DSPJTAG_WRDATA_VALUE_MASK  (0xffffffff)

#define  IO_TB_DSPJTAG_RDDATA_VALUE_SHIFT  (0)
#define  IO_TB_DSPJTAG_RDDATA_VALUE_MASK  (0xffffffff)

#define  IO_TB_TRISTATE_EN_N_VALUE_SHIFT  (0)
#define  IO_TB_TRISTATE_EN_N_VALUE_MASK  (0xffffffff)

#define  IO_TB_ANALYZER_CTRL_REPORT_TOGGLE_SHIFT  (3)
#define  IO_TB_ANALYZER_CTRL_REPORT_TOGGLE_MASK  (0x8)
#define  IO_TB_ANALYZER_CTRL_CLEAR_COUNTERS_SHIFT  (2)
#define  IO_TB_ANALYZER_CTRL_CLEAR_COUNTERS_MASK  (0x4)
#define  IO_TB_ANALYZER_CTRL_ENABLE_B_CHECKS_SHIFT  (1)
#define  IO_TB_ANALYZER_CTRL_ENABLE_B_CHECKS_MASK  (0x2)
#define  IO_TB_ANALYZER_CTRL_ENABLE_A_CHECKS_SHIFT  (0)
#define  IO_TB_ANALYZER_CTRL_ENABLE_A_CHECKS_MASK  (0x1)

#define  IO_TB_ANALYZER_TOG_TOGGLE_SHIFT  (0)
#define  IO_TB_ANALYZER_TOG_TOGGLE_MASK  (0xffffffff)

#define  IO_TB_ANALYZER_ERR_ERROR_SHIFT  (0)
#define  IO_TB_ANALYZER_ERR_ERROR_MASK  (0xffffffff)

#define  IO_TB_TEMP_SENSE_TEMP_VALUE_SHIFT  (0)
#define  IO_TB_TEMP_SENSE_TEMP_VALUE_MASK  (0xffffffff)

#define  IO_TB_TEMP_SENSE_FREQ_VALUE_SHIFT  (0)
#define  IO_TB_TEMP_SENSE_FREQ_VALUE_MASK  (0xffffffff)


#endif // IO_TB_H
