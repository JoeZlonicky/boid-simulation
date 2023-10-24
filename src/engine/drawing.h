#ifndef OPENGL_DEMO_DRAWING_H
#define OPENGL_DEMO_DRAWING_H

#include <vector>

#include "cube.h"
#include "camera.h"

namespace drawing {
    void init();
    void clear();
    void drawCubes(std::vector<Cube>& cubes, Shader& shader, Camera& camera);
}

#endif
