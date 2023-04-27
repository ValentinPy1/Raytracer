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

namespace vanille {
    CerclePrimitive_v::CerclePrimitive_v() : render::IPrimitive(), render::Plugin()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
        _name = "CerclePrimitive_v";
        _priority = 0;
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            return processRay(ray, rdr);
        };
    }

    CerclePrimitive_v::~CerclePrimitive_v()
    {
    }

    render::Ray &CerclePrimitive_v::processRay(render::Ray &ray, const render::Renderer &rdr)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();

        auto a = vd.x * vd.x + vd.y * vd.y + vd.z * vd.z;
        auto b = 2 * (vd.x * (vo.x - _origin.x) + vd.y * (vo.y - _origin.y) + vd.z * (vo.z - _origin.z));
        auto c = (vo.x - _origin.x) * (vo.x - _origin.x) + (vo.y - _origin.y) * (vo.y - _origin.y) + (vo.z - _origin.z) * (vo.z - _origin.z) - _radius * _radius;

        auto delta = b * b - 4 * a * c;

        if (delta < 0)
            return ray;

        float t = (-b - std::sqrt(delta)) / (2.0f * a);
        ray.addIntersection(
            render::Intersection(ray, t).addNormal(this)
        );

        ray.addIntersection(
            render::Intersection(ray, (-b + std::sqrt(delta)) / (2 * a)).addNormal(this)
        );

        return ray;
    }

    sf::Vector3f CerclePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        return (point - _origin);
    }

    void CerclePrimitive_v::selfInit(libconfig::Setting &setting)
    {
        _origin = sf::Vector3f(setting["origin"][0], setting["origin"][1], setting["origin"][2]);
        // _radius = setting["radius"];
        _radius = 1;
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new vanille::CerclePrimitive_v();
    }
}
