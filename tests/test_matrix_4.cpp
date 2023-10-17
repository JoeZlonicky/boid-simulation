#include "math/matrix_4.h"

#include <gtest/gtest.h>
#include "testing_utility.h"


TEST(Matrix4, Multiplication) {
    Matrix4 m1 = {1.f, 2.f, 3.f, 4.f,
                  5.f, 6.f, 7.f, 8.f,
                  9.f, 10.f, 11.f, 12.f,
                  13.f, 14.f, 15.f, 16.f};
    Matrix4 m2 = {17.f, 18.f, 19.f, 20.f,
                  21.f, 22.f, 23.f, 24.f,
                  25.f, 26.f, 27.f, 28.f,
                  29.f, 30.f, 31.f, 32.f};
    Matrix4 m3 = m1 * m2;
    assertMatrixValues(m3, 250.f, 260.f, 270.f, 280.f,
                       618.f, 644.f, 670.f, 696.f,
                       986.f, 1028.f, 1070.f, 1112.f,
                       1354.f, 1412.f, 1470.f, 1528.f);
}

TEST(Matrix4, Negation) {
    Matrix4 m1 = {1.f, 2.f, 3.f, 4.f,
                  5.f, 6.f, 7.f, 8.f,
                  9.f, 10.f, 11.f, 12.f,
                  13.f, 14.f, 15.f, 16.f};
    Matrix4 m2 = -m1;
    assertMatrixValues(m2, -1.f, -2.f, -3.f, -4.f,
                       -5.f, -6.f, -7.f, -8.f,
                       -9.f, -10.f, -11.f, -12.f,
                       -13.f, -14.f, -15.f, -16.f);
}