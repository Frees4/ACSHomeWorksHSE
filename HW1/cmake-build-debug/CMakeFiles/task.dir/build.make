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
CMAKE_SOURCE_DIR = /home/frees/AVS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frees/AVS/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task.dir/flags.make

CMakeFiles/task.dir/src/main.cpp.o: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frees/AVS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task.dir/src/main.cpp.o -c /home/frees/AVS/src/main.cpp

CMakeFiles/task.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frees/AVS/src/main.cpp > CMakeFiles/task.dir/src/main.cpp.i

CMakeFiles/task.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frees/AVS/src/main.cpp -o CMakeFiles/task.dir/src/main.cpp.s

CMakeFiles/task.dir/src/text.cpp.o: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/src/text.cpp.o: ../src/text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frees/AVS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task.dir/src/text.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task.dir/src/text.cpp.o -c /home/frees/AVS/src/text.cpp

CMakeFiles/task.dir/src/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/src/text.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frees/AVS/src/text.cpp > CMakeFiles/task.dir/src/text.cpp.i

CMakeFiles/task.dir/src/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/src/text.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frees/AVS/src/text.cpp -o CMakeFiles/task.dir/src/text.cpp.s

CMakeFiles/task.dir/src/char_encryption.cpp.o: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/src/char_encryption.cpp.o: ../src/char_encryption.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frees/AVS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task.dir/src/char_encryption.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task.dir/src/char_encryption.cpp.o -c /home/frees/AVS/src/char_encryption.cpp

CMakeFiles/task.dir/src/char_encryption.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/src/char_encryption.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frees/AVS/src/char_encryption.cpp > CMakeFiles/task.dir/src/char_encryption.cpp.i

CMakeFiles/task.dir/src/char_encryption.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/src/char_encryption.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frees/AVS/src/char_encryption.cpp -o CMakeFiles/task.dir/src/char_encryption.cpp.s

CMakeFiles/task.dir/src/shift_encryption.cpp.o: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/src/shift_encryption.cpp.o: ../src/shift_encryption.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frees/AVS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task.dir/src/shift_encryption.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task.dir/src/shift_encryption.cpp.o -c /home/frees/AVS/src/shift_encryption.cpp

CMakeFiles/task.dir/src/shift_encryption.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/src/shift_encryption.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frees/AVS/src/shift_encryption.cpp > CMakeFiles/task.dir/src/shift_encryption.cpp.i

CMakeFiles/task.dir/src/shift_encryption.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/src/shift_encryption.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frees/AVS/src/shift_encryption.cpp -o CMakeFiles/task.dir/src/shift_encryption.cpp.s

CMakeFiles/task.dir/src/container.cpp.o: CMakeFiles/task.dir/flags.make
CMakeFiles/task.dir/src/container.cpp.o: ../src/container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frees/AVS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/task.dir/src/container.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task.dir/src/container.cpp.o -c /home/frees/AVS/src/container.cpp

CMakeFiles/task.dir/src/container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/src/container.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frees/AVS/src/container.cpp > CMakeFiles/task.dir/src/container.cpp.i

CMakeFiles/task.dir/src/container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/src/container.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frees/AVS/src/container.cpp -o CMakeFiles/task.dir/src/container.cpp.s

# Object files for target task
task_OBJECTS = \
"CMakeFiles/task.dir/src/main.cpp.o" \
"CMakeFiles/task.dir/src/text.cpp.o" \
"CMakeFiles/task.dir/src/char_encryption.cpp.o" \
"CMakeFiles/task.dir/src/shift_encryption.cpp.o" \
"CMakeFiles/task.dir/src/container.cpp.o"

# External object files for target task
task_EXTERNAL_OBJECTS =

task: CMakeFiles/task.dir/src/main.cpp.o
task: CMakeFiles/task.dir/src/text.cpp.o
task: CMakeFiles/task.dir/src/char_encryption.cpp.o
task: CMakeFiles/task.dir/src/shift_encryption.cpp.o
task: CMakeFiles/task.dir/src/container.cpp.o
task: CMakeFiles/task.dir/build.make
task: CMakeFiles/task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frees/AVS/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable task"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task.dir/build: task

.PHONY : CMakeFiles/task.dir/build

CMakeFiles/task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task.dir/clean

CMakeFiles/task.dir/depend:
	cd /home/frees/AVS/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frees/AVS /home/frees/AVS /home/frees/AVS/cmake-build-debug /home/frees/AVS/cmake-build-debug /home/frees/AVS/cmake-build-debug/CMakeFiles/task.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task.dir/depend

