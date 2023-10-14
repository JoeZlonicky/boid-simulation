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
        return translation_matrix_;
    }

    void rotateX(float radians) {
        translation_matrix_ = glm::rotate(translation_matrix_, radians, glm::vec3(1.0, 0.0, 0.0));
    }

    void rotateY(float radians) {
        translation_matrix_ = glm::rotate(translation_matrix_, radians, glm::vec3(0.0, 1.0, 0.0));
    }

    void rotateZ(float radians) {
        translation_matrix_ = glm::rotate(translation_matrix_, radians, glm::vec3(0.0, 0.0, 1.0));
    }

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    int vertex_count_ = 0;

    glm::mat4 translation_matrix_ = glm::mat4(1.0f);
    glm::mat4 rotation_matrix_ = glm::mat4(1.0f);
    glm::mat4 scale_matrix_ = glm::mat4(1.0f);
};

#endif
