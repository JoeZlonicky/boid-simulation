#ifndef SIM_ENGINE_SHADER_H
#define SIM_ENGINE_SHADER_H

#include <string>
#include "glad/glad.h"

class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();

    void activate() const;
    void setUniform(const std::string& name, bool value) const;
    void setUniform(const std::string& name, int value) const;
    void setUniform(const std::string& name, float value) const;
    void setUniform(const std::string& name, float x, float y, float z, float w) const;

    [[nodiscard]] unsigned int getID() const;
    [[nodiscard]] bool wasCompiledSuccessfully() const;

private:
    static int readFromFile(const char* filePath, std::string& out);
    static int compileShader(GLenum shaderType, const char *filePath, unsigned int& outShader);
    int linkShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);

    unsigned int id;
    bool compiledSuccessfully = false;
};


#endif
