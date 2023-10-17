#ifndef IK_DEMO_VECTOR_4_H_
#define IK_DEMO_VECTOR_4_H_

#include <cmath>

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

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector4& operator*=(float s);
    Vector4 operator*(float s) const;
    Vector4& operator/=(float s);
    Vector4 operator/(float s) const;

    Vector4& operator+=(const Vector4& v);
    Vector4 operator+(const Vector4& v) const;
    Vector4& operator-=(const Vector4& v);
    Vector4 operator-(const Vector4& v) const;

    Vector4 operator-() const;

    void normalize();
    [[nodiscard]] Vector4 normalized() const;
    [[nodiscard]] float magnitude() const;
};

inline Vector4 Vector4::operator*(float s) const {
    return {x * s, y * s, z * s, w * s};
}

inline Vector4 Vector4::operator/(float s) const {
    s = 1.f / s;  // More performant to only do division once and then multiply
    return {x * s, y * s, z * s, w * s};
}

inline Vector4 Vector4::operator-() const {
    return {-x, -y, -z, -w};
}

inline Vector4 Vector4::operator+(const Vector4& v) const {
    return {x + v.x, y + v.y, z + v.z, w + v.w};
}

inline Vector4 Vector4::operator-(const Vector4& v) const {
    return {x - v.x, y - v.y, z - v.z, w - v.w};
}

inline float& Vector4::operator[](int i) {
    return components[i];
}

inline const float& Vector4::operator[](int i) const {
    return components[i];
}

inline Vector4& Vector4::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

inline Vector4& Vector4::operator/=(float s) {
    s = 1.f / s;  // More performant to only do division once and then multiply
    *this *= s;
    return *this;
}

inline Vector4& Vector4::operator+=(const Vector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

inline Vector4& Vector4::operator-=(const Vector4&v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

inline void Vector4::normalize() {
    *this /= magnitude();
}

inline Vector4 Vector4::normalized() const {
    return *this / magnitude();
}

inline float Vector4::magnitude() const {
    return (std::sqrt(x * x + y * y + z * z + w * w));
}

#endif
