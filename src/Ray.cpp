/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Ray.cpp
*/

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Ray.hpp"
#include "operations.hpp"

namespace render {
    Ray::Ray(const sf::Vector3f &origin, const sf::Vector3f &direction, int reflectionDepth)
    : _reflectionDepth(reflectionDepth), _origin(origin), _direction(direction)
    {
        _color = sf::Color::White;
    }

    sf::Vector3f Ray::rotateVector(const sf::Vector3f& vector, const sf::Vector3f& rotation) {
        float angleX = rotation.x * M_PI / 180.0;
        float angleY = rotation.y * M_PI / 180.0;
        float angleZ = rotation.z * M_PI / 180.0;
        float sinX = std::sin(angleX);
        float cosX = std::cos(angleX);
        float sinY = std::sin(angleY);
        float cosY = std::cos(angleY);
        float sinZ = std::sin(angleZ);
        float cosZ = std::cos(angleZ);

        return sf::Vector3f(
            vector.x * (cosY * cosZ) + vector.y * (cosX * sinZ + sinX * sinY * cosZ) + vector.z * (sinX * sinZ - cosX * sinY * cosZ),
            vector.x * (-cosY * sinZ) + vector.y * (cosX * cosZ - sinX * sinY * sinZ) + vector.z * (sinX * cosZ + cosX * sinY * sinZ),
            vector.x * sinY + vector.y * (-sinX * cosY) + vector.z * (cosX * cosY)
        );
    }

    float Ray::getNorm(const sf::Vector3f &vector)
    {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    }

    sf::Vector3f Ray::normalize(const sf::Vector3f &vector)
    {
        float length = std::sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);

        return sf::Vector3f(vector.x / length, vector.y / length, vector.z / length);
    }

    // Ray &Ray::findIntersections(const render::Renderer &renderer)
    // {
    //     for (auto &object : renderer.getObjects()) {
    //         object->solve(*this); // ? TODO optimisation n ^ 2 ?
    //     }
    //     std::sort(_intersections.begin(), _intersections.end(), [](const Intersection &a, const Intersection &b) {
    //         return a.getDistance() < b.getDistance();
    //     });
    //     if (_intersections.size() > 0) {
    //         _color = _intersections[0].getColor();
    //     }
    //     return *this;
    // }

    std::map<std::string, int> Ray::getAllRecursionParameters() const
    {
        return _recursionParameters;
    }

    sf::Color Ray::blendColor(const sf::Color &color) const
    {
        int r = color.r + _color.r;
        int g = color.g + _color.g;
        int b = color.b + _color.b;
        sf::Color final = {
            static_cast<sf::Uint8>((r > 255) ? 255 : r),
            static_cast<sf::Uint8>((g > 255) ? 255 : g),
            static_cast<sf::Uint8>((b > 255) ? 255 : b)
        };
        return final;
    }

    sf::Color Ray::blendMultiply(const sf::Color &color) const
    {
        sf::Color blendedColor;
        blendedColor.r = static_cast<sf::Uint8>((_color.r / 255.0f) * (color.r / 255.0f) * 255.0f);
        blendedColor.g = static_cast<sf::Uint8>((_color.g / 255.0f) * (color.g / 255.0f) * 255.0f);
        blendedColor.b = static_cast<sf::Uint8>((_color.b / 255.0f) * (color.b / 255.0f) * 255.0f);

        return blendedColor;
    }

    sf::Color Ray::blendMultiply(const sf::Color &color1, const sf::Color &color2)
    {
        sf::Color blendedColor;
        blendedColor.r = static_cast<sf::Uint8>((color1.r / 255.0f) * (color2.r / 255.0f) * 255.0f);
        blendedColor.g = static_cast<sf::Uint8>((color1.g / 255.0f) * (color2.g / 255.0f) * 255.0f);
        blendedColor.b = static_cast<sf::Uint8>((color1.b / 255.0f) * (color2.b / 255.0f) * 255.0f);

        return blendedColor;
    }

    bool Ray::hasIntersections() const
    {
        return _intersections.size() > 0;
    }

    std::vector<Intersection> &Ray::getIntersections()
    {
        return _intersections;
    }

    const sf::Vector3f &Ray::getOrigin() const
    {
        return _origin;
    }

    const sf::Vector3f &Ray::getDirection() const
    {
        return _direction;
    }

    void Ray::addIntersection(const Intersection &intersection)
    {
        _intersections.push_back(intersection);
    }

    sf::Color Ray::getColor() const
    {
        return _color;
    }

    void Ray::setColor(const sf::Color &color)
    {
        _color = color;
    }

    sf::Color Ray::blendAdd(const sf::Color &color) const
    {
        int r = color.r + _color.r;
        int g = color.g + _color.g;
        int b = color.b + _color.b;
        sf::Color final = {
            static_cast<sf::Uint8>((r > 255) ? 255 : r),
            static_cast<sf::Uint8>((g > 255) ? 255 : g),
            static_cast<sf::Uint8>((b > 255) ? 255 : b)
        };
        return final;
    }

    sf::Color Ray::blendLerp(const sf::Color &color, float t) const {
        sf::Color final = {
            static_cast<sf::Uint8>((_color.r * (1 - t)) + (color.r * t)),
            static_cast<sf::Uint8>((_color.g * (1 - t)) + (color.g * t)),
            static_cast<sf::Uint8>((_color.b * (1 - t)) + (color.b * t))
        };
        return final;
    }

    // bool Ray::isShadowed(const Renderer &rdr, sf::Vector3f lightPos, sf::Vector3f intersection)
    // {
    //     sf::Vector3f lightDirection = lightPos - intersection;
    //     float lightDistance = getNorm(lightDirection);
    //     Ray shadowRay(intersection, lightDirection);

    //     shadowRay.findIntersections(rdr);
    //     for (auto i : shadowRay.getIntersections()) {
    //         if (i.getDistance() > 0 &&  getNorm(intersection - i.getPoint()) < lightDistance && getNorm(intersection - i.getPoint()) > 0.01f) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // // ? optimize with  deferred shading or forward+ rendering.
    // Ray &Ray::applyLighting(const Renderer &renderer)
    // {
    //     if (_intersections.size() == 0)
    //         return *this;
    //     setColor(blendMultiply(renderer.getAmbientLight()));
    //     for (auto light : renderer.getLights()) {
    //         _color = light.sample(*this, renderer);
    //     }
    //     return *this;
    // }

    // sf::Color Ray::getReflectionColor(const Renderer &renderer)
    // {
    //     if (_intersections.size() == 0)
    //         return sf::Color::Black;
    //     sf::Vector3f normal = _intersections[0].getNormal();
    //     sf::Vector3f reflection = _direction - 2 * normal * (normal.x * _direction.x + normal.y * _direction.y + normal.z * _direction.z);
    //     Ray reflectionRay(_intersections[0].getPoint(), -reflection, _reflectionDepth - 1);
    //     reflectionRay.findIntersections(renderer);
    //     if (reflectionRay._intersections.size() == 0)
    //         return sf::Color::Black;
    //     if (Ray::getNorm(reflectionRay._intersections[0].getPoint() - _intersections[0].getPoint()) < 0.01f)
    //         reflectionRay._intersections.erase(reflectionRay._intersections.begin());
    //     if (reflectionRay._intersections.size() == 0) {
    //         reflectionRay.setColor(sf::Color::Black);
    //         return sf::Color::Black;
    //     }
    //     reflectionRay.applyLighting(renderer);
    //     if (reflectionRay._reflectionDepth > 0)
    //         reflectionRay.blendAdd(reflectionRay.getReflectionColor(renderer));
    //     auto reflectivity = _intersections[0].getInterceptee()->getReflectivity();
    //     auto tmp = reflectionRay.getColor();
    //     tmp = (sf::Color) {
    //         static_cast<sf::Uint8>(tmp.r * reflectivity),
    //         static_cast<sf::Uint8>(tmp.g * reflectivity),
    //         static_cast<sf::Uint8>(tmp.b * reflectivity)
    //     };
    //     return tmp;
    //     // return reflectionRay.getColor();
    // }

    // sf::Color Ray::cast(const Renderer &renderer)
    // {
    //     // findIntersections(renderer);
    //     // if (getIntersections().size() == 0) {
    //     //     setColor(sf::Color {33, 33, 33});
    //     //     return getColor();
    //     // }
    //     // return getColor();

    //     // real pipeline to convert to plugins
    //     // plugin geometry::intersection
    //     findIntersections(renderer);

    //     // plugin lights
    //     if (_intersections.size() == 0)
    //         return sf::Color::Black;
    //     applyLighting(renderer);

    //     //plugin reflection
    //     if (_intersections.size() > 0 && _reflectionDepth > 0) {
    //         return blendAdd(getReflectionColor(renderer));
    //     }

    //     // end of process loop
    //     return getColor();
    // }

    void Ray::setRecursionParameter(const std::string &name, int initialValue)
    {
        _recursionParameters[name] = initialValue;
    }

    void Ray::incrementRecursionParameter(const std::string &name)
    {
        if (_recursionParameters.count(name) == 0) {
            std::cerr << render::yellow << "[WARNING] :" << render::no_color <<  "Trying to increment non-existing recursion parameter" << std::endl;
            return;
        }
        _recursionParameters[name]++;
    }

    void Ray::decrementRecursionParameter(const std::string &name)
    {
        if (_recursionParameters.count(name) == 0) {
            std::cerr << render::yellow << "[WARNING] :" << render::no_color <<  "Trying to decrement non-existing recursion parameter" << std::endl;
            return;
        }
        _recursionParameters[name]--;
    }

    int Ray::getRecursionParameter(const std::string &name) const
    {
        if (_recursionParameters.count(name) == 0) {
            // std::cerr << render::yellow << "[WARNING]: " << render::no_color <<  "Trying to get non-existing recursion parameter (" << render::yellow << name << render::no_color << ")" << std::endl;
            return 0;
        }
        return _recursionParameters.at(name);
    }
}
