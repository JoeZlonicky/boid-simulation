#ifndef OPENGL_DEMO_DEMO_H
#define OPENGL_DEMO_DEMO_H

#include <vector>
#include "engine/cube.h"
#include "engine/camera.h"
#include "engine/shader.h"


class Demo {
public:
    Demo(Shader* shader, Camera* camera);
    void render();
    void update(float time);

private:
    void drawCube(Cube& cube);

    Shader* shader_;
    Camera* camera_;

    Cube top_cube_ {};
    Cube right_cube_ {};
    Cube corner_cube {};
    Cube center_cube_ {};
};

#endif
