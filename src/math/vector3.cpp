#include "vector3.h"


Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

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