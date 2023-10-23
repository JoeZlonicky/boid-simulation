#ifndef IK_DEMO_DRAWING_H
#define IK_DEMO_DRAWING_H

#include <vector>

#include "limb.h"
#include "camera.h"

namespace drawing {
    void init();
    void clear();
    void drawLimbs(std::vector<Limb>& limbs, Shader& shader, Camera& camera);
}

#endif //IK_DEMO_DRAWING_H
