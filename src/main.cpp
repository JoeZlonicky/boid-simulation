#include <iostream>
#include "glad/glad.h"  // Needs to be included before GLFW
#include <GLFW/glfw3.h>

#include "engine/camera.h"
#include "demo/demo.h"
#include "engine/shader.h"
#include "engine/window.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main() {
    Window window {"OpenGL Demo", WINDOW_WIDTH, WINDOW_HEIGHT};
    
    Shader shader {"shaders/default_vertex_shader.vert",
                   "shaders/default_fragment_shader.frag"};

    Camera camera {{0.f, 1.f, 20.f},
                   {0.f, 0.f, 0.f},
                   (float) WINDOW_WIDTH / (float) WINDOW_HEIGHT};
    window.setCamera(&camera);

    Demo demo {&shader, &camera};

    while (window.shouldKeepOpen()) {
        auto current_time = static_cast<float>(glfwGetTime());

        demo.update(current_time);
        demo.render();

        window.refresh();
        glfwPollEvents();
    }

    return 0;
}
