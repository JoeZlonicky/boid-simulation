#include "math/transform.h"

#include <gtest/gtest.h>
#include "testing_utility.h"


TEST(Transform, DefaultConstruction) {
    Transform t {};
    Matrix4 m = t.getMatrix();
    assertMatrixValues(m, 1.f, 0.f, 0.f, 0.f,
                       0.f, 1.f, 0.f, 0.f,
                       0.f, 0.f, 1.f, 0.f,
                       0.f, 0.f, 0.f, 1.f);
}

TEST(Transform, Translation) {
    Transform t {};
    t.setPos(1.f, 1.f, 1.f);
    t.setPosY(2.f);
    t.moveZ(2.f);
    Matrix4 m = t.getMatrix();
    assertMatrixValues(m, 1.f, 0.f, 0.f, 1.f,
                       0.f, 1.f, 0.f, 2.f,
                       0.f, 0.f, 1.f, 3.f,
                       0.f, 0.f, 0.f, 1.f);
}

TEST(Transform, Scale) {
    Transform t {};
    t.setScaleX(2.f);
    t.setScaleY(3.f);
    t.setScaleZ(4.f);
    Matrix4 m = t.getMatrix();
    assertMatrixValues(m, 2.f, 0.f, 0.f, 0.f,
                       0.f, 3.f, 0.f, 0.f,
                       0.f, 0.f, 4.f, 0.f,
                       0.f, 0.f, 0.f, 1.f);
}

TEST(Transform, Rotation) {
    Transform t {};
    Quaternion q {{1.f, 0.f, 0.f}, 90.f};
    t.rotate(q);
    Matrix4 m = t.getMatrix();
    assertMatrixValues(m, 1.f, 0.f, 0.f, 0.f,
                       0.f, 0.f, -1.f, 0.f,
                       0.f, 1.f, 0.f, 0.f,
                       0.f, 0.f, 0.f, 1.f);
}