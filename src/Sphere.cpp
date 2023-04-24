/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.cpp
*/

#include <iostream>
#include <cmath>
#include "../include/operations.hpp"
#include "../include/Ray.hpp"
#include "Camera.hpp"
#include "../include/Sphere.hpp"

render::Sphere::Sphere(const sf::Vector3f &origin, float radius, const sf::Color &color)
    : _origin(origin), _radius(radius)
{
    _color = color;
    Logger().log("Created Sphere at position (" + std::to_string(origin.x) + ", " + std::to_string(origin.y) + ", " + std::to_string(origin.z) + ") with radius " + std::to_string(radius));
}

bool render::Sphere::solve(render::Ray &ray)
{
    sf::Vector3f vo = ray.getOrigin();
    sf::Vector3f vd = ray.getDirection();
    auto a = vd * vd;
    auto b = 2 * vd * (vo - _origin);
    auto c = (vo - _origin) * (vo - _origin) - _radius * _radius;
    auto delta = b * b - 4 * a * c;

    if (delta < 0)
        return false;

    float sqrtDelta = std::sqrt(delta);
    ray.addIntersection(
        render::Intersection(this, ray, (-b - sqrtDelta) / (2 * a))
    );
    ray.addIntersection(
        render::Intersection(this, ray, (-b + sqrtDelta) / (2 * a))
    );
    return true;
}

sf::Vector3f render::Sphere::getNormal(const sf::Vector3f &point) const
{
    return (point - _origin) / _radius;
}
