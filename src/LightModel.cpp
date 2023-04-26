/*
** EPITECH PROJECT, 2022
** ray
** File description:
** BlinnPhongModel.cpp
*/

#include "LightModel.hpp"
#include "operations.hpp"
#include "Ray.hpp"
#include <cmath>

namespace render {
sf::Color LightModel::applyBlinnPhong(
                const sf::Color &lightColor,
                const sf::Vector3f lightDirection,
                const sf::Vector3f &normal,
                const sf::Vector3f &viewDirection,
                const float lightDistance,
                const float shininess,
                const float intensity
            )
        {
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
            buffer = buffer * intensity;
            sf::Color out = {
                static_cast<sf::Uint8>(buffer.x),
                static_cast<sf::Uint8>(buffer.y),
                static_cast<sf::Uint8>(buffer.z)
            };
            return out;
        }

    sf::Color LightModel::apply(
        const std::string &S,
        const sf::Color &lightColor,
        const sf::Vector3f lightDirection,
        const sf::Vector3f &surfaceNormal,
        const sf::Vector3f &viewDirection,
        const float lightDistance,
        const float shininess,
        const float intensity
    )
    {
        return models.at(S)(
            lightColor,
            lightDirection,
            surfaceNormal,
            viewDirection,
            lightDistance,
            shininess,
            intensity
        );
    }
}
