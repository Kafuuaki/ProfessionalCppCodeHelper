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
include test/CMakeFiles/compile-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/compile-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/compile-test.dir/flags.make

test/CMakeFiles/compile-test.dir/compile-test.cc.o: test/CMakeFiles/compile-test.dir/flags.make
test/CMakeFiles/compile-test.dir/compile-test.cc.o: ../test/compile-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/compile-test.dir/compile-test.cc.o"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile-test.dir/compile-test.cc.o -c /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test/compile-test.cc

test/CMakeFiles/compile-test.dir/compile-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile-test.dir/compile-test.cc.i"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test/compile-test.cc > CMakeFiles/compile-test.dir/compile-test.cc.i

test/CMakeFiles/compile-test.dir/compile-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile-test.dir/compile-test.cc.s"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test/compile-test.cc -o CMakeFiles/compile-test.dir/compile-test.cc.s

# Object files for target compile-test
compile__test_OBJECTS = \
"CMakeFiles/compile-test.dir/compile-test.cc.o"

# External object files for target compile-test
compile__test_EXTERNAL_OBJECTS =

bin/compile-test: test/CMakeFiles/compile-test.dir/compile-test.cc.o
bin/compile-test: test/CMakeFiles/compile-test.dir/build.make
bin/compile-test: test/libtest-main.a
bin/compile-test: libfmt.a
bin/compile-test: test/gtest/libgtest.a
bin/compile-test: test/CMakeFiles/compile-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/compile-test"
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/compile-test.dir/build: bin/compile-test

.PHONY : test/CMakeFiles/compile-test.dir/build

test/CMakeFiles/compile-test.dir/clean:
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test && $(CMAKE_COMMAND) -P CMakeFiles/compile-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/compile-test.dir/clean

test/CMakeFiles/compile-test.dir/depend:
	cd /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0 /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/test /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test /home/jianqiu/Desktop/ProfessionalCppCodeHelper/fmt-10.1.0/build/test/CMakeFiles/compile-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/compile-test.dir/depend
