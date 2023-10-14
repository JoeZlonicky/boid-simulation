#ifndef IK_DEMO_SHADER_H
#define IK_DEMO_SHADER_H

#include <string>
#include "glad/glad.h"
#include "glm/ext/matrix_float4x4.hpp"

class Shader {
public:
    ~Shader();

    void create(const char* vertex_shader_path, const char* fragment_shader_path);
    void activate() const;
    void setUniform(const std::string& name, bool value) const;
    void setUniform(const std::string& name, int value) const;
    void setUniform(const std::string& name, float value) const;
    void setUniform(const std::string& name, float x, float y, float z, float w) const;
    void setUniform(const std::string& name, const glm::mat4 &matrix) const;

private:
    static std::string readFromFile(const std::string& file_path);
    static unsigned int compileShader(GLenum shader_type, const std::string& file_path);
    void linkProgram(unsigned int vertex_shader, unsigned int fragment_shader);

    unsigned int id_;
};

#endif
