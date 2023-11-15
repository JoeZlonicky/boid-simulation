#include "vector_3.h"

#include <cmath>


Vector3::Vector3() : x(0.f), y(0.f), z(0.f) {}

Vector3::Vector3(float value) : x(value), y(value), z(value) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

float& Vector3::operator[](const int i) {
    return components[i];
}

const float& Vector3::operator[](const int i) const {
    return components[i];
}

Vector3& Vector3::operator*=(const float s) {
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

float Vector3::dot(const Vector3 &v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vector3 operator*(Vector3 v, const float s) {
    v *= s;
    return v;
}

Vector3 operator/(Vector3 v, const float s) {
    v /= s;
    return v;
}

Vector3 operator+(Vector3 a, const Vector3& b) {
    a += b;
    return a;
}

Vector3 operator-(Vector3 a, const Vector3& b) {
    a -= b;
    return a;
}

Vector3 operator-(Vector3 v) {
    v *= -1.f;
    return v;
}