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

    Vector4();
    explicit Vector4(float value);
    Vector4(float x, float y, float z, float w);
    Vector4(const Vector3& v, float w);

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector4& operator*=(float s);
    Vector4& operator/=(float s);
    Vector4& operator+=(const Vector4& v);
    Vector4& operator-=(const Vector4& v);

    void normalize();
    [[nodiscard]] Vector4 normalized() const;
    [[nodiscard]] float magnitude() const;
    [[nodiscard]] float dot(const Vector4& v) const;
};

Vector4 operator*(Vector4 v, float s);
Vector4 operator/(Vector4 v, float s);
Vector4 operator+(Vector4 a, const Vector4& b);
Vector4 operator-(Vector4 a, const Vector4& b);
Vector4 operator-(Vector4 v);

#endif
