#include <iostream>
#include "glad/glad.h"  // Needs to be included before GLFW
#include <GLFW/glfw3.h>

#include "shader.h"
#include "window.h"
#include "limb.h"
#include "camera.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main() {
    Window window{};
    try {
        window.init("Hello, world!", WINDOW_WIDTH, WINDOW_HEIGHT);
    } catch (const char* e) {
        std::cerr << e << std::endl;
        return 1;
    }

    Shader shader{};
    try {
        shader.create("shaders/default_vertex_shader.vert",
                      "shaders/default_fragment_shader.frag");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    Limb cube{};
    try {
        cube.load();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    Camera camera {{0.0, 0.0, 10.0},
                   {0.0, 0.0, 0.0},
                   (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT};

    Vector3 camPosition {0.0f, 0.0f, 10.0f};

    auto last_frame_time = static_cast<float>(glfwGetTime());
    while (window.shouldKeepOpen()) {
        auto current_frame_time = static_cast<float>(glfwGetTime());
        float delta_time = current_frame_time - last_frame_time;
        last_frame_time = current_frame_time;

        camPosition.x = std::cos(current_frame_time) * 10.0f;
        camera.setPos(camPosition);

        cube.rotateY(delta_time);

        window.clear();
        cube.draw(shader, camera.getProjectionViewMatrix());
        window.refresh();

        glfwPollEvents();
    }

    return 0;
}
