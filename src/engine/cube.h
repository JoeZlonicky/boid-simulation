#ifndef OPENGL_DEMO_CUBE_H_
#define OPENGL_DEMO_CUBE_H_

#include <string>
#include "math/matrix_4.h"
#include "math/transform.h"

class Shader;

class Cube {
public:
    Cube();
    ~Cube();

    Cube(const Cube&) = delete;  // TODO: Implement
    Cube& operator=(const Cube&) = delete;  // TODO: Implement

    [[nodiscard]] unsigned int getVAO() const;
    [[nodiscard]] int getVertexCount() const;
    [[nodiscard]] const Transform& getTransform() const;
    [[nodiscard]] Transform& getTransform();
    [[nodiscard]] Vector3 getEnd() const;

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    int vertex_count_ = 0;

    Transform transform_ {};
};

#endif
