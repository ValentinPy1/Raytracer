/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.primitive.v.hpp
*/

#pragma once

#include "../../PluginManager.hpp"
#include "../APluginPrimitive.hpp"
#include "SFML/System/Vector3.hpp"

namespace vanille {
    class SpherePrimitive_v : public virtual render::APluginPrimitive {
        public:
            SpherePrimitive_v();
            ~SpherePrimitive_v();
            render::Ray &processRay(render::Ray &ray, const render::Renderer &rdr);
            void selfInit(libconfig::Setting setting) override;
        private:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
            sf::Vector3f _origin;
            float _radius;
    };
}