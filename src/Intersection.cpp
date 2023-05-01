/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Intersection.cpp
*/

#include <iostream>
#include "Ray.hpp"
#include "Entity.hpp"
#include "operations.hpp"
#include "Camera.hpp"

namespace render {
    Intersection::Intersection(Entity *interceptee,
    Ray &ray, float distance)
        : _distance(distance), _ray(ray), _interceptee(interceptee)
    {
        int r, g, b;

        _point = _ray.getOrigin() + _ray.getDirection() * (_distance);
        _interceptee->getMaterial()->getColor(r, g, b, (geo::vec3) {_point.x, _point.y, _point.z});
        _color = sf::Color(r, g, b);
        _normal = _interceptee->getPrimitive()->getNormalAt(_point);
    }

    Intersection::Intersection(Ray &ray, float distance)
        : _distance(distance), _ray(ray)
    {
        _point = _ray.getOrigin() + _ray.getDirection() * (_distance);
    }

    Intersection::Intersection(const Intersection &other)
        : _distance(other._distance), _point(other._point),
        _normal(other._normal), _color(other._color),
        _ray(other._ray), _interceptee(other._interceptee)
    {
    }

    Intersection &Intersection::addNormal(IPrimitive *primitive)
    {
        _normal = primitive->getNormalAt(_point);
        return *this;
    }

    Intersection &Intersection::addColor(sf::Color color)
    {
        _color = color;
        return *this;
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

    Entity *Intersection::getInterceptee() const
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
