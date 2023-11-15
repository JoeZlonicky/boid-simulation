#include "vector_4.h"


Vector4::Vector4() : x(0.f), y(0.f), z(0.f), w(0.f) {}

Vector4::Vector4(const float value) : x(value), y(value), z(value), w(value) {}

Vector4::Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector3 &v, const float w) : x(v.x), y(v.y), z(v.z), w(w) {}

float& Vector4::operator[](const int i) {
    return components[i];
}

const float& Vector4::operator[](const int i) const {
    return components[i];
}

Vector4& Vector4::operator*=(const float s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
    return *this;
}

Vector4& Vector4::operator/=(float s) {
    s = 1.f / s;  // More performant to only do division once and then multiply
    *this *= s;
    return *this;
}

Vector4& Vector4::operator+=(const Vector4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vector4& Vector4::operator-=(const Vector4&v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

void Vector4::normalize() {
    *this /= magnitude();
}

Vector4 Vector4::normalized() const {
    return *this / magnitude();
}

float Vector4::magnitude() const {
    return (std::sqrt(x * x + y * y + z * z + w * w));
}

Vector4 operator*(Vector4 v, const float s) {
    v *= s;
    return v;
}

Vector4 operator/(Vector4 v, const float s) {
    v /= s;
    return v;
}

Vector4 operator+(Vector4 a, const Vector4& b) {
    a += b;
    return a;
}

Vector4 operator-(Vector4 a, const Vector4& b) {
    a -= b;
    return a;
}

Vector4 operator-(Vector4 v) {
    v *= -1.f;
    return v;
}