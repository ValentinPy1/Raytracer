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
            FlatMaterial_v(const sf::Color &color);
            ~FlatMaterial_v() = default;
            void getColor(int &r, int &g, int &b, geo::vec3 point) const override;
            float getProperty(const std::string &name) const override;
        private:
            std::map<std::string, float> _properties;
            sf::Color _color;
    };
}
