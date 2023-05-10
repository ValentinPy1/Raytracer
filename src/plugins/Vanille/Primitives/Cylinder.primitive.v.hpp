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


            sf::Vector3f getRotation() const override;
            sf::Vector3f getTranslation() const override;
            float getScale() const override;
        private:
            sf::Vector3f _origin;
            float _radius;
            float _height;
            sf::Vector3f _rotation = {0, 0, 0};
            float _scale = 1;
            render::Entity *_parent;
    };
}
