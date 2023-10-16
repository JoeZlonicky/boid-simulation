#ifndef IK_DEMO_CAMERA_H_
#define IK_DEMO_CAMERA_H_

#include "math/vector_3.h"
#include "math/matrix_4.h"

class Camera {
public:
    Camera(Vector3 pos, Vector3 target, float aspect_ratio);

    void setPos(Vector3 pos);
    void setTarget(Vector3 target);

    const Matrix4& getProjectionViewMatrix();

private:
    void calculateProjectionViewMatrix();

    Vector3 pos_;
    Vector3 target_;
    float fov_;
    float aspect_ratio_;

    Matrix4 projection_view_matrix_ = {};
};

#endif
