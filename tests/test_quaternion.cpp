#include "math/quaternion.h"

#include <gtest/gtest.h>
#include "testing_utility.h"


TEST(Quaternion, Matrix3Construction) {
    Quaternion q {{1.f, 0.f, 0.f}, 0.f};
    Matrix3 m = q.calcRotationMatrix3();
    assertMatrixValues(m, 1.f, 0.f, 0.f,
                       0.f, 1.f, 0.f,
                       0.f, 0.f, 1.f);
}

TEST(Quaternion, Matrix4Construction) {
    Quaternion q {{1.f, 0.f, 0.f}, 0.f};
    Matrix4 m = q.calcRotationMatrix4();
    assertMatrixValues(m, 1.f, 0.f, 0.f, 0.f,
                       0.f, 1.f, 0.f, 0.f,
                       0.f, 0.f, 1.f, 0.f,
                       0.f, 0.f, 0.f, 1.f);
}

TEST(Quaternion, XAxisRotation) {
    Quaternion q {{1.f, 0.f, 0.f}, 90.f};
    Matrix3 m = q.calcRotationMatrix3();
    assertMatrixValues(m, 1.f, 0.f, 0.f,
                       0.f, 0.f, -1.f,
                       0.f, 1.f, 0.f);
}

TEST(Quaternion, YAxisRotation) {
    Quaternion q {{0.f, 1.f, 0.f}, 90.f};
    Matrix3 m = q.calcRotationMatrix3();
    assertMatrixValues(m, 0.f, 0.f, 1.f,
                       0.f, 1.f, 0.f,
                       -1.f, 0.f, 0.f);
}

TEST(Quaternion, ZAxisRotation) {
    Quaternion q {{0.f, 0.f, 1.f}, 90.f};
    Matrix3 m = q.calcRotationMatrix3();
    assertMatrixValues(m, 0.f, -1.f, 0.f,
                       1.f, 0.f, 0.f,
                       0.f, 0.f, 1.f);
}

TEST(Quaternion, Multiplication) {
    Quaternion q1 {{1.f, 0.f, 0.f}, 45.f};
    Quaternion q2 {{1.f, 0.f, 0.f}, 135.f};
    Quaternion q3 = q1 * q2;
    Matrix3 m = q3.calcRotationMatrix3();
    assertMatrixValues(m, 1.f, 0.f, 0.f,
                       0.f, -1.f, 0.f,
                       0.f, 0.f, -1.f);
}