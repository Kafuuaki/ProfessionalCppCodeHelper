# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build

# Include any dependencies generated for this target.
include test/CMakeFiles/xchar-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/xchar-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/xchar-test.dir/flags.make

test/CMakeFiles/xchar-test.dir/xchar-test.cc.o: test/CMakeFiles/xchar-test.dir/flags.make
test/CMakeFiles/xchar-test.dir/xchar-test.cc.o: ../test/xchar-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/xchar-test.dir/xchar-test.cc.o"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xchar-test.dir/xchar-test.cc.o -c /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test/xchar-test.cc

test/CMakeFiles/xchar-test.dir/xchar-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xchar-test.dir/xchar-test.cc.i"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test/xchar-test.cc > CMakeFiles/xchar-test.dir/xchar-test.cc.i

test/CMakeFiles/xchar-test.dir/xchar-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xchar-test.dir/xchar-test.cc.s"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test/xchar-test.cc -o CMakeFiles/xchar-test.dir/xchar-test.cc.s

# Object files for target xchar-test
xchar__test_OBJECTS = \
"CMakeFiles/xchar-test.dir/xchar-test.cc.o"

# External object files for target xchar-test
xchar__test_EXTERNAL_OBJECTS =

bin/xchar-test: test/CMakeFiles/xchar-test.dir/xchar-test.cc.o
bin/xchar-test: test/CMakeFiles/xchar-test.dir/build.make
bin/xchar-test: test/libtest-main.a
bin/xchar-test: libfmt.a
bin/xchar-test: test/gtest/libgtest.a
bin/xchar-test: test/CMakeFiles/xchar-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/xchar-test"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xchar-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/xchar-test.dir/build: bin/xchar-test

.PHONY : test/CMakeFiles/xchar-test.dir/build

test/CMakeFiles/xchar-test.dir/clean:
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && $(CMAKE_COMMAND) -P CMakeFiles/xchar-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/xchar-test.dir/clean

test/CMakeFiles/xchar-test.dir/depend:
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0 /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test/CMakeFiles/xchar-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/xchar-test.dir/depend

