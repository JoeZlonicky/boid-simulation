#ifndef OPENGL_DEMO_DEMO_H
#define OPENGL_DEMO_DEMO_H

#include <vector>
#include "engine/model.h"
#include "engine/camera.h"
#include "engine/shader.h"
#include "math/transform.h"

class Demo {
public:
    Demo(Shader* shader, Camera* camera);

    void render();
    void update(float time);

private:
    void drawBoid(Transform& t);
    void generateBoids();

    Shader* shader_;
    Camera* camera_;

    std::vector<Transform> boids_ {};
    Model boid_model_ = createCubeModel();
};

#endif
