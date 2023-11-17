#ifndef BOID_SIMULATION_MATRIX_4_H_
#define BOID_SIMULATION_MATRIX_4_H_

#include "vector_4.h"

// Implementation takes inspiration from Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// Stored in column-major order: https://en.wikipedia.org/wiki/Row-_and_column-major_order
class Matrix4 {
public:
    Matrix4() = default;

    explicit Matrix4(float diagonal);
    Matrix4(float n00, float n01, float n02, float n03,
            float n10, float n11, float n12, float n13,
            float n20, float n21, float n22, float n23,
            float n30, float n31, float n32, float n33);

    // Parameters are in matrix notation and do not correspond to the internal indices
    void set(float n00, float n01, float n02, float n03,
             float n10, float n11, float n12, float n13,
             float n20, float n21, float n22, float n23,
             float n30, float n31, float n32, float n33);

    Vector4& getColumn(int j);
    [[nodiscard]] const Vector4& getColumn(int j) const;

    float& operator()(int i, int j);
    const float& operator()(int i, int j) const;

    Matrix4& operator*=(const Matrix4& b);
    Matrix4& operator*=(float s);

private:
    float n[4][4];
};

Matrix4 operator*(Matrix4 a, const Matrix4& b);
Matrix4 operator*(Matrix4 m, float s);

Matrix4 operator-(Matrix4 m);

Vector4 operator*(const Matrix4& m, const Vector4& v);

#endif
