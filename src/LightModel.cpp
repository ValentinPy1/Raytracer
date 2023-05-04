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
                const sf::Vector3f lightDir,
                const sf::Vector3f &normal,
                const sf::Vector3f &viewDirection,
                float lightDistance,
                const float shininess,
                const float intensity
            )
        {
            float diffuse = std::max(0.0f, normal * Ray::normalize(lightDir));
            if (diffuse > 255)
                diffuse = 255;
            sf::Vector3f halfwayDir = Ray::normalize(Ray::normalize(lightDir) + viewDirection);
            float specular = std::pow(std::max(0.0f, normal * halfwayDir), shininess);
            float attenuation = 1.0f / (1.0f + 0.01f * lightDistance * lightDistance);

            float r = static_cast<int>((diffuse + specular) * attenuation * lightColor.r) * intensity;
            float g = static_cast<int>((diffuse + specular) * attenuation * lightColor.g) * intensity;
            float b = static_cast<int>((diffuse + specular) * attenuation * lightColor.b) * intensity;
            if (r > 255)
                r = 255;
            if (g > 255)
                g = 255;
            if (b > 255)
                b = 255;
            sf::Color out = {
                static_cast<sf::Uint8>(r),
                static_cast<sf::Uint8>(g),
                static_cast<sf::Uint8>(b)
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
        static const std::map<std::string, LightModel::lightModelApplier_t> models = {
           {"BlinnPhong", &LightModel::applyBlinnPhong}
        };
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
