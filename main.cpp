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
        shader.create("../shaders/default_vertex_shader.vert",
                      "../shaders/default_fragment_shader.frag");
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

    Camera camera {{0.0, 0.0, 3.0},
                   {0.0, 0.0, 0.0},
                   (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT};

    //cube.rotateX(3.141f / 4.0f);

    auto lastFrameTime = static_cast<float>(glfwGetTime());
    while (window.shouldKeepOpen()) {
        auto currentFrameTime = static_cast<float>(glfwGetTime());
        float deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        //cube.rotateX(deltaTime);
        cube.rotateY(deltaTime);
        //cube.rotateZ(deltaTime);

        window.clear();
        cube.draw(shader, camera.getProjectionViewMatrix());
        window.refresh();

        glfwPollEvents();
    }

    return 0;
}
