# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/rachel/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rachel/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rachel/CLionProjects/ass1_spl191

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rachel/CLionProjects/ass1_spl191/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ass1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ass1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ass1.dir/flags.make

CMakeFiles/ass1.dir/src/Customer.cpp.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/src/Customer.cpp.o: ../src/Customer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ass1.dir/src/Customer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass1.dir/src/Customer.cpp.o -c /home/rachel/CLionProjects/ass1_spl191/src/Customer.cpp

CMakeFiles/ass1.dir/src/Customer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/src/Customer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rachel/CLionProjects/ass1_spl191/src/Customer.cpp > CMakeFiles/ass1.dir/src/Customer.cpp.i

CMakeFiles/ass1.dir/src/Customer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/src/Customer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rachel/CLionProjects/ass1_spl191/src/Customer.cpp -o CMakeFiles/ass1.dir/src/Customer.cpp.s

CMakeFiles/ass1.dir/src/Restaurant.cpp.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/src/Restaurant.cpp.o: ../src/Restaurant.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ass1.dir/src/Restaurant.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass1.dir/src/Restaurant.cpp.o -c /home/rachel/CLionProjects/ass1_spl191/src/Restaurant.cpp

CMakeFiles/ass1.dir/src/Restaurant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/src/Restaurant.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rachel/CLionProjects/ass1_spl191/src/Restaurant.cpp > CMakeFiles/ass1.dir/src/Restaurant.cpp.i

CMakeFiles/ass1.dir/src/Restaurant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/src/Restaurant.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rachel/CLionProjects/ass1_spl191/src/Restaurant.cpp -o CMakeFiles/ass1.dir/src/Restaurant.cpp.s

CMakeFiles/ass1.dir/Main.cpp.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ass1.dir/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass1.dir/Main.cpp.o -c /home/rachel/CLionProjects/ass1_spl191/Main.cpp

CMakeFiles/ass1.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rachel/CLionProjects/ass1_spl191/Main.cpp > CMakeFiles/ass1.dir/Main.cpp.i

CMakeFiles/ass1.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rachel/CLionProjects/ass1_spl191/Main.cpp -o CMakeFiles/ass1.dir/Main.cpp.s

CMakeFiles/ass1.dir/src/Dish.cpp.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/src/Dish.cpp.o: ../src/Dish.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ass1.dir/src/Dish.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass1.dir/src/Dish.cpp.o -c /home/rachel/CLionProjects/ass1_spl191/src/Dish.cpp

CMakeFiles/ass1.dir/src/Dish.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/src/Dish.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rachel/CLionProjects/ass1_spl191/src/Dish.cpp > CMakeFiles/ass1.dir/src/Dish.cpp.i

CMakeFiles/ass1.dir/src/Dish.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/src/Dish.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rachel/CLionProjects/ass1_spl191/src/Dish.cpp -o CMakeFiles/ass1.dir/src/Dish.cpp.s

CMakeFiles/ass1.dir/src/Table.cpp.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/src/Table.cpp.o: ../src/Table.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ass1.dir/src/Table.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass1.dir/src/Table.cpp.o -c /home/rachel/CLionProjects/ass1_spl191/src/Table.cpp

CMakeFiles/ass1.dir/src/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/src/Table.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rachel/CLionProjects/ass1_spl191/src/Table.cpp > CMakeFiles/ass1.dir/src/Table.cpp.i

CMakeFiles/ass1.dir/src/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/src/Table.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rachel/CLionProjects/ass1_spl191/src/Table.cpp -o CMakeFiles/ass1.dir/src/Table.cpp.s

CMakeFiles/ass1.dir/src/Action.cpp.o: CMakeFiles/ass1.dir/flags.make
CMakeFiles/ass1.dir/src/Action.cpp.o: ../src/Action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ass1.dir/src/Action.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ass1.dir/src/Action.cpp.o -c /home/rachel/CLionProjects/ass1_spl191/src/Action.cpp

CMakeFiles/ass1.dir/src/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ass1.dir/src/Action.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rachel/CLionProjects/ass1_spl191/src/Action.cpp > CMakeFiles/ass1.dir/src/Action.cpp.i

CMakeFiles/ass1.dir/src/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ass1.dir/src/Action.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rachel/CLionProjects/ass1_spl191/src/Action.cpp -o CMakeFiles/ass1.dir/src/Action.cpp.s

# Object files for target ass1
ass1_OBJECTS = \
"CMakeFiles/ass1.dir/src/Customer.cpp.o" \
"CMakeFiles/ass1.dir/src/Restaurant.cpp.o" \
"CMakeFiles/ass1.dir/Main.cpp.o" \
"CMakeFiles/ass1.dir/src/Dish.cpp.o" \
"CMakeFiles/ass1.dir/src/Table.cpp.o" \
"CMakeFiles/ass1.dir/src/Action.cpp.o"

# External object files for target ass1
ass1_EXTERNAL_OBJECTS =

ass1: CMakeFiles/ass1.dir/src/Customer.cpp.o
ass1: CMakeFiles/ass1.dir/src/Restaurant.cpp.o
ass1: CMakeFiles/ass1.dir/Main.cpp.o
ass1: CMakeFiles/ass1.dir/src/Dish.cpp.o
ass1: CMakeFiles/ass1.dir/src/Table.cpp.o
ass1: CMakeFiles/ass1.dir/src/Action.cpp.o
ass1: CMakeFiles/ass1.dir/build.make
ass1: CMakeFiles/ass1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ass1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ass1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ass1.dir/build: ass1

.PHONY : CMakeFiles/ass1.dir/build

CMakeFiles/ass1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ass1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ass1.dir/clean

CMakeFiles/ass1.dir/depend:
	cd /home/rachel/CLionProjects/ass1_spl191/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rachel/CLionProjects/ass1_spl191 /home/rachel/CLionProjects/ass1_spl191 /home/rachel/CLionProjects/ass1_spl191/cmake-build-debug /home/rachel/CLionProjects/ass1_spl191/cmake-build-debug /home/rachel/CLionProjects/ass1_spl191/cmake-build-debug/CMakeFiles/ass1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ass1.dir/depend
