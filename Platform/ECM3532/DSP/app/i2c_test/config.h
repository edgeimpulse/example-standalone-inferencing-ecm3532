/* Generated by Kconfiglib (https://github.com/ulfalizer/Kconfiglib) */
#define CONFIG_ECM3532 1
#define CONFIG_SOC "ecm3532"
#define CONFIG_M3_RAM_START 0x10000000
#define CONFIG_M3_RAM_SIZE 0x40000
#define CONFIG_M3_FLASH_START 0x01000000
#define CONFIG_M3_FLASH_SIZE 0x80000
#define CONFIG_EVB_BOARD 1
#define CONFIG_APP_LED 1
#define CONFIG_APP_LED_GPIO 20
#define CONFIG_ECM3532_TARGET_BOARD "evb"
#define CONFIG_PIN3_FUNC_UART1RX 1
#define CONFIG_PIN3_MUX 3
#define CONFIG_PIN7_FUNC_UART1TX 1
#define CONFIG_PIN7_MUX 3
#define CONFIG_PIN8_FUNC_I2C2SDA 1
#define CONFIG_PIN8_MUX 3
#define CONFIG_PIN9_FUNC_I2C2SCK 1
#define CONFIG_PIN9_MUX 3
#define CONFIG_PIN20_FUNC_DSP_UART_TX 1
#define CONFIG_PIN20_MUX 2
#define CONFIG_PIN27_FUNC_GPIO27 1
#define CONFIG_PIN27_MUX 0
#define CONFIG_PIN28_FUNC_GPIO28 1
#define CONFIG_PIN28_MUX 0
#define CONFIG_PIN29_FUNC_GPIO29 1
#define CONFIG_PIN29_MUX 0
#define CONFIG_PIN30_FUNC_GPIO30 1
#define CONFIG_PIN30_MUX 0
#define CONFIG_PIN31_FUNC_GPIO31 1
#define CONFIG_PIN31_MUX 0
#define CONFIG_PIN_SPI0CLK_FUNC_SPI0CLK 1
#define CONFIG_PIN_SPI0CLK 0
#define CONFIG_PIN_SPI0MOSI_FUNC_MOSI 1
#define CONFIG_PIN_SPI0MOSI 0
#define CONFIG_PIN_SPI0MISO_FUNC_MISO 1
#define CONFIG_PIN_SPI0MISO 0
#define CONFIG_HAL_COMMON_UART 1
#define CONFIG_UART_ASYNC_RECV_MAX_CNT 2
#define CONFIG_UART_0 1
#define CONFIG_UART0_BRATE_115200 1
#define CONFIG_UART0_DEFAULT_BAUD_RATE 115200
#define CONFIG_UART0_DEFAULT_PARITY 2
#define CONFIG_UART0_DEFAULT_FLOW_CTRL 0
#define CONFIG_UART0_DEFAULT_STOP_BITS 2
#define CONFIG_UART_1 1
#define CONFIG_UART1_BRATE_115200 1
#define CONFIG_UART1_DEFAULT_BAUD_RATE 115200
#define CONFIG_UART1_DEFAULT_PARITY 2
#define CONFIG_UART1_DEFAULT_FLOW_CTRL 0
#define CONFIG_UART1_DEFAULT_STOP_BITS 2
#define CONFIG_UART_CNT 2
#define CONFIG_DEBUG_UART 0
#define CONFIG_HAL_COMMON_GPIO 1
#define CONFIG_GPIO_PIN_CNT 31
#define CONFIG_GPIO_MAX_IRQ 8
#define CONFIG_HAL_COMMON_TIMER 1
#define CONFIG_TMR_CH_0 1
#define CONFIG_HAL_COMMON_RTC 1
#define CONFIG_HAL_COMMON_I2C 1
#define CONFIG_I2C_1 1
#define CONFIG_I2C1_FREQ_400_KHZ 1
#define CONFIG_I2C_1_FREQ 400
#define CONFIG_HAL_COMMON_SPI 1
#define CONFIG_SPI_0_MASTER 1
#define CONFIG_SPI_0_BRATE_1000_KHZ 1
#define CONFIG_SPI_0_BRATE_IN_KHZ 1000
#define CONFIG_M3_INIT_FREQ 60
#define CONFIG_RPC 1
#define CONFIG_DSP_UART 1
#define CONFIG_DSP_I2C 1
#define CONFIG_DSP_FW "i2c_test"
#define CONFIG_SENSOR_MANAGER 1
#define CONFIG_SENSOR_DEV_COUNT 5
#define CONFIG_LSM6DSL_DSP 1
#define CONFIG_LSM6DSL_DSP_NAME "lsm6dsl_dsp"
#define CONFIG_APP_NAME "hello_world"
#define CONFIG_SW_VERSION "0.1"
#define CONFIG_SW_VERSION_EXTRA "48-g5bcac481"
#define CONFIG_RAM_SHM_ONLY 1
#define CONFIG_BIN_IN_RODATA 1
#define CONFIG_BIN_FILE_SECTION ".rodata"
#define CONFIG_SHM_LENGTH 0x4000
#define CONFIG_LINKER_FILE "ram_shm"
#define CONFIG_CLI 1
#define CONFIG_SYSTICK_ON_REF_CLK 1
#define CONFIG_TICK_RATE_HZ 500
#define CONFIG_SYSTICK_REF_CLOCK 1024
#define CONFIG_HEAP_SIZE 30000
#define CONFIG_ENABLE_PACKAGING 1
#define CONFIG_CSP_SRC_PACKAGE 1
#define CONFIG_PM_SRC_PACKAGE 1
#define CONFIG_RPC_SRC_PACKAGE 1
#define CONFIG_EXECUTOR_HEADER_PACKAGE 1
#define CONFIG_EXECUTOR_SRC_PACKAGE 1
#define CONFIG_SM_SRC_PACKAGE 1
#define CONFIG_HAL_SRC_PACKAGE 1
#define CONFIG_DSP_SRC_PACKAGE 1
