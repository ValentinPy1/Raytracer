/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cylinder.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include "Cylinder.primitive.v.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille {
    CylinderPrimitive_v::CylinderPrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    CylinderPrimitive_v::~CylinderPrimitive_v()
    {
    }

    void CylinderPrimitive_v::solve(render::Ray &ray)
    {
        (void) ray;
        // sf::Vector3f vo = ray.getOrigin();
        // sf::Vector3f vd = ray.getDirection();

        // auto a = vd * vd;
        return;
    }

    sf::Vector3f CylinderPrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        // return (point - _origin) / _radius;

        return (point);
    }

    void CylinderPrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        (void) setting;
        // _origin = sf::Vector3f(setting["origin"][0], setting["origin"][1], setting["origin"][2]);
        // _radius = setting["radius"];
    }
}

extern "C" {
    render::IPrimitive *entryPoint() {
        return new vanille::CylinderPrimitive_v();
    }
}
