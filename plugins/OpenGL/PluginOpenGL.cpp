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
#include "PluginManager.hpp"
#include "plugins/PluginOpenGL.hpp"

namespace ogl {
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

    PluginOpenGL::PluginOpenGL() : render::Plugin(nullptr, nullptr, nullptr, 0)
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

    void PluginOpenGL::startProgram(const std::string &programName)
    {
        _mutex.lock();
        glfwMakeContextCurrent(_window.get());
        callgl(glUseProgram)(_programMap[programName]->id);
        _mutex.unlock();
    }
}

extern "C" {
    render::Plugin *entryPoint()
    {
        return new ogl::PluginOpenGL();
    }
}
