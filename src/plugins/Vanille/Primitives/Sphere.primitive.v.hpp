/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.primitive.v.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "Plugin.hpp"
#include "SFML/System/Vector3.hpp"

namespace vanille {
    class SpherePrimitive_v : public render::IPrimitive {
        public:
            SpherePrimitive_v();
            ~SpherePrimitive_v();
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;
        private:
            sf::Vector3f _origin;
            float _radius;
            sf::Vector3f _rotation;
            render::Entity *_parent;
    };
}
