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
include CMakeFiles/v_iterator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/v_iterator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/v_iterator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v_iterator.dir/flags.make

CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o: CMakeFiles/v_iterator.dir/flags.make
CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o: ../test/vector_iterator.cpp
CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o: CMakeFiles/v_iterator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o -MF CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o.d -o CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o -c /Users/wax/42/ft_containers/test/vector_iterator.cpp

CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wax/42/ft_containers/test/vector_iterator.cpp > CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.i

CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wax/42/ft_containers/test/vector_iterator.cpp -o CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.s

# Object files for target v_iterator
v_iterator_OBJECTS = \
"CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o"

# External object files for target v_iterator
v_iterator_EXTERNAL_OBJECTS =

v_iterator: CMakeFiles/v_iterator.dir/test/vector_iterator.cpp.o
v_iterator: CMakeFiles/v_iterator.dir/build.make
v_iterator: CMakeFiles/v_iterator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable v_iterator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v_iterator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v_iterator.dir/build: v_iterator
.PHONY : CMakeFiles/v_iterator.dir/build

CMakeFiles/v_iterator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v_iterator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v_iterator.dir/clean

CMakeFiles/v_iterator.dir/depend:
	cd /Users/wax/42/ft_containers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wax/42/ft_containers /Users/wax/42/ft_containers /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build/CMakeFiles/v_iterator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/v_iterator.dir/depend

