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
include CMakeFiles/v_erase.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/v_erase.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/v_erase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v_erase.dir/flags.make

CMakeFiles/v_erase.dir/test/vector_erase.cpp.o: CMakeFiles/v_erase.dir/flags.make
CMakeFiles/v_erase.dir/test/vector_erase.cpp.o: ../test/vector_erase.cpp
CMakeFiles/v_erase.dir/test/vector_erase.cpp.o: CMakeFiles/v_erase.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/v_erase.dir/test/vector_erase.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/v_erase.dir/test/vector_erase.cpp.o -MF CMakeFiles/v_erase.dir/test/vector_erase.cpp.o.d -o CMakeFiles/v_erase.dir/test/vector_erase.cpp.o -c /Users/wax/42/ft_containers/test/vector_erase.cpp

CMakeFiles/v_erase.dir/test/vector_erase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v_erase.dir/test/vector_erase.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wax/42/ft_containers/test/vector_erase.cpp > CMakeFiles/v_erase.dir/test/vector_erase.cpp.i

CMakeFiles/v_erase.dir/test/vector_erase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v_erase.dir/test/vector_erase.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wax/42/ft_containers/test/vector_erase.cpp -o CMakeFiles/v_erase.dir/test/vector_erase.cpp.s

# Object files for target v_erase
v_erase_OBJECTS = \
"CMakeFiles/v_erase.dir/test/vector_erase.cpp.o"

# External object files for target v_erase
v_erase_EXTERNAL_OBJECTS =

v_erase: CMakeFiles/v_erase.dir/test/vector_erase.cpp.o
v_erase: CMakeFiles/v_erase.dir/build.make
v_erase: CMakeFiles/v_erase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wax/42/ft_containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable v_erase"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v_erase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v_erase.dir/build: v_erase
.PHONY : CMakeFiles/v_erase.dir/build

CMakeFiles/v_erase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v_erase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v_erase.dir/clean

CMakeFiles/v_erase.dir/depend:
	cd /Users/wax/42/ft_containers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wax/42/ft_containers /Users/wax/42/ft_containers /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build /Users/wax/42/ft_containers/build/CMakeFiles/v_erase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/v_erase.dir/depend

