#ifndef OPENGL_DEMO_BOID_H
#define OPENGL_DEMO_BOID_H

#include <vector>
#include "math/transform.h"

struct Boid {
    Transform transform;
    Vector3 velocity;

    void updatePosition(float delta_seconds);

    bool operator==(Boid& other) const;
    bool operator!=(Boid& other) const;
};

#endif //OPENGL_DEMO_BOID_H
