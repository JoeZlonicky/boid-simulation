#include "shader.h"

#include <iostream>
#include <fstream>

Shader::Shader(const char* vertex_shader_path, const char* fragment_shader_path) {
    try {
        unsigned int vertex_shader = compileShader(GL_VERTEX_SHADER, vertex_shader_path);
        unsigned int fragment_shader = compileShader(GL_FRAGMENT_SHADER, fragment_shader_path);
        linkProgram(vertex_shader, fragment_shader);
    } catch (const std::runtime_error& e) {
        throw e;
    }
}

Shader::~Shader() {
    if (id_ != 0) {
        glDeleteProgram(id_);
        id_ = 0;
    }
}

void Shader::activate() const {
    glUseProgram(id_);
}

void Shader::setUniform(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), (int) value);
}

void Shader::setUniform(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void Shader::setUniform(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}

void Shader::setUniform(const std::string& name, float x, float y, float z, float w) const {
    glUniform4f(glGetUniformLocation(id_, name.c_str()), x, y, z, w);
}

void Shader::setUniform(const std::string& name, const Matrix4& matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, &matrix(0, 0));
}

std::string Shader::readFromFile(const std::string& file_path) {
    std::ifstream file {file_path};
    if (!file.is_open()) {
        throw std::runtime_error("Failed to find shader_ at given path: " + file_path);
    }

    return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}

unsigned int Shader::compileShader(GLenum shader_type, const std::string& file_path) {
    std::string shader_source;
    try {
        shader_source = readFromFile(file_path);
    } catch (const std::runtime_error& e) {
        throw e;
    }

    const char* c_str_source = shader_source.c_str();
    unsigned int shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &c_str_source, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    const int info_log_length = 512;
    char info_log[info_log_length];
    if (!success) {
        glGetShaderInfoLog(shader, info_log_length, nullptr, info_log);
        throw std::runtime_error("Failed to compile shader_: " + std::string(info_log));
    }

    return shader;
}

// Shaders are deleted after linking
void Shader::linkProgram(unsigned int vertex_shader, unsigned int fragment_shader) {
    id_ = glCreateProgram();
    glAttachShader(id_, vertex_shader);
    glAttachShader(id_, fragment_shader);
    glLinkProgram(id_);

    int success;
    glGetProgramiv(id_, GL_LINK_STATUS, &success);

    const int info_log_length = 512;
    char info_log[info_log_length];
    if (!success) {
        id_ = 0;
        glGetProgramInfoLog(id_, info_log_length, nullptr, info_log);
        throw std::runtime_error("Failed to link shader_: " + std::string(info_log));
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}
