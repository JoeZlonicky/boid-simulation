#ifndef OPENGL_DEMO_MATRIX_3_H
#define OPENGL_DEMO_MATRIX_3_H

#include "vector_3.h"

// Implementation takes inspiration from Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// Stored in column-major order: https://en.wikipedia.org/wiki/Row-_and_column-major_order
class Matrix3 {
public:
    Matrix3() = default;

    explicit Matrix3(float diagonal);
    Matrix3(float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22);

    // Parameters are in matrix notation and do not correspond to the internal indices
    void set(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22);

    Vector3& getColumn(int j);
    [[nodiscard]] const Vector3& getColumn(int j) const;

    float& operator()(int i, int j);
    const float& operator()(int i, int j) const;

    Matrix3& operator*=(const Matrix3& b);
    Matrix3& operator*=(float s);

private:
    float n[3][3];
};

Matrix3 operator*(Matrix3 a, const Matrix3& b);
Matrix3 operator*(Matrix3 m, float s);

Matrix3 operator-(Matrix3 m);

Vector3 operator*(const Matrix3& m, const Vector3& v);

#endif
