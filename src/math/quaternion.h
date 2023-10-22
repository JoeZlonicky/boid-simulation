#ifndef IK_DEMO_QUATERNION_H_
#define IK_DEMO_QUATERNION_H_

#include <cmath>
#include "vector_3.h"
#include "matrix_4.h"

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
        float components[4] = {0.f, 0.f, 0.f, 1.f};
    };

    Quaternion() : Quaternion({1.0f, 0.f, 0.f}, 0.f) {}
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Quaternion(Vector3 axis, float angle_degrees) {
        axis.normalize();

        float angle_radians = angle_degrees / 180.f * static_cast<float>(M_PI);
        float half_angle = (angle_radians) / 2.f;
        float sin_half_angle = std::sin(half_angle);
        x = axis.x * sin_half_angle;
        y = axis.y * sin_half_angle;
        z = axis.z * sin_half_angle;
        w = std::cos(half_angle);
    }

    float& operator[](int i);
    const float& operator[](int i) const;
    Quaternion operator*(const Quaternion& b) const;
    Quaternion operator+(const Quaternion& b) const;

    [[nodiscard]] Matrix4 calcRotationMatrix() const;
    [[nodiscard]] Vector3& getVectorPart();
    [[nodiscard]] const Vector3& getVectorPart() const;
};

#endif
