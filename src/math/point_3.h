#ifndef IK_DEMO_POINT_3_H_
#define IK_DEMO_POINT_3_H_

#include "vector_3.h"

struct Point3 : Vector3 {
    Point3() : Vector3() {}
    Point3(float x, float y, float z) : Vector3(x, y, z) {}

    Point3 operator+(const Vector3& v);
    Point3 operator-(const Vector3& v);
    Vector3 operator-(const Point3& p);
};

inline Point3 Point3::operator+(const Vector3 &v) {
    return {x + v.x, y + v.y, z + v.z};
}

inline Point3 Point3::operator-(const Vector3 &v) {
    return {x - v.x, y - v.y, z - v.z};
}

inline Vector3 Point3::operator-(const Point3 &p) {
    return {x - p.x, y - p.y, z - p.z};
}

#endif
