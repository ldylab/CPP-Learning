# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /Users/henry/CLionProjects/StaffManage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/henry/CLionProjects/StaffManage/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StaffManage.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/StaffManage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaffManage.dir/flags.make

CMakeFiles/StaffManage.dir/workerManager.cpp.o: CMakeFiles/StaffManage.dir/flags.make
CMakeFiles/StaffManage.dir/workerManager.cpp.o: ../workerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StaffManage.dir/workerManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaffManage.dir/workerManager.cpp.o -c /Users/henry/CLionProjects/StaffManage/workerManager.cpp

CMakeFiles/StaffManage.dir/workerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaffManage.dir/workerManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henry/CLionProjects/StaffManage/workerManager.cpp > CMakeFiles/StaffManage.dir/workerManager.cpp.i

CMakeFiles/StaffManage.dir/workerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaffManage.dir/workerManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henry/CLionProjects/StaffManage/workerManager.cpp -o CMakeFiles/StaffManage.dir/workerManager.cpp.s

CMakeFiles/StaffManage.dir/main.cpp.o: CMakeFiles/StaffManage.dir/flags.make
CMakeFiles/StaffManage.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/StaffManage.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaffManage.dir/main.cpp.o -c /Users/henry/CLionProjects/StaffManage/main.cpp

CMakeFiles/StaffManage.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaffManage.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henry/CLionProjects/StaffManage/main.cpp > CMakeFiles/StaffManage.dir/main.cpp.i

CMakeFiles/StaffManage.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaffManage.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henry/CLionProjects/StaffManage/main.cpp -o CMakeFiles/StaffManage.dir/main.cpp.s

CMakeFiles/StaffManage.dir/worker.cpp.o: CMakeFiles/StaffManage.dir/flags.make
CMakeFiles/StaffManage.dir/worker.cpp.o: ../worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/StaffManage.dir/worker.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaffManage.dir/worker.cpp.o -c /Users/henry/CLionProjects/StaffManage/worker.cpp

CMakeFiles/StaffManage.dir/worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaffManage.dir/worker.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henry/CLionProjects/StaffManage/worker.cpp > CMakeFiles/StaffManage.dir/worker.cpp.i

CMakeFiles/StaffManage.dir/worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaffManage.dir/worker.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henry/CLionProjects/StaffManage/worker.cpp -o CMakeFiles/StaffManage.dir/worker.cpp.s

CMakeFiles/StaffManage.dir/employee.cpp.o: CMakeFiles/StaffManage.dir/flags.make
CMakeFiles/StaffManage.dir/employee.cpp.o: ../employee.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/StaffManage.dir/employee.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaffManage.dir/employee.cpp.o -c /Users/henry/CLionProjects/StaffManage/employee.cpp

CMakeFiles/StaffManage.dir/employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaffManage.dir/employee.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henry/CLionProjects/StaffManage/employee.cpp > CMakeFiles/StaffManage.dir/employee.cpp.i

CMakeFiles/StaffManage.dir/employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaffManage.dir/employee.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henry/CLionProjects/StaffManage/employee.cpp -o CMakeFiles/StaffManage.dir/employee.cpp.s

CMakeFiles/StaffManage.dir/manager.cpp.o: CMakeFiles/StaffManage.dir/flags.make
CMakeFiles/StaffManage.dir/manager.cpp.o: ../manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/StaffManage.dir/manager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaffManage.dir/manager.cpp.o -c /Users/henry/CLionProjects/StaffManage/manager.cpp

CMakeFiles/StaffManage.dir/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaffManage.dir/manager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henry/CLionProjects/StaffManage/manager.cpp > CMakeFiles/StaffManage.dir/manager.cpp.i

CMakeFiles/StaffManage.dir/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaffManage.dir/manager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henry/CLionProjects/StaffManage/manager.cpp -o CMakeFiles/StaffManage.dir/manager.cpp.s

CMakeFiles/StaffManage.dir/boss.cpp.o: CMakeFiles/StaffManage.dir/flags.make
CMakeFiles/StaffManage.dir/boss.cpp.o: ../boss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/StaffManage.dir/boss.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaffManage.dir/boss.cpp.o -c /Users/henry/CLionProjects/StaffManage/boss.cpp

CMakeFiles/StaffManage.dir/boss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaffManage.dir/boss.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/henry/CLionProjects/StaffManage/boss.cpp > CMakeFiles/StaffManage.dir/boss.cpp.i

CMakeFiles/StaffManage.dir/boss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaffManage.dir/boss.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/henry/CLionProjects/StaffManage/boss.cpp -o CMakeFiles/StaffManage.dir/boss.cpp.s

# Object files for target StaffManage
StaffManage_OBJECTS = \
"CMakeFiles/StaffManage.dir/workerManager.cpp.o" \
"CMakeFiles/StaffManage.dir/main.cpp.o" \
"CMakeFiles/StaffManage.dir/worker.cpp.o" \
"CMakeFiles/StaffManage.dir/employee.cpp.o" \
"CMakeFiles/StaffManage.dir/manager.cpp.o" \
"CMakeFiles/StaffManage.dir/boss.cpp.o"

# External object files for target StaffManage
StaffManage_EXTERNAL_OBJECTS =

StaffManage: CMakeFiles/StaffManage.dir/workerManager.cpp.o
StaffManage: CMakeFiles/StaffManage.dir/main.cpp.o
StaffManage: CMakeFiles/StaffManage.dir/worker.cpp.o
StaffManage: CMakeFiles/StaffManage.dir/employee.cpp.o
StaffManage: CMakeFiles/StaffManage.dir/manager.cpp.o
StaffManage: CMakeFiles/StaffManage.dir/boss.cpp.o
StaffManage: CMakeFiles/StaffManage.dir/build.make
StaffManage: CMakeFiles/StaffManage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable StaffManage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StaffManage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaffManage.dir/build: StaffManage
.PHONY : CMakeFiles/StaffManage.dir/build

CMakeFiles/StaffManage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StaffManage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StaffManage.dir/clean

CMakeFiles/StaffManage.dir/depend:
	cd /Users/henry/CLionProjects/StaffManage/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/henry/CLionProjects/StaffManage /Users/henry/CLionProjects/StaffManage /Users/henry/CLionProjects/StaffManage/cmake-build-debug /Users/henry/CLionProjects/StaffManage/cmake-build-debug /Users/henry/CLionProjects/StaffManage/cmake-build-debug/CMakeFiles/StaffManage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StaffManage.dir/depend

