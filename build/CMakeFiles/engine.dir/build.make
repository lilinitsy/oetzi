# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/lappytoppy/Desktop/otzi-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lappytoppy/Desktop/otzi-engine/build

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/src/AABB.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/AABB.cpp.o: ../src/AABB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/src/AABB.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/AABB.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/AABB.cpp

CMakeFiles/engine.dir/src/AABB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/AABB.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/AABB.cpp > CMakeFiles/engine.dir/src/AABB.cpp.i

CMakeFiles/engine.dir/src/AABB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/AABB.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/AABB.cpp -o CMakeFiles/engine.dir/src/AABB.cpp.s

CMakeFiles/engine.dir/src/AABB.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/AABB.cpp.o.requires

CMakeFiles/engine.dir/src/AABB.cpp.o.provides: CMakeFiles/engine.dir/src/AABB.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/AABB.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/AABB.cpp.o.provides

CMakeFiles/engine.dir/src/AABB.cpp.o.provides.build: CMakeFiles/engine.dir/src/AABB.cpp.o


CMakeFiles/engine.dir/src/GameManager.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/GameManager.cpp.o: ../src/GameManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/src/GameManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/GameManager.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/GameManager.cpp

CMakeFiles/engine.dir/src/GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/GameManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/GameManager.cpp > CMakeFiles/engine.dir/src/GameManager.cpp.i

CMakeFiles/engine.dir/src/GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/GameManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/GameManager.cpp -o CMakeFiles/engine.dir/src/GameManager.cpp.s

CMakeFiles/engine.dir/src/GameManager.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/GameManager.cpp.o.requires

CMakeFiles/engine.dir/src/GameManager.cpp.o.provides: CMakeFiles/engine.dir/src/GameManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/GameManager.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/GameManager.cpp.o.provides

CMakeFiles/engine.dir/src/GameManager.cpp.o.provides.build: CMakeFiles/engine.dir/src/GameManager.cpp.o


CMakeFiles/engine.dir/src/Mesh.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Mesh.cpp.o: ../src/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/src/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Mesh.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/Mesh.cpp

CMakeFiles/engine.dir/src/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/Mesh.cpp > CMakeFiles/engine.dir/src/Mesh.cpp.i

CMakeFiles/engine.dir/src/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/Mesh.cpp -o CMakeFiles/engine.dir/src/Mesh.cpp.s

CMakeFiles/engine.dir/src/Mesh.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/Mesh.cpp.o.requires

CMakeFiles/engine.dir/src/Mesh.cpp.o.provides: CMakeFiles/engine.dir/src/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/Mesh.cpp.o.provides

CMakeFiles/engine.dir/src/Mesh.cpp.o.provides.build: CMakeFiles/engine.dir/src/Mesh.cpp.o


CMakeFiles/engine.dir/src/Model.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/src/Model.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Model.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/Model.cpp

CMakeFiles/engine.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/Model.cpp > CMakeFiles/engine.dir/src/Model.cpp.i

CMakeFiles/engine.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/Model.cpp -o CMakeFiles/engine.dir/src/Model.cpp.s

CMakeFiles/engine.dir/src/Model.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/Model.cpp.o.requires

CMakeFiles/engine.dir/src/Model.cpp.o.provides: CMakeFiles/engine.dir/src/Model.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/Model.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/Model.cpp.o.provides

CMakeFiles/engine.dir/src/Model.cpp.o.provides.build: CMakeFiles/engine.dir/src/Model.cpp.o


CMakeFiles/engine.dir/src/ModelInstance.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/ModelInstance.cpp.o: ../src/ModelInstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/src/ModelInstance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/ModelInstance.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/ModelInstance.cpp

CMakeFiles/engine.dir/src/ModelInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/ModelInstance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/ModelInstance.cpp > CMakeFiles/engine.dir/src/ModelInstance.cpp.i

CMakeFiles/engine.dir/src/ModelInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/ModelInstance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/ModelInstance.cpp -o CMakeFiles/engine.dir/src/ModelInstance.cpp.s

CMakeFiles/engine.dir/src/ModelInstance.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/ModelInstance.cpp.o.requires

CMakeFiles/engine.dir/src/ModelInstance.cpp.o.provides: CMakeFiles/engine.dir/src/ModelInstance.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/ModelInstance.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/ModelInstance.cpp.o.provides

CMakeFiles/engine.dir/src/ModelInstance.cpp.o.provides.build: CMakeFiles/engine.dir/src/ModelInstance.cpp.o


CMakeFiles/engine.dir/src/Octree.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/Octree.cpp.o: ../src/Octree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/src/Octree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/Octree.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/Octree.cpp

CMakeFiles/engine.dir/src/Octree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/Octree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/Octree.cpp > CMakeFiles/engine.dir/src/Octree.cpp.i

CMakeFiles/engine.dir/src/Octree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/Octree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/Octree.cpp -o CMakeFiles/engine.dir/src/Octree.cpp.s

CMakeFiles/engine.dir/src/Octree.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/Octree.cpp.o.requires

CMakeFiles/engine.dir/src/Octree.cpp.o.provides: CMakeFiles/engine.dir/src/Octree.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/Octree.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/Octree.cpp.o.provides

CMakeFiles/engine.dir/src/Octree.cpp.o.provides.build: CMakeFiles/engine.dir/src/Octree.cpp.o


CMakeFiles/engine.dir/src/main.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/engine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/main.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/src/main.cpp

CMakeFiles/engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/src/main.cpp > CMakeFiles/engine.dir/src/main.cpp.i

CMakeFiles/engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/src/main.cpp -o CMakeFiles/engine.dir/src/main.cpp.s

CMakeFiles/engine.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/src/main.cpp.o.requires

CMakeFiles/engine.dir/src/main.cpp.o.provides: CMakeFiles/engine.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/src/main.cpp.o.provides

CMakeFiles/engine.dir/src/main.cpp.o.provides.build: CMakeFiles/engine.dir/src/main.cpp.o


CMakeFiles/engine.dir/external/loguru.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/external/loguru.cpp.o: ../external/loguru.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/engine.dir/external/loguru.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/external/loguru.cpp.o -c /home/lappytoppy/Desktop/otzi-engine/external/loguru.cpp

CMakeFiles/engine.dir/external/loguru.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/external/loguru.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lappytoppy/Desktop/otzi-engine/external/loguru.cpp > CMakeFiles/engine.dir/external/loguru.cpp.i

CMakeFiles/engine.dir/external/loguru.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/external/loguru.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lappytoppy/Desktop/otzi-engine/external/loguru.cpp -o CMakeFiles/engine.dir/external/loguru.cpp.s

CMakeFiles/engine.dir/external/loguru.cpp.o.requires:

.PHONY : CMakeFiles/engine.dir/external/loguru.cpp.o.requires

CMakeFiles/engine.dir/external/loguru.cpp.o.provides: CMakeFiles/engine.dir/external/loguru.cpp.o.requires
	$(MAKE) -f CMakeFiles/engine.dir/build.make CMakeFiles/engine.dir/external/loguru.cpp.o.provides.build
.PHONY : CMakeFiles/engine.dir/external/loguru.cpp.o.provides

CMakeFiles/engine.dir/external/loguru.cpp.o.provides.build: CMakeFiles/engine.dir/external/loguru.cpp.o


# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/src/AABB.cpp.o" \
"CMakeFiles/engine.dir/src/GameManager.cpp.o" \
"CMakeFiles/engine.dir/src/Mesh.cpp.o" \
"CMakeFiles/engine.dir/src/Model.cpp.o" \
"CMakeFiles/engine.dir/src/ModelInstance.cpp.o" \
"CMakeFiles/engine.dir/src/Octree.cpp.o" \
"CMakeFiles/engine.dir/src/main.cpp.o" \
"CMakeFiles/engine.dir/external/loguru.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

../programs/engine: CMakeFiles/engine.dir/src/AABB.cpp.o
../programs/engine: CMakeFiles/engine.dir/src/GameManager.cpp.o
../programs/engine: CMakeFiles/engine.dir/src/Mesh.cpp.o
../programs/engine: CMakeFiles/engine.dir/src/Model.cpp.o
../programs/engine: CMakeFiles/engine.dir/src/ModelInstance.cpp.o
../programs/engine: CMakeFiles/engine.dir/src/Octree.cpp.o
../programs/engine: CMakeFiles/engine.dir/src/main.cpp.o
../programs/engine: CMakeFiles/engine.dir/external/loguru.cpp.o
../programs/engine: CMakeFiles/engine.dir/build.make
../programs/engine: /usr/lib/x86_64-linux-gnu/libGL.so
../programs/engine: /usr/lib/x86_64-linux-gnu/libGLU.so
../programs/engine: libglad.a
../programs/engine: libimgui.a
../programs/engine: libLua.a
../programs/engine: CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ../programs/engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: ../programs/engine

.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/AABB.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/GameManager.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/Mesh.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/Model.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/ModelInstance.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/Octree.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/src/main.cpp.o.requires
CMakeFiles/engine.dir/requires: CMakeFiles/engine.dir/external/loguru.cpp.o.requires

.PHONY : CMakeFiles/engine.dir/requires

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/lappytoppy/Desktop/otzi-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lappytoppy/Desktop/otzi-engine /home/lappytoppy/Desktop/otzi-engine /home/lappytoppy/Desktop/otzi-engine/build /home/lappytoppy/Desktop/otzi-engine/build /home/lappytoppy/Desktop/otzi-engine/build/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend
