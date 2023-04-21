/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginSpherePrimitive.gl.cpp
*/

#include <string>
#include "plugins/PluginOpenGL.hpp"
#include "../../include/plugins/SpherePrimitive.gl.hpp"
#include "../../include/Render.hpp"

namespace ogl {
    SpherePrimitive_gl::SpherePrimitive_gl()
    {
    }

    SpherePrimitive_gl::~SpherePrimitive_gl()
    {
    }

    void SpherePrimitive_gl::selfInit(libconfig::Setting &setting)
    {
        setting.lookupValue("x", _center.x);
        setting.lookupValue("y", _center.y);
        setting.lookupValue("z", _center.z);
        setting.lookupValue("radius", this->_radius);
    }
}

extern "C" {
    ogl::SpherePrimitive_gl *entryPoint() {
        return new ogl::SpherePrimitive_gl();
    }
}
