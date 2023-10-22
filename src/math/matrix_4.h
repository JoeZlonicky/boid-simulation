#ifndef IK_DEMO_MATRIX_4_H_
#define IK_DEMO_MATRIX_4_H_

#include "vector_4.h"

// Implementation takes inspiration from Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
struct Matrix4 {
    Matrix4() = default;
    explicit Matrix4(float s) : n{{s, 0.f, 0.f, 0.f},
                                  {0.f, s, 0.f, 0.f},
                                  {0.f, 0.f, s, 0.f},
                                  {0.f, 0.f, 0.f, s}} {}
    Matrix4(float n00, float n01, float n02, float n03,
            float n10, float n11, float n12, float n13,
            float n20, float n21, float n22, float n23,
            float n30, float n31, float n32, float n33) :
            n {{n00, n10, n20, n30},
               {n01, n11, n21, n31},
               {n02, n12, n22, n32},
               {n03, n13, n23, n33}} {}

    // Parameters are in matrix notation and do not correspond to the internal array indices
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

#endif
