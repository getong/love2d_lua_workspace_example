cmake_minimum_required(VERSION 3.10)
project(render_sdl VERSION 1.0.0 LANGUAGES C)

# Find packages
find_package(Lua REQUIRED)
find_package(SDL2 REQUIRED)

# Include directories for Lua and SDL2
include_directories(${LUA_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIRS})

# Add main executable
add_executable(${PROJECT_NAME} main.c)

# Linking libraries for Lua and SDL2
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARIES} ${SDL2_LIBRARIES})
