/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Plane.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include "Plane.primitive.v.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille
{
    PlanePrimitive_v::PlanePrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _normal = sf::Vector3f(0, 0, 0);
    }

    void PlanePrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        if (setting.exists("origin")) {
            libconfig::Setting &origin = setting["origin"];
            _origin = sf::Vector3f(origin["x"], origin["y"], origin["z"]);
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No origin found in primitive" << std::endl;
        }
        if (setting.exists("normal")) {
            libconfig::Setting &normal = setting["normal"];
            _normal = sf::Vector3f(normal["x"], normal["y"], normal["z"]);
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No normal found in primitive" << std::endl;
        }
    }

    PlanePrimitive_v::~PlanePrimitive_v()
    {
    }

    void PlanePrimitive_v::solve(render::Ray &ray)
    {
        if (ray.getDirection() * _normal == 0)
            return;
        float t = (_origin - ray.getOrigin()) * _normal / (ray.getDirection() * _normal);
        if (t < 0)
            return;
        ray.addIntersection(
            render::Intersection(_parent, ray, t)
        );
    }

    sf::Vector3f PlanePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        return -_normal;
    }
}

extern "C" {
    vanille::PlanePrimitive_v *entryPoint()
    {
        return new vanille::PlanePrimitive_v();
    }
}