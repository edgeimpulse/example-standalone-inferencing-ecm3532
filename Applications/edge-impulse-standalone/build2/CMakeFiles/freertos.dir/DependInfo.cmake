# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "C"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_C
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI/FreeRTOS_CLI.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI/FreeRTOS_CLI.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/croutine.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/croutine.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/list.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/list.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/MemMang/heap_4.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/queue.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/queue.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/tasks.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/tasks.c.o"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/timers.c" "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/freertos.dir/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/timers.c.o"
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
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/include"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3"
  "/home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Thirdparty/FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI"
  )

# Targets to which this target links.
set(CMAKE_TARGET_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
