/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ApplyIntersect.process.v.cpp
*/

#include <vector>
#include "IPlugin.hpp"
#include "Plugin.hpp"
#include "Ray.hpp"
#include "Renderer.hpp"

extern "C" {
    render::IPlugin *entryPoint()
    {
        return new render::Plugin(
            nullptr,
            [](render::Ray &ray, const render::Renderer &rdr)->render::Ray & {
                for (auto &e : rdr.getEntities()) {
                    e->getPrimitive()->solve(ray);
                }
                std::sort(ray.getIntersections().begin(), ray.getIntersections().end(), [](const render::Intersection &a, const render::Intersection &b) {
                    return a.getDistance() < b.getDistance();
                });
                if (ray.getIntersections().size() > 0) {
                    auto intersection = ray.getIntersections()[0];
                    int r, g, b;
                    sf::Vector3f point = intersection.getPoint();

                    intersection.getInterceptee()->getMaterial()->getColor(
                        r, g, b, (geo::vec3) {
                            point.x, point.y, point.z}
                    );
                    ray.setColor(sf::Color(r, g, b));
                }
                return ray;
            },
            nullptr,
            0,
            "applyIntersect"
        );
    }
}
