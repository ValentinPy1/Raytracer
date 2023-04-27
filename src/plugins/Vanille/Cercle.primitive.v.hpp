/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Cercle.primitive.v.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "Plugin.hpp"
#include "SFML/System/Vector3.hpp"

namespace vanille {
    class CerclePrimitive_v : public render::IPrimitive, public render::Plugin {
        public:
            CerclePrimitive_v();
            ~CerclePrimitive_v();
            void selfInit(libconfig::Setting &setting) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
        private:
            render::Ray &processRay(render::Ray &ray, const render::Renderer &rdr);
            sf::Vector3f _origin;
            float _radius;
    };
}