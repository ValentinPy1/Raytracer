/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cylinder.primitive.v.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "Plugin.hpp"
#include "SFML/System/Vector3.hpp"

namespace vanille {
    class CylinderPrimitive_v : public render::IPrimitive, public render::Plugin {
        public:
            CylinderPrimitive_v();
            ~CylinderPrimitive_v();
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;
        private:
            sf::Vector3f _origin;
            float _radius;
            render::Entity *_parent;
    };
}
