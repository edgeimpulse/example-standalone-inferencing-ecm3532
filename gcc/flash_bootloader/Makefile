################################################################################
#
# @file Makefile
#
# @brief This file contains the commands to build the edge_impulse example.
#
# Copyright (C) 2020 Eta Compute, Inc
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# This is part of revision 1.0.0a3 of the Tensai Software Development Kit.
#
################################################################################

TOP = ../..

PROJECT_NAME = edge_impulse_inferencing_bootloader

CPU = cortex-m3

LINKER_SCRIPT =	../ecm3532_bootloader.ld
STARTUP_FILE = ../startup_gcc.c

COMPILER = arm-none-eabi

CC = $(COMPILER)-gcc
CXX = $(COMPILER)-g++
LD = $(COMPILER)-ld
AR = $(COMPILER)-ar
CP = $(COMPILER)-objcopy
OD = $(COMPILER)-objdump

DEFINES = -DECM3532 -DFLASH -DPRINTF_SUPPORT_FLOAT -DPROJ_NAME=\"edge_impulse_inferencing_bootloader\"

INCLUDES = -I../../inc
INCLUDES+= -I$(TOP)/soc/ecm3532/m3/reg/inc
INCLUDES+= -I$(TOP)/soc/ecm3532/m3/csp/inc
INCLUDES+= -I$(TOP)/soc/ecm3532/common/csp/inc
INCLUDES+= -I$(TOP)/soc/common/inc
INCLUDES+= -I$(TOP)/soc/ecm3532/boards/eta_ai_sensor/eta_bsp/inc
INCLUDES+= -I$(TOP)/devices/inc
INCLUDES+= -I$(TOP)/utils/inc
INCLUDES+= -I$(TOP)/3rd_party/tiny_printf
INCLUDES+= -I$(TOP)/edge-impulse-sdk
INCLUDES+= -I$(TOP)/edge-impulse-sdk/anomaly
INCLUDES+= -I$(TOP)/edge-impulse-sdk/classifier
INCLUDES+= -I$(TOP)/edge-impulse-sdk/CMSIS/Core/Include
INCLUDES+= -I$(TOP)/edge-impulse-sdk/CMSIS/DSP
INCLUDES+= -I$(TOP)/edge-impulse-sdk/CMSIS/DSP/Include
INCLUDES+= -I$(TOP)/edge-impulse-sdk/CMSIS/DSP/PrivateInclude
INCLUDES+= -I$(TOP)/edge-impulse-sdk/CMSIS/NN/Include
INCLUDES+= -I$(TOP)/edge-impulse-sdk/dsp
INCLUDES+= -I$(TOP)/edge-impulse-sdk/dsp/spectral
INCLUDES+= -I$(TOP)/edge-impulse-sdk/dsp/speechpy
INCLUDES+= -I$(TOP)/edge-impulse-sdk/dsp/kissfft
INCLUDES+= -I$(TOP)/edge-impulse-sdk/porting
INCLUDES+= -I$(TOP)/edge-impulse-sdk/third_party/flatbuffers/include
INCLUDES+= -I$(TOP)/edge-impulse-sdk/third_party/gemmlowp
INCLUDES+= -I$(TOP)/edge-impulse-sdk/third_party/ruy
INCLUDES+= -I$(TOP)/edge-impulse-sdk/third_party/ruy/ruy
INCLUDES+= -I$(TOP)/edge-impulse-sdk/third_party/ruy/ruy/profiler
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/c
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/kernels
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/kernels/internal
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/core/api
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/micro
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/micro/memory_planner
INCLUDES+= -I$(TOP)/edge-impulse-sdk/tensorflow/lite/micro/kernels
INCLUDES+= -I$(TOP)/tflite-model
INCLUDES+= -I$(TOP)/model-parameters
INCLUDES+= -I$(TOP)

VPATH = $(TOP)/src
VPATH+= $(TOP)/soc/ecm3532/boards/eta_ai_sensor/eta_bsp/src
VPATH+= $(TOP)/utils/src
VPATH+= $(TOP)/3rd_party/tiny_printf
VPATH+= $(TOP)/3rd_party/bosch_sensortec/BMP3-Sensor-API
VPATH+= $(TOP)/edge-impulse-sdk
VPATH+= $(TOP)/edge-impulse-sdk/anomaly
VPATH+= $(TOP)/edge-impulse-sdk/classifier
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/Core
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/BasicMathFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/BayesFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/CommonTables
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/ComplexMathFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/ControllerFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/DistanceFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/FastMathFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/FilteringFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/MatrixFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/StatisticsFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/SupportFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/SVMFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/DSP/Source/TransformFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/ActivationFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/BasicMathFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/ConvolutionFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/FullyConnectedFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/NNSupportFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/PoolingFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/ReshapeFunctions
VPATH+= $(TOP)/edge-impulse-sdk/CMSIS/NN/Source/SoftmaxFunctions
VPATH+= $(TOP)/edge-impulse-sdk/dsp
VPATH+= $(TOP)/edge-impulse-sdk/dsp/dct
VPATH+= $(TOP)/edge-impulse-sdk/dsp/spectral
VPATH+= $(TOP)/edge-impulse-sdk/dsp/speechpy
VPATH+= $(TOP)/edge-impulse-sdk/dsp/kissfft
VPATH+= $(TOP)/edge-impulse-sdk/third_party/flatbuffers/include
VPATH+= $(TOP)/edge-impulse-sdk/third_party/gemmlowp
VPATH+= $(TOP)/edge-impulse-sdk/third_party/ruy
VPATH+= $(TOP)/edge-impulse-sdk/third_party/ruy/ruy
VPATH+= $(TOP)/edge-impulse-sdk/third_party/ruy/ruy/profiler
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/c
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/kernels
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/kernels/internal
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/core/api
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/micro
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/micro/memory_planner
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/micro/kernels
VPATH+= $(TOP)/edge-impulse-sdk/tensorflow/lite/micro/testing
VPATH+= $(TOP)/tflite-model
VPATH+= $(TOP)/model-parameters


SRC = main.cpp
SRC+= ei_classifier_porting.cpp
SRC+= debug_log.cc
SRC+= eta_bsp.c
SRC+= eta_bsp_button.c
SRC+= eta_bsp_led.c
SRC+= eta_bsp_power.c
SRC+= eta_utils_stdio.c
SRC+= eta_utils_state.c
SRC+= printf.c
SRC+= ../startup_gcc.c
SRC+= memory.cpp
SRC+= kiss_fft.cpp
SRC+= kiss_fftr.cpp
SRC+= fast-dct-fft.cpp
SRC+= $(shell find ../../edge-impulse-sdk/CMSIS -name "*.c" | rev | cut -d"/" -f1 | rev)
SRC+= $(shell find ../../edge-impulse-sdk/tensorflow -name "*.c*" | rev | cut -d"/" -f1 | rev)


C_SRC = $(filter %.c,$(SRC))
CPP_SRC = $(filter %.cpp,$(SRC))
CC_SRC = $(filter %.cc,$(SRC))
A_SRC = $(filter %.s,$(SRC))

OBJS = $(C_SRC:%.c=bin/%.o)
OBJS+= $(CPP_SRC:%.cpp=bin/%.o)
OBJS+= $(CC_SRC:%.cc=bin/%.o)
OBJS+= $(A_SRC:%.s=bin/%.o)

DEPS = $(C_SRC:%.c=bin/%.d)
DEPS+= $(CPP_SRC:%.cpp=bin/%.d)
DEPS+= $(CC_SRC:%.cc=bin/%.d)
DEPS+= $(A_SRC:%.s=bin/%.d)

M3_CSP_LIB_DIR = $(TOP)/soc/ecm3532/m3/csp/lib/gcc
M3_CSP_LIB = $(M3_CSP_LIB_DIR)/eta_m3_csp.a

LIBS = $(M3_CSP_LIB)
LIBS+=

##### Options #####
OPTS =	-mthumb -mcpu=$(CPU) -mlittle-endian -fmessage-length=0 -fsigned-char
OPTS+= -ffunction-sections -fdata-sections -g3 -fno-common -MMD -MP -Werror
OPTS+= -O3
OPTS+= $(DEFINES)
OPTS+= $(INCLUDES)

CC_OPTS = -std=gnu11
CXX_OPTS = -std=c++11 -U__STRICT_ANSI__

LD_OPTS	= -mthumb -mcpu=$(CPU) -mlittle-endian -O3
LD_OPTS+= -fsigned-char -ffunction-sections -fdata-sections -g3 -fno-common
LD_OPTS+= -nostartfiles -static --specs=nosys.specs -fmessage-length=0 -flto
LD_OPTS+= -v -Xlinker -Map=bin/edge_impulse_audio.map -Wl,--gc-sections
LD_OPTS+= -Wl,--start-group $(LIBS) -Wl,--end-group

CP_OPTS = --verbose -Obinary

OD_OPTS = -S -d

##### Rules #####
.PHONY: all clean realclean
all: bin bin/$(PROJECT_NAME).bin

bin:
	mkdir -p $@

bin/%.o: %.c bin/%.d
	@echo " Compiling $<" with $(CC) ;\
	$(CC) -c $(OPTS) $(CC_OPTS) $< -o $@

bin/%.o: %.cpp bin/%.d
	@echo " Compiling $<" with $(CXX) ;\
	$(CXX) -c $(OPTS) $(CXX_OPTS) $< -o $@

bin/%.o: %.cc bin/%.d
	@echo " Compiling $<" with $(CXX) ;\
	$(CXX) -c $(OPTS) $(CXX_OPTS) $< -o $@

bin/%.o: %.s bin/%.d
	@echo " Assembling $<" with $(CC);\
	$(CC) -c $(OPTS) $(CC_OPTS) $< -o $@

bin/$(PROJECT_NAME).elf : $(OBJS) $(LIBS)
	@echo " Linking $@" with $(CXX);\
	$(CXX) -Wl,-T,$(LINKER_SCRIPT) -o $@ $(OBJS) $(LD_OPTS)

bin/$(PROJECT_NAME).bin: bin/$(PROJECT_NAME).elf
	mkdir -p ../../build/
	@echo " Copying $@..." ;\
	$(CP) $(CP_OPTS) $< $@ ;\
	$(OD) $(OD_OPTS) $< > bin/$(PROJECT_NAME).txt
	cp bin/*.bin ../../build/
	cp bin/*.elf ../../build/

realclean clean:
	rm -f $(OBJS) $(DEPS) \
		bin/$(PROJECT_NAME).bin bin/$(PROJECT_NAME).elf \
		bin/$(PROJECT_NAME).txt bin/$(PROJECT_NAME).map

bin/%d: ;

$(M3_CSP_LIB):
	$(MAKE) -C $(M3_CSP_LIB_DIR)

ifeq ($(OS), Windows_NT)
debug:
	@powershell $(TOP)/../bin/gdb_debug.ps1 ECM3532 $(CURDIR)
else
debug:
	@$(TOP)/../bin/gdb_debug.sh "ECM3532" $(CURDIR)
endif

# Automatically include any generated dependencies
-include $(DEPS)
