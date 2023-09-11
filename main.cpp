#include <iostream>
#include <cmath>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "Shader.h"

const char* WINDOW_TITLE = "Sim Engine";
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr bool WIREFRAME_MODE = false;
constexpr float CLEAR_COLOR[] = {0.2f, 0.3f, 0.3f, 1.0f};

const char* vertexShaderPath = "../shaders/VertexShader.vert";
const char* fragmentShaderPath = "../shaders/FragmentShader.frag";

void framebuffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput([[maybe_unused]] GLFWwindow* window) { }

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }
    glViewport(0, 0, 1280, 720);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader {vertexShaderPath, fragmentShaderPath};
    if (!shader.wasCompiledSuccessfully()) {
        glfwTerminate();
        return -1;
    }

    float vertices[] = {
            0.5f,  0.5f, 0.0f,  // Top right
            0.5f, -0.5f, 0.0f,  // Bottom right
            -0.5f, -0.5f, 0.0f,  // Bottom left
            -0.5f,  0.5f, 0.0f   // Top left
    };
    unsigned int indices[] = {
            0, 1, 3,  // First Triangle
            1, 2, 3   // Second Triangle
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    if (WIREFRAME_MODE) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(CLEAR_COLOR[0], CLEAR_COLOR[1], CLEAR_COLOR[2], CLEAR_COLOR[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.activate();
        double time = glfwGetTime();
        double greenValue = sin(time) / 2.0 + 0.5;
        shader.setUniform("color", 0.0f, greenValue, 0.0f, 1.0f);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    shader.~Shader();  // Needs to be cleaned up before GL context is terminated
    glfwTerminate();
    return 0;
}
