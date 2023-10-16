#include "math/matrix_4.h"

#include <gtest/gtest.h>
#include "testing_utility.h"


TEST(Matrix4, Multiplication) {
    Matrix4 m1 = {1.0f, 2.0f, 3.0f, 4.0f,
                  5.0f, 6.0f, 7.0f, 8.0f,
                  9.0f, 10.0f, 11.0f, 12.0f,
                  13.0f, 14.0f, 15.0f, 16.0f};
    Matrix4 m2 = {17.0f, 18.0f, 19.0f, 20.0f,
                  21.0f, 22.0f, 23.0f, 24.0f,
                  25.0f, 26.0f, 27.0f, 28.0f,
                  29.0f, 30.0f, 31.0f, 32.0f};
    Matrix4 m3 = m1 * m2;
    assertMatrixValues(m3, 250.0f, 260.0f, 270.f, 280.f,
                       618.f, 644.f, 670.f, 696.f,
                       986.f, 1028.f, 1070.f, 1112.f,
                       1354.f, 1412.f, 1470.f, 1528.f);
}

TEST(Matrix4, Negation) {
    Matrix4 m1 = {1.0f, 2.0f, 3.0f, 4.0f,
                  5.0f, 6.0f, 7.0f, 8.0f,
                  9.0f, 10.0f, 11.0f, 12.0f,
                  13.0f, 14.0f, 15.0f, 16.0f};
    Matrix4 m2 = -m1;
    assertMatrixValues(m2, -1.0f, -2.0f, -3.0f, -4.0f,
                       -5.0f, -6.0f, -7.0f, -8.0f,
                       -9.0f, -10.0f, -11.0f, -12.0f,
                       -13.0f, -14.0f, -15.0f, -16.0f);
}