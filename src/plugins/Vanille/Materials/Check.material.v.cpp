/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Check.material.v.cpp
*/

#include "Renderer.hpp"
#include "Check.material.v.hpp"

namespace vanille
{
    CheckMaterial_v::CheckMaterial_v() : render::IMaterial()
    {
        _color1 = sf::Color::White;
        _color2 = sf::Color::Black;
    }
    void CheckMaterial_v::getColor(int &r, int &g, int &b,
        __attribute__((unused)) geo::vec3 point) const
    {
        if ((int)point.x % 2 == 0 ^ (int)point.y % 2 == 0 ^ (int)point.z % 2 == 0) {
            r = _color1.r;
            g = _color1.g;
            b = _color1.b;
        } else {
            r = _color2.r;
            g = _color2.g;
            b = _color2.b;
        }
    }
    float CheckMaterial_v::getProperty(const std::string &name) const
    {
        try {
            return _properties.at(name);
        } catch (std::out_of_range &e) {
            std::cerr << render::yellow << "[WARNING] " << render::no_color
                << "Property " << name << " not found in material" << std::endl;
            return 0;
        }
    }

    void CheckMaterial_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        if (setting.exists("color1")) {
            libconfig::Setting &color = setting["color1"];
            int r = color["r"];
            int g = color["g"];
            int b = color["b"];
            _color1 = sf::Color(r, g, b);
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No color found in material" << std::endl;
        }
        if (setting.exists("color2")) {
            libconfig::Setting &color = setting["color2"];
            int r = color["r"];
            int g = color["g"];
            int b = color["b"];
            _color2 = sf::Color(r, g, b);
        } else {
            std::cout << render::yellow << "[WARNING] " << render::no_color
                << "No color found in material" << std::endl;
        }
        libconfig::Setting &properties = setting.lookup("properties");
        for (int i = 0; i < properties.getLength(); i++) {
            libconfig::Setting &property = properties[i];
            std::string name = property.getName();
            float value = 10;
            properties.lookupValue(name, value);
            _properties[name] = value;
        }
    }
} // namespace v

extern "C" {
    vanille::CheckMaterial_v *entryPoint()
    {
        return new vanille::CheckMaterial_v();
    }
}
