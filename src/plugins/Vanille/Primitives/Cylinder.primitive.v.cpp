/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cylinder.primitive.v.cpp
*/

#include <string>
#include <cmath>
#include "Cylinder.primitive.v.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille
{
    CylinderPrimitive_v::CylinderPrimitive_v() : render::IPrimitive()
    {
        _origin = sf::Vector3f(0, 0, 0);
        _radius = 1;
    }

    CylinderPrimitive_v::~CylinderPrimitive_v()
    {
    }

    void CylinderPrimitive_v::solve(render::Ray &ray)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();
        vo = render::Ray::rotateVector(vo - _origin, -_rotation);
        vd = render::Ray::rotateVector(vd, -_rotation);
        auto a = vd.x * vd.x + vd.z * vd.z;
        auto b = 2 * (vd.x * vo.x + vd.z * vo.z);
        auto c = vo.x * vo.x + vo.z * vo.z - _radius * _radius;

        topCircle->solve(ray);
        bottomCircle->solve(ray);

        auto delta = (b * b) - 4 * a * c;

        if (delta < 0)
            return;
        auto t1 = (-b - std::sqrt(delta)) / (2.0f * a);
        auto t2 = (-b + std::sqrt(delta)) / (2.0f * a);
        auto t = std::min(t1, t2);
        if (t < 0)
            return;
        auto point = vo + vd * t;
        if (_height != -1 && (point.y < 0 || point.y > _height))
        {
            t = std::max(t1, t2);
            if (t < 0)
                return;
            point = vo + vd * t;
            if (point.y < 0 || point.y > _height)
                return;
        }

        auto backupVd = ray.getDirection();
        auto backupVo = ray.getOrigin();
        ray.setOrigin(vo);
        ray.setDirection(vd);
        topCircle->solve(ray);
        // if (ray.getIntersections().size() > 0)
        //     ray.getIntersections().back().addNormal(getNormalAt(point));
        bottomCircle->solve(ray);
        ray.setOrigin(backupVo);
        ray.setDirection(backupVd);
        // if (ray.getIntersections().size() > 0)
        //     ray.getIntersections().back().addNormal(getNormalAt(point));



        ray.addIntersection(
            render::Intersection(_parent, ray, t).addNormal(getNormalAt(point)));

        return;
    }

    sf::Vector3f CylinderPrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        point = render::Ray::rotateVector(point, _rotation);
        point = point - _origin;
        point.y = 0;
        point = render::Ray::rotateVector(point, -_rotation);
        point = render::Ray::normalize(point);
        return (point);
    }

    void CylinderPrimitive_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        const auto &translation = setting.lookup("origin");
        _origin = sf::Vector3f(translation[0], translation[1], translation[2]);
        _radius = setting.lookup("radius");
        if (setting.exists("scale"))
            _scale = setting.lookup("scale");
        else
            _scale = 1;
        if (setting.exists("rotation")) {
            const auto &rotation = setting.lookup("rotation");
            _rotation = sf::Vector3f(rotation[0], rotation[1], rotation[2]);
        } else {
            _rotation = {0, 0, 0};
        }
        if (setting.exists("height")) {
            _height = setting.lookup("height");
        } else {
            _height = -1;
        }
        sf::Vector3f topCirclePosition = _origin + sf::Vector3f(0, _height, 0);

        topCircle = new CerclePrimitive_v(topCirclePosition, _rotation, {0, 0, 0}, _scale);
        bottomCircle = new CerclePrimitive_v(_origin, _rotation, {0, 0, 0}, _scale);
        topCircle->setParent(parent);
        bottomCircle->setParent(parent);
    }

    sf::Vector3f CylinderPrimitive_v::getRotation() const
    {
        return _rotation;
    }

    sf::Vector3f CylinderPrimitive_v::getTranslation() const
    {
        return _origin;
    }

    float CylinderPrimitive_v::getScale() const
    {
        return _radius;
    }
}
