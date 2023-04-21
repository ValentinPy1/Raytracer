/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Lighting.process.v.cpp
*/

#include "Lighting.process.v.hpp"

vanille::LightingProcess_v::LightingProcess_v() {
    _processRay = &vanille::LightingProcess_v::processRay;
}

vanille::LightingProcess_v::~LightingProcess_v() {
}

render::Ray &vanille::LightingProcess_v::processRay(render::Ray &ray, const render::Renderer &rdr) {
    if (ray.getIntersections().size() == 0)
        return ray;
    ray.setColor(blendMultiply(rdr.getAmbientLight()));
    for (auto light : rdr.getLights()) {
        ray.setColor(light.sample(ray, rdr));
    }
    return ray;
}
