/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include "Sphere.primitive.v.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille {
    SpherePrimitive_v::SpherePrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    SpherePrimitive_v::~SpherePrimitive_v()
    {
    }

    void SpherePrimitive_v::solve(render::Ray &ray)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();
        auto a = vd * vd;
        auto b = 2 * vd * (vo - _origin);
        auto c = (vo - _origin) * (vo - _origin) - _radius * _radius;
        auto delta = b * b - 4 * a * c;

        if (delta < 0)
            return;

        float sqrtDelta = std::sqrt(delta);
        float t1 = (-b - sqrtDelta) / (2 * a);
        float t2 = (-b + sqrtDelta) / (2 * a);

        if (t1 > 0)
            ray.addIntersection(
                render::Intersection(_parent, ray, t1)
            );
        if (t2 > 0)
            ray.addIntersection(
                render::Intersection(_parent, ray, t2)
            );
    }

    sf::Vector3f SpherePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        return (point - _origin) / _radius;
    }

    void SpherePrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        setting.lookupValue("x", _origin.x);
        setting.lookupValue("y", _origin.y);
        setting.lookupValue("z", _origin.z);
        setting.lookupValue("radius", _radius);
        _parent = parent;
    }
}

extern "C" {
    render::IPrimitive *entryPoint() {
        return new vanille::SpherePrimitive_v();
    }
}
