# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/vstan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vstan/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vstan/Documents/Dev/conix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vstan/Documents/Dev/conix/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/conix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/conix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/conix.dir/flags.make

CMakeFiles/conix.dir/src/conix.c.o: CMakeFiles/conix.dir/flags.make
CMakeFiles/conix.dir/src/conix.c.o: ../src/conix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vstan/Documents/Dev/conix/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/conix.dir/src/conix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/conix.dir/src/conix.c.o   -c /home/vstan/Documents/Dev/conix/src/conix.c

CMakeFiles/conix.dir/src/conix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/conix.dir/src/conix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vstan/Documents/Dev/conix/src/conix.c > CMakeFiles/conix.dir/src/conix.c.i

CMakeFiles/conix.dir/src/conix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/conix.dir/src/conix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vstan/Documents/Dev/conix/src/conix.c -o CMakeFiles/conix.dir/src/conix.c.s

CMakeFiles/conix.dir/src/list.c.o: CMakeFiles/conix.dir/flags.make
CMakeFiles/conix.dir/src/list.c.o: ../src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vstan/Documents/Dev/conix/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/conix.dir/src/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/conix.dir/src/list.c.o   -c /home/vstan/Documents/Dev/conix/src/list.c

CMakeFiles/conix.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/conix.dir/src/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vstan/Documents/Dev/conix/src/list.c > CMakeFiles/conix.dir/src/list.c.i

CMakeFiles/conix.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/conix.dir/src/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vstan/Documents/Dev/conix/src/list.c -o CMakeFiles/conix.dir/src/list.c.s

CMakeFiles/conix.dir/src/map.c.o: CMakeFiles/conix.dir/flags.make
CMakeFiles/conix.dir/src/map.c.o: ../src/map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vstan/Documents/Dev/conix/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/conix.dir/src/map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/conix.dir/src/map.c.o   -c /home/vstan/Documents/Dev/conix/src/map.c

CMakeFiles/conix.dir/src/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/conix.dir/src/map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vstan/Documents/Dev/conix/src/map.c > CMakeFiles/conix.dir/src/map.c.i

CMakeFiles/conix.dir/src/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/conix.dir/src/map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vstan/Documents/Dev/conix/src/map.c -o CMakeFiles/conix.dir/src/map.c.s

# Object files for target conix
conix_OBJECTS = \
"CMakeFiles/conix.dir/src/conix.c.o" \
"CMakeFiles/conix.dir/src/list.c.o" \
"CMakeFiles/conix.dir/src/map.c.o"

# External object files for target conix
conix_EXTERNAL_OBJECTS =

libconix.a: CMakeFiles/conix.dir/src/conix.c.o
libconix.a: CMakeFiles/conix.dir/src/list.c.o
libconix.a: CMakeFiles/conix.dir/src/map.c.o
libconix.a: CMakeFiles/conix.dir/build.make
libconix.a: CMakeFiles/conix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vstan/Documents/Dev/conix/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libconix.a"
	$(CMAKE_COMMAND) -P CMakeFiles/conix.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/conix.dir/build: libconix.a

.PHONY : CMakeFiles/conix.dir/build

CMakeFiles/conix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/conix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/conix.dir/clean

CMakeFiles/conix.dir/depend:
	cd /home/vstan/Documents/Dev/conix/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vstan/Documents/Dev/conix /home/vstan/Documents/Dev/conix /home/vstan/Documents/Dev/conix/cmake-build-debug-coverage /home/vstan/Documents/Dev/conix/cmake-build-debug-coverage /home/vstan/Documents/Dev/conix/cmake-build-debug-coverage/CMakeFiles/conix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/conix.dir/depend
