#include "boid.h"

void Boid::updatePosition(float delta_seconds) {
    transform.move(velocity.x * delta_seconds, velocity.y * delta_seconds, velocity.z * delta_seconds);
}

void Boid::updateRotation() {
    // Set rotation to face velocity
    Vector3 unit_vector {1.f, 0.f, 0.f};
    Vector3 normalized_velocity = velocity.normalized();
    Vector3 cross = unit_vector.cross(normalized_velocity);
    Vector4 q_normalized = Vector4 {cross.x, cross.y, cross.z,
                                    1.f + unit_vector.dot(normalized_velocity)}.normalized();
    transform.setRotation({q_normalized.x, q_normalized.y, q_normalized.z, q_normalized.w});
}

bool Boid::operator==(Boid& other) const {
    return this == &other;
}

bool Boid::operator!=(Boid& other) const {
    return !(*this == other);
}