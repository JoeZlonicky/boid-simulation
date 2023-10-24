#ifndef OPENGL_DEMO_TRANSFORM_H_
#define OPENGL_DEMO_TRANSFORM_H_

#include "math/vector_3.h"
#include "math/quaternion.h"
#include "math/matrix_4.h"

class Transform {
public:
    Transform() = default;

    [[nodiscard]] const Vector3& getPosition() const;
    [[nodiscard]] const Vector3& getScale() const;
    [[nodiscard]] const Quaternion& getRotation() const;

    void setPos(float x, float y, float z);
    void setPos(const Vector3& v);
    void setPosX(float x);
    void setPosY(float y);
    void setPosZ(float z);

    void move(float x, float y, float z);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);

    void setScale(float x, float y, float z);
    void setScaleX(float x);
    void setScaleY(float y);
    void setScaleZ(float z);

    void setRotation(Quaternion q);
    void rotate(Quaternion q);

    const Matrix4& getMatrix();

private:
    void updatePositionMatrix();
    void updateRotationMatrix();
    void updateScaleMatrix();

    Vector3 position_ {0.f};
    Quaternion rotation_ {};
    Vector3 scale_ {1.f};

    bool is_position_dirty_ = true;
    bool is_rotation_dirty_ = true;
    bool is_scale_dirty_ = true;
    Matrix4 position_matrix_ {1.f};
    Matrix4 scale_matrix_ {1.f};
    Matrix4 rotation_matrix_ {1.f};

    Matrix4 matrix_ {0.f};
};

#endif
