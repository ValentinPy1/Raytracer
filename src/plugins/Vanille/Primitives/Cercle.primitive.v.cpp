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

    void setRotation(sfVector3f rotation)
    {
        _rotation = rotation;
    }

    sfVector3f getRotation()
    {
        return _rotation;
    }

    CerclePrimitive_v::CerclePrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    void CerclePrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
            setting.lookupValue("x", _origin.x);
            setting.lookupValue("y", _origin.y);
            setting.lookupValue("z", _origin.z);
        if (setting.exists("radius")) {
            libconfig::Setting &radius = setting["radius"];
            _radius = radius;
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No radius found in primitive" << std::endl;
        }
    }

    CerclePrimitive_v::~CerclePrimitive_v()
    {
    }

    void CerclePrimitive_v::solve(render::Ray &ray)
{
    sf::Vector3f vo = render::Ray::rotateVector(ray.getOrigin(), _parent->getRotation());
    sf::Vector3f vd = render::Ray::rotateVector(ray.getDirection(), _parent->getRotation());

    auto a = vd.x * vd.x + vd.y * vd.y + vd.z * vd.z;
    auto b = 2 * (vd.x * (vo.x - _origin.x) + vd.y * (vo.y - _origin.y) + vd.z * (vo.z - _origin.z));
    auto c = (vo.x - _origin.x) * (vo.x - _origin.x) + (vo.y - _origin.y) * (vo.y - _origin.y) + (vo.z - _origin.z) * (vo.z - _origin.z) - _radius * _radius;

    auto delta = b * b - 4 * a * c;

    if (delta < 0)
        return;

    float t1 = (-b - std::sqrt(delta)) / (2.0f * a);
    sf::Vector3f intersection1 = vo + t1 * vd;
    float t2 = (-b + std::sqrt(delta)) / (2.0f * a);
    sf::Vector3f intersection2 = vo + t2 * vd;

    sf::Vector3f intersection;
    if (t1 >= 0 && t2 >= 0) {
        if (t1 < t2)
            intersection = intersection1;
        else
            intersection = intersection2;
    }
    else if (t1 >= 0)
        intersection = intersection1;
    else if (t2 >= 0)
        intersection = intersection2;
    else
        return;

    intersection = render::Ray::rotateVector(intersection, _parent->getRotation());
    sf::Vector3f normal = intersection - _origin;
    normal = render::Ray::rotateVector(normal, _parent->getRotation());

    ray.addIntersection(render::Intersection(ray, (intersection - vo).length()).addNormal(normal));
}



    sf::Vector3f CerclePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        return (point - _origin);
    }

}

extern "C" {
    render::IPrimitive *entryPoint()
    {
        return new vanille::CerclePrimitive_v();
    }
}
