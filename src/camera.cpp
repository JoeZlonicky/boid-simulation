#include "camera.h"

#include "glm/geometric.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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

const glm::mat4 &Camera::getProjectionViewMatrix() {
    return projection_view_matrix_;
}

void Camera::calculateProjectionViewMatrix() {
    Vector3 to_camera = (pos_ - target_).normalized();

    Vector3 world_up = {0.0f, 1.0f, 0.0f};
    Vector3 right = world_up.cross(to_camera).normalized();
    Vector3 up = to_camera.cross(right);

    const float near_plane = 0.1f;
    const float far_plane = 100.0f;

    glm::mat4 view = glm::mat4(right.x, up.x, to_camera.x, 0.0f,
                               right.y, up.y, to_camera.y, 0.0f,
                               right.z, up.z, to_camera.z, 0.0f,
                               0.0f, 0.0f, 0.0f, 1.0f);
    view *= glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 1.0f, 0.0f,
                      -pos_.x, -pos_.y, -pos_.z, 1.0f);

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(fov_), aspect_ratio_, near_plane, far_plane);
    projection_view_matrix_ = projection * view;
}
