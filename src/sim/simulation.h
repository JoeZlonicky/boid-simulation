#ifndef BOID_SIMULATION_SIMULATION_H
#define BOID_SIMULATION_SIMULATION_H

#include "engine/camera.h"

class Simulation {
public:
    explicit Simulation(Camera* camera);
    virtual ~Simulation() = default;

    virtual void render() = 0;
    virtual void update(float delta_seconds) = 0;

protected:
    Camera* camera_;
};

#endif //BOID_SIMULATION_SIMULATION_H
