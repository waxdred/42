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
include CMakeFiles/v_clear.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/v_clear.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/v_clear.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v_clear.dir/flags.make

CMakeFiles/v_clear.dir/test/vector_clear.cpp.o: CMakeFiles/v_clear.dir/flags.make
CMakeFiles/v_clear.dir/test/vector_clear.cpp.o: ../test/vector_clear.cpp
CMakeFiles/v_clear.dir/test/vector_clear.cpp.o: CMakeFiles/v_clear.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/v_clear.dir/test/vector_clear.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/v_clear.dir/test/vector_clear.cpp.o -MF CMakeFiles/v_clear.dir/test/vector_clear.cpp.o.d -o CMakeFiles/v_clear.dir/test/vector_clear.cpp.o -c /Users/wax/42/ft_containers/test/vector_clear.cpp

CMakeFiles/v_clear.dir/test/vector_clear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v_clear.dir/test/vector_clear.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wax/42/ft_containers/test/vector_clear.cpp > CMakeFiles/v_clear.dir/test/vector_clear.cpp.i

CMakeFiles/v_clear.dir/test/vector_clear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v_clear.dir/test/vector_clear.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wax/42/ft_containers/test/vector_clear.cpp -o CMakeFiles/v_clear.dir/test/vector_clear.cpp.s

# Object files for target v_clear
v_clear_OBJECTS = \
"CMakeFiles/v_clear.dir/test/vector_clear.cpp.o"

# External object files for target v_clear
v_clear_EXTERNAL_OBJECTS =

v_clear: CMakeFiles/v_clear.dir/test/vector_clear.cpp.o
v_clear: CMakeFiles/v_clear.dir/build.make
v_clear: CMakeFiles/v_clear.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable v_clear"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v_clear.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v_clear.dir/build: v_clear
.PHONY : CMakeFiles/v_clear.dir/build

CMakeFiles/v_clear.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v_clear.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v_clear.dir/clean

CMakeFiles/v_clear.dir/depend:
	cd /Users/wax/42/ft_containers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wax/42/ft_containers /Users/wax/42/ft_containers /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build/CMakeFiles/v_clear.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/v_clear.dir/depend
