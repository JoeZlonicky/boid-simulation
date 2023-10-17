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

private:
    [[nodiscard]] Matrix4 calcTranslationMatrix() const;
    [[nodiscard]] Matrix4 calcScaleMatrix() const;

    Vector3 position {0.f};
    Vector3 scale {1.f};
    Quaternion rotation {};

    bool isMatrixDirty = false;
    Matrix4 matrix {0.f};
};

inline Matrix4 Transform::calcTranslationMatrix() const {
    return {
        1.f, 0.f, 0.f, position.x,
        0.f, 1.f, 0.f, position.y,
        0.f, 0.f, 1.f, position.z,
        0.f, 0.f, 0.f, 1.f
    };
}

inline Matrix4 Transform::calcScaleMatrix() const {
    return {
        scale.x, 0.f, 0.f, 0.f,
        0.f, scale.y, 0.f, 0.f,
        0.f, 0.f, scale.z, 0.f,
        0.f, 0.f, 0.f, 1.f
    };
}

inline const Vector3 &Transform::getPosition() const {
    return position;
}

inline const Vector3 &Transform::getScale() const {
    return scale;
}

inline const Quaternion &Transform::getRotation() const {
    return rotation;
}

inline void Transform::setPos(float x, float y, float z) {
    setPosX(x);
    setPosY(y);
    setPosZ(z);
}

inline void Transform::setPosX(float x) {
    position.x = x;
    isMatrixDirty = true;
}

inline void Transform::setPosY(float y) {
    position.y = y;
    isMatrixDirty = true;
}

inline void Transform::setPosZ(float z) {
    position.z = z;
    isMatrixDirty = true;
}

inline void Transform::move(float x, float y, float z) {
    moveX(x);
    moveY(y);
    moveZ(z);
}

inline void Transform::moveX(float x) {
    position.x += x;
    isMatrixDirty = true;
}

inline void Transform::moveY(float y) {
    position.y += y;
    isMatrixDirty = true;
}

inline void Transform::moveZ(float z) {
    position.z += z;
    isMatrixDirty = true;
}

inline void Transform::setScale(float x, float y, float z) {
    setScaleX(x);
    setScaleY(y);
    setScaleZ(z);
}

inline void Transform::setScaleX(float x) {
    scale.x = x;
    isMatrixDirty = true;
}

inline void Transform::setScaleY(float y) {
    scale.y = y;
    isMatrixDirty = true;
}

inline void Transform::setScaleZ(float z) {
    scale.z = z;
    isMatrixDirty = true;
}

inline void Transform::setRotation(Quaternion q) {
    rotation = q;
}

inline void Transform::rotate(Quaternion q) {
    rotation = rotation * q;
}

#endif
