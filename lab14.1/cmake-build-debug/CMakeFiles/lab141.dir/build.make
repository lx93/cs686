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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab141.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab141.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab141.dir/flags.make

CMakeFiles/lab141.dir/main.c.o: CMakeFiles/lab141.dir/flags.make
CMakeFiles/lab141.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab141.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab141.dir/main.c.o   -c "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/main.c"

CMakeFiles/lab141.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab141.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/main.c" > CMakeFiles/lab141.dir/main.c.i

CMakeFiles/lab141.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab141.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/main.c" -o CMakeFiles/lab141.dir/main.c.s

# Object files for target lab141
lab141_OBJECTS = \
"CMakeFiles/lab141.dir/main.c.o"

# External object files for target lab141
lab141_EXTERNAL_OBJECTS =

lab141: CMakeFiles/lab141.dir/main.c.o
lab141: CMakeFiles/lab141.dir/build.make
lab141: CMakeFiles/lab141.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab141"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab141.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab141.dir/build: lab141

.PHONY : CMakeFiles/lab141.dir/build

CMakeFiles/lab141.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab141.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab141.dir/clean

CMakeFiles/lab141.dir/depend:
	cd "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1" "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1" "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug" "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug" "/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/cmake-build-debug/CMakeFiles/lab141.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab141.dir/depend

