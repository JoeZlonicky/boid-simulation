include_directories("../external/glad/include")

add_executable(ik-demo
        "main.cpp"
        "engine/shader.cpp"
        "engine/shader.h"
        "engine/window.cpp"
        "engine/window.h"
        "limb.cpp"
        "limb.h"
        "engine/camera.cpp"
        "engine/camera.h"
        "math/vector_3.h"
        "math/quaternion.h"
        "../external/glad/src/glad.c"
        math/matrix_4.h
        math/vector_4.h
        math/point_3.h
        engine/transform.h
)

target_link_libraries(ik-demo glfw ${OPENGL_gl_LIBRARY})