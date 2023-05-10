/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cercle.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include "Cercle.primitive.v.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille
{
    CerclePrimitive_v::CerclePrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    vanille::CerclePrimitive_v::CerclePrimitive_v(sf::Vector3f origin) : render::IPrimitive()
    {
        _origin = origin;
        _radius = 1;
    }

    void CerclePrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        setting.lookupValue("x", _origin.x);
        setting.lookupValue("y", _origin.y);
        setting.lookupValue("z", _origin.z);
        if (setting.exists("radius"))
        {
            libconfig::Setting &radius = setting["radius"];
            _radius = radius;
        }
        else
        {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                      << "No radius found in primitive" << std::endl;
        }
    }

    CerclePrimitive_v::~CerclePrimitive_v()
    {
    }

    void CerclePrimitive_v::solve(render::Ray &ray)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();

        auto a = vd.x * vd.x + vd.y * vd.y + vd.z * vd.z;
        auto b = 2 * (vd.x * (vo.x - _origin.x) + vd.y * (vo.y - _origin.y) + vd.z * (vo.z - _origin.z));
        auto c = (vo.x - _origin.x) * (vo.x - _origin.x) + (vo.y - _origin.y) * (vo.y - _origin.y) + (vo.z - _origin.z) * (vo.z - _origin.z) - _radius * _radius;

        auto delta = b * b - 4 * a * c;

        if (delta < 0)
            return;

        float t1 = (-b - std::sqrt(delta)) / (2.0f * a);
        float t2 = (-b + std::sqrt(delta)) / (2.0f * a);

        t1 = std::min(t1, t2);

        ray.addIntersection(
            render::Intersection(_parent, ray, t1).addNormal(vo + t1 * vd));
    }

    sf::Vector3f CerclePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        return (point - _origin);
    }

}

extern "C"
{
    render::IPrimitive *entryPoint()
    {
        return new vanille::CerclePrimitive_v();
    }
}
