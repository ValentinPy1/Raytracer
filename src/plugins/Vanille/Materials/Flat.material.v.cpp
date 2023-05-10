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

    void FlatMaterial_v::selfInit(libconfig::Setting &setting, __attribute__((unused)) render::Entity *parent)
    {
        libconfig::Setting &color = setting.lookup("color");
        int r, g, b;
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        _color = sf::Color(r, g, b);

        libconfig::Setting &properties = setting.lookup("properties");
        for (int i = 0; i < properties.getLength(); i++) {
            libconfig::Setting &property = properties[i];
            std::string name = property.getName();
            float value = 10;
            properties.lookupValue(name, value);
            _properties[name] = value;
        }
    }
}

extern "C" {
    render::IMaterial *entryPoint()
    {
        return new vanille::FlatMaterial_v();
    }
}
