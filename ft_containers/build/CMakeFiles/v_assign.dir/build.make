# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wax/42/ft_containers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wax/42/ft_containers/build

# Include any dependencies generated for this target.
include CMakeFiles/v_assign.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/v_assign.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/v_assign.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v_assign.dir/flags.make

CMakeFiles/v_assign.dir/test/vector_assign.cpp.o: CMakeFiles/v_assign.dir/flags.make
CMakeFiles/v_assign.dir/test/vector_assign.cpp.o: ../test/vector_assign.cpp
CMakeFiles/v_assign.dir/test/vector_assign.cpp.o: CMakeFiles/v_assign.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/v_assign.dir/test/vector_assign.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/v_assign.dir/test/vector_assign.cpp.o -MF CMakeFiles/v_assign.dir/test/vector_assign.cpp.o.d -o CMakeFiles/v_assign.dir/test/vector_assign.cpp.o -c /Users/wax/42/ft_containers/test/vector_assign.cpp

CMakeFiles/v_assign.dir/test/vector_assign.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v_assign.dir/test/vector_assign.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wax/42/ft_containers/test/vector_assign.cpp > CMakeFiles/v_assign.dir/test/vector_assign.cpp.i

CMakeFiles/v_assign.dir/test/vector_assign.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v_assign.dir/test/vector_assign.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wax/42/ft_containers/test/vector_assign.cpp -o CMakeFiles/v_assign.dir/test/vector_assign.cpp.s

# Object files for target v_assign
v_assign_OBJECTS = \
"CMakeFiles/v_assign.dir/test/vector_assign.cpp.o"

# External object files for target v_assign
v_assign_EXTERNAL_OBJECTS =

v_assign: CMakeFiles/v_assign.dir/test/vector_assign.cpp.o
v_assign: CMakeFiles/v_assign.dir/build.make
v_assign: CMakeFiles/v_assign.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable v_assign"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v_assign.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v_assign.dir/build: v_assign
.PHONY : CMakeFiles/v_assign.dir/build

CMakeFiles/v_assign.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v_assign.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v_assign.dir/clean

CMakeFiles/v_assign.dir/depend:
	cd /Users/wax/42/ft_containers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wax/42/ft_containers /Users/wax/42/ft_containers /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build/CMakeFiles/v_assign.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/v_assign.dir/depend

