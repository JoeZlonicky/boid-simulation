#ifndef IK_DEMO_QUATERNION_H_
#define IK_DEMO_QUATERNION_H_

#include <cmath>
#include "vector_3.h"

// Implementation takes inspiration from
// 1) Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// 2) Godot Game Engine source code
struct Quaternion {
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float components[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    };

    Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Quaternion(const Vector3& v, float s) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = s;
    }

    float& operator[](int i);
    const float& operator[](int i) const;

    [[nodiscard]] Vector3 getAxis() const;
    [[nodiscard]] float getAngle() const;
};

inline float& Quaternion::operator[](int i) {
    return components[i];
}

inline const float& Quaternion::operator[](int i) const {
    return components[i];
}

Vector3 Quaternion::getAxis() const {
    // TODO: Implement
    return {};
}

float Quaternion::getAngle() const {
    return 2 * std::acos(w);
}

#endif
