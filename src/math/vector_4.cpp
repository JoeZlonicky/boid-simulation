#include "vector_4.h"


Vector4 Vector4::operator*(float s) const {
    return {x * s, y * s, z * s, w * s};
}

Vector4 Vector4::operator/(float s) const {
    s = 1.f / s;  // More performant to only do division once and then multiply
    return {x * s, y * s, z * s, w * s};
}

Vector4 Vector4::operator-() const {
    return {-x, -y, -z, -w};
}

Vector4 Vector4::operator+(const Vector4& v) const {
    return {x + v.x, y + v.y, z + v.z, w + v.w};
}

Vector4 Vector4::operator-(const Vector4& v) const {
    return {x - v.x, y - v.y, z - v.z, w - v.w};
}

float& Vector4::operator[](int i) {
    return components[i];
}

const float& Vector4::operator[](int i) const {
    return components[i];
}

Vector4& Vector4::operator*=(float s) {
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