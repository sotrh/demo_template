# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/benjamin/bin/clion-2017.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/benjamin/bin/clion-2017.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benjamin/CLionProjects/demo_template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benjamin/CLionProjects/demo_template/cmake-build-debug

# Include any dependencies generated for this target.
include lib/glfw/examples/CMakeFiles/simple.dir/depend.make

# Include the progress variables for this target.
include lib/glfw/examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw/examples/CMakeFiles/simple.dir/flags.make

lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o: lib/glfw/examples/CMakeFiles/simple.dir/flags.make
lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o: ../lib/glfw/examples/simple.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benjamin/CLionProjects/demo_template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple.dir/simple.c.o   -c /home/benjamin/CLionProjects/demo_template/lib/glfw/examples/simple.c

lib/glfw/examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/benjamin/CLionProjects/demo_template/lib/glfw/examples/simple.c > CMakeFiles/simple.dir/simple.c.i

lib/glfw/examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/benjamin/CLionProjects/demo_template/lib/glfw/examples/simple.c -o CMakeFiles/simple.dir/simple.c.s

lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.requires:

.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.requires

lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.provides: lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.requires
	$(MAKE) -f lib/glfw/examples/CMakeFiles/simple.dir/build.make lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.provides.build
.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.provides

lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.provides.build: lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o


lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o: lib/glfw/examples/CMakeFiles/simple.dir/flags.make
lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o: ../lib/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benjamin/CLionProjects/demo_template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple.dir/__/deps/glad.c.o   -c /home/benjamin/CLionProjects/demo_template/lib/glfw/deps/glad.c

lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/__/deps/glad.c.i"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/benjamin/CLionProjects/demo_template/lib/glfw/deps/glad.c > CMakeFiles/simple.dir/__/deps/glad.c.i

lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/__/deps/glad.c.s"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/benjamin/CLionProjects/demo_template/lib/glfw/deps/glad.c -o CMakeFiles/simple.dir/__/deps/glad.c.s

lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.requires:

.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.requires

lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.provides: lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.requires
	$(MAKE) -f lib/glfw/examples/CMakeFiles/simple.dir/build.make lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.provides.build
.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.provides

lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.provides.build: lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o


# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.o" \
"CMakeFiles/simple.dir/__/deps/glad.c.o"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

lib/glfw/examples/simple: lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o
lib/glfw/examples/simple: lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o
lib/glfw/examples/simple: lib/glfw/examples/CMakeFiles/simple.dir/build.make
lib/glfw/examples/simple: lib/glfw/src/libglfw3.a
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/libm.so
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/librt.so
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/libm.so
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/libX11.so
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/libXrandr.so
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/libXinerama.so
lib/glfw/examples/simple: /usr/lib/x86_64-linux-gnu/libXcursor.so
lib/glfw/examples/simple: lib/glfw/examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benjamin/CLionProjects/demo_template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable simple"
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw/examples/CMakeFiles/simple.dir/build: lib/glfw/examples/simple

.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/build

lib/glfw/examples/CMakeFiles/simple.dir/requires: lib/glfw/examples/CMakeFiles/simple.dir/simple.c.o.requires
lib/glfw/examples/CMakeFiles/simple.dir/requires: lib/glfw/examples/CMakeFiles/simple.dir/__/deps/glad.c.o.requires

.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/requires

lib/glfw/examples/CMakeFiles/simple.dir/clean:
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/simple.dir/cmake_clean.cmake
.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/clean

lib/glfw/examples/CMakeFiles/simple.dir/depend:
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benjamin/CLionProjects/demo_template /home/benjamin/CLionProjects/demo_template/lib/glfw/examples /home/benjamin/CLionProjects/demo_template/cmake-build-debug /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/examples/CMakeFiles/simple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/examples/CMakeFiles/simple.dir/depend

