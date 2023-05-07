/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Triangle.primitive.v.cpp
*/

#include <string>
#include "Triangle.primitive.v.hpp"
#include "Render.hpp"
#include "Ray.hpp"
#include "operations.hpp"

namespace vanille {
    TrianglePrimitive_v::TrianglePrimitive_v() : render::IPrimitive(), render::APlugin()
    {
        _vertexA = sf::Vector3f(0, 0, 0);
        _vertexB = sf::Vector3f(0, 1, 0);
        _vertexC = sf::Vector3f(1, 0, 0);
        _name = "TrianglePrimitive_v";
        _priority = 0;
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            return processRay(ray, rdr);
        };
    }

    render::Ray &TrianglePrimitive_v::processRay(render::Ray &ray, const render::Renderer &rdr)
    {
        sf::Vector3f vo = ray.getOrigin();
        sf::Vector3f vd = ray.getDirection();
        sf::Vector3f e1 = _vertexB - _vertexA;
        sf::Vector3f e2 = _vertexC - _vertexA;
        sf::Vector3f pvec = crossProduct(vd, e2);
        float det = dotProduct(e1, pvec);

        if (det < 0.0001 && det > -0.0001)
            return ray;

        float inv_det = 1 / det;
        sf::Vector3f tvec = vo - _vertexA;
        float u = dotProduct(tvec, pvec) * inv_det;

        if (u < 0 || u > 1)
            return ray;

        sf::Vector3f qvec = crossProduct(tvec, e1);
        float v = dotProduct(vd, qvec) * inv_det;

        if (v < 0 || u + v > 1)
            return ray;

        float t = dotProduct(e2, qvec) * inv_det;
        ray.addIntersection(
            render::Intersection(ray, t).addNormal(this)
        );
        return ray;
    }

    sf::Vector3f TrianglePrimitive_v::getNormalAt(sf::Vector3f &point)
    {
        sf::Vector3f edge1 = _vertexB - _vertexA;
        sf::Vector3f edge2 = _vertexC - _vertexA;
        return normalize(crossProduct(edge1, edge2));
    }

    void TrianglePrimitive_v::selfInit(libconfig::Setting &setting)
    {
        _vertexA = sf::Vector3f(setting["vertexA"][0], setting["vertexA"][1], setting["vertexA"][2]);
        _vertexB = sf::Vector3f(setting["vertexB"][0], setting["vertexB"][1], setting["vertexB"][2]);
        _vertexC = sf::Vector3f(setting["vertexC"][0], setting["vertexC"][1], setting["vertexC"][2]);
    }
}

extern "C" {
    render::APlugin *entryPoint() {
        return new vanille::TrianglePrimitive_v();
    }
}
