/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Intersection.cpp
*/

#include <iostream>
#include "../include/AObject.hpp"
#include "../include/Ray.hpp"
#include "operations.hpp"

namespace render {
    Intersection::Intersection(AObject *interceptee,
    Ray &ray, float distance)
        : _distance(distance), _ray(ray), _interceptee(interceptee)
    {
        _point = _ray.getOrigin() + _ray.getDirection() * (_distance);
        _color = _interceptee->getColor();
        _normal = _interceptee->getNormal(_point);
    }

    Intersection::Intersection(const Intersection &other)
        : _distance(other._distance), _point(other._point),
        _normal(other._normal), _color(other._color),
        _ray(other._ray), _interceptee(other._interceptee)
    {
    }

    float Intersection::getDistance() const
    {
        return _distance;
    }

    bool Intersection::isFacingCamera(const Camera &camera) const
    {
        //TODO
        (void) camera;
        return false;
    }

    sf::Vector3f Intersection::getNormal() const
    {
        return _normal;
    }

    sf::Color Intersection::getColor() const
    {
        return _color;
    }

    IObject *Intersection::getInterceptee() const
    {
        return _interceptee;
    }

    Intersection &Intersection::operator=(const Intersection &other)
    {
        _distance = other._distance;
        _point = other._point;
        _normal = other._normal;
        _color = other._color;
        _ray = other._ray;
        _interceptee = other._interceptee;
        return *this;
    }

    sf::Vector3f Intersection::getPoint() const
    {
        return _point;
    }

    float Intersection::getShininess() const
    {
        return _shininess;
    }

    sf::Vector3f Intersection::getPointRelativeToCamera(const Camera &camera) const
    {
        return _point + camera.getFocalPoint();
    }

}
