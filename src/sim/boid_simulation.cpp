#include "boid_simulation.h"
#include <random>
#include <iostream>

constexpr float CAMERA_DISTANCE = 1500.f;
constexpr float CAMERA_FOV = 75.f;
constexpr float BOID_SIZE = 15.f;

constexpr float ACCELERATION_MODIFIER = 10.f;
constexpr float VELOCITY_MODIFIER = 10.f;

constexpr int N_BOIDS = 200;

constexpr float FLY_TOWARDS_CENTER_STRENGTH = 0.01f;
constexpr float KEEP_DISTANCE_FROM_OTHERS_STRENGTH = 0.2f;
constexpr float KEEP_DISTANCE_CONSIDERATION_DISTANCE = 150.f;
constexpr float MATCH_VELOCITY_STRENGTH = 0.12f;
constexpr float KEEP_IN_BOUNDS_STRENGTH = 10.f;
constexpr float MAX_VELOCITY = 100.f;

constexpr float SPAWN_AREA_SIZE = 800.f;
constexpr float HALF_SPAWN_AREA_SIZE = SPAWN_AREA_SIZE / 2.f;
constexpr float BOUNDS_SIZE = 400.f;
constexpr float HALF_BOUNDS_SIZE = BOUNDS_SIZE / 2.f;

BoidSimulation::BoidSimulation(Camera* camera) : Simulation(camera),
                                                 boid_shader_("shaders/default_vertex_shader.vert",
                                                              "shaders/default_fragment_shader.frag") {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);

    camera->setPosZ(CAMERA_DISTANCE);
    camera->setFOV(CAMERA_FOV);
    generateBoids();
}

void BoidSimulation::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    boid_shader_.activate();
    boid_shader_.setUniform("projection_view", camera_->getProjectionViewMatrix());

    glBindVertexArray(boid_model_.getVAO());
    for (Boid& boid : boids_) {
        drawBoid(boid.transform);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(0);
}

void BoidSimulation::update(float delta_seconds) {
    for (Boid& b : boids_) {
        Vector3 v = flyTowardsCenter(b);
        v += keepDistanceFromOthers(b);
        v += matchVelocity(b);
        v += keepInBounds(b);

        b.velocity += v * ACCELERATION_MODIFIER * delta_seconds;
        clampVelocity(b);

        b.updateRotation();
        b.updatePosition(VELOCITY_MODIFIER * delta_seconds);
    }
}

Vector3 BoidSimulation::flyTowardsCenter(Boid& b) {
    Vector3 average {};
    for (Boid& other : boids_) {
        if (other == b) continue;
        average += other.transform.getPosition();
    }
    average /= static_cast<float>(boids_.size() - 1);

    return (average - b.transform.getPosition()) * FLY_TOWARDS_CENTER_STRENGTH;
}

Vector3 BoidSimulation::keepDistanceFromOthers(Boid& b) {
    Vector3 sum {};
    for (Boid& other : boids_) {
        if (other == b) continue;

        Vector3 pos_diff = other.transform.getPosition() - b.transform.getPosition();
        if (pos_diff.magnitude() > KEEP_DISTANCE_CONSIDERATION_DISTANCE) continue;

        sum -= pos_diff;
    }

    return sum * KEEP_DISTANCE_FROM_OTHERS_STRENGTH;
}

Vector3 BoidSimulation::matchVelocity(Boid& b) {
    Vector3 average {};
    for (Boid& other : boids_) {
        if (other == b) continue;
        average += other.velocity;
    }
    average /= static_cast<float>(boids_.size() - 1);

    return (average - b.velocity) * MATCH_VELOCITY_STRENGTH;
}

Vector3 BoidSimulation::keepInBounds(Boid& b) {
    Vector3 velocity {};
    Vector3 pos = b.transform.getPosition();

    if (pos.x > HALF_BOUNDS_SIZE) {
        velocity.x = -KEEP_IN_BOUNDS_STRENGTH;
    } else if (pos.x < -HALF_BOUNDS_SIZE) {
        velocity.x = KEEP_IN_BOUNDS_STRENGTH;
    }
    if (pos.y > HALF_BOUNDS_SIZE) {
        velocity.y = -KEEP_IN_BOUNDS_STRENGTH;
    } else if (pos.y < -HALF_BOUNDS_SIZE) {
        velocity.y = KEEP_IN_BOUNDS_STRENGTH;
    }
    if (pos.z > HALF_BOUNDS_SIZE) {
        velocity.z = -KEEP_IN_BOUNDS_STRENGTH;
    } else if (pos.z < HALF_BOUNDS_SIZE) {
        velocity.z = KEEP_IN_BOUNDS_STRENGTH;
    }
    return velocity;
}

void BoidSimulation::clampVelocity(Boid& b) {
    b.velocity.clamp(MAX_VELOCITY);
}

void BoidSimulation::generateBoids() {
    std::random_device seed {};
    std::mt19937 generator {seed()};
    std::uniform_real_distribution<> pos_range {-HALF_SPAWN_AREA_SIZE, HALF_SPAWN_AREA_SIZE};

    for (int i = 0; i < N_BOIDS; ++i) {
        Boid& new_boid = boids_.emplace_back();
        new_boid.transform.setPosX(static_cast<float>(pos_range(generator)));
        new_boid.transform.setPosY(static_cast<float>(pos_range(generator)));
        new_boid.transform.setPosZ(static_cast<float>(pos_range(generator)));

        new_boid.transform.setScale(BOID_SIZE);
    }
}

void BoidSimulation::drawBoid(Transform& t) {
    boid_shader_.setUniform("model", t.getMatrix());

    boid_shader_.setUniform("color", 0.4, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(1.0f);
    glPolygonOffset(0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, boid_model_.getVertexCount());

    boid_shader_.setUniform("color", 1.0, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2.0f);
    glPolygonOffset(10.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, boid_model_.getVertexCount());
}
