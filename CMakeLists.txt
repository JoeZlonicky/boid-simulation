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

add_executable(ik-demo
        "src/main.cpp"
        "src/shader.cpp"
        "src/shader.h"
        "src/window.cpp"
        "src/window.h"
        "src/limb.cpp"
        "src/limb.h"
        "src/camera.cpp"
        "src/camera.h"
        "src/math/vector3.h"
        "src/math/vector3.cpp"
        "src/math/quaternion.h"
        "external/glad/src/glad.c"
)

target_link_libraries(ik-demo glfw OpenGL)