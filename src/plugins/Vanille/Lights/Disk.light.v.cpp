/*
** EPITECH PROJECT, 2022
** ray
** File description:
** DiskLight.v.cpp
*/

#include <cmath>
#include "Disk.light.v.hpp"
#include "operations.hpp"

namespace vanille {
        bool DiskLight::pointIsShadowed(const render::Renderer &rdr, const sf::Vector3f &intersection, const sf::Vector3f &lightDirection)
        {
            float distance = render::Ray::getNorm(lightDirection);
            render::Ray shadowRay(intersection, render::Ray::normalize(lightDirection));

            for (auto &e : rdr.getEntities()) {
                e->getPrimitive()->solve(shadowRay);
            }
            auto intersections = shadowRay.getIntersections();
            std::sort(intersections.begin(), intersections.end(), [](const render::Intersection &a, const render::Intersection &b) {
                return a.getDistance() < b.getDistance();
            });
            return (intersections.size() > 0 && intersections[0].getDistance() < distance && intersections[0].getDistance() > 0.001);
        }


        sf::Color DiskLight::sampleHardLight(render::Ray &ray,
        const render::Renderer &renderer, const sf::Vector3f &lightpos)
        {
            auto interObj = ray.getIntersections()[0];
            sf::Vector3f lightDirection;
            sf::Vector3f intersection = interObj.getPoint() + interObj.getNormal() * 0.1f;
            sf::Vector3f normal = render::Ray::normalize(interObj.getNormal());
            sf::Color color;
            lightDirection = lightpos - intersection;
            lightDirection = -lightDirection;



            if (pointIsShadowed(renderer, intersection, lightDirection)) {
                return sf::Color::Black;
            }

            color = _lightModel.apply(
                _applyMode,
                _color,
                lightDirection,
                normal,
                ray.getDirection(),
                render::Ray::getNorm(lightDirection),
                ray.getIntersections()[0].getInterceptee()->getMaterial()->getProperty("shininess"),
                _intensity
            );
            return color;
        }

        sf::Color DiskLight::averageSamples(std::vector<sf::Color> &samples)
        {
            sf::Vector3f average = {0, 0, 0};

            for (auto &sample : samples) {
                average.x += sample.r;
                average.y += sample.g;
                average.z += sample.b;
            }
            average.x /= samples.size();
            average.y /= samples.size();
            average.z /= samples.size();
            return {
                static_cast<sf::Uint8>(average.x),
                static_cast<sf::Uint8>(average.y),
                static_cast<sf::Uint8>(average.z)
            };
        }

    void DiskLight::sample(render::Ray &ray, const render::Renderer &rdr)
    {
        if (!ray.hasIntersections()) {
            return;
        }

        sf::Vector3f randomSample;
        std::vector<sf::Color> samples;
        sf::Vector3f position = _position;

        for (int i = 0; i < _nSamples * _radius; ++i) {
            randomSample = {static_cast<float>(fmod(rand(), _radius)), static_cast<float>(fmod(rand(), _radius)), static_cast<float>(fmod(rand(), _radius))};
            sf::Vector3f tmp = position + randomSample;
            samples.push_back(sampleHardLight(ray, rdr, tmp));
        }
        auto average = averageSamples(samples);
        // ray.setColor(ray.blendLerp(average, 0.5f));
        // ray.setColor(ray.blendMultiply(average));
        ray.setColor(ray.blendColor(average));
    }

    void DiskLight::selfInit(const libconfig::Setting &setting)
    {
        const libconfig::Setting &colorSetting = setting.lookup("color");
        const libconfig::Setting &positionSetting = setting.lookup("position");
        int r, g, b;
        float x, y, z;

        colorSetting.lookupValue("r", r);
        colorSetting.lookupValue("g", g);
        colorSetting.lookupValue("b", b);
        positionSetting.lookupValue("x", x);
        positionSetting.lookupValue("y", y);
        positionSetting.lookupValue("z", z);

        _position = sf::Vector3f(x, y, z);
        _color = sf::Color(r, g, b);
        setting.lookupValue("applyMode", _applyMode);
        setting.lookupValue("shadowSamples", _nSamples);
        setting.lookupValue("radius", _radius);
        setting.lookupValue("intensity", _intensity);
    }
}

extern "C" {
    vanille::DiskLight *entryPoint()
    {
        return new vanille::DiskLight();
    }
}
