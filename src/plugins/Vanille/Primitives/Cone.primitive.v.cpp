/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cone.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include "Cone.primitive.v.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"
#include "operations.hpp"




namespace vanille {
    ConePrimitive_v::ConePrimitive_v() : render::IPrimitive()
    {
        std::cout << "ConePrimitive_v::ConePrimitive_v" << std::endl;
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    ConePrimitive_v::~ConePrimitive_v()
    {
    }

    void ConePrimitive_v::solve(render::Ray &ray)
    {
    //  a=xD2+yD2-zD2, b=2xExD+2yEyD-2zEzD, and c=xE2+yE2-zE2
        auto vo = ray.getOrigin();
        auto vd = ray.getDirection();

        // _direction is the rotation of the cone in x y z, we need to rotate the ray to match the cone

        // auto x = vd.x * std::cos(_rotation.x) - vd.x * std::sin(_rotation.x);
        // auto y = vd.x * std::sin(_rotation.y) + vd.y * std::cos(_rotation.y);
        // auto z = vd.z * std::cos(_rotation.z) - vd.z * std::sin(_rotation.z);
        vd = render::Ray::rotateVector(vd, _rotation);
        vo = render::Ray::rotateVector(vo, _rotation);


        auto a = vd.x * vd.x + vd.z * vd.z - vd.y * vd.y;
        auto b = 2 * (vd.x * (vo.x - _origin.x) + vd.z * (vo.z - _origin.z) - vd.y * (vo.y - _origin.y));
        auto c = (vo.x - _origin.x) * (vo.x - _origin.x) + (vo.z - _origin.z) *
                (vo.z - _origin.z) - (vo.y - _origin.y) * (vo.y - _origin.y);

        auto delta = (b * b) - 4 * a * c;

        if (delta < 0)
            return;

        float t1 = (-b - std::sqrt(delta)) / (2.0f * a);
        float t2 = (-b + std::sqrt(delta)) / (2.0f * a);

        t1 = std::min(t1, t2);

        auto point = vo + vd * t1;

        if (point.y < _origin.y || point.y > _origin.y + _height)
            return;

        ray.addIntersection(
            render::Intersection(_parent, ray, t1)
            .addNormal(getNormalAt(point))
        );

        return;
    }

    sf::Vector3f ConePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        // return (point - _origin) / _radius;
        // get the normal of a cone at a given point
        // the normal of a cone is the vector from the point to the center of the cone
        // the center of the cone is the origin
        // return (point - _origin);

        // auto k = 1.0f; //angle
        // auto x = point.x;
        // auto y = point.y;
        // auto z = point.z;
        // auto sqr = std::sqrt(x * x + y * y);

        // auto dx = -k * (x / sqr);
        // auto dy = -k * (y / sqr);
        // auto dz = 1.0f;

        // return sf::Vector3f(dx, dy, dz);

        // auto angle = 45.0f;
        // // demi angle + 90
        // auto k = (angle / 2.0f) + 90.0f;

        // return sf::Vector3f(
        //     std::cos(k) * point.x,
        //     std::sin(k) * point.y,
        //     std::sin(k) * point.z
        // );

        // rotate the normal vector to match the cone rotation

        // auto x = point.x * std::cos(_rotation.x) - point.x * std::sin(_rotation.x);
        // auto y = point.x * std::sin(_rotation.y) + point.y * std::cos(_rotation.y);
        // auto z = point.z * std::cos(_rotation.z) - point.z * std::sin(_rotation.z);
        //render::ray::rotateVector(point, _rotation);

        auto rotation = render::Ray::rotateVector(point, _rotation);

        return sf::Vector3f(
            rotation.x,
            rotation.y,
            rotation.z
        );
        // return sf::Vector3f(x, y, z);

    }

    void ConePrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        setting.lookupValue("x", _origin.x);
        setting.lookupValue("y", _origin.y);
        setting.lookupValue("z", _origin.z);
        setting.lookupValue("radius", _radius);
        setting.lookupValue("height", _height);
        _rotation = sf::Vector3f(0, 0, 0);
        if (setting.exists("rotation")) {
            libconfig::Setting &rotation = setting.lookup("rotation");
            rotation.lookupValue("x", _rotation.x);
            rotation.lookupValue("y", _rotation.y);
            rotation.lookupValue("z", _rotation.z);
        }
    }
}

extern "C" {
    render::IPrimitive *entryPoint() {
        return new vanille::ConePrimitive_v();
    }
}
