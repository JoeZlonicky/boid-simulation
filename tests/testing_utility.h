#ifndef IK_DEMO_TESTING_UTILITY_H_
#define IK_DEMO_TESTING_UTILITY_H_

#include <gtest/gtest.h>
#include "math/vector_3.h"
#include "math/vector_4.h"
#include "math/point_3.h"
#include "math/matrix_4.h"

inline void assertVectorValues(const Vector3& v, float x, float y, float z) {
    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, z);
}

inline void assertVectorValues(const Vector4& v, float x, float y, float z, float w) {
    ASSERT_FLOAT_EQ(v.x, x);
    ASSERT_FLOAT_EQ(v.y, y);
    ASSERT_FLOAT_EQ(v.z, z);
    ASSERT_FLOAT_EQ(v.w, w);
}

inline void assertPointValues(const Point3& p, float x, float y, float z) {
    assertVectorValues(p, x, y, z);
}

inline void assertMatrixValues(const Matrix4& m, float n00, float n01, float n02, float n03,
                               float n10, float n11, float n12, float n13,
                               float n20, float n21, float n22, float n23,
                               float n30, float n31, float n32, float n33) {
    ASSERT_FLOAT_EQ(m(0, 0), n00);
    ASSERT_FLOAT_EQ(m(0, 1), n01);
    ASSERT_FLOAT_EQ(m(0, 2), n02);
    ASSERT_FLOAT_EQ(m(0, 3), n03);

    ASSERT_FLOAT_EQ(m(1, 0), n10);
    ASSERT_FLOAT_EQ(m(1, 1), n11);
    ASSERT_FLOAT_EQ(m(1, 2), n12);
    ASSERT_FLOAT_EQ(m(1, 3), n13);

    ASSERT_FLOAT_EQ(m(2, 0), n20);
    ASSERT_FLOAT_EQ(m(2, 1), n21);
    ASSERT_FLOAT_EQ(m(2, 2), n22);
    ASSERT_FLOAT_EQ(m(2, 3), n23);

    ASSERT_FLOAT_EQ(m(3, 0), n30);
    ASSERT_FLOAT_EQ(m(3, 1), n31);
    ASSERT_FLOAT_EQ(m(3, 2), n32);
    ASSERT_FLOAT_EQ(m(3, 3), n33);
}

#endif
