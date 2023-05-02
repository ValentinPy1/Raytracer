/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientLight.v.cpp
*/

#include "AmbientLight.v.hpp"

namespace render {
    AmbientLight_v::AmbientLight_v() :
        Plugin(
            nullptr,
            nullptr,
            nullptr,
            1000,
            "AmbientLight"
        )
    {
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            applyAmbientLight(ray, rdr);
            return ray;
        };
    }

    void AmbientLight_v::applyAmbientLight(render::Ray &ray,
        __attribute__((unused)) const render::Renderer &rdr) {
        if (!ray.hasIntersections())
            return;
        ray.setColor(ray.blendMultiply(ray.getColor(), _color));
    }
}
