/*
** EPITECH PROJECT, 2022
** B-OOP-400-BAR-4-1-raytracer-eliot.janvier
** File description:
** Texture.material.v.cpp
*/

#include "Renderer.hpp"
#include "Texture.material.v.hpp"

namespace vanille
{
    TextureMaterial_v::TextureMaterial_v() : render::IMaterial()
    {
        _scale = 1;
    }

    void TextureMaterial_v::getColor(int &r, int &g, int &b,
        __attribute__((unused)) geo::vec3 point) const
    {
        int x = (int)(point.x / _scale);
        int y = (int)(point.z / _scale);
        if (x < 0)
            x += _size.x / _scale;
        if (y < 0)
            y += _size.y / _scale;
        sf::Vector2u pixel = sf::Vector2u(
            _size.x - (unsigned int)x % _size.x,
            _size.y - (unsigned int)y % _size.y
        );
        sf::Color color = _image.getPixel(pixel.x, pixel.y);
        r = (int)color.r;
        g = (int)color.g;
        b = (int)color.b;

    }

    float TextureMaterial_v::getProperty(const std::string &name) const
    {
        try {
            return _properties.at(name);
        } catch (std::out_of_range &e) {
            std::cerr << render::yellow << "[WARNING] " << render::no_color
                << "Property " << name << " not found in material" << std::endl;
            return 0;
        }
    }

    void TextureMaterial_v::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        _parent = parent;
        std::string path;
        setting.lookupValue("path", path);
        _image.loadFromFile(path);
        _texture.loadFromImage(_image);
        _size = _image.getSize();
        setting.lookupValue("scale", _scale);
        libconfig::Setting &properties = setting["properties"];
        for (int i = 0; i < properties.getLength(); i++) {
            std::string name = properties[i].getName();
            float value;
            properties[i].lookupValue(name, value);
            _properties[name] = value;
        }
    }
}

extern "C" {
    render::IMaterial *entryPoint()
    {
        return new vanille::TextureMaterial_v();
    }
}