/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Flat.texture.v.cpp
*/

#include "Flat.material.v.hpp"

FlatTexture_v::FlatTexture_v(const sf::Color &color) : _color(color)
{
}

sf::Color FlatTexture_v::getColor(const sf::Vector2f &point) const
{
    (void)point;
    return _color;
}
