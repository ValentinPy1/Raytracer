/*
** EPITECH PROJECT, 2022
** ray
** File description:
** applyPointLights.process.v.cpp
*/

#include "Renderer.hpp"
#include "Ray.hpp"
#include "IPlugin.hpp"

extern "C" {
    render::IPlugin *entryPoint()
    {
        return new render::Plugin(
            nullptr,
            [](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
                if (!ray.hasIntersections())
                    return ray;
                for (auto &light : rdr.getLights()) {
                    light->sample(ray, rdr);
                }
                return ray;
            },
            nullptr,
            1000,
            "applyPointLights"
        );
    }
}
