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
CMAKE_SOURCE_DIR = /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build

# Include any dependencies generated for this target.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/depend.make

# Include the progress variables for this target.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/progress.make

# Include the compile flags for this target's objects.
include Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o: ../Project_SDL_Part1_base/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/main.cpp.o -c /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base/main.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/main.cpp.i"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base/main.cpp > CMakeFiles/SDL_part1.dir/main.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/main.cpp.s"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base/main.cpp -o CMakeFiles/SDL_part1.dir/main.cpp.s

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/flags.make
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: ../Project_SDL_Part1_base/Project_SDL1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o -c /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base/Project_SDL1.cpp

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base/Project_SDL1.cpp > CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base/Project_SDL1.cpp -o CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s

# Object files for target SDL_part1
SDL_part1_OBJECTS = \
"CMakeFiles/SDL_part1.dir/main.cpp.o" \
"CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o"

# External object files for target SDL_part1
SDL_part1_EXTERNAL_OBJECTS =

Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/main.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/build.make
Project_SDL_Part1_base/SDL_part1: Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SDL_part1"
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_part1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/build: Project_SDL_Part1_base/SDL_part1

.PHONY : Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/build

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/clean:
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base && $(CMAKE_COMMAND) -P CMakeFiles/SDL_part1.dir/cmake_clean.cmake
.PHONY : Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/clean

Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/depend:
	cd /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/Project_SDL_Part1_base /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base /home/adrienne/Bureau/Etudes/C++/SDL_Project/Base_Project/build/Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Project_SDL_Part1_base/CMakeFiles/SDL_part1.dir/depend

