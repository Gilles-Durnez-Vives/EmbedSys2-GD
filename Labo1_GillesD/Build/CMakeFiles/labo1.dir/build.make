# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build

# Include any dependencies generated for this target.
include CMakeFiles/labo1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/labo1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/labo1.dir/flags.make

CMakeFiles/labo1.dir/main.c.o: CMakeFiles/labo1.dir/flags.make
CMakeFiles/labo1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/labo1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/labo1.dir/main.c.o -c /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/main.c

CMakeFiles/labo1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/labo1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/main.c > CMakeFiles/labo1.dir/main.c.i

CMakeFiles/labo1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/labo1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/main.c -o CMakeFiles/labo1.dir/main.c.s

# Object files for target labo1
labo1_OBJECTS = \
"CMakeFiles/labo1.dir/main.c.o"

# External object files for target labo1
labo1_EXTERNAL_OBJECTS =

labo1: CMakeFiles/labo1.dir/main.c.o
labo1: CMakeFiles/labo1.dir/build.make
labo1: CMakeFiles/labo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable labo1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/labo1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/labo1.dir/build: labo1

.PHONY : CMakeFiles/labo1.dir/build

CMakeFiles/labo1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/labo1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/labo1.dir/clean

CMakeFiles/labo1.dir/depend:
	cd /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build /home/pi/School/Embed/EmbedSys2-GD/Labo1_GillesD/Build/CMakeFiles/labo1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/labo1.dir/depend

