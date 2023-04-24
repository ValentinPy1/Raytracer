/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.primitive.v.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "APlugin.hpp"
#include "SFML/System/Vector3.hpp"

// namespace render {
//     class IPrimitive {
//         public:
//             virtual void selfInit(libconfig::Setting &setting) = 0;
//     };
// }

namespace vanille {
    class SpherePrimitive_v : public render::IPrimitive, public render::APlugin {
        public:
            SpherePrimitive_v();
            ~SpherePrimitive_v();
            void selfInit(libconfig::Setting &setting) override;
        private:
            render::Ray &processRay(render::Ray &ray, const render::Renderer &rdr);
            sf::Vector3f _origin;
            float _radius;
    };
}
