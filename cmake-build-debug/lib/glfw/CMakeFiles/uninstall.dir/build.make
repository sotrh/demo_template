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

# Utility rule file for uninstall.

# Include the progress variables for this target.
include lib/glfw/CMakeFiles/uninstall.dir/progress.make

lib/glfw/CMakeFiles/uninstall:
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw && /home/benjamin/bin/clion-2017.2/bin/cmake/bin/cmake -P /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/cmake_uninstall.cmake

uninstall: lib/glfw/CMakeFiles/uninstall
uninstall: lib/glfw/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
lib/glfw/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : lib/glfw/CMakeFiles/uninstall.dir/build

lib/glfw/CMakeFiles/uninstall.dir/clean:
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/clean

lib/glfw/CMakeFiles/uninstall.dir/depend:
	cd /home/benjamin/CLionProjects/demo_template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benjamin/CLionProjects/demo_template /home/benjamin/CLionProjects/demo_template/lib/glfw /home/benjamin/CLionProjects/demo_template/cmake-build-debug /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw /home/benjamin/CLionProjects/demo_template/cmake-build-debug/lib/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/depend

