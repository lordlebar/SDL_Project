# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL_part1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL_part1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL_part1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL_part1.dir/flags.make

CMakeFiles/SDL_part1.dir/main.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/main.cpp.o: ../main.cpp
CMakeFiles/SDL_part1.dir/main.cpp.o: CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL_part1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL_part1.dir/main.cpp.o -MF CMakeFiles/SDL_part1.dir/main.cpp.o.d -o CMakeFiles/SDL_part1.dir/main.cpp.o -c /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/main.cpp

CMakeFiles/SDL_part1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/main.cpp > CMakeFiles/SDL_part1.dir/main.cpp.i

CMakeFiles/SDL_part1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/main.cpp -o CMakeFiles/SDL_part1.dir/main.cpp.s

CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: CMakeFiles/SDL_part1.dir/flags.make
CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: ../Project_SDL1.cpp
CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o: CMakeFiles/SDL_part1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o -MF CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o.d -o CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o -c /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/Project_SDL1.cpp

CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/Project_SDL1.cpp > CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.i

CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/Project_SDL1.cpp -o CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.s

# Object files for target SDL_part1
SDL_part1_OBJECTS = \
"CMakeFiles/SDL_part1.dir/main.cpp.o" \
"CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o"

# External object files for target SDL_part1
SDL_part1_EXTERNAL_OBJECTS =

SDL_part1: CMakeFiles/SDL_part1.dir/main.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/Project_SDL1.cpp.o
SDL_part1: CMakeFiles/SDL_part1.dir/build.make
SDL_part1: CMakeFiles/SDL_part1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SDL_part1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_part1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL_part1.dir/build: SDL_part1
.PHONY : CMakeFiles/SDL_part1.dir/build

CMakeFiles/SDL_part1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL_part1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL_part1.dir/clean

CMakeFiles/SDL_part1.dir/depend:
	cd /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build /home/corentin/Desktop/SDL_Project/Base_Project/Project_SDL/build/CMakeFiles/SDL_part1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL_part1.dir/depend

