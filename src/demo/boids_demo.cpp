#include "boids_demo.h"

#include <random>
#include <iostream>

BoidsDemo::BoidsDemo(Camera* camera) : Demo(camera),
                                       boid_shader_("shaders/default_vertex_shader.vert",
                                                    "shaders/default_fragment_shader.frag") {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);

    camera->setPosZ(15.f);
    generateBoids();
}

void BoidsDemo::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawBoids();
}

void BoidsDemo::update(float delta_seconds) {
    for (Boid& b: boids_) {
        b.update(delta_seconds);
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

void BoidsDemo::generateBoids() {
    std::random_device seed {};
    std::mt19937 generator {seed()};
    std::uniform_real_distribution<> pos_range {-5, 5};
    std::uniform_int_distribution<> velocity_range {-1, 1};

    for (int i = 0; i < 25; ++i) {
        Boid& new_boid = boids_.emplace_back();
        new_boid.transform.setPosX(static_cast<float>(pos_range(generator)));
        new_boid.transform.setPosY(static_cast<float>(pos_range(generator)));
        new_boid.transform.setPosZ(static_cast<float>(pos_range(generator)));

        new_boid.velocity.x = static_cast<float>(velocity_range(generator));
        new_boid.velocity.y = static_cast<float>(velocity_range(generator));
        new_boid.velocity.z = static_cast<float>(velocity_range(generator));

        new_boid.transform.setScale(0.25f);
    }
}
