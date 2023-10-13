#ifndef IK_DEMO_SHADER_H
#define IK_DEMO_SHADER_H

#include <string>
#include "glad/glad.h"
#include "glm/ext/matrix_float4x4.hpp"

class Shader {
public:
    ~Shader();

    void create(const char* vertexShaderPath, const char* fragmentShaderPath);
    void activate() const;
    void setUniform(const std::string& name, bool value) const;
    void setUniform(const std::string& name, int value) const;
    void setUniform(const std::string& name, float value) const;
    void setUniform(const std::string& name, float x, float y, float z, float w) const;
    void setUniform(const std::string& name, const glm::mat4 &matrix) const;

private:
    static std::string readFromFile(const std::string& filePath);
    static unsigned int compileShader(GLenum shaderType, const std::string& filePath);
    void linkProgram(unsigned int vertexShader, unsigned int fragmentShader);

    unsigned int id;
};

#endif
