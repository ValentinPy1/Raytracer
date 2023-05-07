/*
** EPITECH PROJECT, 2022
** ray
** File description:
** TrianglePart.primitive.v.cpp
*/

#include <cmath>
#include "operations.hpp"
#include "Mesh.primitive.v.hpp"

namespace vanille {
    void TrianglePart::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        const libconfig::Setting &vertices = setting.lookup("vertices");

        if (vertices.getLength() != 3)
            throw std::runtime_error("A triangle must have 3 vertices");
        vertices[0].lookupValue("x", _p1.x);
        vertices[0].lookupValue("y", _p1.y);
        vertices[0].lookupValue("z", _p1.z);
        vertices[1].lookupValue("x", _p2.x);
        vertices[1].lookupValue("y", _p2.y);
        vertices[1].lookupValue("z", _p2.z);
        vertices[2].lookupValue("x", _p3.x);
        vertices[2].lookupValue("y", _p3.y);
        vertices[2].lookupValue("z", _p3.z);
        _normal = (_p2 - _p1) ^ (_p3 - _p1);
        _parent = parent;
    }

    sf::Vector3f TrianglePart::getNormalAt(__attribute__((unused)) sf::Vector3f &point)
    {
        return _normal;
    }

    void TrianglePart::move(sf::Vector3f &offset)
    {
        _p1 += offset;
        _p2 += offset;
        _p3 += offset;
    }

    void TrianglePart::rotate(sf::Vector3f &rotation, sf::Vector3f center)
    {
        computePointRotation(_p1, rotation, center);
        computePointRotation(_p2, rotation, center);
        computePointRotation(_p3, rotation, center);
        _normal = (_p2 - _p1) ^ (_p3 - _p1);
    }

    void TrianglePart::computePointRotation(sf::Vector3f &point, sf::Vector3f &rotation, sf::Vector3f barycenter)
    {
        sf::Vector3f tmp = point - barycenter;
        sf::Vector3f rotated = {0, 0, 0};
        float x = tmp.x;
        float y = tmp.y;
        float z = tmp.z;
        float a = rotation.x * (float) M_PI / 180.0;
        float b = rotation.y * (float) M_PI / 180.0;
        float c = rotation.z * (float) M_PI / 180.0;
        rotated.x = cos(b)*cos(c)*x - cos(b)*sin(c)*y + sin(b)*z;
        rotated.y = sin(a)*sin(b)*cos(c)*x + cos(a)*sin(c)*x - sin(a)*sin(b)*sin(c)*y + cos(a)*cos(c)*y - sin(a)*cos(b)*z;
        rotated.z = -cos(a)*sin(b)*cos(c)*x + sin(a)*sin(c)*x + cos(a)*sin(b)*sin(c)*y + sin(a)*cos(c)*y + cos(a)*cos(b)*z;

        point = rotated + barycenter;
    }

    void TrianglePart::scale(float scale) {
        _p1 *= scale;
        _p2 *= scale;
        _p3 *= scale;
        _normal = (_p2 - _p1) ^ (_p3 - _p1);
    }

    void TrianglePart::solve(render::Ray &ray)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();
        sf::Vector3f e1 = _p2 - _p1;
        sf::Vector3f e2 = _p3 - _p1;
        sf::Vector3f pvec = vd ^ e2;
        float det = e1 * pvec;

        if (det < 0.0001 && det > -0.0001)
            return;

        float inv_det = 1 / det;
        sf::Vector3f tvec = vo - _p1;
        float u = (tvec * pvec) * inv_det;

        if (u < 0 || u > 1)
            return;

        sf::Vector3f qvec = (tvec ^ e1);
        float v = vd * qvec * inv_det;

        if (v < 0 || u + v > 1)
            return;

        float t = e2 * qvec * inv_det;
        ray.addIntersection(
            render::Intersection(_parent, ray, t).addNormal(vo + t * vd)
        );
    }
}
