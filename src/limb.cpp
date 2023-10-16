#include "limb.h"

#include <stdexcept>
#include "glad/glad.h"
#include "engine/shader.h"


Limb::~Limb() {
    glDeleteVertexArrays(1, &vao_);
    glDeleteBuffers(1, &vbo_);
}

const Matrix4 &Limb::getTransform() const {
    return transform_;
}

void Limb::load() {
    float vertices[] = {
        0.0f, -0.25f, -0.25f,
        1.0f, -0.25f, -0.25f,
        1.0f,  0.25f, -0.25f,
        1.0f,  0.25f, -0.25f,
        0.0f,  0.25f, -0.25f,
        0.0f, -0.25f, -0.25f,

        0.0f, -0.25f,  0.25f,
        1.0f, -0.25f,  0.25f,
        1.0f,  0.25f,  0.25f,
        1.0f,  0.25f,  0.25f,
        0.0f,  0.25f,  0.25f,
        0.0f, -0.25f,  0.25f,

        0.0f,  0.25f,  0.25f,
        0.0f,  0.25f, -0.25f,
        0.0f, -0.25f, -0.25f,
        0.0f, -0.25f, -0.25f,
        0.0f, -0.25f,  0.25f,
        0.0f,  0.25f,  0.25f,

        1.0f,  0.25f,  0.25f,
        1.0f,  0.25f, -0.25f,
        1.0f, -0.25f, -0.25f,
        1.0f, -0.25f, -0.25f,
        1.0f, -0.25f,  0.25f,
        1.0f,  0.25f,  0.25f,

        0.0f, -0.25f, -0.25f,
        1.0f, -0.25f, -0.25f,
        1.0f, -0.25f,  0.25f,
        1.0f, -0.25f,  0.25f,
        0.0f, -0.25f,  0.25f,
        0.0f, -0.25f, -0.25f,

        0.0f,  0.25f, -0.25f,
        1.0f,  0.25f, -0.25f,
        1.0f,  0.25f,  0.25f,
        1.0f,  0.25f,  0.25f,
        0.0f,  0.25f,  0.25f,
        0.0f,  0.25f, -0.25f,
    };
    vertex_count_ = 36;

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


void Limb::draw(Shader& shader, const Matrix4& projectionViewMatrix) const {
    shader.activate();
    shader.setUniform("model", getTransform());
    shader.setUniform("projection_view", projectionViewMatrix);

    shader.setUniform("color", 0.4, 0.0, 0.0, 1.0);

    glBindVertexArray(vao_);
    glLineWidth(1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPolygonOffset(0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count_);

    shader.setUniform("color", 1.0, 0.0, 0.0, 1.0);
    glLineWidth(2.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonOffset(10.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count_);

    glBindVertexArray(0);
}
