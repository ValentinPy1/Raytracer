/*
** EPITECH PROJECT, 2023
** raytracer
** File description:
** Triangle.primitive.v.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "APlugin.hpp"
#include "SFML/System/Vector3.hpp"

namespace vanille
{
    class TrianglePrimitive_v : public render::IPrimitive, public render::APlugin
    {
    public:
        TrianglePrimitive_v();
        ~TrianglePrimitive_v() = default;
        void selfInit(libconfig::Setting &setting) override;
        sf::Vector3f getNormalAt(sf::Vector3f &point) override;

    private:
        render::Ray &processRay(render::Ray &ray, const render::Renderer &rdr);
        sf::Vector3f _vertexA;
        sf::Vector3f _vertexB;
        sf::Vector3f _vertexC;
    };
}
