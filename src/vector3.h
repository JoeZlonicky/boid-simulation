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

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector3& operator*=(float s);
    Vector3 operator*(float s) const;
    Vector3& operator/=(float s);
    Vector3 operator/(float s) const;

    Vector3& operator+=(const Vector3& v);
    Vector3 operator+(const Vector3& v) const;
    Vector3& operator-=(const Vector3& v);
    Vector3 operator-(const Vector3& v) const;

    Vector3 operator-() const;

    void normalize();
    [[nodiscard]] Vector3 normalized() const;

    [[nodiscard]] float magnitude() const;
};

inline Vector3 Vector3::operator*(float s) const {
    return {x * s, y * s, z * s};
}

inline Vector3 Vector3::operator/(float s) const {
    s = 1.0f / s;  // More performant to only do division once and then multiply
    return {x * s, y * s, z * s};
}

inline Vector3 Vector3::operator-() const {
    return {-x, -y, -z};
}

inline Vector3 Vector3::operator+(const Vector3& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

inline Vector3 Vector3::operator-(const Vector3& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

inline float& Vector3::operator[](int i) {
    return components[i];
}

inline const float& Vector3::operator[](int i) const {
    return components[i];
}

inline Vector3& Vector3::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

inline Vector3& Vector3::operator/=(float s) {
    s = 1.0f / s;  // More performant to only do division once and then multiply
    *this *= s;
    return *this;
}

inline Vector3& Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector3& Vector3::operator-=(const Vector3&v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline void Vector3::normalize() {
    *this /= magnitude();
}

inline Vector3 Vector3::normalized() const {
    return *this / magnitude();
}

inline float Vector3::magnitude() const {
    return (std::sqrt(x * x + y * y + z * z));
}

#endif
