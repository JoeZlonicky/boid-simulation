
#include "math/matrix_3.h"

#include <gtest/gtest.h>
#include "testing_utility.h"


TEST(Matrix3, Multiplication) {
    Matrix3 m1 = {1.f, 2.f, 3.f,
                  4.f, 5.f, 6.f,
                  7.f, 8.f, 9.f};
    Matrix3 m2 = {10.f, 11.f, 12.f,
                  13.f, 14.f, 15.f,
                  16.f, 17.f, 18.f};
    Matrix3 m3 = m1 * m2;
    assertMatrixValues(m3, 84.f, 90.f, 96.f,
                       201.f, 216.f, 231.f,
                       318.f, 342.f, 366.f);
}

TEST(Matrix3, ScalarMultiplication) {
    Matrix3 m = {1.f, 2.f, 3.f,
                 4.f, 5.f, 6.f,
                 7.f, 8.f, 9.f};
    m *= 2;
    assertMatrixValues(m, 2.f, 4.f, 6.f,
                       8.f, 10.f, 12.f,
                       14.f, 16.f, 18.f);
}

TEST(Matrix3, Negation) {
    Matrix3 m1 = {1.f, 2.f, 3.f,
                  4.f,5.f, 6.f,
                  7.f, 8.f, 9.f};
    Matrix3 m2 = -m1;
    assertMatrixValues(m2, -1.f, -2.f, -3.f,
                       -4.f,-5.f, -6.f,
                       -7.f, -8.f,-9.f);
}