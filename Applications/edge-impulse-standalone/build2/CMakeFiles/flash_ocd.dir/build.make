# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2

# Utility rule file for flash_ocd.

# Include the progress variables for this target.
include CMakeFiles/flash_ocd.dir/progress.make

CMakeFiles/flash_ocd:
	/usr/bin/python3.8 /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Platform/ECM3532/M3/scripts/program.py --ide=gcc --soc=ecm3532 --interface=ocd --bin edge-impulse-standalone.bin --type f

flash_ocd: CMakeFiles/flash_ocd
flash_ocd: CMakeFiles/flash_ocd.dir/build.make

.PHONY : flash_ocd

# Rule to build all files generated by this target.
CMakeFiles/flash_ocd.dir/build: flash_ocd

.PHONY : CMakeFiles/flash_ocd.dir/build

CMakeFiles/flash_ocd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flash_ocd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flash_ocd.dir/clean

CMakeFiles/flash_ocd.dir/depend:
	cd /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2 /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2 /home/arjan/Documents/EdgeImpulse/Firmware/example-standalone-inferencing-ecm3532/Applications/edge-impulse-standalone/build2/CMakeFiles/flash_ocd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flash_ocd.dir/depend
