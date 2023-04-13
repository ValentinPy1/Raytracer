/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Light.cpp
*/

#include <cmath>
#include "Render.hpp"
#include "Ray.hpp"
#include "Light.hpp"
#include "operations.hpp"

namespace render {

        Light::Light(const sf::Vector3f &position, const sf::Color &color,
            const float &intensity, const float &radius, int nSamples)
            : _position(position), _color(color), _intensity(intensity), _radius(radius), _nSamples(nSamples)
        {
        }

        sf::Vector3f Light::getPosition() const
        {
            return _position;
        }

        float Light::getDistanceTo(const sf::Vector3f &point)
        {
            return sqrt(pow(_position.x - point.x, 2) + pow(_position.y - point.y, 2) + pow(_position.z - point.z, 2));
        }

        sf::Color Light::getColor() const
        {
            return _color;
        }

        float Light::getIntensity() const
        {
            return _intensity;
        }


        sf::Color Light::getBlinnPhongColor(
            const sf::Vector3f &lightDirection,
            const sf::Vector3f &normal,
            const sf::Vector3f &viewDirection,
            float shininess)
        {
            sf::Color lightColor = _color;
            sf::Vector3f buffer = {0, 0, 0};
            sf::Vector3f halfVector = Ray::normalize(lightDirection + viewDirection);
            float lightDistance = std::sqrt(lightDirection.x * lightDirection.x + lightDirection.y * lightDirection.y + lightDirection.z * lightDirection.z);

            float diffuse = std::min(std::max(0.0f, normal * lightDirection), 255.0f);
            buffer = diffuse * (sf::Vector3f) {
                static_cast<float>(lightColor.r),
                static_cast<float>(lightColor.g),
                static_cast<float>(lightColor.b)
            } / lightDistance;
            float specular = std::pow(std::min(std::max(0.0f, normal * halfVector), 255.0f), shininess);
            buffer += specular * (sf::Vector3f) {
                static_cast<float>(lightColor.r),
                static_cast<float>(lightColor.g),
                static_cast<float>(lightColor.b)
            } / lightDistance;
            if (buffer.x > 255)
                buffer.x = 255;
            if (buffer.y > 255)
                buffer.y = 255;
            if (buffer.z > 255)
                buffer.z = 255;
            buffer = buffer * _intensity;
            sf::Color out = {
                static_cast<sf::Uint8>(buffer.x),
                static_cast<sf::Uint8>(buffer.y),
                static_cast<sf::Uint8>(buffer.z)
            };
            return out;
        }

        sf::Color Light::sampleHardLight(Ray &ray, const Renderer &renderer)
        {
            sf::Vector3f lightDirection;
            sf::Vector3f intersection = ray.getIntersections()[0].getPoint();
            sf::Vector3f normal = ray.getIntersections()[0].getNormal();
            sf::Color color;

            if (ray.isShadowed(renderer, _position, intersection)) {
                return ray.getColor();
            }
            lightDirection = getPosition() - intersection;

            color = getBlinnPhongColor(
                lightDirection,
                normal,
                ray.getDirection(),
                ray.getIntersections()[0].getShininess()
            );
            return ray.blendAdd(color);
        }

        sf::Color Light::averageSamples(std::vector<sf::Color> &samples)
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

        sf::Color Light::sampleSoftLight(Ray &ray, const Renderer &renderer)
        {
            sf::Vector3f randomSample;
            std::vector<sf::Color> samples;
            auto backup = _position;

            for (int i = 0; i < _nSamples; ++i) {
                randomSample = {static_cast<float>(fmod(rand(), _radius)), static_cast<float>(fmod(rand(), _radius)), static_cast<float>(fmod(rand(), _radius))};
                _position = backup + randomSample;
                samples.push_back(sampleHardLight(ray, renderer));
            }
            _position = backup;
            return ray.blendAdd(averageSamples(samples));
        }

        sf::Color Light::sample(Ray &ray, const Renderer &renderer)
        {
            if (_radius == 0)
                return sampleHardLight(ray, renderer);
            return sampleSoftLight(ray, renderer);
        }
}
