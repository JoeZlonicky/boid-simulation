#ifndef IK_DEMO_CAMERA_H_
#define IK_DEMO_CAMERA_H_

#include "glm/ext/matrix_float4x4.hpp"
#include "math/vector_3.h"

class Camera {
public:
    Camera(Vector3 pos, Vector3 target, float aspect_ratio);

    void setPos(Vector3 pos);
    void setTarget(Vector3 target);

    const glm::mat4& getProjectionViewMatrix();

private:
    void calculateProjectionViewMatrix();

    Vector3 pos_;
    Vector3 target_;
    float fov_;
    float aspect_ratio_;

    glm::mat4 projection_view_matrix_ = glm::mat4();
};

#endif
