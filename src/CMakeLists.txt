include_directories(../external/glad/include)

add_executable(ik-demo
        main.cpp
        limb.h
        limb.cpp
        ../external/glad/src/glad.c
        engine/shader.h
        engine/shader.cpp
        engine/window.h
        engine/window.cpp
        engine/camera.h
        engine/camera.cpp
        engine/transform.h
        engine/transform.cpp
        math/vector_3.h
        math/vector_3.cpp
        math/quaternion.h
        math/quaternion.cpp
        math/matrix_4.h
        math/vector_4.h
        math/vector_4.cpp
        math/matrix_4.cpp
)

target_link_libraries(ik-demo glfw ${OPENGL_gl_LIBRARY})