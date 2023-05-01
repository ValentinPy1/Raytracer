/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Flat.material.v.cpp
*/

#include "Renderer.hpp"
#include "Flat.material.v.hpp"

namespace vanille {
    FlatMaterial_v::FlatMaterial_v() : render::IMaterial()
    {
        _color = sf::Color::White;
    }

    void FlatMaterial_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        if (setting.exists("color")) {
            libconfig::Setting &color = setting["color"];
            int r = color["r"];
            int g = color["g"];
            int b = color["b"];
            _color = sf::Color(r, g, b);
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No color found in material" << std::endl;
        }
        if (setting.exists("shininess")) {
            libconfig::Setting &shininess = setting["shininess"];
            _properties["shininess"] = shininess;
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No shininess found in material" << std::endl;
        }
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
        return new vanille::FlatMaterial_v();
    }
}
