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

    // void CerclePrimitive_v::solve(render::Ray &ray)
    // {
    //     sf::Vector3f vo = ray.getOrigin();
    //     sf::Vector3f vd = ray.getDirection();

    //     auto a = vd.x * vd.x + vd.y * vd.y + vd.z * vd.z;
    //     auto b = 2 * (vd.x * (vo.x - _origin.x) + vd.y * (vo.y - _origin.y) + vd.z * (vo.z - _origin.z));
    //     auto c = (vo.x - _origin.x) * (vo.x - _origin.x) + (vo.y - _origin.y) * (vo.y - _origin.y) + (vo.z - _origin.z) * (vo.z - _origin.z) - _radius * _radius;

    //     auto delta = b * b - 4 * a * c;

    //     if (delta < 0)
    //         return;

    //     float t = (-b - std::sqrt(delta)) / (2.0f * a);
    //     ray.addIntersection(
    //         render::Intersection(ray, t).addNormal(vo + t * vd)
    //     );
    //     float t2 = (-b + std::sqrt(delta)) / (2.0f * a);
    //     ray.addIntersection(
    //         render::Intersection(ray, t2).addNormal(vo + t2 * vd)
    //     );
    // }

    void CerclePrimitive_v::solve(render::Ray &ray) {
        sf::Vector3f origin = render::Ray::rotateVector(_origin, _parent->getRotation());
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();

        auto a = vd.x * vd.x + vd.y * vd.y + vd.z * vd.z;
        auto b = 2 * (vd.x * (vo.x - origin.x) + vd.y * (vo.y - origin.y) + vd.z * (vo.z - origin.z));
        auto c = (vo.x - origin.x) * (vo.x - origin.x) + (vo.y - origin.y) * (vo.y - origin.y) + (vo.z - origin.z) * (vo.z - origin.z) - _radius * _radius;

        auto delta = b * b - 4 * a * c;

        if (delta < 0)
            return;

        float t = (-b - std::sqrt(delta)) / (2.0f * a);
        sf::Vector3f intersection1 = vo + t * vd;
        intersection1 = render::Ray::rotateVector(intersection1, _parent->getRotation());
        ray.addIntersection(render::Intersection(ray, t).addNormal(intersection1 - origin));

        float t2 = (-b + std::sqrt(delta)) / (2.0f * a);
        sf::Vector3f intersection2 = vo + t2 * vd;
        intersection2 = render::Ray::rotateVector(intersection2, _parent->getRotation());
        ray.addIntersection(render::Intersection(ray, t2).addNormal(intersection2 - origin));

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
