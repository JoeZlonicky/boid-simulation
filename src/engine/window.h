#ifndef IK_DEMO_WINDOW_H
#define IK_DEMO_WINDOW_H

#include <string>
#include "camera.h"

class GLFWwindow;

class Window {
public:
    ~Window();
    void init(const std::string & title, int width, int height);
    void clear() ;
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
