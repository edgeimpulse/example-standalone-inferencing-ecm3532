# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  "C"
  "CXX"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/startup_ecm3532.s" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/startup_ecm3532.s.o"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "ARM_MATH_LOOPUNROL"
  "ECM3532"
  "EIDSP_QUANTIZE_FILTERBANK=0"
  "EIDSP_USE_CMSIS_DSP=1"
  "EI_SENSOR_AQ_STREAM=FILE"
  "FLASH"
  "PROJ_NAME=\"edge_impulse_ingestion\""
  "USE_BLE"
  "USE_PDM_MIC"
  "USE_SPIFLASH"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "../../../Thirdparty/edge_impulse"
  "../../../Thirdparty/edge_impulse/ingestion-sdk-platform/eta-compute"
  "../../../Thirdparty/edge_impulse/repl"
  "../../../Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/DSP/Include"
  "../../../Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/Core/Include"
  "../../../Platform/ECM3532/M3/hw/hal/common/include"
  "../../../Platform/ECM3532/Common/framework/inc"
  "../../../eta_ai_bsp/inc"
  "../src"
  "../"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/include/ecm3532"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/board/ecm3532/ai_vision/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/include"
  "../include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/hal/common/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/hal/ecm3532/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/common/csp/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/reg/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/csp/../../../common/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/csp/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/drivers/spi_flash/common"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/drivers/spi_flash/maxim"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/classifier"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/model-parameters"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/tflite-model"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/dsp"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/tensorflow/lite/micro"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/flatbuffers/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/gemmlowp"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/ruy"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/DSP/Include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/inc"
  )
set(CMAKE_DEPENDS_CHECK_C
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/board/ecm3532/ai_vision/src/board_config.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/board/ecm3532/ai_vision/src/board_config.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/ecm3532_pinconfig.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/ecm3532_pinconfig.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/os_systick.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/os_systick.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/system_ecm3532.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/system/ecm3532/src/system_ecm3532.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/src/Sample-CLI-commands.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/src/Sample-CLI-commands.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/src/UARTCommandConsole.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/src/UARTCommandConsole.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/src/printf-stdarg.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/src/printf-stdarg.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/helper_func/src/freestanding_functions.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/helper_func/src/freestanding_functions.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp_button.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp_button.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp_led.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp_led.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp_power.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_bsp_power.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_devices_icm20602.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/src/eta_devices_icm20602.c.o"
  )
set(CMAKE_C_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_C
  "ARM_MATH_LOOPUNROL"
  "ECM3532"
  "EIDSP_QUANTIZE_FILTERBANK=0"
  "EIDSP_USE_CMSIS_DSP=1"
  "EI_SENSOR_AQ_STREAM=FILE"
  "FLASH"
  "PROJ_NAME=\"edge_impulse_ingestion\""
  "USE_BLE"
  "USE_PDM_MIC"
  "USE_SPIFLASH"
  )

# The include file search paths:
set(CMAKE_C_TARGET_INCLUDE_PATH
  "../../../Thirdparty/edge_impulse"
  "../../../Thirdparty/edge_impulse/ingestion-sdk-platform/eta-compute"
  "../../../Thirdparty/edge_impulse/repl"
  "../../../Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/DSP/Include"
  "../../../Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/Core/Include"
  "../../../Platform/ECM3532/M3/hw/hal/common/include"
  "../../../Platform/ECM3532/Common/framework/inc"
  "../../../eta_ai_bsp/inc"
  "../src"
  "../"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/include/ecm3532"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/board/ecm3532/ai_vision/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/include"
  "../include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/hal/common/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/hal/ecm3532/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/common/csp/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/reg/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/csp/../../../common/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/csp/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/drivers/spi_flash/common"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/drivers/spi_flash/maxim"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/classifier"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/model-parameters"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/tflite-model"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/dsp"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/tensorflow/lite/micro"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/flatbuffers/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/gemmlowp"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/ruy"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/DSP/Include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/inc"
  )
set(CMAKE_DEPENDS_CHECK_CXX
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting/ecm3532/debug_log.cpp" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting/ecm3532/debug_log.cpp.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting/ecm3532/ei_classifier_porting.cpp" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting/ecm3532/ei_classifier_porting.cpp.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/src/main.cpp" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edge-impulse-standalone.elf.dir/src/main.cpp.o"
  )
set(CMAKE_CXX_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_CXX
  "ARM_MATH_LOOPUNROL"
  "ECM3532"
  "EIDSP_QUANTIZE_FILTERBANK=0"
  "EIDSP_USE_CMSIS_DSP=1"
  "EI_SENSOR_AQ_STREAM=FILE"
  "FLASH"
  "PROJ_NAME=\"edge_impulse_ingestion\""
  "USE_BLE"
  "USE_PDM_MIC"
  "USE_SPIFLASH"
  )

# The include file search paths:
set(CMAKE_CXX_TARGET_INCLUDE_PATH
  "../../../Thirdparty/edge_impulse"
  "../../../Thirdparty/edge_impulse/ingestion-sdk-platform/eta-compute"
  "../../../Thirdparty/edge_impulse/repl"
  "../../../Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/DSP/Include"
  "../../../Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/Core/Include"
  "../../../Platform/ECM3532/M3/hw/hal/common/include"
  "../../../Platform/ECM3532/Common/framework/inc"
  "../../../eta_ai_bsp/inc"
  "../src"
  "../"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/include/ecm3532"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/board/ecm3532/ai_vision/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/util/console/include"
  "../include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/hal/common/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/hal/ecm3532/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/common/csp/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/reg/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/csp/../../../common/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/csp/ecm3532/m3/csp/inc"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/drivers/spi_flash/common"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/hw/drivers/spi_flash/maxim"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/porting"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/classifier"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/model-parameters"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/tflite-model"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/dsp"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/tensorflow/lite/micro"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/flatbuffers/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/gemmlowp"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/third_party/ruy"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/edge_impulse/edge-impulse-sdk/CMSIS/DSP/Include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/eta_ai_bsp/inc"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/DependInfo.cmake"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/hal.dir/DependInfo.cmake"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/csp.dir/DependInfo.cmake"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/iodev.dir/DependInfo.cmake"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/edgeimpulse.dir/DependInfo.cmake"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/eta_ai_bsp.dir/DependInfo.cmake"
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
