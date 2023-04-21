/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.gl.cpp
*/

#include "Render.hpp"
#include "PluginManager.hpp"
#include "plugins/PluginShader.gl.hpp"
#include "plugins/Wrapper.gl.hpp"

namespace ogl {
    Wrapper_gl::Wrapper_gl(
        const std::string &name) :
        render::AWrapper(
            nullptr,
            nullptr,
            nullptr,
            0,
            name
    )
    {
        _init = [this](render::Renderer &rdr) {
            initWrapper_gl(rdr);
        };
    }

    void Wrapper_gl::run(render::Renderer &rdr)
    {
    }

    void Wrapper_gl::initWrapper_gl(render::Renderer &rdr)
    {
        try {
            _opengl = dynamic_cast<ogl::PluginOpenGL *>(rdr.getPluginManager().require("OpenGL"));
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            throw std::runtime_error("OpenGL plugin not found");
        }
        buildShaders(rdr);
    }

    void Wrapper_gl::buildShaders(render::Renderer &rdr)
    {
        std::vector<std::string> shaderNames;

        auto endsWith = [](const std::string &str, const std::string &suffix) {
            return str.size() >= suffix.size() and
                   str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
        };
        for (auto &plugin : rdr.getPluginManager().getPlugins()) {
            if (!(endsWith(plugin->getName(), "_gl") or endsWith(plugin->getName(), ".gl")))
                continue;
            auto shader = dynamic_cast<PluginShader *>(plugin.get());
            if (shader == nullptr or shader->getPriority() < 0)
                continue;
            _shaders.push_back(shader);
        }
        std::sort(_shaders.begin(), _shaders.end(), [](PluginShader *a, PluginShader *b) {
            return a->getPriority() > b->getPriority();
        });
        for (auto &shader : _shaders) {
            shaderNames.push_back(shader->getName());
            _opengl->registerShader(*shader);
        }
        _opengl->registerProgram("render", shaderNames);
        _opengl->useProgram("render");
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new ogl::Wrapper_gl("OpenGL");
    }
}
