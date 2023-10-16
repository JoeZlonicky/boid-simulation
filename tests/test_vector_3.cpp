#include "math/vector_3.h"

#include <gtest/gtest.h>
#include <cmath>
#include "testing_utility.h"

TEST(Vector3, DefaultConstruction) {
    Vector3 v;
    assertVectorValues(v, 0.0f, 0.0f, 0.0f);
}

TEST(Vector3, ValueConstruction) {
    Vector3 v {1.0f, 2.0f, 3.0f};
    assertVectorValues(v, 1.0f, 2.0f, 3.0f);
}

TEST(Vector3, CopyConstruction) {
    Vector3 v1 {1.0f, 2.0f, 3.0f};
    Vector3 v2 {v1};
    assertVectorValues(v2, 1.0f, 2.0f, 3.0f);
}

TEST(Vector3, PropertyAssignment) {
    Vector3 v;
    v.x = 1.0f;
    v.y = 2.0f;
    v.z = 3.0f;
    assertVectorValues(v, 1.0f, 2.0f, 3.0f);
}

TEST(Vector3, IndexAssignment) {
    Vector3 v;
    v[0] = 1.0f;
    v[1] = 2.0f;
    v[2] = 3.0f;
    assertVectorValues(v, 1.0f, 2.0f, 3.0f);
}

TEST(Vector3, Addition) {
    Vector3 v1 {1.0f, 2.0f, 3.0f};
    Vector3 v2 {4.0f, 5.0f, 6.0f};
    Vector3 v3 = v1 + v2;
    assertVectorValues(v3, 5.0f, 7.0f, 9.0f);
}

TEST(Vector3, Subtraction) {
    Vector3 v1 {1.0f, 2.0f, 3.0f};
    Vector3 v2 {2.0f, 4.0f, 6.0f};
    Vector3 v3 = v1 - v2;
    assertVectorValues(v3, -1.0f, -2.0f, -3.0f);
}

TEST(Vector3, ScalarMultiplication) {
    Vector3 v1 {1.0f, 2.0f, 3.0f};
    Vector3 v2 = v1 * 5;
    assertVectorValues(v2, 5.0f, 10.0f, 15.0f);
}

TEST(Vector3, ScalarDivision) {
    Vector3 v1 {5.0f, 10.0f, 15.0f};
    Vector3 v2 = v1 / 5.0f;
    assertVectorValues(v2, 1.0f, 2.0f, 3.0f);
}

TEST(Vector3, Negation) {
    Vector3 v1 {1.0f, 2.0f, 3.0f};
    Vector3 v2 = -v1;
    assertVectorValues(v2, -1.0f, -2.0f, -3.0f);
}

TEST(Vector3, Magnitude) {
    Vector3 v {1.0f, 2.0f, 3.0f};
    float expected_magnitude = std::sqrt(1.0f * 1.0f + 2.0f * 2.0f + 3.0f * 3.0f);
    ASSERT_FLOAT_EQ(v.magnitude(), expected_magnitude);
}

TEST(Vector3, Normalize) {
    Vector3 v {1.0f, 1.0f, 1.0f};
    v.normalize();
    ASSERT_FLOAT_EQ(v.magnitude(), 1.0f);
}

TEST(Vector3, CrossProduct) {
    Vector3 v1 {1.0f, 0.0f, 0.0f};
    Vector3 v2 {0.0f, 1.0f, 0.0f};
    Vector3 v3 = v1.cross(v2);
    assertVectorValues(v3, 0.0f, 0.0f, 1.0f);
}