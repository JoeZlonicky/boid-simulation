#ifndef OPENGL_DEMO_BOIDS_DEMO_H
#define OPENGL_DEMO_BOIDS_DEMO_H

#include <vector>
#include "engine/model.h"
#include "engine/camera.h"
#include "engine/shader.h"
#include "math/transform.h"
#include "demo.h"
#include "boid.h"

class BoidsDemo : public Demo {
public:
    explicit BoidsDemo(Camera* camera);

    void render() override;
    void update(float delta_seconds) override;

private:
    void drawBoids();
    void drawBoid(Boid& t);
    void generateBoids();

    std::vector<Boid> boids_ {};

    Shader boid_shader_;
    Model boid_model_ = createCubeModel();
};

#endif
