#include "math/point_3.h"

#include <gtest/gtest.h>
#include "testing_utility.h"
#include "math/vector_3.h"


TEST(Point3, VectorAddition) {
    Point3 p1 {1.f, 2.f, 3.f};
    Vector3 v {1.f, 2.f, 3.f};
    Point3 p2 = p1 + v;
    assertPointValues(p2, 2.f, 4.f, 6.f);
}

TEST(Point3, VectorSubtraction) {
    Point3 p1 {1.f, 2.f, 3.f};
    Vector3 v {2.f, 4.f, 6.f};
    Point3 p2 = p1 - v;
    assertPointValues(p2, -1.f, -2.f, -3.f);
}

TEST(Point3, Difference) {
    Point3 p1 {1.f, 2.f, 3.f};
    Point3 p2 {-1.f, -2.f, -3.f};
    Vector3 v = p1 - p2;
    assertVectorValues(v, 2.f, 4.f, 6.f);
}