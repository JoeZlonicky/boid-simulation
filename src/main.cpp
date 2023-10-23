#include <iostream>
#include <vector>
#include "glad/glad.h"  // Needs to be included before GLFW
#include <GLFW/glfw3.h>

#include "engine/camera.h"
#include "engine/drawing.h"
#include "engine/inverse_kinematics.h"
#include "engine/limb.h"
#include "engine/shader.h"
#include "engine/window.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

int main() {
    Window window {};
    try {
        window.init("Hello, world!", WINDOW_WIDTH, WINDOW_HEIGHT);
    } catch (const char* e) {
        std::cerr << e << std::endl;
        return 1;
    }

    Shader shader {};
    try {
        shader.create("shaders/default_vertex_shader.vert",
                      "shaders/default_fragment_shader.frag");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::vector<Limb> limbs {5};

    Camera camera {{5.f, 5.f, 10.f},
                   {0.f, 0.f, 0.f},
                   (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT};
    window.setCamera(&camera);

    drawing::init();
    auto last_frame_time = static_cast<float>(glfwGetTime());
    while (window.shouldKeepOpen()) {
        auto current_frame_time = static_cast<float>(glfwGetTime());
        float delta_time = current_frame_time - last_frame_time;
        last_frame_time = current_frame_time;

        inverse_kinematics::perform(limbs, current_frame_time);

        drawing::clear();
        drawing::drawLimbs(limbs, shader, camera);

        window.refresh();
        glfwPollEvents();
    }

    return 0;
}
