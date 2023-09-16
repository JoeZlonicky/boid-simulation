#include "camera.h"

#include "glm/geometric.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(glm::vec3 pos, glm::vec3 target, float aspect_ratio) : pos_(pos), target_(target), aspect_ratio_(aspect_ratio), fov_(45.0f) {
    glm::vec3 direction = glm::normalize(pos_ - target_);  // Name misleading because actually opposite direction

    glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right = glm::normalize(glm::cross(worldUp, direction));
    glm::vec3 up = glm::cross(direction, right);

    const float radius = 10.0f;
    const float cameraAngle = 0.0f;
    const float near_plane = 0.1f;
    const float far_plane = 100.0f;

    const float camX = std::sin(cameraAngle) * radius;
    const float camZ = std::cos(cameraAngle) * radius;

    glm::mat4 view = glm::lookAt(glm::vec3(camX, 0.0f, camZ),
                                 glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(fov_), aspect_ratio, near_plane, far_plane);
    projection_view_matrix_ = projection * view;
}
