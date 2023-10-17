#ifndef IK_DEMO_LIMB_H_
#define IK_DEMO_LIMB_H_

#include <string>
#include "math/matrix_4.h"
#include "math/transform.h"

class Shader;

class Limb {
public:
    ~Limb();
    void load();
    void draw(Shader& shader, const Matrix4& projectionViewMatrix);

    [[nodiscard]] const Transform& getTransform() const;
    [[nodiscard]] Transform& getTransform();

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    int vertex_count_ = 0;

    Transform transform_ {};
};

#endif
