#ifndef BOID_SIMULATION_BOID_H
#define BOID_SIMULATION_BOID_H

#include <vector>
#include "math/transform.h"

struct Boid {
    Transform transform;
    Vector3 velocity;

    void updatePosition(float delta_seconds);
    void updateRotation();

    bool operator==(Boid& other) const;
    bool operator!=(Boid& other) const;
};

#endif //BOID_SIMULATION_BOID_H
