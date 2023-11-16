#include "boid.h"

void Boid::updatePosition(float delta_seconds) {
    transform.move(velocity.x * delta_seconds, velocity.y * delta_seconds, velocity.z * delta_seconds);
}

bool Boid::operator==(Boid& other) const {
    return this == &other;
}

bool Boid::operator!=(Boid& other) const {
    return !(*this == other);
}
