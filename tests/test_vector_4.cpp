#include "math/vector_4.h"

#include <gtest/gtest.h>
#include <cmath>
#include "testing_utility.h"

TEST(Vector4, DefaultConstruction) {
    Vector4 v;
    assertVectorValues(v, 0.0f, 0.0f, 0.0f, 0.0f);
}

TEST(Vector4, ValueConstruction) {
    Vector4 v {1.0f, 2.0f, 3.0f, 4.0f};
    assertVectorValues(v, 1.0f, 2.0f, 3.0f, 4.0f);
}

TEST(Vector4, CopyConstruction) {
    Vector4 v1 {1.0f, 2.0f, 3.0f, 4.0f};
    Vector4 v2 {v1};
    assertVectorValues(v2, 1.0f, 2.0f, 3.0f, 4.0f);
}

TEST(Vector4, PropertyAssignment) {
    Vector4 v;
    v.x = 1.0f;
    v.y = 2.0f;
    v.z = 3.0f;
    v.w = 4.0f;
    assertVectorValues(v, 1.0f, 2.0f, 3.0f, 4.0f);
}

TEST(Vector4, IndexAssignment) {
    Vector4 v;
    v[0] = 1.0f;
    v[1] = 2.0f;
    v[2] = 3.0f;
    v[3] = 4.0f;
    assertVectorValues(v, 1.0f, 2.0f, 3.0f, 4.0f);
}

TEST(Vector4, Addition) {
    Vector4 v1 {1.0f, 2.0f, 3.0f, 4.0f};
    Vector4 v2 {4.0f, 5.0f, 6.0f, 7.0f};
    Vector4 v3 = v1 + v2;
    assertVectorValues(v3, 5.0f, 7.0f, 9.0f, 11.0f);
}

TEST(Vector4, Subtraction) {
    Vector4 v1 {1.0f, 2.0f, 3.0f, 4.0f};
    Vector4 v2 {2.0f, 4.0f, 6.0f, 8.0f};
    Vector4 v3 = v1 - v2;
    assertVectorValues(v3, -1.0f, -2.0f, -3.0f, -4.0f);
}

TEST(Vector4, ScalarMultiplication) {
    Vector4 v1 {1.0f, 2.0f, 3.0f, 4.0f};
    Vector4 v2 = v1 * 5;
    assertVectorValues(v2, 5.0f, 10.0f, 15.0f, 20.0f);
}

TEST(Vector4, ScalarDivision) {
    Vector4 v1 {5.0f, 10.0f, 15.0f, 20.0f};
    Vector4 v2 = v1 / 5.0f;
    assertVectorValues(v2, 1.0f, 2.0f, 3.0f, 4.0f);
}

TEST(Vector4, Negation) {
    Vector4 v1 {1.0f, 2.0f, 3.0f, 4.0f};
    Vector4 v2 = -v1;
    assertVectorValues(v2, -1.0f, -2.0f, -3.0f, -4.0f);
}

TEST(Vector4, Magnitude) {
    Vector4 v {1.0f, 2.0f, 3.0f, 4.0f};
    float expected_magnitude = std::sqrt(1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f + 4.0f * 4.0f);
    ASSERT_FLOAT_EQ(v.magnitude(), expected_magnitude);
}

TEST(Vector4, Normalize) {
    Vector4 v {1.0f, 1.0f, 1.0f, 1.0f};
    v.normalize();
    ASSERT_FLOAT_EQ(v.magnitude(), 1.0f);
}