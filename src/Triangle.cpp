/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Triangle.cpp
*/

#include "operations.hpp"
#include "Triangle.hpp"

namespace render {
    Triangle::Triangle(
        const sf::Vector3f &p1, const sf::Vector3f &p2,
        const sf::Vector3f &p3, const sf::Color &color)
        : _p1(p1), _p2(p2), _p3(p3)
    {
        _color = color;
        _edge1 = _p2 - _p1;
        _edge2 = _p3 - _p1;
        _edge3 = _p3 - _p2;
        _normal = _edge1 ^ _edge2;
    }

    bool Triangle::solve(render::Ray &ray)
    {
        float denom = ray.getDirection() * _normal;

        if (denom == 0 || denom < 0)
            return false;
        float t = (_p1 - ray.getOrigin()) * _normal / denom;
        if (t < 0)
            return false;

        sf::Vector3f intersection = ray.getOrigin() + ray.getDirection() * t;
        sf::Vector3f c1 = intersection - _p1;
        sf::Vector3f c2 = intersection - _p2;
        sf::Vector3f c3 = intersection - _p3;
        if ((_normal * (_edge1 ^ c1)) > 0 &&
            (_normal * (_edge2 ^ c2)) > 0 &&
            (_normal * (_edge3 ^ c3)) > 0) {
            ray.addIntersection(
                render::Intersection(this, ray, t)
            );
            return true;
        }
        return false;
    }

    sf::Vector3f Triangle::getNormal(const sf::Vector3f &point) const
    {
        if (point * _normal > 0)
            return _normal;
        return -_normal;
    }
}
