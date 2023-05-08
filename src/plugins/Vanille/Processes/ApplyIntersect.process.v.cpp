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
                auto intersections = ray.getIntersections();
                std::sort(intersections.begin(), intersections.end(), [](const render::Intersection &a, const render::Intersection &b) {
                    return a.getDistance() < b.getDistance();
                });
                if (intersections.size() > 0 && intersections[0].getDistance() < 0.001) {
                    intersections.erase(intersections.begin());
                }
                if (intersections.size() > 0) {
                    ray.setColor(intersections[0].getColor());
                }
                return ray;
            },
            nullptr,
            0,
            "applyIntersect"
        );
    }
}
