cmake_minimum_required(VERSION 3.26)
project(ik-demo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
add_subdirectory("external/glfw")

include_directories("external/glm")
include_directories("external/glad/include")

add_executable(ik-demo main.cpp
        "external/glad/src/glad.c"
        shader.cpp
        shader.h
        window.cpp
        window.h
        limb.cpp
        limb.h
        camera.cpp
        camera.h
        math/vector3.h
        math/vector3.cpp
        math/quaternion.h
)

target_link_libraries(ik-demo glfw OpenGL)