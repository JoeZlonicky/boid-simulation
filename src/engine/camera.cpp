#include "camera.h"

#include <cmath>

Camera::Camera(Vector3 pos, Vector3 target, float aspect_ratio) : pos_(pos), target_(target), aspect_ratio_(aspect_ratio), fov_(45.0f) {
    calculateProjectionViewMatrix();
}

void Camera::setPos(Vector3 pos) {
    pos_ = pos;
    calculateProjectionViewMatrix();
}

void Camera::setTarget(Vector3 target) {
    target_ = target;
    calculateProjectionViewMatrix();
}

const Matrix4 & Camera::getProjectionViewMatrix() {
    return projection_view_matrix_;
}

void Camera::calculateProjectionViewMatrix() {
    Vector3 to_camera = (pos_ - target_).normalized();

    Vector3 world_up = {0.0f, 1.0f, 0.0f};
    Vector3 right = world_up.cross(to_camera).normalized();
    Vector3 up = to_camera.cross(right);

    const float near_plane = 0.1f;
    const float far_plane = 100.0f;

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
    float fov_radians = (fov_ / 180.f) * static_cast<float>(M_PI);
    float tan_half_fov = std::tan(fov_radians / 2.0f);
    projection(0, 0) = 1.f / (aspect_ratio_ * tan_half_fov);
    projection(1, 1) = 1.f / tan_half_fov;
    projection(2, 2) = -(far_plane + near_plane) / (far_plane - near_plane);
    projection(3, 2) = -1.f;
    projection(2, 3) = -(2.f * far_plane * near_plane) / (far_plane - near_plane);

    projection_view_matrix_ = projection * view;

}
