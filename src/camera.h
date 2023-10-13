#ifndef SIM_ENGINE_CAMERA_H_
#define SIM_ENGINE_CAMERA_H_

#include "glm/vec3.hpp"
#include "glm/ext/matrix_float4x4.hpp"

class Camera {
public:
    Camera(glm::vec3 pos, glm::vec3 target, float aspect_ratio);

    const glm::mat4& getProjectionViewMatrix() {
        return projection_view_matrix_;
    }

private:
    glm::vec3 pos_;
    glm::vec3 target_;
    float fov_;
    float aspect_ratio_;

    glm::mat4 projection_view_matrix_;
};

#endif
