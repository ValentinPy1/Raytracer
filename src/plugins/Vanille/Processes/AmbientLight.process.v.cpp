/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientLight.process.v.cpp
*/

#include <libconfig.h++>
#include "Camera.hpp"
#include "Ray.hpp"
#include "Renderer.hpp"
#include "AmbientLight.process.v.hpp"
#include <math.h>

namespace render {
    AmbientLight_v::AmbientLight_v() :
        Plugin(
           nullptr,
            nullptr,
            nullptr,
            1000,
            "AmbientLight"
        )
    {
        _init =  [this](render::Renderer &rdr) {
                try {
                    const libconfig::Setting *setting = rdr.getParams();
                    if (setting == nullptr)
                        throw std::runtime_error("No params set");
                    const libconfig::Setting &ambientLight = setting->lookup("ambientLight");
                    std::string type;
                    ambientLight.lookupValue("type", type);
                    if (type == "flat")
                        _type = Type::FLAT;
                    else if (type == "gradient")
                        _type = Type::GRADIENT;
                    else if (type == "texture")
                        _type = Type::TEXTURE;
                    else
                        throw std::runtime_error("Invalid type");
                    if (_type == Type::FLAT)
                        loadFlatColor(rdr);
                    else if (_type == Type::GRADIENT)
                        loadGradient(rdr);
                    else if (_type == Type::TEXTURE)
                        loadTexture(rdr);
                } catch (std::exception &e) {
                    std::cout << render::green << "[INFO] " << render::yellow << "[Ambient Light Plugin] " << render::no_color << "Defaulting to flat color" << std::endl;
                    _type = Type::FLAT;
                    _color = sf::Color(30, 30, 50);
                }
            };
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            applyAmbientLight(ray, rdr);
            return ray;
        };
    }

    void AmbientLight_v::loadFlatColor(render::Renderer &rdr)
    {
        const libconfig::Setting *setting = rdr.getParams();
        if (setting == nullptr)
            throw std::runtime_error("No params set");
        const libconfig::Setting &ambientLight = setting->lookup("ambientLight");
        const libconfig::Setting &color = ambientLight.lookup("color");
        int r, g, b;
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        _color = sf::Color(r, g, b);
    }

    void AmbientLight_v::loadGradient(render::Renderer &rdr)
    {
        _gradientColors.clear();
        const libconfig::Setting *setting = rdr.getParams();
        if (setting == nullptr)
            throw std::runtime_error("No params set");
        const libconfig::Setting &ambientLight = setting->lookup("ambientLight");
        const libconfig::Setting &gradient = ambientLight.lookup("gradient");
        for (int i = 0; i < gradient.getLength(); i++) {
            int r, g, b;
            gradient[i].lookupValue("r", r);
            gradient[i].lookupValue("g", g);
            gradient[i].lookupValue("b", b);
            _gradientColors.push_back(sf::Color(r, g, b));
        }
        generateGradient();
        int r = 0, g = 0, b = 0;
        for (auto &color : _gradient) {
            r += color.r;
            g += color.g;
            b += color.b;
        }
        r /= _gradientColors.size();
        g /= _gradientColors.size();
        b /= _gradientColors.size();
        _color = sf::Color(r, g, b);
    }

    void AmbientLight_v::generateGradient()
    {
        for (int i = 0; i < 360; i++) {
            sf::Color color;
            color.r = (int) (sin(i * M_PI / 180) * 127 + 128);
            color.g = (int) (sin(i * M_PI / 180 + 2 * M_PI / 3) * 127 + 128);
            color.b = (int) (sin(i * M_PI / 180 + 4 * M_PI / 3) * 127 + 128);
            _gradient.push_back(color);
        }
    }

    void AmbientLight_v::loadTexture(render::Renderer &rdr)
    {
        const libconfig::Setting *setting = rdr.getParams();
        if (setting == nullptr)
            throw std::runtime_error("No params set");
        const libconfig::Setting &ambientLight = setting->lookup("ambientLight");
        std::string path;
        ambientLight.lookupValue("path", path);
        if (!_texture.loadFromFile(path))
            throw std::runtime_error("Failed to load texture");
        _texture.setRepeated(true);
        _texture.setSmooth(true);
        _image = _texture.copyToImage();
        int meanR = 0, meanG = 0, meanB = 0;
        for (int i = 0; i < _image.getSize().x; i++) {
            for (int j = 0; j < _image.getSize().y; j++) {
                sf::Color color = _image.getPixel(i, j);
                meanR += color.r;
                meanG += color.g;
                meanB += color.b;
            }
        }
        meanR /= _image.getSize().x * _image.getSize().y;
        meanG /= _image.getSize().x * _image.getSize().y;
        meanB /= _image.getSize().x * _image.getSize().y;
        _color = sf::Color(meanR, meanG, meanB);
    }

    void AmbientLight_v::applyColor(render::Ray &ray, __attribute__((unused)) const render::Renderer &rdr, sf::Color color) {
        if (!ray.hasIntersections()) {
            ray.setColor(sf::Color(color));
            return;
        }
        ray.setColor(ray.blendMultiply(_color));
    }

    void AmbientLight_v::applyFlatColor(render::Ray &ray, __attribute__((unused)) const render::Renderer &rdr) {
        applyColor(ray, rdr, _color);
    }

    void AmbientLight_v::applyGradient(render::Ray &ray, __attribute__((unused)) const render::Renderer &rdr) {
        sf::Vector2u projection = getProjection(ray.getDirection());
        sf::Color color = _gradient[projection.x];
        applyColor(ray, rdr, color);
    }

    void AmbientLight_v::applyTexture(render::Ray &ray, __attribute__((unused)) const render::Renderer &rdr) {
        sf::Vector2u projection = getProjection(ray.getDirection());
        size_t width = _image.getSize().x;
        size_t height = _image.getSize().y;
        sf::Vector2u center = sf::Vector2u(width / 2, height / 2);
        int x = (int) (center.x + projection.x * width / 360);
        int y = (int) (center.y + projection.y * height / 360);
        sf::Color color = _image.getPixel(x, y);
        applyColor(ray, rdr, color);
    }

    void AmbientLight_v::applyAmbientLight(render::Ray &ray, const render::Renderer &rdr) {
        if (_type == Type::FLAT)
            applyFlatColor(ray, rdr);
        else if (_type == Type::GRADIENT)
            applyGradient(ray, rdr);
        else if (_type == Type::TEXTURE)
            applyTexture(ray, rdr);
    }

    sf::Vector2u AmbientLight_v::getProjection(sf::Vector3f vector)
    {
        float x = vector.x;
        float y = vector.y;
        float z = vector.z;
        float r = sqrt(x * x + y * y + z * z);
        float theta = acos(z / r);
        float phi = atan2(y, x);
        if (phi < 0)
            phi += 2 * M_PI;
        return sf::Vector2u((int) (phi * 180 / M_PI), (int) (theta * 180 / M_PI));
    }
}

extern "C" {
    render::IPlugin *entryPoint()
    {
        return new render::AmbientLight_v();
    }
}
