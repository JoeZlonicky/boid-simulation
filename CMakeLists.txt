cmake_minimum_required(VERSION 3.26)
project(sim_engine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL)
find_package(glfw3 3.3 REQUIRED)

include_directories("glad/include")

add_executable(sim_engine main.cpp
        Shader.cpp
        Shader.h
        "glad/src/glad.c")
target_link_libraries(sim_engine glfw)