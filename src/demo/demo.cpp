#include "demo.h"

#include <cmath>
#include <random>

Demo::Demo(Shader* shader, Camera* camera) : shader_(shader), camera_(camera) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);
    generateBoids();
}

void Demo::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader_->activate();
    shader_->setUniform("projection_view", camera_->getProjectionViewMatrix());
    for (Transform& boid: boids_) {
        drawBoid(boid);
    }
}

void Demo::update(float time) {

}

void Demo::drawBoid(Transform& t) {
    glBindVertexArray(boid_model_.getVAO());
    shader_->setUniform("model", t.getMatrix());

    shader_->setUniform("color", 0.4, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonOffset(0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, boid_model_.getVertexCount());

    shader_->setUniform("color", 1.0, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2.0f);
    glPolygonOffset(10.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, boid_model_.getVertexCount());

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(1.0f);
    glBindVertexArray(0);
}

void Demo::generateBoids() {
    std::random_device seed {};
    std::mt19937 generator {seed()};
    std::uniform_int_distribution<> range {-500, 500};

    for (int i = 0; i < 25; ++i) {
        Transform& new_boid = boids_.emplace_back();
        new_boid.setPosX(static_cast<float>(range(generator)) / 100.f);
        new_boid.setPosY(static_cast<float>(range(generator)) / 100.f);
        new_boid.setPosZ(static_cast<float>(range(generator)) / 100.f);
        new_boid.setScale(0.25f);
    }

}
