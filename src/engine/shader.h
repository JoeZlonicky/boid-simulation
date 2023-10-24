#ifndef OPENGL_DEMO_SHADER_H
#define OPENGL_DEMO_SHADER_H

#include <string>
#include "glad/glad.h"
#include "math/matrix_4.h"

class Shader {
public:
    Shader() = default;
    ~Shader();

    Shader(const Shader&) = delete;  // TODO: Implement
    Shader& operator=(const Shader&) = delete;  // TODO: Implement

    void create(const char* vertex_shader_path, const char* fragment_shader_path);
    void activate() const;
    void setUniform(const std::string& name, bool value) const;
    void setUniform(const std::string& name, int value) const;
    void setUniform(const std::string& name, float value) const;
    void setUniform(const std::string& name, float x, float y, float z, float w) const;
    void setUniform(const std::string& name, const Matrix4& matrix) const;

private:
    static std::string readFromFile(const std::string& file_path);
    static unsigned int compileShader(GLenum shader_type, const std::string& file_path);
    void linkProgram(unsigned int vertex_shader, unsigned int fragment_shader);

    unsigned int id_;
};

#endif
