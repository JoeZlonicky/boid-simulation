#include <iostream>
#include <vector>
#include "glad/glad.h"  // Needs to be included before GLFW
#include <GLFW/glfw3.h>

#include "engine/shader.h"
#include "engine/window.h"
#include "engine/limb.h"
#include "engine/camera.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

void performInverseKinematics(std::vector<Limb>& limbs, float time) {
    if (limbs.empty()) {
        return;
    }

    const Limb* previous = &limbs.at(0);
    const float rotation_increment = std::sin(time * 2.f) * 15.f;
    float rotation = rotation_increment;
    for (int i = 1; i < limbs.size(); ++i) {
        Limb& current = limbs.at(i);
        current.getTransform().setPos(previous->getEnd());
        current.getTransform().setRotation({{0, 0, 1}, rotation});
        previous = &current;
        rotation += rotation_increment;
    }
}

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

    auto last_frame_time = static_cast<float>(glfwGetTime());
    while (window.shouldKeepOpen()) {
        auto current_frame_time = static_cast<float>(glfwGetTime());
        float delta_time = current_frame_time - last_frame_time;
        last_frame_time = current_frame_time;

        performInverseKinematics(limbs, current_frame_time);

        window.clear();
        for (Limb& limb : limbs) {
            limb.draw(shader, camera.getProjectionViewMatrix());
        }

        window.refresh();

        glfwPollEvents();
    }

    return 0;
}
