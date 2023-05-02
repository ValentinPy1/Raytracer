/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ShaderProgram.cpp
*/

#include "ShaderProgram.hpp"
#include "Opgl.hpp"

namespace gpu {
    ShaderProgram::ShaderProgram(std::vector<std::string> shaderPath) {
            _id = callgl(glCreateProgram)();
            std::vector<GLuint> shaders;
            for (auto &path : shaderPath) {
                shaders.push_back(loadShader(path));
                callgl(glAttachShader)(_id, shaders.back());
            }
            callgl(glLinkProgram)(_id);
            for (auto &shader : shaders)
                callgl(glDeleteShader)(shader);
        }

        ShaderProgram::~ShaderProgram() {
            callgl(glDeleteProgram)(_id);
        }

        void ShaderProgram::use() {
            callgl(glUseProgram)(_id);
        }

        void ShaderProgram::setUniform3f(const std::string &uniName, float v0, float v1, float v2) {
            callgl(glUniform3f)(callgl(glGetUniformLocation)(_id, uniName.c_str()), v0, v1, v2);
        }

        void ShaderProgram::setUniform1f(const std::string &uniName, float v0) {
            callgl(glUniform1f)(callgl(glGetUniformLocation)(_id, uniName.c_str()), v0);
        }

        void ShaderProgram::setUniform2f(const std::string &uniName, float v0, float v1) {
            callgl(glUniform2f)(callgl(glGetUniformLocation)(_id, uniName.c_str()), v0, v1);
        }

        GLuint ShaderProgram::getId() const { return _id; }

        GLuint ShaderProgram::loadShader(const std::string &path)
        {
            std::ifstream f(path);
            std::stringstream buffer;
            std::string srcContent;
            const char *src;

            GLuint id;
            GLenum type = (strEndsWith(path, ".vert")) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

            if (!f.is_open())
                throw std::runtime_error("Failed to open shader file");
            buffer << f.rdbuf();
            srcContent = buffer.str();
            src = (char *) srcContent.c_str();

            id = callgl(glCreateShader)(type);
            callgl(glShaderSource)(id, 1, &src, NULL);
            callgl(glCompileShader)(id);

            int  success;
            char infoLog[512];
            callgl(glGetShaderiv)(id, GL_COMPILE_STATUS, &success);
            if (!success) {
                callgl(glGetShaderInfoLog)(id, 512, NULL, infoLog);
                throw std::runtime_error("Failed to compile shader: " + std::string(infoLog));
            }
            return id;
        }

        bool ShaderProgram::strEndsWith(const std::string &str, const std::string &end) {
            if (end.size() > str.size()) return false;
                return std::equal(end.rbegin(), end.rend(), str.rbegin());
        }
}
