# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joao99sb/code/embedded_system/arduino/memory_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joao99sb/code/embedded_system/arduino/memory_game/build

# Include any dependencies generated for this target.
include CMakeFiles/memory_game.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/memory_game.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/memory_game.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memory_game.elf.dir/flags.make

CMakeFiles/memory_game.elf.dir/src/Array.c.o: CMakeFiles/memory_game.elf.dir/flags.make
CMakeFiles/memory_game.elf.dir/src/Array.c.o: /home/joao99sb/code/embedded_system/arduino/memory_game/src/Array.c
CMakeFiles/memory_game.elf.dir/src/Array.c.o: CMakeFiles/memory_game.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/joao99sb/code/embedded_system/arduino/memory_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/memory_game.elf.dir/src/Array.c.o"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/memory_game.elf.dir/src/Array.c.o -MF CMakeFiles/memory_game.elf.dir/src/Array.c.o.d -o CMakeFiles/memory_game.elf.dir/src/Array.c.o -c /home/joao99sb/code/embedded_system/arduino/memory_game/src/Array.c

CMakeFiles/memory_game.elf.dir/src/Array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/memory_game.elf.dir/src/Array.c.i"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao99sb/code/embedded_system/arduino/memory_game/src/Array.c > CMakeFiles/memory_game.elf.dir/src/Array.c.i

CMakeFiles/memory_game.elf.dir/src/Array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/memory_game.elf.dir/src/Array.c.s"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao99sb/code/embedded_system/arduino/memory_game/src/Array.c -o CMakeFiles/memory_game.elf.dir/src/Array.c.s

CMakeFiles/memory_game.elf.dir/src/core.c.o: CMakeFiles/memory_game.elf.dir/flags.make
CMakeFiles/memory_game.elf.dir/src/core.c.o: /home/joao99sb/code/embedded_system/arduino/memory_game/src/core.c
CMakeFiles/memory_game.elf.dir/src/core.c.o: CMakeFiles/memory_game.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/joao99sb/code/embedded_system/arduino/memory_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/memory_game.elf.dir/src/core.c.o"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/memory_game.elf.dir/src/core.c.o -MF CMakeFiles/memory_game.elf.dir/src/core.c.o.d -o CMakeFiles/memory_game.elf.dir/src/core.c.o -c /home/joao99sb/code/embedded_system/arduino/memory_game/src/core.c

CMakeFiles/memory_game.elf.dir/src/core.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/memory_game.elf.dir/src/core.c.i"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao99sb/code/embedded_system/arduino/memory_game/src/core.c > CMakeFiles/memory_game.elf.dir/src/core.c.i

CMakeFiles/memory_game.elf.dir/src/core.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/memory_game.elf.dir/src/core.c.s"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao99sb/code/embedded_system/arduino/memory_game/src/core.c -o CMakeFiles/memory_game.elf.dir/src/core.c.s

CMakeFiles/memory_game.elf.dir/src/main.c.o: CMakeFiles/memory_game.elf.dir/flags.make
CMakeFiles/memory_game.elf.dir/src/main.c.o: /home/joao99sb/code/embedded_system/arduino/memory_game/src/main.c
CMakeFiles/memory_game.elf.dir/src/main.c.o: CMakeFiles/memory_game.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/joao99sb/code/embedded_system/arduino/memory_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/memory_game.elf.dir/src/main.c.o"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/memory_game.elf.dir/src/main.c.o -MF CMakeFiles/memory_game.elf.dir/src/main.c.o.d -o CMakeFiles/memory_game.elf.dir/src/main.c.o -c /home/joao99sb/code/embedded_system/arduino/memory_game/src/main.c

CMakeFiles/memory_game.elf.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/memory_game.elf.dir/src/main.c.i"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao99sb/code/embedded_system/arduino/memory_game/src/main.c > CMakeFiles/memory_game.elf.dir/src/main.c.i

CMakeFiles/memory_game.elf.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/memory_game.elf.dir/src/main.c.s"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao99sb/code/embedded_system/arduino/memory_game/src/main.c -o CMakeFiles/memory_game.elf.dir/src/main.c.s

# Object files for target memory_game.elf
memory_game_elf_OBJECTS = \
"CMakeFiles/memory_game.elf.dir/src/Array.c.o" \
"CMakeFiles/memory_game.elf.dir/src/core.c.o" \
"CMakeFiles/memory_game.elf.dir/src/main.c.o"

# External object files for target memory_game.elf
memory_game_elf_EXTERNAL_OBJECTS =

memory_game.elf: CMakeFiles/memory_game.elf.dir/src/Array.c.o
memory_game.elf: CMakeFiles/memory_game.elf.dir/src/core.c.o
memory_game.elf: CMakeFiles/memory_game.elf.dir/src/main.c.o
memory_game.elf: CMakeFiles/memory_game.elf.dir/build.make
memory_game.elf: CMakeFiles/memory_game.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/joao99sb/code/embedded_system/arduino/memory_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable memory_game.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memory_game.elf.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Generating HEX file"
	avr-objcopy -O ihex -R .eeprom memory_game.elf memory_game.hex

# Rule to build all files generated by this target.
CMakeFiles/memory_game.elf.dir/build: memory_game.elf
.PHONY : CMakeFiles/memory_game.elf.dir/build

CMakeFiles/memory_game.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memory_game.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memory_game.elf.dir/clean

CMakeFiles/memory_game.elf.dir/depend:
	cd /home/joao99sb/code/embedded_system/arduino/memory_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joao99sb/code/embedded_system/arduino/memory_game /home/joao99sb/code/embedded_system/arduino/memory_game /home/joao99sb/code/embedded_system/arduino/memory_game/build /home/joao99sb/code/embedded_system/arduino/memory_game/build /home/joao99sb/code/embedded_system/arduino/memory_game/build/CMakeFiles/memory_game.elf.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/memory_game.elf.dir/depend

