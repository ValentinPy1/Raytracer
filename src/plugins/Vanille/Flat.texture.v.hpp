/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Flat.texture.v.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>

class FlatTexture_v : public render::ITexture, public render::Plugin  {
    public:
        FlatTexture_v(const sf::Color &color);
        ~FlatTexture_v() = default;
        sf::Color getColor(const sf::Vector2f &point) const;
    private:
        sf::Color _color;
};