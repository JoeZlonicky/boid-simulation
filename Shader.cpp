#include "Shader.h"

#include <iostream>
#include <fstream>
#include <cassert>

#include "glad/glad.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) : id(0) {
    unsigned int vertexShader;
    if (compileShader(GL_VERTEX_SHADER, vertexShaderPath, vertexShader) != 0) {
        return;
    }

    unsigned int fragmentShader;
    if (compileShader(GL_FRAGMENT_SHADER, fragmentShaderPath, fragmentShader) != 0) {
        return;
    }

    if (linkShaderProgram(vertexShader, fragmentShader) != 0) {
        return;
    }
    compiledSuccessfully = true;
}

Shader::~Shader() {
    if (id != 0) {
        glDeleteProgram(id);
        id = 0;
    }
}

void Shader::activate() const {
    assert(compiledSuccessfully);
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

unsigned int Shader::getID() const {
    return id;
}

int Shader::readFromFile(const char *filePath, std::string& out) {
    std::ifstream file {filePath};
    if (!file.is_open()) {
        std::cerr << "Failed to find file at path: " << filePath << std::endl;
        return -1;
    }

    out = {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
    return 0;
}

int Shader::compileShader(GLenum shaderType, const char *filePath, unsigned int& outShader) {
    std::string shaderSource;
    if (readFromFile(filePath, shaderSource) != 0) {
        return -1;
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
        std::cerr << "Failed to compile shader\n" << infoLog << std::endl;
        return -1;
    }

    outShader = shader;
    return 0;
}

// Shaders are deleted after linking
int Shader::linkShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    int success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    const int infoLogLength = 512;
    char infoLog[infoLogLength];
    if (!success) {
        glGetProgramInfoLog(id, infoLogLength, nullptr, infoLog);
        std::cerr << "Failed to link shader\n" << infoLog << std::endl;
        id = 0;
        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return 0;
}

bool Shader::wasCompiledSuccessfully() const {
    return compiledSuccessfully;
}
