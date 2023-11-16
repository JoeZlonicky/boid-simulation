#include "math/vector_3.h"

#include <gtest/gtest.h>
#include <cmath>
#include "testing_utility.h"

TEST(Vector3, DefaultConstruction) {
    Vector3 v {};
    assertVectorValues(v, 0.f, 0.f, 0.f);
}

TEST(Vector3, ValueConstruction) {
    Vector3 v {1.f, 2.f, 3.f};
    assertVectorValues(v, 1.f, 2.f, 3.f);
}

TEST(Vector3, FillConstruction) {
    Vector3 v {1.f};
    assertVectorValues(v, 1.f, 1.f, 1.f);
}

TEST(Vector3, CopyConstruction) {
    Vector3 v1 {1.f, 2.f, 3.f};
    Vector3 v2 {v1};
    assertVectorValues(v2, 1.f, 2.f, 3.f);
}

TEST(Vector3, PropertyAssignment) {
    Vector3 v {};
    v.x = 1.f;
    v.y = 2.f;
    v.z = 3.f;
    assertVectorValues(v, 1.f, 2.f, 3.f);
}

TEST(Vector3, IndexAssignment) {
    Vector3 v {};
    v[0] = 1.f;
    v[1] = 2.f;
    v[2] = 3.f;
    assertVectorValues(v, 1.f, 2.f, 3.f);
}

TEST(Vector3, Addition) {
    Vector3 v1 {1.f, 2.f, 3.f};
    Vector3 v2 {4.f, 5.f, 6.f};
    Vector3 v3 = v1 + v2;
    assertVectorValues(v3, 5.f, 7.f, 9.f);
}

TEST(Vector3, Subtraction) {
    Vector3 v1 {1.f, 2.f, 3.f};
    Vector3 v2 {2.f, 4.f, 6.f};
    Vector3 v3 = v1 - v2;
    assertVectorValues(v3, -1.f, -2.f, -3.f);
}

TEST(Vector3, ScalarMultiplication) {
    Vector3 v1 {1.f, 2.f, 3.f};
    Vector3 v2 = v1 * 5;
    assertVectorValues(v2, 5.f, 10.f, 15.f);
}

TEST(Vector3, ScalarDivision) {
    Vector3 v1 {5.f, 10.f, 15.f};
    Vector3 v2 = v1 / 5.f;
    assertVectorValues(v2, 1.f, 2.f, 3.f);
}

TEST(Vector3, Negation) {
    Vector3 v1 {1.f, 2.f, 3.f};
    Vector3 v2 = -v1;
    assertVectorValues(v2, -1.f, -2.f, -3.f);
}

TEST(Vector3, Magnitude) {
    Vector3 v {1.f, 2.f, 3.f};
    float expected_magnitude = std::sqrt(1.f * 1.f + 2.f * 2.f + 3.f * 3.f);
    ASSERT_FLOAT_EQ(v.magnitude(), expected_magnitude);
}

TEST(Vector3, Normalize) {
    Vector3 v {1.f, 1.f, 1.f};
    v.normalize();
    ASSERT_FLOAT_EQ(v.magnitude(), 1.f);
}

TEST(Vector3, CrossProduct) {
    Vector3 v1 {1.f, 0.f, 0.f};
    Vector3 v2 {0.f, 1.f, 0.f};
    Vector3 v3 = v1.cross(v2);
    assertVectorValues(v3, 0.f, 0.f, 1.f);
}

TEST(Vector3, DotProduct) {
    Vector3 v1 {1.f, 2.f, 3.f};
    Vector3 v2 {4.f, 5.f, 6.f};
    float dot_product = v1.dot(v2);
    float expected_dot_product = 1.f * 4.f + 2.f * 5.f + 3.f * 6.f;
    ASSERT_FLOAT_EQ(dot_product, expected_dot_product);
}