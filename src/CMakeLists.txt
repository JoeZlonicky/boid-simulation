include_directories("../external/glm")
include_directories("../external/glad/include")

add_executable(ik-demo
        "main.cpp"
        "shader.cpp"
        "shader.h"
        "window.cpp"
        "window.h"
        "limb.cpp"
        "limb.h"
        "camera.cpp"
        "camera.h"
        "vector3.h"
        "quaternion.h"
        "../external/glad/src/glad.c"
)

target_link_libraries(ik-demo glfw OpenGL)