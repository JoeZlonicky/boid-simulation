#ifndef OPENGL_DEMO_WINDOW_H
#define OPENGL_DEMO_WINDOW_H

#include <string>
#include "camera.h"

class GLFWwindow;

class Window {
public:
    Window() = default;
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void init(const std::string & title, int width, int height);
    void refresh() const;
    void resize(int width, int height);

    void setCamera(Camera* camera);

    [[nodiscard]] bool shouldKeepOpen() const;
    [[nodiscard]] int getWidth() const { return width_; };
    [[nodiscard]] int getHeight() const { return height_; };

private:
    GLFWwindow* glfw_window_ = nullptr;
    Camera* camera_ = nullptr;
    int width_ = 0;
    int height_ = 0;
};


#endif
