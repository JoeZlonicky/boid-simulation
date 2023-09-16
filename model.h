#ifndef SIM_ENGINE_MODEL_H_
#define SIM_ENGINE_MODEL_H_

#include <string>
#include "glm/mat4x4.hpp"
#include "glm/ext/matrix_transform.hpp"

class Model {
public:
    ~Model();
    void load();
    void draw() const;

    const glm::mat4& getTransform() {
        return transform;
    }

    void rotateX(float degrees) {
        transform = glm::rotate(transform, degrees, glm::vec3(1.0, 0.0, 0.0));
    }

    void rotateY(float degrees) {
        transform = glm::rotate(transform, degrees, glm::vec3(0.0, 1.0, 0.0));
    }

    void rotateZ(float degrees) {
        transform = glm::rotate(transform, degrees, glm::vec3(0.0, 0.0, 1.0));
    }

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    unsigned int texture_ = 0;
    int vertex_count_ = 0;

    glm::mat4 transform = glm::mat4(1.0f);
};

#endif
