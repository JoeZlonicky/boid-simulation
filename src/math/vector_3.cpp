#include "vector_3.h"


Vector3 Vector3::operator*(float s) const {
    return {x * s, y * s, z * s};
}

Vector3 Vector3::operator/(float s) const {
    s = 1.f / s;  // More performant to only do division once and then multiply
    return {x * s, y * s, z * s};
}

Vector3 Vector3::operator-() const {
    return {-x, -y, -z};
}

Vector3 Vector3::operator+(const Vector3& v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vector3 Vector3::operator-(const Vector3& v) const {
    return {x - v.x, y - v.y, z - v.z};
}

float& Vector3::operator[](int i) {
    return components[i];
}

const float& Vector3::operator[](int i) const {
    return components[i];
}

Vector3& Vector3::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

Vector3& Vector3::operator/=(float s) {
    s = 1.f / s;  // More performant to only do division once and then multiply
    *this *= s;
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3&v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

void Vector3::normalize() {
    *this /= magnitude();
}

Vector3 Vector3::normalized() const {
    return *this / magnitude();
}

float Vector3::magnitude() const {
    return (std::sqrt(x * x + y * y + z * z));
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x};
}