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
include test/CMakeFiles/progress_bar_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/progress_bar_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/progress_bar_test.dir/flags.make

test/CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.o: test/CMakeFiles/progress_bar_test.dir/flags.make
test/CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.o: test/progress_bar_test_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.o"
	cd /home/diode/Desktop/progress_bar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.o -c /home/diode/Desktop/progress_bar/build/test/progress_bar_test_autogen/mocs_compilation.cpp

test/CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.i"
	cd /home/diode/Desktop/progress_bar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diode/Desktop/progress_bar/build/test/progress_bar_test_autogen/mocs_compilation.cpp > CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.i

test/CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.s"
	cd /home/diode/Desktop/progress_bar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diode/Desktop/progress_bar/build/test/progress_bar_test_autogen/mocs_compilation.cpp -o CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.s

test/CMakeFiles/progress_bar_test.dir/main.cpp.o: test/CMakeFiles/progress_bar_test.dir/flags.make
test/CMakeFiles/progress_bar_test.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/progress_bar_test.dir/main.cpp.o"
	cd /home/diode/Desktop/progress_bar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progress_bar_test.dir/main.cpp.o -c /home/diode/Desktop/progress_bar/test/main.cpp

test/CMakeFiles/progress_bar_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progress_bar_test.dir/main.cpp.i"
	cd /home/diode/Desktop/progress_bar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diode/Desktop/progress_bar/test/main.cpp > CMakeFiles/progress_bar_test.dir/main.cpp.i

test/CMakeFiles/progress_bar_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progress_bar_test.dir/main.cpp.s"
	cd /home/diode/Desktop/progress_bar/build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diode/Desktop/progress_bar/test/main.cpp -o CMakeFiles/progress_bar_test.dir/main.cpp.s

# Object files for target progress_bar_test
progress_bar_test_OBJECTS = \
"CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/progress_bar_test.dir/main.cpp.o"

# External object files for target progress_bar_test
progress_bar_test_EXTERNAL_OBJECTS =

test/progress_bar_test: test/CMakeFiles/progress_bar_test.dir/progress_bar_test_autogen/mocs_compilation.cpp.o
test/progress_bar_test: test/CMakeFiles/progress_bar_test.dir/main.cpp.o
test/progress_bar_test: test/CMakeFiles/progress_bar_test.dir/build.make
test/progress_bar_test: libprogress_bar.a
test/progress_bar_test: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
test/progress_bar_test: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
test/progress_bar_test: /usr/lib/x86_64-linux-gnu/libQt5Sql.so.5.12.8
test/progress_bar_test: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
test/progress_bar_test: test/CMakeFiles/progress_bar_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diode/Desktop/progress_bar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable progress_bar_test"
	cd /home/diode/Desktop/progress_bar/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progress_bar_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/progress_bar_test.dir/build: test/progress_bar_test

.PHONY : test/CMakeFiles/progress_bar_test.dir/build

test/CMakeFiles/progress_bar_test.dir/clean:
	cd /home/diode/Desktop/progress_bar/build/test && $(CMAKE_COMMAND) -P CMakeFiles/progress_bar_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/progress_bar_test.dir/clean

test/CMakeFiles/progress_bar_test.dir/depend:
	cd /home/diode/Desktop/progress_bar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diode/Desktop/progress_bar /home/diode/Desktop/progress_bar/test /home/diode/Desktop/progress_bar/build /home/diode/Desktop/progress_bar/build/test /home/diode/Desktop/progress_bar/build/test/CMakeFiles/progress_bar_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/progress_bar_test.dir/depend

