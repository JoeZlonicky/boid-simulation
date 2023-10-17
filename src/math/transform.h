#ifndef IK_DEMO_TRANSFORM_H_
#define IK_DEMO_TRANSFORM_H_

#include "vector_3.h"
#include "quaternion.h"
#include "matrix_4.h"

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
    [[nodiscard]] Matrix4 calcTranslationMatrix() const;
    [[nodiscard]] Matrix4 calcScaleMatrix() const;

    Vector3 position_ {0.f};
    Vector3 scale_ {1.f};
    Quaternion rotation_ {};

    bool is_matrix_dirty_ = true;
    Matrix4 matrix_ {0.f};
};

inline Matrix4 Transform::calcTranslationMatrix() const {
    return {
        1.f, 0.f, 0.f, position_.x,
        0.f, 1.f, 0.f, position_.y,
        0.f, 0.f, 1.f, position_.z,
        0.f, 0.f, 0.f, 1.f
    };
}

inline Matrix4 Transform::calcScaleMatrix() const {
    return {
        scale_.x, 0.f, 0.f, 0.f,
        0.f, scale_.y, 0.f, 0.f,
        0.f, 0.f, scale_.z, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
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
    is_matrix_dirty_ = true;
}

inline void Transform::setPosY(float y) {
    position_.y = y;
    is_matrix_dirty_ = true;
}

inline void Transform::setPosZ(float z) {
    position_.z = z;
    is_matrix_dirty_ = true;
}

inline void Transform::move(float x, float y, float z) {
    moveX(x);
    moveY(y);
    moveZ(z);
}

inline void Transform::moveX(float x) {
    position_.x += x;
    is_matrix_dirty_ = true;
}

inline void Transform::moveY(float y) {
    position_.y += y;
    is_matrix_dirty_ = true;
}

inline void Transform::moveZ(float z) {
    position_.z += z;
    is_matrix_dirty_ = true;
}

inline void Transform::setScale(float x, float y, float z) {
    setScaleX(x);
    setScaleY(y);
    setScaleZ(z);
}

inline void Transform::setScaleX(float x) {
    scale_.x = x;
    is_matrix_dirty_ = true;
}

inline void Transform::setScaleY(float y) {
    scale_.y = y;
    is_matrix_dirty_ = true;
}

inline void Transform::setScaleZ(float z) {
    scale_.z = z;
    is_matrix_dirty_ = true;
}

inline void Transform::setRotation(Quaternion q) {
    rotation_ = q;
    is_matrix_dirty_ = true;
}

inline void Transform::rotate(Quaternion q) {
    rotation_ = q * rotation_;
    is_matrix_dirty_ = true;
}

inline const Matrix4& Transform::getMatrix() {
    if (is_matrix_dirty_) {
        matrix_ =  calcTranslationMatrix() * rotation_.calcRotationMatrix() * calcScaleMatrix();
        is_matrix_dirty_ = false;
    }
    return matrix_;
}

#endif
