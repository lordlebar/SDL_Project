# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/corentin/Desktop/SDL_Project/test_SDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/corentin/Desktop/SDL_Project/test_SDL/build

# Include any dependencies generated for this target.
include SDL_Test/CMakeFiles/SDLTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include SDL_Test/CMakeFiles/SDLTest.dir/compiler_depend.make

# Include the progress variables for this target.
include SDL_Test/CMakeFiles/SDLTest.dir/progress.make

# Include the compile flags for this target's objects.
include SDL_Test/CMakeFiles/SDLTest.dir/flags.make

SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.o: SDL_Test/CMakeFiles/SDLTest.dir/flags.make
SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.o: /Users/corentin/Desktop/SDL_Project/test_SDL/SDL_Test/Main.cpp
SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.o: SDL_Test/CMakeFiles/SDLTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/corentin/Desktop/SDL_Project/test_SDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.o"
	cd /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.o -MF CMakeFiles/SDLTest.dir/Main.cpp.o.d -o CMakeFiles/SDLTest.dir/Main.cpp.o -c /Users/corentin/Desktop/SDL_Project/test_SDL/SDL_Test/Main.cpp

SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SDLTest.dir/Main.cpp.i"
	cd /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/corentin/Desktop/SDL_Project/test_SDL/SDL_Test/Main.cpp > CMakeFiles/SDLTest.dir/Main.cpp.i

SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SDLTest.dir/Main.cpp.s"
	cd /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/corentin/Desktop/SDL_Project/test_SDL/SDL_Test/Main.cpp -o CMakeFiles/SDLTest.dir/Main.cpp.s

# Object files for target SDLTest
SDLTest_OBJECTS = \
"CMakeFiles/SDLTest.dir/Main.cpp.o"

# External object files for target SDLTest
SDLTest_EXTERNAL_OBJECTS =

SDL_Test/SDLTest: SDL_Test/CMakeFiles/SDLTest.dir/Main.cpp.o
SDL_Test/SDLTest: SDL_Test/CMakeFiles/SDLTest.dir/build.make
SDL_Test/SDLTest: /usr/local/lib/libSDL2.dylib
SDL_Test/SDLTest: SDL_Test/CMakeFiles/SDLTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/corentin/Desktop/SDL_Project/test_SDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SDLTest"
	cd /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDLTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
SDL_Test/CMakeFiles/SDLTest.dir/build: SDL_Test/SDLTest
.PHONY : SDL_Test/CMakeFiles/SDLTest.dir/build

SDL_Test/CMakeFiles/SDLTest.dir/clean:
	cd /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test && $(CMAKE_COMMAND) -P CMakeFiles/SDLTest.dir/cmake_clean.cmake
.PHONY : SDL_Test/CMakeFiles/SDLTest.dir/clean

SDL_Test/CMakeFiles/SDLTest.dir/depend:
	cd /Users/corentin/Desktop/SDL_Project/test_SDL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/corentin/Desktop/SDL_Project/test_SDL /Users/corentin/Desktop/SDL_Project/test_SDL/SDL_Test /Users/corentin/Desktop/SDL_Project/test_SDL/build /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test /Users/corentin/Desktop/SDL_Project/test_SDL/build/SDL_Test/CMakeFiles/SDLTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : SDL_Test/CMakeFiles/SDLTest.dir/depend

