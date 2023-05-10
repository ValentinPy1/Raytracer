/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cercle.primitive.v.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "Plugin.hpp"
#include "Entity.hpp"

namespace vanille {
    class CerclePrimitive_v : public render::IPrimitive {
        public:
            CerclePrimitive_v();
            CerclePrimitive_v(sf::Vector3f origin, sf::Vector3f rotation, sf::Vector3f translation, float scale);
            ~CerclePrimitive_v();
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;
        private:
            sf::Vector3f _origin;
            float _radius;
            sf::Vector3f _rotation;
            sf::Vector3f _translation;
            float _scale;
            render::Entity *_parent;
    };
}
