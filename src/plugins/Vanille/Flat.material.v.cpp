/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Flat.material.v.cpp
*/

#include "Flat.material.v.hpp"

namespace vanille {
    FlatMaterial_v::FlatMaterial_v(const sf::Color &color) : render::AMaterial()
    {
        _color = color;
    }

    void FlatMaterial_v::getColor(int &r, int &g, int &b, geo::vec3 point) const
    {
        r = _color.r;
        g = _color.g;
        b = _color.b;
    }
}

extern "C" {
    render::IMaterial *entryPoint()
    {
        return new vanille::FlatMaterial_v(sf::Color::White);
    }
}
