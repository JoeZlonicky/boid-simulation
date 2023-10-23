#include "limb.h"

#include "glad/glad.h"
#include "engine/shader.h"


Limb::Limb() {
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

Limb::~Limb() {
    glDeleteVertexArrays(1, &vao_);
    glDeleteBuffers(1, &vbo_);
}

unsigned int Limb::getVAO() const {
    return vao_;
}

int Limb::getVertexCount() const {
    return vertex_count_;
}

const Transform& Limb::getTransform() const {
    return transform_;
}

Transform& Limb::getTransform() {
    return transform_;
}

Vector3 Limb::getEnd() const {
    const float length = 1.0f;
    Vector3 unit {1, 0, 0};
    Vector3 direction = transform_.getRotation().calcRotationMatrix3() * unit;
    const Vector3 end = transform_.getPosition() + direction.normalized() * length;
    return end;
}