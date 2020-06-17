################################################################################
#
# @file Makefile
#
# @brief This file contains the commands to build the examples.
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

SUBDIRS := $(dir $(wildcard */[Mm]akefile))

#
# GCC CSP directory.
#
ETA_CSP_DIR=./soc/ecm3532/m3/csp/lib/gcc/

#
# IDE dirs.
#
GCC_DIR=gcc
KEIL_DIR=keil
IAR_DIR=iar
ES_DIR=embedded_studio

#
# Check dependencies and build if necessary.
#
.PHONY: all gcc keil iar es
all: all gcc

gcc:
	@echo
	@echo "Building GCC..."
	@echo "Check CSP lib"
	make -C $(ETA_CSP_DIR)
	@echo "Make gcc here"
	! test -d $(GCC_DIR) || $(MAKE) -C gcc
	@echo
	@echo "...GCC compilation finished (see the build/ folder)"
	@echo

#
# Clean.
#
clean:
	@for i in ${SUBDIRS}; do \
		$(MAKE) -C $${i} $@ || exit $? ;\
	done

	rm -r build/
