include_directories(../external/glad/include)
include_directories(.)

set (ENGINE_SOURCE_FILES
        engine/camera.cpp
        engine/limb.cpp
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

add_executable(ik-demo
        main.cpp
        ../external/glad/src/glad.c
        ${ENGINE_SOURCE_FILES}
        ${MATH_SOURCE_FILES}
)

target_link_libraries(ik-demo glfw ${OPENGL_gl_LIBRARY})