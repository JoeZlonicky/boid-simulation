#ifndef IK_DEMO_TESTING_UTILITY_H_
#define IK_DEMO_TESTING_UTILITY_H_

#include <gtest/gtest.h>
#include "math/matrix_3.h"
#include "math/matrix_4.h"
#include "math/vector_3.h"
#include "math/vector_4.h"

namespace {
    float epsilon = 0.0000001f;
}

inline void assertVectorValues(const Vector3& v, float x, float y, float z) {
    ASSERT_NEAR(v.x, x, epsilon);
    ASSERT_NEAR(v.y, y, epsilon);
    ASSERT_NEAR(v.z, z, epsilon);
}

inline void assertVectorValues(const Vector4& v, float x, float y, float z, float w) {
    ASSERT_NEAR(v.x, x, epsilon);
    ASSERT_NEAR(v.y, y, epsilon);
    ASSERT_NEAR(v.z, z, epsilon);
    ASSERT_NEAR(v.w, w, epsilon);
}

inline void assertMatrixValues(const Matrix4& m, float n00, float n01, float n02, float n03,
                               float n10, float n11, float n12, float n13,
                               float n20, float n21, float n22, float n23,
                               float n30, float n31, float n32, float n33) {
    ASSERT_NEAR(m(0, 0), n00, epsilon);
    ASSERT_NEAR(m(0, 1), n01, epsilon);
    ASSERT_NEAR(m(0, 2), n02, epsilon);
    ASSERT_NEAR(m(0, 3), n03, epsilon);

    ASSERT_NEAR(m(1, 0), n10, epsilon);
    ASSERT_NEAR(m(1, 1), n11, epsilon);
    ASSERT_NEAR(m(1, 2), n12, epsilon);
    ASSERT_NEAR(m(1, 3), n13, epsilon);

    ASSERT_NEAR(m(2, 0), n20, epsilon);
    ASSERT_NEAR(m(2, 1), n21, epsilon);
    ASSERT_NEAR(m(2, 2), n22, epsilon);
    ASSERT_NEAR(m(2, 3), n23, epsilon);

    ASSERT_NEAR(m(3, 0), n30, epsilon);
    ASSERT_NEAR(m(3, 1), n31, epsilon);
    ASSERT_NEAR(m(3, 2), n32, epsilon);
    ASSERT_NEAR(m(3, 3), n33, epsilon);
}

inline void assertMatrixValues(const Matrix3& m, float n00, float n01, float n02,
                               float n10, float n11, float n12,
                               float n20, float n21, float n22) {
    ASSERT_NEAR(m(0, 0), n00, epsilon);
    ASSERT_NEAR(m(0, 1), n01, epsilon);
    ASSERT_NEAR(m(0, 2), n02, epsilon);

    ASSERT_NEAR(m(1, 0), n10, epsilon);
    ASSERT_NEAR(m(1, 1), n11, epsilon);
    ASSERT_NEAR(m(1, 2), n12, epsilon);

    ASSERT_NEAR(m(2, 0), n20, epsilon);
    ASSERT_NEAR(m(2, 1), n21, epsilon);
    ASSERT_NEAR(m(2, 2), n22, epsilon);
}

#endif