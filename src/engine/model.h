#ifndef BOID_SIMULATION_CUBE_H_
#define BOID_SIMULATION_CUBE_H_

#include <string>
#include <vector>

#include "math/matrix_4.h"

class Model {
public:
    Model(float vertices[], int n_vertices);
    ~Model();

    Model(const Model&) = delete;
    Model& operator=(const Model&) = delete;

    [[nodiscard]] unsigned int getVAO() const;
    [[nodiscard]] int getVertexCount() const;

private:
    unsigned int vao_ = 0;
    unsigned int vbo_ = 0;
    int vertex_count_ = 0;
};

Model createCubeModel();  // A 1x1x1 cube
#endif
