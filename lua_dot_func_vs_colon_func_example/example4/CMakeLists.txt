cmake_minimum_required(VERSION 3.10)
project(funct C)

find_package(Lua REQUIRED)

# If funct.c is in the src directory, change this to src/funct.c
add_library(funct MODULE funct.c)

# Set the output name of the library to funct.so without any prefix
set_target_properties(funct PROPERTIES PREFIX "")
set_target_properties(funct PROPERTIES OUTPUT_NAME "funct")

target_include_directories(funct PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(funct ${LUA_LIBRARIES})
