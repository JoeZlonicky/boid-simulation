include_directories(../external/glad/include)
include_directories(.)

set (ENGINE_SOURCE_FILES
        engine/camera.cpp
        engine/demo.cpp
        engine/cube.cpp
        engine/shader.cpp
        engine/window.cpp
        engine/drawing.cpp
)

set (MATH_SOURCE_FILES
        math/matrix_3.cpp
        math/matrix_4.cpp
        math/transform.cpp
        math/quaternion.cpp
        math/vector_3.cpp
        math/vector_4.cpp
)

add_executable(opengl-demo
        main.cpp
        ../external/glad/src/glad.c
        ${ENGINE_SOURCE_FILES}
        ${MATH_SOURCE_FILES}
)

target_link_libraries(opengl-demo glfw ${OPENGL_gl_LIBRARY})