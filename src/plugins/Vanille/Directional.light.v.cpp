/*
** EPITECH PROJECT, 2022
** ray
** File description:
** DirectionalLight.v.cpp
*/

#include "LightModel.hpp"
#include "Directional.light.v.hpp"

namespace vanille {
    void DirectionalLight_v::selfInit(const libconfig::Setting &setting)
    {
        const libconfig::Setting &colorSetting = setting.lookup("color");
        const libconfig::Setting &directionSetting = setting.lookup("direction");
        int r, g, b;
        int x, y, z;

        colorSetting.lookupValue("r", r);
        colorSetting.lookupValue("g", g);
        colorSetting.lookupValue("b", b);
        directionSetting.lookupValue("x", x);
        directionSetting.lookupValue("y", y);
        directionSetting.lookupValue("z", z);
        _color = sf::Color(r, g, b);
        _direction = sf::Vector3f(x, y, z);

        setting.lookupValue("applyMode", _applyMode);
        setting.lookupValue("shadowSamples", _shadowSamples);
    }

    void DirectionalLight_v::sample(render::Ray &ray, const render::Renderer &rdr)
    {
        if (!ray.hasIntersections())
            return;
        render::Intersection intersect = ray.getIntersections().front();
        render::Entity *interceptee = intersect.getInterceptee();
        sf::Vector3f normal = intersect.getNormal();
        sf::Vector3f viewDirection = ray.getDirection();

        sf::Color color = render::LightModel::apply(
            "BlinnPhong",
            _color,
            -_direction,
            normal,
            viewDirection,
            0,
            interceptee->getTexture()->getProperty("shininess"),
            1
        );

        castShadow(color, intersect, rdr);

        ray.blendMultiply(color);
    }

    void DirectionalLight_v::castShadow(sf::Color &color, render::Intersection &intersect, const render::Renderer &rdr)
    {
        sf::Vector3f origin = intersect.getPoint();
        std::vector<render::Ray> shadowRays;

        for (int i = 0; i < _shadowSamples; i++) {
            sf::Vector3f direction = _direction;
            direction.x += (rand() % 100) / 100.0f;
            direction.y += (rand() % 100) / 100.0f;
            direction.z += (rand() % 100) / 100.0f;
            shadowRays.emplace_back(origin, direction);
        }

        int hitNbr = 0;
        for (auto &ray : shadowRays) {
            for (auto &entity : rdr.getEntities()) {
                if (entity.get() == intersect.getInterceptee())
                    continue;
                entity->getPrimitive()->solve(ray);
                if (ray.hasIntersections()) {
                    hitNbr++;
                    break;
                }
            }
        }

        sf::Color finalColor = sf::Color(
            color.r * hitNbr / _shadowSamples,
            color.g * hitNbr / _shadowSamples,
            color.b * hitNbr / _shadowSamples
        );
        color = finalColor;
    }
}
