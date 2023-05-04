/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-eliot.janvier
** File description:
** Texture.material.v.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Plugin.hpp"
#include "IMaterial.hpp"

namespace vanille {
    class TextureMaterial_v : public render::IMaterial {
        public:
            TextureMaterial_v();
            ~TextureMaterial_v() = default;
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            void getColor(int &r, int &g, int &b, geo::vec3 point) const override;
            float getProperty(const std::string &name) const override;
        private:
            std::map<std::string, float> _properties = {
                {"reflectivity", 0},
                {"shininess", 0},
            };
            render::Entity *_parent;
            sf::Image _image;
            sf::Texture _texture;
            sf::Vector2u _size;
            float _scale;
    };
}
