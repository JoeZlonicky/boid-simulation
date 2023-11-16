#ifndef OPENGL_DEMO_BOID_H
#define OPENGL_DEMO_BOID_H

#include "math/transform.h"

struct Boid {
    Transform transform;
    Vector3 velocity;

    void update(float delta_seconds) {
        transform.move(velocity.x * delta_seconds, velocity.y * delta_seconds, velocity.z * delta_seconds);
    }
};

#endif //OPENGL_DEMO_BOID_H
