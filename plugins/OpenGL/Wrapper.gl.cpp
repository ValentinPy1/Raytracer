/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.gl.cpp
*/

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
            _opengl = dynamic_cast<render::PluginOpenGL *>(rdr.getPluginManager().require("OpenGL"));
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            throw std::runtime_error("OpenGL plugin not found");
        }
        buildShaders(rdr);
    }

    void Wrapper_gl::buildShaders(render::Renderer &rdr)
    {
        std::vector<PluginShader *> shaders;

        for (auto &plugin : rdr.getPluginManager().getPlugins()) {
            if (!(plugin->getName().ends_with("_gl") or plugin->getName().ends_with(".gl")))
                continue;
            auto tmp = dynamic_cast<render::PluginShader *>(plugin);
            if (tmp)
                shaders.push_back(tmp);
        }
        std::sort(plugins.begin(), plugins.end(), [](IPlugin *a, IPlugin *b) {
            return a->getPriority() < b->getPriority();
        });
        for (auto &plugin : shaders) {
            _opengl.registerShader(*plugin);
        }

        std::vector <std::string> shaderNames;
        for (auto &plugin : shaders) {
            shaderNames.push_back(plugin->getName());
        }
        opgl.registerProgram("renderPipeline.gl", shaderNames);
        opgl.useProgram("renderPipeline.gl");
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new ogl::Wrapper_gl("OpenGL");
    }
}
