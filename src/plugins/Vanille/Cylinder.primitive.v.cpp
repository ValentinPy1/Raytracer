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
    CylinderPrimitive_v::CylinderPrimitive_v() : render::IPrimitive(), render::Plugin()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
        _name = "CylinderPrimitive_v";
        _priority = 0;
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            return processRay(ray, rdr);
        };
    }

    CylinderPrimitive_v::~CylinderPrimitive_v()
    {
    }

    render::Ray &CylinderPrimitive_v::processRay(render::Ray &ray, const render::Renderer &rdr)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();

        auto a = vd * vd;
        return ray;
    }

    sf::Vector3f CylinderPrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        // return (point - _origin) / _radius;
    }

    void CylinderPrimitive_v::selfInit(libconfig::Setting &setting)
    {
        // _origin = sf::Vector3f(setting["origin"][0], setting["origin"][1], setting["origin"][2]);
        // _radius = setting["radius"];
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new vanille::CylinderPrimitive_v();
    }
}
