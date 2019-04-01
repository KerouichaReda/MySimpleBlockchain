@echo off
mkdir build
cd build
cmake ..\src\ "-DCMAKE_TOOLCHAIN_FILE=D:\Documents\VisualStudio\Libraries\vcpkg\vcpkg\scripts\buildsystems\vcpkg.cmake"
