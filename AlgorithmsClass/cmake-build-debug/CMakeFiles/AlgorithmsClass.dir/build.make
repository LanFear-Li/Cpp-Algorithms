# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\IDE\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\IDE\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AlgorithmsClass.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AlgorithmsClass.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AlgorithmsClass.dir/flags.make

CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.obj: CMakeFiles/AlgorithmsClass.dir/flags.make
CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.obj: ../Algorithms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.obj"
	D:\IDE\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AlgorithmsClass.dir\Algorithms.cpp.obj -c D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\Algorithms.cpp

CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.i"
	D:\IDE\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\Algorithms.cpp > CMakeFiles\AlgorithmsClass.dir\Algorithms.cpp.i

CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.s"
	D:\IDE\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\Algorithms.cpp -o CMakeFiles\AlgorithmsClass.dir\Algorithms.cpp.s

CMakeFiles/AlgorithmsClass.dir/test.cpp.obj: CMakeFiles/AlgorithmsClass.dir/flags.make
CMakeFiles/AlgorithmsClass.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AlgorithmsClass.dir/test.cpp.obj"
	D:\IDE\Dev-Cpp\MinGW64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AlgorithmsClass.dir\test.cpp.obj -c D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\test.cpp

CMakeFiles/AlgorithmsClass.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgorithmsClass.dir/test.cpp.i"
	D:\IDE\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\test.cpp > CMakeFiles\AlgorithmsClass.dir\test.cpp.i

CMakeFiles/AlgorithmsClass.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgorithmsClass.dir/test.cpp.s"
	D:\IDE\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\test.cpp -o CMakeFiles\AlgorithmsClass.dir\test.cpp.s

# Object files for target AlgorithmsClass
AlgorithmsClass_OBJECTS = \
"CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.obj" \
"CMakeFiles/AlgorithmsClass.dir/test.cpp.obj"

# External object files for target AlgorithmsClass
AlgorithmsClass_EXTERNAL_OBJECTS =

AlgorithmsClass.exe: CMakeFiles/AlgorithmsClass.dir/Algorithms.cpp.obj
AlgorithmsClass.exe: CMakeFiles/AlgorithmsClass.dir/test.cpp.obj
AlgorithmsClass.exe: CMakeFiles/AlgorithmsClass.dir/build.make
AlgorithmsClass.exe: CMakeFiles/AlgorithmsClass.dir/linklibs.rsp
AlgorithmsClass.exe: CMakeFiles/AlgorithmsClass.dir/objects1.rsp
AlgorithmsClass.exe: CMakeFiles/AlgorithmsClass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AlgorithmsClass.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AlgorithmsClass.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AlgorithmsClass.dir/build: AlgorithmsClass.exe

.PHONY : CMakeFiles/AlgorithmsClass.dir/build

CMakeFiles/AlgorithmsClass.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AlgorithmsClass.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AlgorithmsClass.dir/clean

CMakeFiles/AlgorithmsClass.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug D:\Files\MyRepo\Cpp-Algorithms\AlgorithmsClass\cmake-build-debug\CMakeFiles\AlgorithmsClass.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AlgorithmsClass.dir/depend

