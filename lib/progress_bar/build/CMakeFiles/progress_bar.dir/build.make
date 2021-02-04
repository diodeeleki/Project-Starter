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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/diode/Desktop/progress_bar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diode/Desktop/progress_bar/build

# Include any dependencies generated for this target.
include CMakeFiles/progress_bar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/progress_bar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progress_bar.dir/flags.make

ui_progress_bar.h: ../ui/progress_bar.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_progress_bar.h"
	/usr/lib/qt5/bin/uic -o /home/diode/Desktop/progress_bar/build/ui_progress_bar.h /home/diode/Desktop/progress_bar/ui/progress_bar.ui

CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.o: CMakeFiles/progress_bar.dir/flags.make
CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.o: progress_bar_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.o -c /home/diode/Desktop/progress_bar/build/progress_bar_autogen/mocs_compilation.cpp

CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diode/Desktop/progress_bar/build/progress_bar_autogen/mocs_compilation.cpp > CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.i

CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diode/Desktop/progress_bar/build/progress_bar_autogen/mocs_compilation.cpp -o CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.s

CMakeFiles/progress_bar.dir/src/progress_bar.cpp.o: CMakeFiles/progress_bar.dir/flags.make
CMakeFiles/progress_bar.dir/src/progress_bar.cpp.o: ../src/progress_bar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/progress_bar.dir/src/progress_bar.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progress_bar.dir/src/progress_bar.cpp.o -c /home/diode/Desktop/progress_bar/src/progress_bar.cpp

CMakeFiles/progress_bar.dir/src/progress_bar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progress_bar.dir/src/progress_bar.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diode/Desktop/progress_bar/src/progress_bar.cpp > CMakeFiles/progress_bar.dir/src/progress_bar.cpp.i

CMakeFiles/progress_bar.dir/src/progress_bar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progress_bar.dir/src/progress_bar.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diode/Desktop/progress_bar/src/progress_bar.cpp -o CMakeFiles/progress_bar.dir/src/progress_bar.cpp.s

# Object files for target progress_bar
progress_bar_OBJECTS = \
"CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/progress_bar.dir/src/progress_bar.cpp.o"

# External object files for target progress_bar
progress_bar_EXTERNAL_OBJECTS =

libprogress_bar.a: CMakeFiles/progress_bar.dir/progress_bar_autogen/mocs_compilation.cpp.o
libprogress_bar.a: CMakeFiles/progress_bar.dir/src/progress_bar.cpp.o
libprogress_bar.a: CMakeFiles/progress_bar.dir/build.make
libprogress_bar.a: CMakeFiles/progress_bar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libprogress_bar.a"
	$(CMAKE_COMMAND) -P CMakeFiles/progress_bar.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progress_bar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progress_bar.dir/build: libprogress_bar.a

.PHONY : CMakeFiles/progress_bar.dir/build

CMakeFiles/progress_bar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progress_bar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progress_bar.dir/clean

CMakeFiles/progress_bar.dir/depend: ui_progress_bar.h
	cd /home/diode/Desktop/progress_bar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diode/Desktop/progress_bar /home/diode/Desktop/progress_bar /home/diode/Desktop/progress_bar/build /home/diode/Desktop/progress_bar/build /home/diode/Desktop/progress_bar/build/CMakeFiles/progress_bar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progress_bar.dir/depend

