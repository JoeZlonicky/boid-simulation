#include "window.h"

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

Window::~Window() {
    glfwTerminate();
}


void Window::init(const std::string & title, const int width, const int height) {
    width_ = width;
    height_ = height;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  glfw_window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (glfw_window_ == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to load GLFW window");
    }
    glfwMakeContextCurrent(glfw_window_);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw std::runtime_error("Failed to load GLFW window");
    }

    glViewport(0, 0, width, height);
    glEnable(GL_DEPTH_TEST);

    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetScrollCallback(window, scrollCallback);
}

void Window::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::refresh() const {
    glfwSwapBuffers(glfw_window_);
}

bool Window::shouldKeepOpen() const {
    return glfwWindowShouldClose(glfw_window_) == false;
}