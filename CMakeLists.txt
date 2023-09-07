cmake_minimum_required(VERSION 3.26)
project(sim_engine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL)
find_package(GLFW)

include_directories("glad/include")

add_executable(sim_engine main.cpp "glad/src/glad.c")