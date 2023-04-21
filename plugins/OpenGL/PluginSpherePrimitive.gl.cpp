/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginSpherePrimitive.gl.cpp
*/

#include <string>
#include "plugins/PluginOpenGL.hpp"
#include "plugins/PluginSpherePrimitive.gl.hpp"
#include "../../include/Render.hpp"

namespace ogl {
    SpherePrimitive_gl::SpherePrimitive_gl() :
        render::APluginPrimitive()
    {
        _init = [this](render::Renderer &rdr) {
            initSpherePrimitive_gl(rdr);
        };
    }

    SpherePrimitive_gl::~SpherePrimitive_gl()
    {
    }

    void SpherePrimitive_gl::initSpherePrimitive_gl(render::Renderer &rdr)
    {
        try {
            _opengl = dynamic_cast<PluginOpenGL *>(rdr.getPluginManager().require("OpenGL"));
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            return;
        }

    }

    void SpherePrimitive_gl::selfInit(libconfig::Setting &setting)
    {
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new ogl::SpherePrimitive_gl();
    }
}
