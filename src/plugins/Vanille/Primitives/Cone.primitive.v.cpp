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
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    ConePrimitive_v::~ConePrimitive_v()
    {
    }

    void ConePrimitive_v::solve(render::Ray &ray)
    {
        auto vo = ray.getVirtualOrigin(_rotation, {0, 0, 0}, _scale);
        auto vd = ray.getVirtualDirection(_rotation);

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
        point = render::Ray::rotateVector(point - _origin, -_rotation);
        auto diff = render::Ray::normalize(point - _origin);
        auto normal = diff ^ sf::Vector3f(0, 1, 0);
        normal = render::Ray::normalize(normal);
        normal = render::Ray::getVirtualNormal(normal, _rotation);
        return normal;
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
        if (setting.exists("translation")) {
            libconfig::Setting &translation = setting["translation"];
            _origin += sf::Vector3f(translation["x"], translation["y"], translation["z"]);
        }
        if (setting.exists("scale")) {
            float scale = setting["scale"];
            _radius *= scale;
            _height *= scale;
        }
    }

    sf::Vector3f ConePrimitive_v::getRotation() const
    {
        // delt with internally
        return {0, 0, 0};
    }

    sf::Vector3f ConePrimitive_v::getTranslation() const
    {
        return _origin;
    }

    float ConePrimitive_v::getScale() const
    {
        return _radius;
    }
}

extern "C" {
    render::IPrimitive *entryPoint() {
        return new vanille::ConePrimitive_v();
    }
}
