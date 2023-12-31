#include "camera.h"

#include <cmath>

Camera::Camera() : pos_(0.f, 0.f, 0.f), target_(0.f, 0.f, -0.1f), aspect_ratio_(16.f / 9.f) {}

Camera::Camera(Vector3 pos, Vector3 target, float aspect_ratio) : pos_(pos), target_(target),
                                                                  aspect_ratio_(aspect_ratio) {
}

void Camera::setPos(Vector3 pos) {
    pos_ = pos;
    dirty_matrix_flag_ = true;
}

void Camera::setPosX(float x) {
    pos_.x = x;
    dirty_matrix_flag_ = true;
}

void Camera::setPosY(float y) {
    pos_.y = y;
    dirty_matrix_flag_ = true;
}

void Camera::setPosZ(float z) {
    pos_.z = z;
    dirty_matrix_flag_ = true;
}

void Camera::setTarget(Vector3 target) {
    target_ = target;
    dirty_matrix_flag_ = true;
}

void Camera::setFOV(float degrees) {
    fov_degrees_ = degrees;
    dirty_matrix_flag_ = true;
}

void Camera::setNearPlane(float d) {
    near_plane_ = d;
    dirty_matrix_flag_ = true;
}

void Camera::setFarPlane(float d) {
    far_plane_ = d;
    dirty_matrix_flag_ = true;
}

void Camera::setAspectRatio(float ratio) {
    aspect_ratio_ = ratio;
    dirty_matrix_flag_ = true;
}

const Matrix4& Camera::getProjectionViewMatrix() {
    if (dirty_matrix_flag_) {
        calculateProjectionViewMatrix();
    }
    return projection_view_matrix_;
}

const Vector3& Camera::getPos() {
    return pos_;
}

void Camera::calculateProjectionViewMatrix() {
    Vector3 to_camera = (pos_ - target_).normalized();

    Vector3 world_up = {0.f, 1.f, 0.f};
    Vector3 right = world_up.cross(to_camera).normalized();
    Vector3 up = to_camera.cross(right);

    Matrix4 view = Matrix4 {
            right.x, right.y, right.z, 0.f,
            up.x, up.y, up.z, 0.f,
            to_camera.x, to_camera.y, to_camera.z, 0.f,
            0.f, 0.f, 0.f, 1.f}
                   * Matrix4 {
            1.f, 0.f, 0.f, -pos_.x,
            0.f, 1.f, 0.f, -pos_.y,
            0.f, 0.f, 1.f, -pos_.z,
            0.f, 0.f, 0.f, 1.f};

    Matrix4 projection = Matrix4 {0.f};
    float fov_radians = (fov_degrees_ / 180.f) * static_cast<float>(M_PI);
    float tan_half_fov = std::tan(fov_radians / 2.f);
    projection(0, 0) = 1.f / (aspect_ratio_ * tan_half_fov);
    projection(1, 1) = 1.f / tan_half_fov;
    projection(2, 2) = -(far_plane_ + near_plane_) / (far_plane_ - near_plane_);
    projection(3, 2) = -1.f;
    projection(2, 3) = -(2.f * far_plane_ * near_plane_) / (far_plane_ - near_plane_);

    projection_view_matrix_ = projection * view;
    dirty_matrix_flag_ = false;
}
