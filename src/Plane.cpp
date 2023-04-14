/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Plane.cpp
*/

#include "operations.hpp"
#include "Plane.hpp"

namespace render {
    Plane::Plane(const sf::Vector3f &positionVector, const sf::Vector3f &normal, const sf::Color &color)
        : _origin(positionVector), _normal(normal)
    {
        _color = color;
    }

    bool Plane::solve(render::Ray &ray)
    {
        if (ray.getDirection() * _normal == 0)
            return false;
        float t = (_origin - ray.getOrigin()) * _normal / (ray.getDirection() * _normal);
        if (t < 0)
            return false;
        ray.addIntersection(
            Intersection(
                this,
                ray,
                t
            )
        );
        return true;
    }

    sf::Vector3f Plane::getNormal(__attribute__((unused)) const sf::Vector3f &point) const
    {
        return -_normal;
    }
}
