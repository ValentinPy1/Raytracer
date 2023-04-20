/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginOpenGL.cpp
*/

#include <memory>
#include <functional>
#include <fstream>
#include <iostream>
#include <sstream>
#include <csignal>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "PluginManager.hpp"
#include "plugins/PluginOpenGL.hpp"

namespace ogl {
    // VBO
    PluginOpenGL::VBO::VBO()
    {
        callgl(glGenBuffers)(1, &_id);
    }

    PluginOpenGL::VBO::~VBO()
    {
        try {
            callgl(glDeleteBuffers)(1, &_id);
        } catch (std::exception &e) {
        }
    }

    GLuint PluginOpenGL::VBO::getId() const
    {
        return _id;
    }

    void PluginOpenGL::VBO::bind()
    {
        callgl(glBindBuffer)(GL_ARRAY_BUFFER, _id);
    }

    // VAO

    PluginOpenGL::VAO::VAO()
    {
        callgl(glGenVertexArrays)(1, &_id);
    }

    PluginOpenGL::VAO::~VAO()
    {
        //TODO
    }

    GLuint PluginOpenGL::VAO::getId() const
    {
        return _id;
    }

    void PluginOpenGL::VAO::bind()
    {
        callgl(glBindVertexArray)(_id);
    }

    // UBO
    PluginOpenGL::UBO::UBO(const size_t size, GLenum usage)
    {
        _size = size;
        callgl(glGenBuffers)(1, &_id);
        callgl(glBindBuffer)(GL_UNIFORM_BUFFER, _id);
        callgl(glBufferData)(GL_UNIFORM_BUFFER, _size, NULL, usage);
    }

    PluginOpenGL::UBO::~UBO()
    {

    }

    GLuint PluginOpenGL::UBO::getId() const
    {
        return _id;
    }

    void PluginOpenGL::UBO::bind()
    {
        callgl(glBindBuffer)(GL_UNIFORM_BUFFER, _id);
    }

    // SSBO
    PluginOpenGL::SSBO::SSBO(const size_t size, GLenum usage)
    {
        _size = size;
        callgl(glGenBuffers)(1, &_id);
        bind();
        setData(size, nullptr);
    }

    PluginOpenGL::SSBO::~SSBO()
    {
    }

    GLuint PluginOpenGL::SSBO::getId() const
    {
        return _id;
    }

    void PluginOpenGL::SSBO::bind(GLuint bindingIndex)
    {
        callgl(glBindBufferRange)(GL_SHADER_STORAGE_BUFFER, bindingIndex, _id, 0, _size);
    }

    void PluginOpenGL::SSBO::setData(const size_t size, void *data)
    {
        bind();
        callgl(glBufferData)(GL_SHADER_STORAGE_BUFFER, size, data, GL_DYNAMIC_DRAW);
    }

    // SHADERS

    Shader::Shader(int shaderType, std::string srcPath) : type(shaderType)
    {
        std::ifstream f(srcPath);
        std::stringstream buffer;

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
    }

    Shader::~Shader()
    {
        try {
            callgl(glDeleteShader)(id);
        } catch (std::exception &e) {
        }
    }

    ShaderProgram::ShaderProgram(std::vector<std::shared_ptr<Shader>> shaders)
    {
        id = callgl(glCreateProgram)();
        for (auto &shader : shaders) {
            callgl(glAttachShader)(id, shader->id);
        }
        callgl(glLinkProgram)(id);
        // should we delete the shaders here or wait in case someone else needs them?

        int  success;
        char infoLog[512];
        callgl(glGetProgramiv)(id, GL_LINK_STATUS, &success);
        if (!success) {
            callgl(glGetProgramInfoLog)(id, 512, NULL, infoLog);
            throw std::runtime_error("Failed to link program: " + std::string(infoLog));
        }
    }

    ShaderProgram::~ShaderProgram()
    {
        try {
            callgl(glDeleteProgram)(id);
        } catch (std::exception &e) {
        }
    }

    PluginOpenGL::PluginOpenGL() : render::Plugin(nullptr, nullptr, nullptr, 0, "OpenGL")
    {
        _init = [this](render::Renderer &rdr) {
            initOpenGL(rdr);
        };
    }

    PluginOpenGL::~PluginOpenGL()
    {
        try {
            terminate();
        } catch (std::exception &e) {
        }
    }

    bool wasKilled = false;
    void killOpenGL(int sig)
    {
        if (sig == SIGINT)
            wasKilled = true;
    }

    void PluginOpenGL::initOpenGL(render::Renderer &rdr)
    {
        if (!glfwInit())
            throw std::runtime_error("Failed to init glfw");

        _window = std::shared_ptr<GLFWwindow>(glfwCreateWindow(640, 480, "opgl_plugin", NULL, NULL), [](GLFWwindow *window) {
            glfwDestroyWindow(window);
        });
        if (_window.get() == nullptr) {
            glfwTerminate();
            throw std::runtime_error("Failed to create window");
        }
        signal(SIGINT, killOpenGL);
        _displayThread = std::thread([this]() {
            // doWindowLoop();
        });
        _isInitialized = true;
    }

    GLFWwindow *PluginOpenGL::getWindow() const
    {
        return _window.get();
    }

    void PluginOpenGL::doWindowLoop()
    {
        while (!glfwWindowShouldClose(_window.get()) and not wasKilled)
        {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);
            _mutex.lock();
            glfwSwapBuffers(_window.get());
            _mutex.unlock();
        }
    }

    void PluginOpenGL::terminate()
    {
        if (_isInitialized)
        {
            glfwSetWindowShouldClose(_window.get(), true);
            _displayThread.join();
            glfwTerminate();
        }
    }

    void PluginOpenGL::registerShader(
        const std::string &srcPath,
        const std::string &shaderName,
        int shaderType)
    {
        glfwMakeContextCurrent(_window.get());
        _shaderMap[shaderName] = std::shared_ptr<Shader>(new Shader(shaderType, srcPath));
    }

    void PluginOpenGL::registerShader(PluginShader &shader)
    {
        glfwMakeContextCurrent(_window.get());
        _shaderMap[shader.getName()] = std::shared_ptr<Shader>(new Shader(shader.getShaderType(), shader.getShaderPath()));
    }

    void PluginOpenGL::registerProgram(
        const std::string &programName,
        std::initializer_list<std::string> shaderNames)
    {
        std::vector<std::shared_ptr<Shader>> shaders;
        for (auto &shaderName : shaderNames) {
            shaders.push_back(_shaderMap[shaderName]);
        }
        _programMap[programName] = std::shared_ptr<ShaderProgram>(new ShaderProgram(shaders));
    }

    void PluginOpenGL::useProgram(const std::string &programName)
    {
        _mutex.lock();
        glfwMakeContextCurrent(_window.get());
        callgl(glUseProgram)(_programMap[programName]->id);
        _mutex.unlock();
    }

    std::shared_ptr<ShaderProgram> PluginOpenGL::getProgram(const std::string &programName)
    {
        return _programMap[programName];
    }

    GLuint PluginOpenGL::createBuffer()
    {
        std::shared_ptr<VBO> vbo(new VBO());
        _vboMap[vbo->getId()] = vbo;
        return vbo->getId();
    }

    void PluginOpenGL::bindBuffer(GLuint id)
    {
        _vboMap[id]->bind();
    }

    GLuint PluginOpenGL::createVertexArray()
    {
        std::shared_ptr<VAO> vao(new VAO());
        _vaoMap[vao->getId()] = vao;
        return vao->getId();
    }

    void PluginOpenGL::bindVertexArray(GLuint id)
    {
        _vaoMap[id]->bind();
    }

    void PluginOpenGL::setUniform3f(const std::string &uniformName, const std::string &progName, float x, float y, float z) {
        GLuint progId = getProgram(progName)->id;
        GLuint loc = callgl(glGetUniformLocation)(progId, uniformName.c_str());
        callgl(glUniform3f)(loc, x, y, z);
    }

    void PluginOpenGL::setBufferData(size_t size, void *data, int usage)
    {
        callgl(glBufferData)(GL_ARRAY_BUFFER, size, data, usage);
    }

    void PluginOpenGL::setVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    {
        callgl(glVertexAttribPointer)(index, size, type, normalized, stride, pointer);
        callgl(glEnableVertexAttribArray)(index);
    }

    GLuint PluginOpenGL::createUniformBuffer(size_t size, GLenum usage)
    {
        std::shared_ptr<UBO> ubo(new UBO(size, usage));
        _uboMap[ubo->getId()] = ubo;
        return ubo->getId();
    }

    void PluginOpenGL::bindUniformBuffer(GLuint id)
    {
        _uboMap[id]->bind();
    }

    void PluginOpenGL::setUniformBufferData(size_t size, void *data, GLuint bufferIndex, GLuint uboId, const std::string &uboName, const std::string &programName)
    {
        void *buffPtr = callgl(glMapBuffer)(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
        GLuint programId = getProgram(programName)->id;
        memcpy(buffPtr, data, size);

        callgl(glBindBufferBase)(GL_UNIFORM_BUFFER, bufferIndex, uboId);
        int uniformIndex = callgl(glGetUniformBlockIndex)(programId, uboName.c_str());
        callgl(glUniformBlockBinding)(programId, uniformIndex, bufferIndex);
    }

    GLuint PluginOpenGL::createShaderStorageBuffer(size_t size, GLenum usage)
    {
        std::shared_ptr<SSBO> ssbo(new SSBO(size, usage));
        _ssboMap[ssbo->getId()] = ssbo;
        return ssbo->getId();
    }

    void PluginOpenGL::bindShaderStorageBuffer(GLuint id, GLuint bufferIndex)
    {
        _ssboMap[id]->bind(bufferIndex);
    }

    void PluginOpenGL::setShaderStorageBufferData(size_t size, void *data, GLuint bufferIndex, GLuint ssboId, const std::string &ssboName, const std::string &programName)
    {
        void *buffPtr = callgl(glMapBuffer)(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
        GLuint programId = getProgram(programName)->id;
        memcpy(buffPtr, data, size);

        callgl(glBindBufferBase)(GL_SHADER_STORAGE_BUFFER, bufferIndex, ssboId);
        int uniformIndex = callgl(glGetProgramResourceIndex)(programId, GL_SHADER_STORAGE_BLOCK, ssboName.c_str());
        callgl(glShaderStorageBlockBinding)(programId, uniformIndex, bufferIndex);
    }
}

extern "C" {
    render::Plugin *entryPoint()
    {
        return new ogl::PluginOpenGL();
    }
}
//
