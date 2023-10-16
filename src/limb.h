#ifndef IK_DEMO_LIMB_H_
#define IK_DEMO_LIMB_H_

#include <string>
#include "math/matrix_4.h"

class Shader;

class Limb {
public:
    ~Limb();
    void load();
    void draw(Shader& shader, const Matrix4& projectionViewMatrix) const;

    [[nodiscard]] const Matrix4& getTransform() const;

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    int vertex_count_ = 0;

    Matrix4 transform_ = Matrix4{1.0f};
};

#endif
