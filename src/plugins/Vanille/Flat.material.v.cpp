/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Flat.material.v.cpp
*/

#include "Renderer.hpp"
#include "Flat.material.v.hpp"

namespace vanille {
    FlatMaterial_v::FlatMaterial_v(const sf::Color &color) : render::IMaterial()
    {
        _color = color;
    }

    void FlatMaterial_v::getColor(int &r, int &g, int &b,
        __attribute__((unused)) geo::vec3 point) const
    {
        r = _color.r;
        g = _color.g;
        b = _color.b;
    }

    float FlatMaterial_v::getProperty(const std::string &name) const
    {
        try {
            return _properties.at(name);
        } catch (std::out_of_range &e) {
            std::cerr << render::yellow << "[WARNING] " << render::no_color
                << "Property " << name << " not found in material" << std::endl;
            return 0;
        }
    }
}

extern "C" {
    render::IMaterial *entryPoint()
    {
        return new vanille::FlatMaterial_v(sf::Color::Red);
    }
}
