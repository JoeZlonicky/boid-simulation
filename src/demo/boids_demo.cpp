#include "boids_demo.h"

#include <random>
#include <iostream>

BoidsDemo::BoidsDemo(Camera* camera) : Demo(camera),
                                       boid_shader_("shaders/default_vertex_shader.vert",
                                                    "shaders/default_fragment_shader.frag") {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);

    camera->setPosZ(1500.f);
    generateBoids();
}

void BoidsDemo::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawBoids();
}

void BoidsDemo::update(float delta_seconds) {
    for (Boid& b: boids_) {
        Vector3 v = flyTowardsCenter(b);
        v += keepDistanceFromOthers(b);
        v += matchVelocity(b);
        v += keepInBounds(b);

        b.velocity += v * 5 * delta_seconds;
        b.updatePosition(10.f * delta_seconds);
    }
    std::cout << boids_[0].velocity.magnitude() << std::endl;
}

Vector3 BoidsDemo::flyTowardsCenter(Boid& b) {
    Vector3 average {};
    for (Boid& other: boids_) {
        if (other == b) continue;
        average += other.transform.getPosition();
    }
    average /= static_cast<float>(boids_.size() - 1);

    return (average - b.transform.getPosition()) / 100.f;
}

Vector3 BoidsDemo::keepDistanceFromOthers(Boid& b) {
    Vector3 sum {};
    for (Boid& other: boids_) {
        if (other == b) continue;

        Vector3 pos_diff = other.transform.getPosition() - b.transform.getPosition();
        if (pos_diff.magnitude() > 100.f) continue;

        sum -= pos_diff;
    }

    return sum / 10.f;
}

Vector3 BoidsDemo::keepInBounds(Boid& b) {
    Vector3 velocity {};
    Vector3 pos = b.transform.getPosition();

    if (pos.x > 200.f) {
        velocity.x = -10.f;
    } else if (pos.x < -400.f) {
        velocity.x = 10.f;
    }
    if (pos.y > 200.f) {
        velocity.y = -10.f;
    } else if (pos.y < -200.f) {
        velocity.y = 10.f;
    }
    if (pos.z > 0.f) {
        velocity.z = -10.f;
    } else if (pos.z < -200.f) {
        velocity.z = 10.f;
    }
    return velocity;
}

Vector3 BoidsDemo::matchVelocity(Boid& b) {
    Vector3 average {};
    for (Boid& other: boids_) {
        if (other == b) continue;
        average += other.velocity;
    }
    average /= static_cast<float>(boids_.size() - 1);

    return (average - b.velocity) / 8.f;
}

void BoidsDemo::generateBoids() {
    std::random_device seed {};
    std::mt19937 generator {seed()};
    std::uniform_real_distribution<> pos_range {-400, 400};
    std::uniform_int_distribution<> velocity_range {-1, 1};

    for (int i = 0; i < 500; ++i) {
        Boid& new_boid = boids_.emplace_back();
        new_boid.transform.setPosX(static_cast<float>(pos_range(generator)));
        new_boid.transform.setPosY(static_cast<float>(pos_range(generator)));
        new_boid.transform.setPosZ(static_cast<float>(pos_range(generator)));

        new_boid.transform.setScale(10.f);
    }
}

void BoidsDemo::drawBoids() {
    boid_shader_.activate();
    boid_shader_.setUniform("projection_view", camera_->getProjectionViewMatrix());

    glBindVertexArray(boid_model_.getVAO());
    for (Boid& boid: boids_) {
        drawBoid(boid);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBindVertexArray(0);
}

void BoidsDemo::drawBoid(Boid& boid) {
    boid_shader_.setUniform("model", boid.transform.getMatrix());

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