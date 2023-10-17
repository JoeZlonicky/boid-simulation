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

    Quaternion() : x(0.f), y(0.f), z(0.f), w(1.f) {}
    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Quaternion(const Vector3& v, float s) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = s;
    }

    float& operator[](int i);
    const float& operator[](int i) const;
    Quaternion operator*(const Quaternion& b) const;

    [[nodiscard]] Matrix4 calcRotationMatrix() const;
    [[nodiscard]] Vector3& getVectorPart();
    [[nodiscard]] const Vector3& getVectorPart() const;
};

inline float& Quaternion::operator[](int i) {
    return components[i];
}

inline const float& Quaternion::operator[](int i) const {
    return components[i];
}

inline Vector3& Quaternion::getVectorPart() {
    return reinterpret_cast<Vector3&>(x);
}

inline const Vector3 &Quaternion::getVectorPart() const {
    return reinterpret_cast<const Vector3&>(x);
}

inline Matrix4 Quaternion::calcRotationMatrix() const {
    float x2 = x * x;
    float y2 = y * y;
    float z2 = z * z;
    float xy = x * y;
    float xz = x * z;
    float yz = y * z;
    float wx = w * x;
    float wy = w * y;
    float wz = w * z;
    return {
        1.f - 2.f * (y2 + z2), 2.f * (xy - wz), 2.f * (xz + wy), 0.f,
        2.f * xy + wz, 1.f - 2.f * (x2 + z2), 2.f * (yz - wx), 0.f,
        2.f * (xz - wy), 2.f * (yz + wx), 1.f - 2.f * (x2 + y2), 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

Quaternion Quaternion::operator*(const Quaternion &b) const {
    return {
        w * b.x + x * b.w + y * b.z - z * b.y,
        w * b.y - x * b.z + y * b.w + z * b.x,
        w * b.z + x * b.y - y * b.x + z * b.w,
        w * b.w - x * b.x - y * b.y - z * b.z
    };
}

#endif
