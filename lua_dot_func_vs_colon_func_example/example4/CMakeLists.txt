cmake_minimum_required(VERSION 3.10)
project(lua_funct C)

find_package(Lua REQUIRED)

# If funct.c is in the src directory, change this to src/funct.c
add_library(lua_funct MODULE funct.c)

target_include_directories(lua_funct PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(lua_funct ${LUA_LIBRARIES})
set_target_properties(lua_funct PROPERTIES PREFIX "lib")
