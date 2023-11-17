#include "matrix_4.h"

Matrix4::Matrix4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20,
                 float n21, float n22, float n23, float n30, float n31, float n32, float n33) :
        n {{n00, n10, n20, n30},
           {n01, n11, n21, n31},
           {n02, n12, n22, n32},
           {n03, n13, n23, n33}} {}

Matrix4::Matrix4(float diagonal) : n {{diagonal, 0.f,      0.f,      0.f},
                                      {0.f,      diagonal, 0.f,      0.f},
                                      {0.f,      0.f,      diagonal, 0.f},
                                      {0.f,      0.f,      0.f,      diagonal}} {}

void Matrix4::set(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20,
                  float n21, float n22, float n23, float n30, float n31, float n32, float n33) {
    n[0][0] = n00;
    n[1][0] = n01;
    n[2][0] = n02;
    n[3][0] = n03;
    n[0][1] = n10;
    n[1][1] = n11;
    n[2][1] = n12;
    n[3][1] = n13;
    n[0][2] = n20;
    n[1][2] = n21;
    n[2][2] = n22;
    n[3][2] = n23;
    n[0][3] = n30;
    n[1][3] = n31;
    n[2][3] = n32;
    n[3][3] = n33;
}

Vector4& Matrix4::getColumn(int j) {
    return (*reinterpret_cast<Vector4*>(n[j]));
}

const Vector4& Matrix4::getColumn(int j) const {
    return (*reinterpret_cast<const Vector4*>(n[j]));
}

float& Matrix4::operator()(int i, int j) {
    return n[j][i];
}

const float& Matrix4::operator()(int i, int j) const {
    return n[j][i];
}

Matrix4& Matrix4::operator*=(const Matrix4& b) {
    const Matrix4& a = (*this);
    set(
            a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) + a(0, 2) * b(2, 0) + a(0, 3) * b(3, 0),
            a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) + a(0, 2) * b(2, 1) + a(0, 3) * b(3, 1),
            a(0, 0) * b(0, 2) + a(0, 1) * b(1, 2) + a(0, 2) * b(2, 2) + a(0, 3) * b(3, 2),
            a(0, 0) * b(0, 3) + a(0, 1) * b(1, 3) + a(0, 2) * b(2, 3) + a(0, 3) * b(3, 3),

            a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) + a(1, 2) * b(2, 0) + a(1, 3) * b(3, 0),
            a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) + a(1, 2) * b(2, 1) + a(1, 3) * b(3, 1),
            a(1, 0) * b(0, 2) + a(1, 1) * b(1, 2) + a(1, 2) * b(2, 2) + a(1, 3) * b(3, 2),
            a(1, 0) * b(0, 3) + a(1, 1) * b(1, 3) + a(1, 2) * b(2, 3) + a(1, 3) * b(3, 3),

            a(2, 0) * b(0, 0) + a(2, 1) * b(1, 0) + a(2, 2) * b(2, 0) + a(2, 3) * b(3, 0),
            a(2, 0) * b(0, 1) + a(2, 1) * b(1, 1) + a(2, 2) * b(2, 1) + a(2, 3) * b(3, 1),
            a(2, 0) * b(0, 2) + a(2, 1) * b(1, 2) + a(2, 2) * b(2, 2) + a(2, 3) * b(3, 2),
            a(2, 0) * b(0, 3) + a(2, 1) * b(1, 3) + a(2, 2) * b(2, 3) + a(2, 3) * b(3, 3),

            a(3, 0) * b(0, 0) + a(3, 1) * b(1, 0) + a(3, 2) * b(2, 0) + a(3, 3) * b(3, 0),
            a(3, 0) * b(0, 1) + a(3, 1) * b(1, 1) + a(3, 2) * b(2, 1) + a(3, 3) * b(3, 1),
            a(3, 0) * b(0, 2) + a(3, 1) * b(1, 2) + a(3, 2) * b(2, 2) + a(3, 3) * b(3, 2),
            a(3, 0) * b(0, 3) + a(3, 1) * b(1, 3) + a(3, 2) * b(2, 3) + a(3, 3) * b(3, 3)
    );
    return *this;
}

Matrix4& Matrix4::operator*=(float s) {
    const Matrix4& m = (*this);
    set(
            s * m(0, 0), s * m(0, 1), s * m(0, 2), s * m(0, 3),
            s * m(1, 0), s * m(1, 1), s * m(1, 2), s * m(1, 3),
            s * m(2, 0), s * m(2, 1), s * m(2, 2), s * m(2, 3),
            s * m(3, 0), s * m(3, 1), s * m(3, 2), s * m(3, 3));
    return *this;
}

Matrix4 operator*(Matrix4 a, const Matrix4& b) {
    a *= b;
    return a;
}

Matrix4 operator*(Matrix4 m, float s) {
    m *= s;
    return m;
}

Matrix4 operator-(Matrix4 m) {
    return m * -1;
}

Vector4 operator*(const Matrix4& m, const Vector4& v) {
    return {
            m(0, 0) * v.x + m(0, 1) * v.y + m(0, 2) * v.z + m(0, 3) * v.w,
            m(1, 0) * v.x + m(1, 1) * v.y + m(1, 2) * v.z + m(1, 3) * v.w,
            m(2, 0) * v.x + m(2, 1) * v.y + m(2, 2) * v.z + m(2, 3) * v.w,
            m(3, 0) * v.x + m(3, 1) * v.y + m(3, 2) * v.z + m(3, 3) * v.w
    };
}
