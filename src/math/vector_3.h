#ifndef OPENGL_DEMO_VECTOR_3_H_
#define OPENGL_DEMO_VECTOR_3_H_

// Implementation takes inspiration from
// 1) Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// 2) Godot Game Engine source code
struct Vector3 {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float components[3] = {0.f};
    };

    Vector3();
    explicit Vector3(float value);
    Vector3(float x, float y, float z);

    float& operator[](int i);
    const float& operator[](int i) const;

    Vector3& operator*=(float s);

    Vector3& operator/=(float s);

    Vector3& operator+=(const Vector3& v);

    Vector3& operator-=(const Vector3& v);

    void normalize();
    [[nodiscard]] Vector3 normalized() const;

    [[nodiscard]] float magnitude() const;

    [[nodiscard]] Vector3 cross(const Vector3& v) const;

    [[nodiscard]] float dot(const Vector3& v) const;
};

Vector3 operator*(Vector3 v, float s);

Vector3 operator/(Vector3 v, float s);

Vector3 operator+(Vector3 a, const Vector3& b);

Vector3 operator-(Vector3 a, const Vector3& b);
Vector3 operator-(Vector3 v);

#endif
