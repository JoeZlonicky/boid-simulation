#ifndef IK_DEMO_LIMB_H_
#define IK_DEMO_LIMB_H_

#include <string>
#include "glm/mat4x4.hpp"
#include "glm/ext/matrix_transform.hpp"

class Shader;

class Limb {
public:
    ~Limb();
    void load();
    void draw(Shader& shader, glm::mat4 projectionViewMatrix) const;

    [[nodiscard]] const glm::mat4& getTransform() const {
        return translationMatrix;
    }

    void rotateX(float radians) {
        translationMatrix = glm::rotate(translationMatrix, radians, glm::vec3(1.0, 0.0, 0.0));
    }

    void rotateY(float radians) {
        translationMatrix = glm::rotate(translationMatrix, radians, glm::vec3(0.0, 1.0, 0.0));
    }

    void rotateZ(float radians) {
        translationMatrix = glm::rotate(translationMatrix, radians, glm::vec3(0.0, 0.0, 1.0));
    }

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    int vertex_count_ = 0;

    glm::mat4 translationMatrix = glm::mat4(1.0f);
    glm::mat4 rotationMatrix = glm::mat4(1.0f);
    glm::mat4 scaleMatrix = glm::mat4(1.0f);
};

#endif
