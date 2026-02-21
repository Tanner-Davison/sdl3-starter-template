cmake_minimum_required(VERSION 3.15)
project(sdl2-starter-template)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files — add your .cpp files here
set(SOURCES
    src/main.cpp
    src/window.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Include src for local headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link SDL3 via find_package (install SDL3 on your system first)
# Linux:   sudo apt install libsdl3-dev   (or build from source)
# macOS:   brew install sdl3
# Windows: set SDL3_DIR to your SDL3 cmake config folder
find_package(SDL3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
