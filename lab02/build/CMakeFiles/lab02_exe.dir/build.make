# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/oop/lab02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/oop/lab02/build

# Include any dependencies generated for this target.
include CMakeFiles/lab02_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab02_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab02_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab02_exe.dir/flags.make

CMakeFiles/lab02_exe.dir/main.cpp.o: CMakeFiles/lab02_exe.dir/flags.make
CMakeFiles/lab02_exe.dir/main.cpp.o: /workspaces/oop/lab02/main.cpp
CMakeFiles/lab02_exe.dir/main.cpp.o: CMakeFiles/lab02_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/oop/lab02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab02_exe.dir/main.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab02_exe.dir/main.cpp.o -MF CMakeFiles/lab02_exe.dir/main.cpp.o.d -o CMakeFiles/lab02_exe.dir/main.cpp.o -c /workspaces/oop/lab02/main.cpp

CMakeFiles/lab02_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab02_exe.dir/main.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/oop/lab02/main.cpp > CMakeFiles/lab02_exe.dir/main.cpp.i

CMakeFiles/lab02_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab02_exe.dir/main.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/oop/lab02/main.cpp -o CMakeFiles/lab02_exe.dir/main.cpp.s

# Object files for target lab02_exe
lab02_exe_OBJECTS = \
"CMakeFiles/lab02_exe.dir/main.cpp.o"

# External object files for target lab02_exe
lab02_exe_EXTERNAL_OBJECTS =

lab02_exe: CMakeFiles/lab02_exe.dir/main.cpp.o
lab02_exe: CMakeFiles/lab02_exe.dir/build.make
lab02_exe: liblab02_lib.a
lab02_exe: CMakeFiles/lab02_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/oop/lab02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab02_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab02_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab02_exe.dir/build: lab02_exe
.PHONY : CMakeFiles/lab02_exe.dir/build

CMakeFiles/lab02_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab02_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab02_exe.dir/clean

CMakeFiles/lab02_exe.dir/depend:
	cd /workspaces/oop/lab02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/oop/lab02 /workspaces/oop/lab02 /workspaces/oop/lab02/build /workspaces/oop/lab02/build /workspaces/oop/lab02/build/CMakeFiles/lab02_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab02_exe.dir/depend

