/*
** EPITECH PROJECT, 2022
** ray
** File description:
** FlatMaterial.gl.cpp
*/

#include "FlatMaterial.gl.hpp"

namespace gpu {
    FlatMaterial_gl::FlatMaterial_gl(int r, int g, int b) :
        _r(r),
        _g(g),
        _b(b)
    {

    }

    float FlatMaterial_gl::getProperty(const std::string &name) const
    {
        if (_properties.find(name) == _properties.end())
            return 0;
        return _properties.at(name);
    }

    void FlatMaterial_gl::getColor(int &r, int &g, int &b,
    __attribute__((unused)) geo::vec3 point) const
    {
        r = _r;
        g = _g;
        b = _b;
    }

    void FlatMaterial_gl::selfInit(libconfig::Setting &setting, render::Entity *en)
    {
        libconfig::Setting &color = setting.lookup("color");

        color.lookupValue("r", _r);
        color.lookupValue("g", _g);
        color.lookupValue("b", _b);
    }
}

extern "C" {
    render::IMaterial *entryPoint()
    {
        return new gpu::FlatMaterial_gl(255, 0, 0);
    }
}
