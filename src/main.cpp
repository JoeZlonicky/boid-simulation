#include "glad/glad.h"  // Needs to be included before GLFW
#include <GLFW/glfw3.h>
#include <memory>

#include "engine/camera.h"
#include "sim/boid_simulation.h"
#include "engine/window.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 800;

int main() {
    Window window {"Boid Simulation", WINDOW_WIDTH, WINDOW_HEIGHT};

    Camera camera {};
    window.setCamera(&camera);

    std::unique_ptr<Simulation> demo = std::make_unique<BoidSimulation>(&camera);

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
