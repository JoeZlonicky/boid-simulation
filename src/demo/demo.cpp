#include "demo.h"

#include <cmath>


Demo::Demo(Shader *shader, Camera *camera) : shader_(shader), camera_(camera) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);

    top_cube_.getTransform().setPosY(3.f);
    right_cube_.getTransform().setPosX(5.f);
    corner_cube.getTransform().setPos(-5.f, -3.f, 0.f);
}

void Demo::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader_->activate();
    shader_->setUniform("projection_view", camera_->getProjectionViewMatrix());

    drawCube(top_cube_);
    drawCube(right_cube_);
    drawCube(corner_cube);
    drawCube(center_cube_);
}

void Demo::update(float time) {
    // Numbers like 1.f, 2.f, 3.f, etc. are added to trig functions to make everything less synchronized
    const float left_to_right_translation = std::cos(time + 1.f) * 3.f - 1.f;
    const Quaternion x_axis_rotation {{1.f, 0.f, 0.f}, fmodf(time * 50.f, 360.f)};
    const float z_scale = 1.f + std::cos(time + 6.f) * 0.5f;
    top_cube_.getTransform().setPosX(left_to_right_translation);
    top_cube_.getTransform().setRotation(x_axis_rotation);
    top_cube_.getTransform().setScaleZ(z_scale);

    const float up_and_down_translation = std::cos(time + 2.f) * 2.f;
    const Quaternion y_axis_rotation {{0.f, 1.f, 0.f}, fmodf(time * 50.f, 360.f)};
    const float x_scale = 1.f + std::cos(time + 4.f) * 0.5f;
    right_cube_.getTransform().setPosY(up_and_down_translation);
    right_cube_.getTransform().setRotation(y_axis_rotation);
    right_cube_.getTransform().setScaleX(x_scale);

    const float back_and_forth_translation = std::cos(time + 3.f) * -3.f - 2.f;
    const Quaternion z_axis_rotation {{0.f, 0.f, 1.f}, fmodf(time * 50.f, 360.f)};
    const float y_scale = 1.f + std::cos(time + 5.f) * 0.5f;
    corner_cube.getTransform().setPosZ(back_and_forth_translation);
    corner_cube.getTransform().setRotation(z_axis_rotation);
    corner_cube.getTransform().setScaleY(y_scale);

    const Quaternion everything_rotation = x_axis_rotation * y_axis_rotation * z_axis_rotation;
    center_cube_.getTransform().setScale(x_scale, y_scale, z_scale);
    center_cube_.getTransform().setRotation(everything_rotation);
}

void Demo::drawCube(Cube &cube) {
    glBindVertexArray(cube.getVAO());
    shader_->setUniform("model", cube.getTransform().getMatrix());

    shader_->setUniform("color", 0.4, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonOffset(0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, cube.getVertexCount());

    shader_->setUniform("color", 1.0, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2.0f);
    glPolygonOffset(10.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, cube.getVertexCount());

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(1.0f);
    glBindVertexArray(0);
}
