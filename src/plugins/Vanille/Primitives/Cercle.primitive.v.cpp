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

namespace vanille
{
    CerclePrimitive_v::CerclePrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    vanille::CerclePrimitive_v::CerclePrimitive_v(sf::Vector3f origin, sf::Vector3f rotation, sf::Vector3f translation, float scale) : render::IPrimitive()
    {
        _origin = origin;
        _radius = 1;
        _rotation = rotation;
        _translation = translation;
        _scale = scale;
    }

    void CerclePrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        setting.lookupValue("x", _origin.x);
        setting.lookupValue("y", _origin.y);
        setting.lookupValue("z", _origin.z);
        if (setting.exists("radius"))
        {
            libconfig::Setting &radius = setting["radius"];
            _radius = radius;
        }
        else
        {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                      << "No radius found in primitive" << std::endl;
        }
        if (setting.exists("rotation")) {
            libconfig::Setting &rotation = setting["rotation"];
            _rotation = sf::Vector3f(rotation["x"], rotation["y"], rotation["z"]);
        }
        if (setting.exists("translation")) {
            libconfig::Setting &translation = setting["translation"];
            _translation = sf::Vector3f(translation["x"], translation["y"], translation["z"]);
        }
        if (setting.exists("scale")) {
            float scale = setting["scale"];
            _scale = scale;
        }
    }

    CerclePrimitive_v::~CerclePrimitive_v()
    {
    }

    void CerclePrimitive_v::solve(render::Ray &ray)
    {
        auto vo = ray.getVirtualOrigin(_rotation, _translation, _scale);
        auto vd = ray.getVirtualDirection(_rotation);

        auto a = vd.x * vd.x + vd.y * vd.y + vd.z * vd.z;
        auto b = 2 * (vd.x * (vo.x - _origin.x) + vd.y * (vo.y - _origin.y) + vd.z * (vo.z - _origin.z));
        auto c = (vo.x - _origin.x) * (vo.x - _origin.x) + (vo.y - _origin.y) * (vo.y - _origin.y) + (vo.z - _origin.z) * (vo.z - _origin.z) - _radius * _radius;

        auto delta = b * b - 4 * a * c;

        if (delta < 0)
            return;

        float t1 = (-b - std::sqrt(delta)) / (2.0f * a);
        float t2 = (-b + std::sqrt(delta)) / (2.0f * a);

        t1 = std::min(t1, t2);

        ray.addIntersection(
            render::Intersection(_parent, ray, t1).addNormal(vo + t1 * vd));
    }

    sf::Vector3f CerclePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        auto normal = (point - _origin);
        return render::Ray::normalize(render::Ray::getVirtualNormal(normal, _rotation));
    }

    sf::Vector3f CerclePrimitive_v::getRotation() const
    {
        return _rotation;
    }

    sf::Vector3f CerclePrimitive_v::getTranslation() const
    {
        return _translation;
    }

    float CerclePrimitive_v::getScale() const
    {
        return _scale;
    }
}

extern "C"
{
    render::IPrimitive *entryPoint()
    {
        return new vanille::CerclePrimitive_v();
    }
}
