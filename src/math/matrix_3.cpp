

#include "matrix_3.h"

void Matrix3::set(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22) {
    n[0][0] = n00; n[1][0] = n01; n[2][0] = n02;
    n[0][1] = n10; n[1][1] = n11; n[2][1] = n12;
    n[0][2] = n20; n[1][2] = n21; n[2][2] = n22;
}

Vector3 &Matrix3::getColumn(int j) {
    return *reinterpret_cast<Vector3*>(n[j]);
}

const Vector3 &Matrix3::getColumn(int j) const {
    return *reinterpret_cast<const Vector3*>(n[j]);
}

float &Matrix3::operator()(int i, int j) {
    return n[j][i];
}

const float &Matrix3::operator()(int i, int j) const {
    return n[j][i];
}

Matrix3 &Matrix3::operator*=(const Matrix3 &b) {
    const Matrix3& a = (*this);
    set(
            a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0),
            a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1),
            a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2),

            a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0),
            a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1),
            a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2),

            a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0),
            a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1),
            a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2)
            );

    return *this;
}

Matrix3 &Matrix3::operator*=(float s) {
    const Matrix3& m = (*this);
    set(
            s * m(0, 0), s * m(0, 1), s * m(0, 2),
            s * m(1, 0), s * m(1, 1), s * m(1, 2),
            s * m(2, 0), s * m(2, 1), s * m(2, 2)
            );
    return *this;
}

Matrix3 operator*(Matrix3 a, const Matrix3 &b) {
    a *= b;
    return a;
}

Matrix3 operator*(Matrix3 m, float s) {
    m *= s;
    return m;
}

Matrix3 operator-(Matrix3 m) {
    m *= -1;
    return m;
}

Vector3 operator*(const Matrix3 &m, const Vector3 &v) {
    return {
        m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z,
        m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z,
        m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z
    };
}
