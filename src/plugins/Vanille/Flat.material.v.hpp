/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Flat.material.v.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Plugin.hpp"
#include "IMaterial.hpp"

namespace vanille {
    class FlatMaterial_v : public render::IMaterial {
        public:
            FlatMaterial_v();
            ~FlatMaterial_v() = default;
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            void getColor(int &r, int &g, int &b, geo::vec3 point) const override;
            float getProperty(const std::string &name) const override;
        private:
            std::map<std::string, float> _properties = {
                {"shininess", 0},
            };
            sf::Color _color;
            render::Entity *_parent;
    };
}
