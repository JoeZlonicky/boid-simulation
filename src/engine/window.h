#ifndef IK_DEMO_WINDOW_H
#define IK_DEMO_WINDOW_H

#include <string>

class GLFWwindow;

class Window {
public:
    ~Window();
    void init(const std::string & title, int width, int height);
    void clear() ;
    void refresh() const;

    void resize(int width, int height);

    [[nodiscard]] bool shouldKeepOpen() const;
    [[nodiscard]] int getWidth() const { return width_; };
    [[nodiscard]] int getHeight() const { return height_; };

private:
    GLFWwindow* glfw_window_;
    int width_;
    int height_;
};


#endif
