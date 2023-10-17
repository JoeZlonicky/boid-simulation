#include "math/vector_4.h"

#include <gtest/gtest.h>
#include <cmath>
#include "testing_utility.h"

TEST(Vector4, DefaultConstruction) {
    Vector4 v;
    assertVectorValues(v, 0.f, 0.f, 0.f, 0.f);
}

TEST(Vector4, ValueConstruction) {
    Vector4 v {1.f, 2.f, 3.f, 4.f};
    assertVectorValues(v, 1.f, 2.f, 3.f, 4.f);
}

TEST(Vector4, FillConstruction) {
    Vector4 v {1.f};
    assertVectorValues(v, 1.f, 1.f, 1.f, 1.f);
}

TEST(Vector4, CopyConstruction) {
    Vector4 v1 {1.f, 2.f, 3.f, 4.f};
    Vector4 v2 {v1};
    assertVectorValues(v2, 1.f, 2.f, 3.f, 4.f);
}

TEST(Vector4, PropertyAssignment) {
    Vector4 v;
    v.x = 1.f;
    v.y = 2.f;
    v.z = 3.f;
    v.w = 4.f;
    assertVectorValues(v, 1.f, 2.f, 3.f, 4.f);
}

TEST(Vector4, IndexAssignment) {
    Vector4 v;
    v[0] = 1.f;
    v[1] = 2.f;
    v[2] = 3.f;
    v[3] = 4.f;
    assertVectorValues(v, 1.f, 2.f, 3.f, 4.f);
}

TEST(Vector4, Addition) {
    Vector4 v1 {1.f, 2.f, 3.f, 4.f};
    Vector4 v2 {4.f, 5.f, 6.f, 7.f};
    Vector4 v3 = v1 + v2;
    assertVectorValues(v3, 5.f, 7.f, 9.f, 11.f);
}

TEST(Vector4, Subtraction) {
    Vector4 v1 {1.f, 2.f, 3.f, 4.f};
    Vector4 v2 {2.f, 4.f, 6.f, 8.f};
    Vector4 v3 = v1 - v2;
    assertVectorValues(v3, -1.f, -2.f, -3.f, -4.f);
}

TEST(Vector4, ScalarMultiplication) {
    Vector4 v1 {1.f, 2.f, 3.f, 4.f};
    Vector4 v2 = v1 * 5;
    assertVectorValues(v2, 5.f, 10.f, 15.f, 20.f);
}

TEST(Vector4, ScalarDivision) {
    Vector4 v1 {5.f, 10.f, 15.f, 20.f};
    Vector4 v2 = v1 / 5.f;
    assertVectorValues(v2, 1.f, 2.f, 3.f, 4.f);
}

TEST(Vector4, Negation) {
    Vector4 v1 {1.f, 2.f, 3.f, 4.f};
    Vector4 v2 = -v1;
    assertVectorValues(v2, -1.f, -2.f, -3.f, -4.f);
}

TEST(Vector4, Magnitude) {
    Vector4 v {1.f, 2.f, 3.f, 4.f};
    float expected_magnitude = std::sqrt(1.f * 1.f + 2.f * 2.f + 3.f * 3.f + 4.f * 4.f);
    ASSERT_FLOAT_EQ(v.magnitude(), expected_magnitude);
}

TEST(Vector4, Normalize) {
    Vector4 v {1.f, 1.f, 1.f, 1.f};
    v.normalize();
    ASSERT_FLOAT_EQ(v.magnitude(), 1.f);
}