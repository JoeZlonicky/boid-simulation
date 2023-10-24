#include "demo.h"

#include <cmath>


Demo::Demo(Shader *shader, Camera *camera) : shader(shader), camera(camera) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POLYGON_OFFSET_FILL);

    topCube.getTransform().setPosY(3.f);
    rightCube.getTransform().setPosX(5.f);
    cornerCube.getTransform().setPos(-5.f, -3.f, 0.f);
}

void Demo::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader->activate();
    shader->setUniform("projection_view", camera->getProjectionViewMatrix());

    drawCube(topCube);
    drawCube(rightCube);
    drawCube(cornerCube);
    drawCube(centerCube);
}

void Demo::update(float time) {
    const float left_to_right_translation = std::cos(time + 1.f) * 3.f - 1.f;
    const Quaternion x_axis_rotation {{1.f, 0.f, 0.f}, fmodf(time * 50.f, 360.f)};
    topCube.getTransform().setPosX(left_to_right_translation);
    topCube.getTransform().setRotation(x_axis_rotation);

    const float up_and_down_translation = std::cos(time + 2.f) * 2.f;
    const Quaternion y_axis_rotation {{0.f, 1.f, 0.f}, fmodf(time * 50.f, 360.f)};
    rightCube.getTransform().setPosY(up_and_down_translation);
    rightCube.getTransform().setRotation(y_axis_rotation);

    const float back_and_forth_translation = std::cos(time + 3.f) * -3.f - 2.f;
    const Quaternion z_axis_rotation {{0.f, 0.f, 1.f}, fmodf(time * 50.f, 360.f)};
    cornerCube.getTransform().setPosZ(back_and_forth_translation);
    cornerCube.getTransform().setRotation(z_axis_rotation);

    float x_scale = 1.f + std::cos(time + 4.f) * 0.5f;
    float y_scale = 1.f + std::cos(time + 5.f) * 0.5f;
    float z_scale = 1.f + std::cos(time + 6.f) * 0.5f;
    const Quaternion everything_rotation = x_axis_rotation * y_axis_rotation * z_axis_rotation;
    centerCube.getTransform().setScale(x_scale, y_scale, z_scale);
    centerCube.getTransform().setRotation(everything_rotation);
}

void Demo::drawCube(Cube &cube) {
    glBindVertexArray(cube.getVAO());
    shader->setUniform("model", cube.getTransform().getMatrix());

    shader->setUniform("color", 0.4, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonOffset(0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, cube.getVertexCount());

    shader->setUniform("color", 1.0, 0.0, 0.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2.0f);
    glPolygonOffset(10.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, cube.getVertexCount());

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glLineWidth(1.0f);
    glBindVertexArray(0);
}
