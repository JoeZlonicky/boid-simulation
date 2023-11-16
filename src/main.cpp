#include <iostream>
#include "glad/glad.h"  // Needs to be included before GLFW
#include <GLFW/glfw3.h>
#include <memory>

#include "engine/camera.h"
#include "demo/boids_demo.h"
#include "engine/shader.h"
#include "engine/window.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main() {
    Window window {"OpenGL BoidsDemo", WINDOW_WIDTH, WINDOW_HEIGHT};

    Camera camera {};
    window.setCamera(&camera);

    std::unique_ptr<Demo> demo = std::make_unique<BoidsDemo>(&camera);

    float last_time_seconds = 0;
    while (window.shouldKeepOpen()) {
        auto current_time_seconds = static_cast<float>(glfwGetTime());
        float delta_time_seconds = current_time_seconds - last_time_seconds;
        last_time_seconds = current_time_seconds;

        demo->update(delta_time_seconds);
        demo->render();

        window.refresh();
        glfwPollEvents();
    }

    return 0;
}
