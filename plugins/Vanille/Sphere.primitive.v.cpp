/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include "Sphere.primitive.v.hpp"
#include "Render.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille {
    SpherePrimitive_v::SpherePrimitive_v() : render::APluginPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            return processRay(ray, rdr);
        };
    }

    SpherePrimitive_v::~SpherePrimitive_v()
    {
    }

    render::Ray &SpherePrimitive_v::processRay(render::Ray &ray, const render::Renderer &rdr)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();
        auto a = vd * vd;
        auto b = 2 * vd * (vo - _origin);
        auto c = (vo - _origin) * (vo - _origin) - _radius * _radius;
        auto delta = b * b - 4 * a * c;

        if (delta < 0)
            return ray;

        float sqrtDelta = std::sqrt(delta);
        ray.addIntersection(
            render::Intersection(this, ray, (-b - sqrtDelta) / (2 * a))
        );
        ray.addIntersection(
            render::Intersection(this, ray, (-b + sqrtDelta) / (2 * a))
        );
        return ray;
    }

    void SpherePrimitive_v::selfInit(libconfig::Setting setting)
    {
        _origin = sf::Vector3f(setting["origin"][0], setting["origin"][1], setting["origin"][2]);
        _radius = setting["radius"];
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new vanille::SpherePrimitive_v();
    }
}