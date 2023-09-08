#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>

static constexpr const char* WINDOW_TITLE = "Sim Engine";
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
constexpr bool WIREFRAME_MODE = true;
constexpr float CLEAR_COLOR[] = {0.2f, 0.3f, 0.3f, 1.0f};

const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
const char* fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";

void framebuffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput([[maybe_unused]] GLFWwindow* window) { }

int createShader(GLenum shaderType, const char* shaderSource, unsigned int& outShader) {
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    const int infoLogLength = 512;
    int success;
    char infoLog[infoLogLength];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, infoLogLength, nullptr, infoLog);
        std::cerr << "Failed to compile shader\n" << infoLog << std::endl;
        return -1;
    }

    outShader = shader;
    return 0;
}

// Will delete vertex and fragment shader once linked (as they are no longer needed)
int createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader, unsigned int& outProgram) {
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    const int infoLogLength = 512;
    int success;
    char infoLog[infoLogLength];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, infoLogLength, nullptr, infoLog);
        std::cerr << "Failed to link shader program\n" << infoLog << std::endl;
        return -1;
    }

    outProgram = shaderProgram;
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return 0;
}

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

    unsigned int vertexShader;
    if (createShader(GL_VERTEX_SHADER, vertexShaderSource, vertexShader) == -1) {
        glfwTerminate();
        return -1;
    }

    unsigned int fragmentShader;
    if (createShader(GL_FRAGMENT_SHADER, fragmentShaderSource, fragmentShader) == -1) {
        glfwTerminate();
        return -1;
    }

    unsigned int shaderProgram;
    if (createShaderProgram(vertexShader, fragmentShader, shaderProgram) == -1) {
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

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}
