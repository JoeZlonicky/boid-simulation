#ifndef IK_DEMO_MATRIX_4_H_
#define IK_DEMO_MATRIX_4_H_

#include "vector_4.h"

// Implementation takes inspiration from Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
struct Matrix4 {
protected:
    float n[4][4];

public:
    Matrix4() : n{0} {}
    explicit Matrix4(float s) : n{{s, 0.f, 0.f, 0.f},
                                  {0.f, s, 0.f, 0.f},
                                  {0.f, 0.f, s, 0.f},
                                  {0.f, 0.f, 0.f, s}} {}
    Matrix4(float n00, float n01, float n02, float n03,
            float n10, float n11, float n12, float n13,
            float n20, float n21, float n22, float n23,
            float n30, float n31, float n32, float n33) : n {{n00, n10, n20, n30},
                                                             {n01, n11, n21, n31},
                                                             {n02, n12, n22, n32},
                                                             {n03, n13, n23, n33}} {}

    Vector4& getColumn(int j);
    [[nodiscard]] const Vector4& getColumn(int j) const;

    float& operator()(int i, int j);
    const float& operator()(int i, int j) const;

    Matrix4 operator*(const Matrix4& b);
    Matrix4 operator-();
};

inline float& Matrix4::operator()(int i, int j) {
    return n[j][i];
}

inline const float& Matrix4::operator()(int i, int j) const {
    return n[j][i];
}

inline Vector4& Matrix4::getColumn(int j) {
    return (*reinterpret_cast<Vector4*>(n[j]));
}

inline const Vector4& Matrix4::getColumn(int j) const {
    return (*reinterpret_cast<const Vector4*>(n[j]));
}

inline Matrix4 Matrix4::operator*(const Matrix4 &b) {
    const Matrix4& a = (*this);

    return {
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
        };
}

inline Matrix4 Matrix4::operator-() {
    const Matrix4& m = (*this);
    return {
        -m(0, 0), -m(0, 1), -m(0, 2), -m(0, 3),
        -m(1, 0), -m(1, 1), -m(1, 2), -m(1, 3),
        -m(2, 0), -m(2, 1), -m(2, 2), -m(2, 3),
        -m(3, 0), -m(3, 1), -m(3, 2), -m(3, 3)
    };
}

#endif
