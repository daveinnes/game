# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\david\Documents\code\game\external\jsoncpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\david\Documents\code\game\build\jsoncpp

# Utility rule file for jsoncpp_readerwriter_tests.

# Include any custom commands dependencies for this target.
include src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/progress.make

src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests: bin/jsontestrunner_exe.exe
src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests: bin/jsoncpp_test.exe
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\jsontestrunner && C:\Users\david\AppData\Local\Programs\Python\Python310\python.exe -B C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/runjsontests.py C:/Users/david/Documents/code/game/build/jsoncpp/bin/jsontestrunner_exe.exe C:/Users/david/Documents/code/game/external/jsoncpp/src/jsontestrunner/../../test/data

jsoncpp_readerwriter_tests: src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests
jsoncpp_readerwriter_tests: src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/build.make
.PHONY : jsoncpp_readerwriter_tests

# Rule to build all files generated by this target.
src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/build: jsoncpp_readerwriter_tests
.PHONY : src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/build

src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/clean:
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\jsontestrunner && $(CMAKE_COMMAND) -P CMakeFiles\jsoncpp_readerwriter_tests.dir\cmake_clean.cmake
.PHONY : src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/clean

src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\david\Documents\code\game\external\jsoncpp C:\Users\david\Documents\code\game\external\jsoncpp\src\jsontestrunner C:\Users\david\Documents\code\game\build\jsoncpp C:\Users\david\Documents\code\game\build\jsoncpp\src\jsontestrunner C:\Users\david\Documents\code\game\build\jsoncpp\src\jsontestrunner\CMakeFiles\jsoncpp_readerwriter_tests.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/depend
