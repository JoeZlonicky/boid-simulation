cmake_minimum_required(VERSION 3.26)
project(ik-demo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL)

include_directories("external/include")

add_executable(ik-demo main.cpp
        "external/src/glad.c"
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

target_link_libraries(ik-demo X11 "${CMAKE_SOURCE_DIR}/external/lib/GLFW/libglfw3.a")