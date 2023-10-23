#include "drawing.h"

#include "glad/glad.h"

#include "shader.h"

namespace {
    void drawLimb(Limb& limb, Shader& shader) {
        glBindVertexArray(limb.getVAO());
        shader.setUniform("model", limb.getTransform().getMatrix());

        shader.setUniform("color", 0.4, 0.0, 0.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glPolygonOffset(0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, limb.getVertexCount());

        shader.setUniform("color", 1.0, 0.0, 0.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(2.0f);
        glPolygonOffset(10.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, limb.getVertexCount());

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

    void drawLimbs(std::vector<Limb>& limbs, Shader& shader, Camera& camera) {
        shader.activate();
        shader.setUniform("projection_view", camera.getProjectionViewMatrix());

        for (Limb& limb : limbs) {
            drawLimb(limb, shader);
        }
    }
}
