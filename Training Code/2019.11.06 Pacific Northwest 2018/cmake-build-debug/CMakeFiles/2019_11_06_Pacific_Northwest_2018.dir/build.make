# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/flags.make

CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.obj: CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/flags.make
CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.obj: ../I2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2019_11_06_Pacific_Northwest_2018.dir\I2.cpp.obj -c "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\I2.cpp"

CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\I2.cpp" > CMakeFiles\2019_11_06_Pacific_Northwest_2018.dir\I2.cpp.i

CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\I2.cpp" -o CMakeFiles\2019_11_06_Pacific_Northwest_2018.dir\I2.cpp.s

# Object files for target 2019_11_06_Pacific_Northwest_2018
2019_11_06_Pacific_Northwest_2018_OBJECTS = \
"CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.obj"

# External object files for target 2019_11_06_Pacific_Northwest_2018
2019_11_06_Pacific_Northwest_2018_EXTERNAL_OBJECTS =

2019_11_06_Pacific_Northwest_2018.exe: CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/I2.cpp.obj
2019_11_06_Pacific_Northwest_2018.exe: CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/build.make
2019_11_06_Pacific_Northwest_2018.exe: CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/linklibs.rsp
2019_11_06_Pacific_Northwest_2018.exe: CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/objects1.rsp
2019_11_06_Pacific_Northwest_2018.exe: CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2019_11_06_Pacific_Northwest_2018.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2019_11_06_Pacific_Northwest_2018.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/build: 2019_11_06_Pacific_Northwest_2018.exe

.PHONY : CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/build

CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2019_11_06_Pacific_Northwest_2018.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/clean

CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018" "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018" "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\cmake-build-debug" "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\cmake-build-debug" "C:\c++\Team-Model-Solution\Training Code\2019.11.06 Pacific Northwest 2018\cmake-build-debug\CMakeFiles\2019_11_06_Pacific_Northwest_2018.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/2019_11_06_Pacific_Northwest_2018.dir/depend

