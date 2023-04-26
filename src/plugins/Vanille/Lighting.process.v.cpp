/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Lighting.process.v.cpp
*/

#include "Lighting.process.v.hpp"

namespace vanille {
    LightingProcess_v::LightingProcess_v() {
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
                return processRay(ray, rdr);
        };
    }

    LightingProcess_v::~LightingProcess_v() {
    }

    render::Ray &LightingProcess_v::processRay(render::Ray &ray, const render::Renderer &rdr) {
        if (ray.getIntersections().size() == 0)
            return ray;
        ray.setColor(ray.blendMultiply(rdr.getAmbientLight()));
        for (auto light : rdr.getLights()) {
            ray.setColor(light.sample(ray, rdr));
        }
        return ray;
    }
}

