#!/bin/bash

echo "Creating build directory"
mkdir build
cd build
echo "Removing old cmake files"
rm Makefile
rm CMakeCache.txt
rm cmake_install.cmake
rm project4
rm -rf CMakeFiles
echo "Running cmake and make"
cmake ../
make
