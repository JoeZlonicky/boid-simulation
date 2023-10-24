#ifndef OPENGL_DEMO_VECTOR_4_H_
#define OPENGL_DEMO_VECTOR_4_H_

#include <cmath>
#include "vector_3.h"

// Implementation takes inspiration from
// 1) Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// 2) Godot Game Engine source code
struct Vector4 {
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float components[4] = {0.f};
    };

    Vector4() : x(0.f), y(0.f), z(0.f), w(0.f) {}
    explicit Vector4(float value) : x(value), y(value), z(value), w(value) {}
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Vector4(const Vector3& v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector4& operator*=(float s);
    Vector4& operator/=(float s);
    Vector4& operator+=(const Vector4& v);
    Vector4& operator-=(const Vector4& v);

    void normalize();
    [[nodiscard]] Vector4 normalized() const;
    [[nodiscard]] float magnitude() const;
};

Vector4 operator*(Vector4 v, float s);
Vector4 operator/(Vector4 v, float s);
Vector4 operator+(Vector4 a, const Vector4& b);
Vector4 operator-(Vector4 a, const Vector4& b);
Vector4 operator-(Vector4 v);

#endif
