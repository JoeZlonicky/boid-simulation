#include "drawing.h"

#include "glad/glad.h"

#include "shader.h"

namespace {
    void drawCube(Cube& cube, Shader& shader) {
        glBindVertexArray(cube.getVAO());
        shader.setUniform("model", cube.getTransform().getMatrix());

        shader.setUniform("color", 0.4, 0.0, 0.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glPolygonOffset(0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, cube.getVertexCount());

        shader.setUniform("color", 1.0, 0.0, 0.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2.0f);
        glPolygonOffset(10.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, cube.getVertexCount());

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1.0f);
        glBindVertexArray(0);
    }
}

namespace drawing {
    void init() {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_POLYGON_OFFSET_FILL);
    }

    void clear() {
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void drawCubes(std::vector<Cube>& cubes, Shader& shader, Camera& camera) {
        shader.activate();
        shader.setUniform("projection_view", camera.getProjectionViewMatrix());

        for (Cube& cube : cubes) {
            drawCube(cube, shader);
        }
    }
}
