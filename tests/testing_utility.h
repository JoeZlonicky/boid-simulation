#ifndef IK_DEMO_TESTING_UTILITY_H_
#define IK_DEMO_TESTING_UTILITY_H_

#include <gtest/gtest.h>
#include "math/vector_3.h"
#include "math/vector_4.h"
#include "math/point_3.h"

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

#endif
