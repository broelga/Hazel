# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ibroel/dev/Marble

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ibroel/dev/Marble/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Marbled_unity.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Marbled_unity.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Marbled_unity.dir/flags.make

cotire/Marbled_CXX_prefix.hxx: cotire/Marbled_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/ibroel/dev/Marble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating CXX prefix header cotire/Marbled_CXX_prefix.hxx"
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Debug -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /Users/ibroel/dev/Marble/CMake/cotire.cmake combine /Users/ibroel/dev/Marble/cmake-build-debug/Marbled_CXX_Debug_cotire.cmake /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_prefix.hxx /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_prefix.cxx

cotire/Marbled_CXX_unity.cxx: Marbled_CXX_Debug_cotire.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/ibroel/dev/Marble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CXX unity source cotire/Marbled_CXX_unity.cxx"
	cd /Users/ibroel/dev/Marble && /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Debug -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /Users/ibroel/dev/Marble/CMake/cotire.cmake unity /Users/ibroel/dev/Marble/cmake-build-debug/Marbled_CXX_Debug_cotire.cmake /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_unity.cxx

cotire/Marbled_CXX_prefix.cxx: ../Marble/src/mrblpch.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/ibroel/dev/Marble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating CXX prefix source cotire/Marbled_CXX_prefix.cxx"
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Debug -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /Users/ibroel/dev/Marble/CMake/cotire.cmake combine /Users/ibroel/dev/Marble/cmake-build-debug/Marbled_CXX_Debug_cotire.cmake /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_prefix.cxx /Users/ibroel/dev/Marble/Marble/src/mrblpch.h

CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o: CMakeFiles/Marbled_unity.dir/flags.make
CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o: cotire/Marbled_CXX_unity.cxx
CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o: cotire/Marbled_CXX_prefix.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ibroel/dev/Marble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -include "/Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_prefix.hxx"  -o CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o -c /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_unity.cxx

CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -include "/Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_prefix.hxx"  -E /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_unity.cxx > CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.i

CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -include "/Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_prefix.hxx"  -S /Users/ibroel/dev/Marble/cmake-build-debug/cotire/Marbled_CXX_unity.cxx -o CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.s

# Object files for target Marbled_unity
Marbled_unity_OBJECTS = \
"CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o"

# External object files for target Marbled_unity
Marbled_unity_EXTERNAL_OBJECTS =

Marbled: CMakeFiles/Marbled_unity.dir/cotire/Marbled_CXX_unity.cxx.o
Marbled: CMakeFiles/Marbled_unity.dir/build.make
Marbled: Marble/vendor/GLFW/src/libglfw3.a
Marbled: CMakeFiles/Marbled_unity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ibroel/dev/Marble/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Marbled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Marbled_unity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Marbled_unity.dir/build: Marbled

.PHONY : CMakeFiles/Marbled_unity.dir/build

CMakeFiles/Marbled_unity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Marbled_unity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Marbled_unity.dir/clean

CMakeFiles/Marbled_unity.dir/depend: cotire/Marbled_CXX_prefix.cxx
CMakeFiles/Marbled_unity.dir/depend: cotire/Marbled_CXX_prefix.hxx
CMakeFiles/Marbled_unity.dir/depend: cotire/Marbled_CXX_unity.cxx
	cd /Users/ibroel/dev/Marble/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ibroel/dev/Marble /Users/ibroel/dev/Marble /Users/ibroel/dev/Marble/cmake-build-debug /Users/ibroel/dev/Marble/cmake-build-debug /Users/ibroel/dev/Marble/cmake-build-debug/CMakeFiles/Marbled_unity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Marbled_unity.dir/depend
