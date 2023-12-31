#include "Quaternion.h"

Quaternion::Quaternion(Vector3 axis, float angle_degrees) {
    axis.normalize();

    float angle_radians = angle_degrees / 180.f * static_cast<float>(M_PI);
    float half_angle = (angle_radians) / 2.f;
    float sin_half_angle = std::sin(half_angle);
    x = axis.x * sin_half_angle;
    y = axis.y * sin_half_angle;
    z = axis.z * sin_half_angle;
    w = std::cos(half_angle);
}

Quaternion::Quaternion() : Quaternion({1.0f, 0.f, 0.f}, 0.f) {}

Quaternion::Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

float& Quaternion::operator[](int i) {
    return components[i];
}

const float& Quaternion::operator[](int i) const {
    return components[i];
}

void Quaternion::set(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Matrix3 Quaternion::calcRotationMatrix3() const {
    float x2 = x * x;
    float y2 = y * y;
    float z2 = z * z;
    float xy = x * y;
    float xz = x * z;
    float yz = y * z;
    float wx = w * x;
    float wy = w * y;
    float wz = w * z;
    return {
            1.f - 2.f * (y2 + z2), 2.f * (xy - wz), 2.f * (xz + wy),
            2.f * (xy + wz), 1.f - 2.f * (x2 + z2), 2.f * (yz - wx),
            2.f * (xz - wy), 2.f * (yz + wx), 1.f - 2.f * (x2 + y2),
    };
}

Matrix4 Quaternion::calcRotationMatrix4() const {
    float x2 = x * x;
    float y2 = y * y;
    float z2 = z * z;
    float xy = x * y;
    float xz = x * z;
    float yz = y * z;
    float wx = w * x;
    float wy = w * y;
    float wz = w * z;
    return {
            1.f - 2.f * (y2 + z2), 2.f * (xy - wz), 2.f * (xz + wy), 0.f,
            2.f * (xy + wz), 1.f - 2.f * (x2 + z2), 2.f * (yz - wx), 0.f,
            2.f * (xz - wy), 2.f * (yz + wx), 1.f - 2.f * (x2 + y2), 0.f,
            0.f, 0.f, 0.f, 1.f
    };
}

Vector3& Quaternion::getVectorPart() {
    return reinterpret_cast<Vector3&>(x);
}

const Vector3& Quaternion::getVectorPart() const {
    return reinterpret_cast<const Vector3&>(x);
}

Quaternion& Quaternion::operator*=(const Quaternion& q) {
    set(
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w,
            w * q.w - x * q.x - y * q.y - z * q.z
    );
    return *this;
}

Quaternion operator*(Quaternion a, const Quaternion& b) {
    a *= b;
    return a;
}