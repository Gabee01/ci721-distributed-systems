# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vcube.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vcube.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vcube.dir/flags.make

CMakeFiles/vcube.dir/cisj.c.o: CMakeFiles/vcube.dir/flags.make
CMakeFiles/vcube.dir/cisj.c.o: ../cisj.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/vcube.dir/cisj.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vcube.dir/cisj.c.o   -c /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cisj.c

CMakeFiles/vcube.dir/cisj.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vcube.dir/cisj.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cisj.c > CMakeFiles/vcube.dir/cisj.c.i

CMakeFiles/vcube.dir/cisj.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vcube.dir/cisj.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cisj.c -o CMakeFiles/vcube.dir/cisj.c.s

CMakeFiles/vcube.dir/cisj.c.o.requires:

.PHONY : CMakeFiles/vcube.dir/cisj.c.o.requires

CMakeFiles/vcube.dir/cisj.c.o.provides: CMakeFiles/vcube.dir/cisj.c.o.requires
	$(MAKE) -f CMakeFiles/vcube.dir/build.make CMakeFiles/vcube.dir/cisj.c.o.provides.build
.PHONY : CMakeFiles/vcube.dir/cisj.c.o.provides

CMakeFiles/vcube.dir/cisj.c.o.provides.build: CMakeFiles/vcube.dir/cisj.c.o


CMakeFiles/vcube.dir/failure_detector.c.o: CMakeFiles/vcube.dir/flags.make
CMakeFiles/vcube.dir/failure_detector.c.o: ../failure_detector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/vcube.dir/failure_detector.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vcube.dir/failure_detector.c.o   -c /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/failure_detector.c

CMakeFiles/vcube.dir/failure_detector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vcube.dir/failure_detector.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/failure_detector.c > CMakeFiles/vcube.dir/failure_detector.c.i

CMakeFiles/vcube.dir/failure_detector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vcube.dir/failure_detector.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/failure_detector.c -o CMakeFiles/vcube.dir/failure_detector.c.s

CMakeFiles/vcube.dir/failure_detector.c.o.requires:

.PHONY : CMakeFiles/vcube.dir/failure_detector.c.o.requires

CMakeFiles/vcube.dir/failure_detector.c.o.provides: CMakeFiles/vcube.dir/failure_detector.c.o.requires
	$(MAKE) -f CMakeFiles/vcube.dir/build.make CMakeFiles/vcube.dir/failure_detector.c.o.provides.build
.PHONY : CMakeFiles/vcube.dir/failure_detector.c.o.provides

CMakeFiles/vcube.dir/failure_detector.c.o.provides.build: CMakeFiles/vcube.dir/failure_detector.c.o


CMakeFiles/vcube.dir/rand.c.o: CMakeFiles/vcube.dir/flags.make
CMakeFiles/vcube.dir/rand.c.o: ../rand.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/vcube.dir/rand.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vcube.dir/rand.c.o   -c /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/rand.c

CMakeFiles/vcube.dir/rand.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vcube.dir/rand.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/rand.c > CMakeFiles/vcube.dir/rand.c.i

CMakeFiles/vcube.dir/rand.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vcube.dir/rand.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/rand.c -o CMakeFiles/vcube.dir/rand.c.s

CMakeFiles/vcube.dir/rand.c.o.requires:

.PHONY : CMakeFiles/vcube.dir/rand.c.o.requires

CMakeFiles/vcube.dir/rand.c.o.provides: CMakeFiles/vcube.dir/rand.c.o.requires
	$(MAKE) -f CMakeFiles/vcube.dir/build.make CMakeFiles/vcube.dir/rand.c.o.provides.build
.PHONY : CMakeFiles/vcube.dir/rand.c.o.provides

CMakeFiles/vcube.dir/rand.c.o.provides.build: CMakeFiles/vcube.dir/rand.c.o


CMakeFiles/vcube.dir/smpl.c.o: CMakeFiles/vcube.dir/flags.make
CMakeFiles/vcube.dir/smpl.c.o: ../smpl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/vcube.dir/smpl.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vcube.dir/smpl.c.o   -c /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/smpl.c

CMakeFiles/vcube.dir/smpl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vcube.dir/smpl.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/smpl.c > CMakeFiles/vcube.dir/smpl.c.i

CMakeFiles/vcube.dir/smpl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vcube.dir/smpl.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/smpl.c -o CMakeFiles/vcube.dir/smpl.c.s

CMakeFiles/vcube.dir/smpl.c.o.requires:

.PHONY : CMakeFiles/vcube.dir/smpl.c.o.requires

CMakeFiles/vcube.dir/smpl.c.o.provides: CMakeFiles/vcube.dir/smpl.c.o.requires
	$(MAKE) -f CMakeFiles/vcube.dir/build.make CMakeFiles/vcube.dir/smpl.c.o.provides.build
.PHONY : CMakeFiles/vcube.dir/smpl.c.o.provides

CMakeFiles/vcube.dir/smpl.c.o.provides.build: CMakeFiles/vcube.dir/smpl.c.o


CMakeFiles/vcube.dir/vcube.c.o: CMakeFiles/vcube.dir/flags.make
CMakeFiles/vcube.dir/vcube.c.o: ../vcube.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/vcube.dir/vcube.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vcube.dir/vcube.c.o   -c /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/vcube.c

CMakeFiles/vcube.dir/vcube.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vcube.dir/vcube.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/vcube.c > CMakeFiles/vcube.dir/vcube.c.i

CMakeFiles/vcube.dir/vcube.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vcube.dir/vcube.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/vcube.c -o CMakeFiles/vcube.dir/vcube.c.s

CMakeFiles/vcube.dir/vcube.c.o.requires:

.PHONY : CMakeFiles/vcube.dir/vcube.c.o.requires

CMakeFiles/vcube.dir/vcube.c.o.provides: CMakeFiles/vcube.dir/vcube.c.o.requires
	$(MAKE) -f CMakeFiles/vcube.dir/build.make CMakeFiles/vcube.dir/vcube.c.o.provides.build
.PHONY : CMakeFiles/vcube.dir/vcube.c.o.provides

CMakeFiles/vcube.dir/vcube.c.o.provides.build: CMakeFiles/vcube.dir/vcube.c.o


CMakeFiles/vcube.dir/logger.c.o: CMakeFiles/vcube.dir/flags.make
CMakeFiles/vcube.dir/logger.c.o: ../logger.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/vcube.dir/logger.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vcube.dir/logger.c.o   -c /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/logger.c

CMakeFiles/vcube.dir/logger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vcube.dir/logger.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/logger.c > CMakeFiles/vcube.dir/logger.c.i

CMakeFiles/vcube.dir/logger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vcube.dir/logger.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/logger.c -o CMakeFiles/vcube.dir/logger.c.s

CMakeFiles/vcube.dir/logger.c.o.requires:

.PHONY : CMakeFiles/vcube.dir/logger.c.o.requires

CMakeFiles/vcube.dir/logger.c.o.provides: CMakeFiles/vcube.dir/logger.c.o.requires
	$(MAKE) -f CMakeFiles/vcube.dir/build.make CMakeFiles/vcube.dir/logger.c.o.provides.build
.PHONY : CMakeFiles/vcube.dir/logger.c.o.provides

CMakeFiles/vcube.dir/logger.c.o.provides.build: CMakeFiles/vcube.dir/logger.c.o


# Object files for target vcube
vcube_OBJECTS = \
"CMakeFiles/vcube.dir/cisj.c.o" \
"CMakeFiles/vcube.dir/failure_detector.c.o" \
"CMakeFiles/vcube.dir/rand.c.o" \
"CMakeFiles/vcube.dir/smpl.c.o" \
"CMakeFiles/vcube.dir/vcube.c.o" \
"CMakeFiles/vcube.dir/logger.c.o"

# External object files for target vcube
vcube_EXTERNAL_OBJECTS =

vcube: CMakeFiles/vcube.dir/cisj.c.o
vcube: CMakeFiles/vcube.dir/failure_detector.c.o
vcube: CMakeFiles/vcube.dir/rand.c.o
vcube: CMakeFiles/vcube.dir/smpl.c.o
vcube: CMakeFiles/vcube.dir/vcube.c.o
vcube: CMakeFiles/vcube.dir/logger.c.o
vcube: CMakeFiles/vcube.dir/build.make
vcube: CMakeFiles/vcube.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable vcube"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vcube.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vcube.dir/build: vcube

.PHONY : CMakeFiles/vcube.dir/build

CMakeFiles/vcube.dir/requires: CMakeFiles/vcube.dir/cisj.c.o.requires
CMakeFiles/vcube.dir/requires: CMakeFiles/vcube.dir/failure_detector.c.o.requires
CMakeFiles/vcube.dir/requires: CMakeFiles/vcube.dir/rand.c.o.requires
CMakeFiles/vcube.dir/requires: CMakeFiles/vcube.dir/smpl.c.o.requires
CMakeFiles/vcube.dir/requires: CMakeFiles/vcube.dir/vcube.c.o.requires
CMakeFiles/vcube.dir/requires: CMakeFiles/vcube.dir/logger.c.o.requires

.PHONY : CMakeFiles/vcube.dir/requires

CMakeFiles/vcube.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vcube.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vcube.dir/clean

CMakeFiles/vcube.dir/depend:
	cd /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug /Users/gabrielcarraro/Workspace/sistemas-distribuidos/vcube/cmake-build-debug/CMakeFiles/vcube.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vcube.dir/depend

