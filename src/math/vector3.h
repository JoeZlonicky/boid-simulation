#ifndef IK_DEMO_VECTOR3_H_
#define IK_DEMO_VECTOR3_H_

#include <cmath>

// Implementation takes inspiration from
// 1) Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// 2) Godot Game Engine source code
struct Vector3 {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float components[3] = {0.0f};
    };

    Vector3();
    Vector3(float x, float y, float z);

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector3& operator*=(float s);
    Vector3& operator/=(float s);
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3&v);

    void normalize();
    [[nodiscard]] Vector3 normalized() const;

    [[nodiscard]] float magnitude() const;
};

inline Vector3 operator*(const Vector3& v, float s) {
    return {v.x * s, v.y * s, v.z * s};
}

inline Vector3 operator/(const Vector3& v, float s) {
    s = 1.0f / s;  // More performant to only do division once and then multiply
    return {v.x * s, v.y * s, v.z * s};
}

inline Vector3 operator-(const Vector3& v) {
    return {-v.x, -v.y, -v.z};
}

inline Vector3 operator+(const Vector3& a, const Vector3& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

inline Vector3 operator-(const Vector3& a, const Vector3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

#endif
