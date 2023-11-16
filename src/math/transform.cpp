#include "transform.h"

const Vector3& Transform::getPosition() const {
    return position_;
}

const Vector3& Transform::getScale() const {
    return scale_;
}

const Quaternion& Transform::getRotation() const {
    return rotation_;
}

void Transform::setPos(float x, float y, float z) {
    setPosX(x);
    setPosY(y);
    setPosZ(z);
}

void Transform::setPos(const Vector3& v) {
    setPosX(v.x);
    setPosY(v.y);
    setPosZ(v.z);
}

void Transform::setPosX(float x) {
    position_.x = x;
    is_position_dirty_ = true;
}

void Transform::setPosY(float y) {
    position_.y = y;
    is_position_dirty_ = true;
}

void Transform::setPosZ(float z) {
    position_.z = z;
    is_position_dirty_ = true;
}

void Transform::move(float x, float y, float z) {
    moveX(x);
    moveY(y);
    moveZ(z);
}

void Transform::moveX(float x) {
    position_.x += x;
    is_position_dirty_ = true;
}

void Transform::moveY(float y) {
    position_.y += y;
    is_position_dirty_ = true;
}

void Transform::moveZ(float z) {
    position_.z += z;
    is_position_dirty_ = true;
}

void Transform::setScale(float x, float y, float z) {
    setScaleX(x);
    setScaleY(y);
    setScaleZ(z);
}

void Transform::setScale(float s) {
    setScale(s, s, s);
}

void Transform::setScaleX(float x) {
    scale_.x = x;
    is_scale_dirty_ = true;
}

void Transform::setScaleY(float y) {
    scale_.y = y;
    is_scale_dirty_ = true;
}

void Transform::setScaleZ(float z) {
    scale_.z = z;
    is_scale_dirty_ = true;
}

void Transform::setRotation(Quaternion q) {
    rotation_ = q;
    is_rotation_dirty_ = true;
}

void Transform::rotate(Quaternion q) {
    rotation_ = q * rotation_;
    is_rotation_dirty_ = true;
}

const Matrix4& Transform::getMatrix() {
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

void Transform::updatePositionMatrix() {
    position_matrix_(0, 3) = position_.x;
    position_matrix_(1, 3) = position_.y;
    position_matrix_(2, 3) = position_.z;
    is_position_dirty_ = false;
}

void Transform::updateRotationMatrix() {
    rotation_matrix_ = rotation_.calcRotationMatrix4();
    is_rotation_dirty_ = false;
}

void Transform::updateScaleMatrix() {
    scale_matrix_(0, 0) = scale_.x;
    scale_matrix_(1, 1) = scale_.y;
    scale_matrix_(2, 2) = scale_.z;
    is_scale_dirty_ = false;
}
