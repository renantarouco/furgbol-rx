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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/renan/Workspace/cpp/furgbol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/renan/Workspace/cpp/furgbol/build

# Include any dependencies generated for this target.
include CMakeFiles/furgbol_sources.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/furgbol_sources.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/furgbol_sources.dir/flags.make

CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o: CMakeFiles/furgbol_sources.dir/flags.make
CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o: ../src/sources/sources.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/renan/Workspace/cpp/furgbol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o -c /home/renan/Workspace/cpp/furgbol/src/sources/sources.cc

CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/renan/Workspace/cpp/furgbol/src/sources/sources.cc > CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.i

CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/renan/Workspace/cpp/furgbol/src/sources/sources.cc -o CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.s

CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.requires:

.PHONY : CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.requires

CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.provides: CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.requires
	$(MAKE) -f CMakeFiles/furgbol_sources.dir/build.make CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.provides.build
.PHONY : CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.provides

CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.provides.build: CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o


# Object files for target furgbol_sources
furgbol_sources_OBJECTS = \
"CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o"

# External object files for target furgbol_sources
furgbol_sources_EXTERNAL_OBJECTS =

libfurgbol_sources.a: CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o
libfurgbol_sources.a: CMakeFiles/furgbol_sources.dir/build.make
libfurgbol_sources.a: CMakeFiles/furgbol_sources.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/renan/Workspace/cpp/furgbol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfurgbol_sources.a"
	$(CMAKE_COMMAND) -P CMakeFiles/furgbol_sources.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/furgbol_sources.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/furgbol_sources.dir/build: libfurgbol_sources.a

.PHONY : CMakeFiles/furgbol_sources.dir/build

CMakeFiles/furgbol_sources.dir/requires: CMakeFiles/furgbol_sources.dir/src/sources/sources.cc.o.requires

.PHONY : CMakeFiles/furgbol_sources.dir/requires

CMakeFiles/furgbol_sources.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/furgbol_sources.dir/cmake_clean.cmake
.PHONY : CMakeFiles/furgbol_sources.dir/clean

CMakeFiles/furgbol_sources.dir/depend:
	cd /home/renan/Workspace/cpp/furgbol/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/renan/Workspace/cpp/furgbol /home/renan/Workspace/cpp/furgbol /home/renan/Workspace/cpp/furgbol/build /home/renan/Workspace/cpp/furgbol/build /home/renan/Workspace/cpp/furgbol/build/CMakeFiles/furgbol_sources.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/furgbol_sources.dir/depend
