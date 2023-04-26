/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Lighting.process.v.hpp
*/

#pragma once

#include "APlugin.hpp"
#include "SFML/System/Vector3.hpp"
#include "Ray.hpp"
#include "Plugin.hpp"

namespace vanille {
    class LightingProcess_v : public virtual render::Plugin {
        public:
            LightingProcess_v();
            ~LightingProcess_v();
            render::Ray &processRay(render::Ray &ray, const render::Renderer &rdr);
        private:
    };
}
