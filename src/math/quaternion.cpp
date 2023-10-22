#include "Quaternion.h"


float& Quaternion::operator[](int i) {
    return components[i];
}

const float& Quaternion::operator[](int i) const {
    return components[i];
}

Vector3& Quaternion::getVectorPart() {
    return reinterpret_cast<Vector3&>(x);
}

const Vector3 &Quaternion::getVectorPart() const {
    return reinterpret_cast<const Vector3&>(x);
}

Matrix4 Quaternion::calcRotationMatrix() const {
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

Quaternion Quaternion::operator*(const Quaternion &b) const {
    return {
            w * b.x + x * b.w + y * b.z - z * b.y,
            w * b.y - x * b.z + y * b.w + z * b.x,
            w * b.z + x * b.y - y * b.x + z * b.w,
            w * b.w - x * b.x - y * b.y - z * b.z
    };
}

Quaternion Quaternion::operator+(const Quaternion& b) const {
    return {x + b.x, y + b.y, z + b.z, w + b.w};
}