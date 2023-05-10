/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Plane.primitive.v hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "Plugin.hpp"
#include "Entity.hpp"

namespace vanille {
    class PlanePrimitive_v : public render::IPrimitive {
        public:
            PlanePrimitive_v();
            ~PlanePrimitive_v();
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;
        private:
            sf::Vector3f _origin;
            sf::Vector3f _normal;
            sf::Vector3f _rotation;
            render::Entity *_parent;
    };
}
