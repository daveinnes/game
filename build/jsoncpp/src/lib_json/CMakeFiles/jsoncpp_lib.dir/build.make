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

# Include any dependencies generated for this target.
include src/lib_json/CMakeFiles/jsoncpp_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/lib_json/CMakeFiles/jsoncpp_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/lib_json/CMakeFiles/jsoncpp_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib_json/CMakeFiles/jsoncpp_lib.dir/flags.make

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/flags.make
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/includes_CXX.rsp
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj: C:/Users/david/Documents/code/game/external/jsoncpp/src/lib_json/json_reader.cpp
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\david\Documents\code\game\build\jsoncpp\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj -MF CMakeFiles\jsoncpp_lib.dir\json_reader.cpp.obj.d -o CMakeFiles\jsoncpp_lib.dir\json_reader.cpp.obj -c C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_reader.cpp

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.i"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_reader.cpp > CMakeFiles\jsoncpp_lib.dir\json_reader.cpp.i

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.s"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_reader.cpp -o CMakeFiles\jsoncpp_lib.dir\json_reader.cpp.s

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/flags.make
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/includes_CXX.rsp
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj: C:/Users/david/Documents/code/game/external/jsoncpp/src/lib_json/json_value.cpp
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\david\Documents\code\game\build\jsoncpp\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj -MF CMakeFiles\jsoncpp_lib.dir\json_value.cpp.obj.d -o CMakeFiles\jsoncpp_lib.dir\json_value.cpp.obj -c C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_value.cpp

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/jsoncpp_lib.dir/json_value.cpp.i"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_value.cpp > CMakeFiles\jsoncpp_lib.dir\json_value.cpp.i

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/jsoncpp_lib.dir/json_value.cpp.s"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_value.cpp -o CMakeFiles\jsoncpp_lib.dir\json_value.cpp.s

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/flags.make
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/includes_CXX.rsp
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj: C:/Users/david/Documents/code/game/external/jsoncpp/src/lib_json/json_writer.cpp
src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj: src/lib_json/CMakeFiles/jsoncpp_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\david\Documents\code\game\build\jsoncpp\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj -MF CMakeFiles\jsoncpp_lib.dir\json_writer.cpp.obj.d -o CMakeFiles\jsoncpp_lib.dir\json_writer.cpp.obj -c C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_writer.cpp

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.i"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_writer.cpp > CMakeFiles\jsoncpp_lib.dir\json_writer.cpp.i

src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.s"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && C:\msys64\ucrt64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json\json_writer.cpp -o CMakeFiles\jsoncpp_lib.dir\json_writer.cpp.s

# Object files for target jsoncpp_lib
jsoncpp_lib_OBJECTS = \
"CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj" \
"CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj" \
"CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj"

# External object files for target jsoncpp_lib
jsoncpp_lib_EXTERNAL_OBJECTS =

bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.obj
bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.obj
bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.obj
bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/build.make
bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/linkLibs.rsp
bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/objects1.rsp
bin/libjsoncpp.dll: src/lib_json/CMakeFiles/jsoncpp_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\david\Documents\code\game\build\jsoncpp\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library ..\..\bin\libjsoncpp.dll"
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\jsoncpp_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib_json/CMakeFiles/jsoncpp_lib.dir/build: bin/libjsoncpp.dll
.PHONY : src/lib_json/CMakeFiles/jsoncpp_lib.dir/build

src/lib_json/CMakeFiles/jsoncpp_lib.dir/clean:
	cd /d C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json && $(CMAKE_COMMAND) -P CMakeFiles\jsoncpp_lib.dir\cmake_clean.cmake
.PHONY : src/lib_json/CMakeFiles/jsoncpp_lib.dir/clean

src/lib_json/CMakeFiles/jsoncpp_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\david\Documents\code\game\external\jsoncpp C:\Users\david\Documents\code\game\external\jsoncpp\src\lib_json C:\Users\david\Documents\code\game\build\jsoncpp C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json C:\Users\david\Documents\code\game\build\jsoncpp\src\lib_json\CMakeFiles\jsoncpp_lib.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/lib_json/CMakeFiles/jsoncpp_lib.dir/depend

