#include "shader.h"

#include <iostream>
#include <fstream>
#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"

Shader::~Shader() {
    if (id != 0) {
        glDeleteProgram(id);
        id = 0;
    }
}

void Shader::create(const char *vertexShaderPath, const char *fragmentShaderPath) {
    unsigned int vertexShader;
    unsigned int fragmentShader;
    try {
        vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderPath);
        fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderPath);
        linkProgram(vertexShader, fragmentShader);
    } catch (const std::runtime_error& e) {
        throw e;
    }
}

void Shader::activate() const {
    glUseProgram(id);
}

void Shader::setUniform(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setUniform(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setUniform(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setUniform(const std::string & name, float x, float y, float z, float w) const {
    glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);
}

void Shader::setUniform(const std::string & name, const glm::mat4 &matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}

std::string Shader::readFromFile(const std::string& filePath) {
    std::ifstream file {filePath};
    if (!file.is_open()) {
        throw std::runtime_error("Failed to find shader at given path: " + filePath);
    }

    return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}

unsigned int Shader::compileShader(GLenum shaderType, const std::string &filePath) {
    std::string shaderSource;
    try {
        shaderSource = readFromFile(filePath);
    } catch (const std::runtime_error& e) {
        throw e;
    }

    const char* cStrSource = shaderSource.c_str();
    unsigned int shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &cStrSource, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    const int infoLogLength = 512;
    char infoLog[infoLogLength];
    if (!success) {
        glGetShaderInfoLog(shader, infoLogLength, nullptr, infoLog);
        throw std::runtime_error("Failed to compile shader: " + std::string(infoLog));
    }

    return shader;
}

// Shaders are deleted after linking
void Shader::linkProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    int success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    const int infoLogLength = 512;
    char infoLog[infoLogLength];
    if (!success) {
        id = 0;
        glGetProgramInfoLog(id, infoLogLength, nullptr, infoLog);
        throw std::runtime_error("Failed to link shader: " + std::string(infoLog));
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}