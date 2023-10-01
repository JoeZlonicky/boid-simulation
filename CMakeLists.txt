cmake_minimum_required(VERSION 3.26)
project(ik-demo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL)
find_package(glfw3 3.3 REQUIRED)

include_directories("external/include")

add_executable(ik-demo main.cpp
        "external/src/glad.c"
        "external/src/stb_image.cpp"
        shader.cpp
        shader.h
        window.cpp
        window.h
        limb.cpp
        limb.h
        camera.cpp
        camera.h
)

target_link_libraries(ik-demo glfw)