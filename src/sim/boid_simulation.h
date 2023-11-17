#ifndef BOID_SIMULATION_BOID_SIMULATION_H
#define BOID_SIMULATION_BOID_SIMULATION_H

#include <vector>
#include "engine/model.h"
#include "engine/camera.h"
#include "engine/shader.h"
#include "math/transform.h"
#include "simulation.h"
#include "boid.h"

// Algorithms used are derived from https://vergenet.net/~conrad/boids/pseudocode.html
class BoidSimulation : public Simulation {
public:
    explicit BoidSimulation(Camera* camera);

    void render() override;
    void update(float delta_seconds) override;

private:
    Vector3 flyTowardsCenter(Boid& b);
    Vector3 keepDistanceFromOthers(Boid& b);
    Vector3 matchVelocity(Boid& b);
    Vector3 keepInBounds(Boid& b);
    void clampVelocity(Boid& b);

    void generateBoids();

    void drawBoids();
    void drawBoid(Boid& boid);

    std::vector<Boid> boids_ {};

    Shader boid_shader_;
    Model boid_model_ = createCubeModel();
};

#endif
