/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Triangle.primitive.gl.cpp
*/

#include "IPrimitive.hpp"
#include "Opgl.hpp"
#include "TrianglePrimitiveHelper.gl.hpp"
#include "Triangle.primitive.gl.hpp"

namespace gpu {

    void TrianglePrimitive_gl::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _helper = std::make_shared<TrianglePrimitiveHelper>();
        _helper->selfInit(setting);

        auto tmpPlugin = std::dynamic_pointer_cast<render::IPlugin>(_helper);
        if (!tmpPlugin)
            throw gpu::Opgl::IncompatibleException("The specified helper is not a Plugin.");
        parent->addPlugin(tmpPlugin);
    }

    sf::Vector3f TrianglePrimitive_gl::getNormalAt(
        __attribute__((unused)) sf::Vector3f &point)
    {
        throw gpu::Opgl::IncompatibleException("getNormalAt: not compatible with OpenGL. This should be implemented in a shader.");
    }

    void TrianglePrimitive_gl::solve(
        __attribute__((unused)) render::Ray &ray)
    {
        throw gpu::Opgl::IncompatibleException("solve: not compatible with OpenGL. This should be implemented in a shader.");
    }
}

extern "C" {
    render::IPrimitive *entryPoint()
    {
        return new gpu::TrianglePrimitive_gl();
    }
}
