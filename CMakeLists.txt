cmake_minimum_required(VERSION 3.15)
project(TeaPot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w -lsfml-graphics -lsfml-window -lsfml-system")

# Statically link SFML
set(SFML_STATIC_LIBRARIES TRUE)
## In most cases better set in the CMake cache (Windows)
#set(SFML_DIR "./library/frameworks/SFML-2.5.1/lib/cmake/SFML")

add_executable(TeaPot main.cpp )