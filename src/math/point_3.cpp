#include "point_3.h"

Point3 Point3::operator+(const Vector3 &v) {
    return {x + v.x, y + v.y, z + v.z};
}

Point3 Point3::operator-(const Vector3 &v) {
    return {x - v.x, y - v.y, z - v.z};
}