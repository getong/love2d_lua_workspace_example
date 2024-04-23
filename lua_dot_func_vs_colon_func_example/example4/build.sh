#!/bin/sh

# Create and enter the build directory
mkdir -p build
cd build || exit 1

# Configure the project and generate the compile commands in one go
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..

# Build the project
make

# Move compile_commands.json up one directory (change this if you have specific needs)
mv compile_commands.json ../../..
