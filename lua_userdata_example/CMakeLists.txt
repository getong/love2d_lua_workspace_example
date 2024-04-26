cmake_minimum_required(VERSION 3.10)
project(lua_userdata VERSION 1.0.0 LANGUAGES C)

find_package(Lua REQUIRED)

# Find Lua libraries
find_library(LUA_LIBRARY NAMES lua5.4 lua54 lua PATHS /usr/local/lib /usr/lib)
if(NOT LUA_LIBRARY)
  message(FATAL_ERROR "Lua library not found")
endif()

# Include directories for Lua
include_directories(/usr/local/include/lua/)

# If funct.c is in the src directory, change this to src/main.c
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARY})