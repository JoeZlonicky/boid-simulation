#include "camera.h"

#include <cmath>

Camera::Camera(Vector3 pos, Vector3 target, float aspect_ratio) : pos_(pos), target_(target), aspect_ratio_(aspect_ratio) {
    dirtyMatrixFlag = true;
}

void Camera::setPos(Vector3 pos) {
    pos_ = pos;
    dirtyMatrixFlag = true;
}

void Camera::setPosX(float x) {
    pos_.x = x;
    dirtyMatrixFlag = true;
}

void Camera::setPosY(float y) {
    pos_.y = y;
    dirtyMatrixFlag = true;
}

void Camera::setPosZ(float z) {
    pos_.z = z;
}

void Camera::setTarget(Vector3 target) {
    target_ = target;
    dirtyMatrixFlag = true;
}

void Camera::setFOV(float degrees) {
    fov_degrees_ = degrees;
    dirtyMatrixFlag = true;
}

void Camera::setNearPlane(float d) {
    near_plane_ = d;
    dirtyMatrixFlag = true;
}

void Camera::setFarPlane(float d) {
    far_plane_ = d;
    dirtyMatrixFlag = true;
}

void Camera::setAspectRatio(float ratio) {
    aspect_ratio_ = ratio;
    dirtyMatrixFlag = true;
}


const Matrix4 & Camera::getProjectionViewMatrix() {
    if (dirtyMatrixFlag) {
        calculateProjectionViewMatrix();
    }
    return projection_view_matrix_;
}

const Vector3 &Camera::getPos() {
    return pos_;
}

void Camera::calculateProjectionViewMatrix() {
    Vector3 to_camera = (pos_ - target_).normalized();

    Vector3 world_up = {0.0f, 1.0f, 0.0f};
    Vector3 right = world_up.cross(to_camera).normalized();
    Vector3 up = to_camera.cross(right);

    Matrix4 view = Matrix4{
        right.x, right.y, right.z, 0.0f,
        up.x, up.y, up.z, 0.0f,
        to_camera.x, to_camera.y, to_camera.z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f}
        * Matrix4{
            1.0f, 0.0f, 0.0f, -pos_.x,
            0.0f, 1.0f, 0.0f, -pos_.y,
            0.0f, 0.0f, 1.0f, -pos_.z,
            0.f, 0.f, 0.f, 1.0f};

    Matrix4 projection = Matrix4{0.f};
    float fov_radians = (fov_degrees_ / 180.f) * static_cast<float>(M_PI);
    float tan_half_fov = std::tan(fov_radians / 2.0f);
    projection(0, 0) = 1.f / (aspect_ratio_ * tan_half_fov);
    projection(1, 1) = 1.f / tan_half_fov;
    projection(2, 2) = -(far_plane_ + near_plane_) / (far_plane_ - near_plane_);
    projection(3, 2) = -1.f;
    projection(2, 3) = -(2.f * far_plane_ * near_plane_) / (far_plane_ - near_plane_);

    projection_view_matrix_ = projection * view;
    dirtyMatrixFlag = false;
}
