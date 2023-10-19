#ifndef IK_DEMO_TRANSFORM_H_
#define IK_DEMO_TRANSFORM_H_

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

inline void Transform::updatePositionMatrix() {
    position_matrix_(0, 3) = position_.x;
    position_matrix_(1, 3) = position_.y;
    position_matrix_(2, 3) = position_.z;
    is_position_dirty_ = false;
}

inline void Transform::updateRotationMatrix() {
    rotation_matrix_ = rotation_.calcRotationMatrix();
    is_rotation_dirty_ = false;
}

inline void Transform::updateScaleMatrix() {
    scale_matrix_(0, 0) = scale_.x;
    scale_matrix_(1, 1) = scale_.y;
    scale_matrix_(2, 2) = scale_.z;
    is_scale_dirty_ = false;
}

inline const Vector3 &Transform::getPosition() const {
    return position_;
}

inline const Vector3 &Transform::getScale() const {
    return scale_;
}

inline const Quaternion &Transform::getRotation() const {
    return rotation_;
}

inline void Transform::setPos(float x, float y, float z) {
    setPosX(x);
    setPosY(y);
    setPosZ(z);
}

inline void Transform::setPosX(float x) {
    position_.x = x;
    is_position_dirty_ = true;
}

inline void Transform::setPosY(float y) {
    position_.y = y;
    is_position_dirty_ = true;
}

inline void Transform::setPosZ(float z) {
    position_.z = z;
    is_position_dirty_ = true;
}

inline void Transform::move(float x, float y, float z) {
    moveX(x);
    moveY(y);
    moveZ(z);
}

inline void Transform::moveX(float x) {
    position_.x += x;
    is_position_dirty_ = true;
}

inline void Transform::moveY(float y) {
    position_.y += y;
    is_position_dirty_ = true;
}

inline void Transform::moveZ(float z) {
    position_.z += z;
    is_position_dirty_ = true;
}

inline void Transform::setScale(float x, float y, float z) {
    setScaleX(x);
    setScaleY(y);
    setScaleZ(z);
}

inline void Transform::setScaleX(float x) {
    scale_.x = x;
    is_scale_dirty_ = true;
}

inline void Transform::setScaleY(float y) {
    scale_.y = y;
    is_scale_dirty_ = true;
}

inline void Transform::setScaleZ(float z) {
    scale_.z = z;
    is_scale_dirty_ = true;
}

inline void Transform::setRotation(Quaternion q) {
    rotation_ = q;
    is_rotation_dirty_ = true;
}

inline void Transform::rotate(Quaternion q) {
    rotation_ = q * rotation_;
    is_rotation_dirty_ = true;
}

inline const Matrix4& Transform::getMatrix() {
    bool is_transform_dirty = false;
    if (is_position_dirty_) {
        updatePositionMatrix();
        is_transform_dirty = true;
    }
    if (is_scale_dirty_) {
        updateScaleMatrix();
        is_transform_dirty = true;
    }
    if (is_rotation_dirty_) {
        updateRotationMatrix();
        is_transform_dirty = true;
    }
    if (is_transform_dirty) {
        matrix_ = position_matrix_ * rotation_matrix_ * scale_matrix_;
    }
    return matrix_;
}

#endif
