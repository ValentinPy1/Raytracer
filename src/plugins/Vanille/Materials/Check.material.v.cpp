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
        _colors.push_back(sf::Color::White);
        _colors.push_back(sf::Color::Black);

        _pattern.push_back(_colors);
        std::reverse(_colors.begin(), _colors.end());
        _pattern.push_back(_colors);

        _scale = 1;
    }

    void CheckMaterial_v::getColor(int &r, int &g, int &b,
        __attribute__((unused)) geo::vec3 point) const
    {
        float scaledX = point.x / _scale;
        float scaledY = point.z / _scale;
        if (scaledX < 0)
            scaledX -= 1;
        if (scaledY < 0)
            scaledY -= 1;
        size_t patternWidth = _pattern[0].size();
        size_t patternHeight = _pattern.size();
        size_t indexX = (size_t)scaledX % patternWidth;
        size_t indexY = (size_t)scaledY % patternHeight;
        sf::Color color = _pattern[indexY][indexX];
        r = (int)color.r;
        g = (int)color.g;
        b = (int)color.b;
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
        _colors = {};
        _pattern = {};
        libconfig::Setting &colors = setting.lookup("colors");
        for (int i = 0; i < colors.getLength(); i++) {
            libconfig::Setting &color = colors[i];
            int r;
            int g;
            int b;
            color.lookupValue("r", r);
            color.lookupValue("g", g);
            color.lookupValue("b", b);
            _colors.push_back(sf::Color(r, g, b));
        }
        libconfig::Setting &pattern = setting.lookup("pattern");
        for (int y = 0; y < pattern.getLength(); y++) {
            libconfig::Setting &row = pattern[y];
            std::vector<sf::Color> rowColors;
            for (int x = 0; x < row.getLength(); x++) {
                int index = row[x];
                rowColors.push_back(_colors[index]);
            }
            _pattern.push_back(rowColors);
        }
        setting.lookupValue("scale", _scale);
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
