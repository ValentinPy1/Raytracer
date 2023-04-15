/*
** EPITECH PROJECT, 2022
** ray
** File description:
** FastRender.cpp
*/

#include "SFML/Graphics.hpp"
#include "Ray.hpp"
#include "PluginManager.hpp"

extern "C" {
    Plugin *entryPoint()
    {
        return new Plugin(
            nullptr,
            [](render::Ray &ray, const render::Renderer &rdr) {
                ray = ray.findIntersections(rdr);

                if (ray.getIntersections().size() == 0) {
                    ray.setColor(sf::Color {33, 33, 33});
                    return;
                }
                sf::Vector3f intersectionPoint = ray.getIntersections()[0]
                    .getInterceptPoint();
                float colorIntensityFromNormal =
                    (90.0 - ray.getDirection() * ray.getIntersections()[0]
                        .getInterceptee().getNormal(intersectionPoint)) / 90.0;
                sf::Color color = sf::Color {
                    200, 200, 200
                }
                ray.setColor(sf::Color(
                    color * colorIntensityFromNormal,
                    color * colorIntensityFromNormal,
                    color * colorIntensityFromNormal));
            },
            nullptr,
            0
        );
    }
}
