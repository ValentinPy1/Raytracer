/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Triangle.primitive.gl.hpp
*/

#ifndef C75316E8_0B95_433B_B883_3CC41C27E055
#define C75316E8_0B95_433B_B883_3CC41C27E055
#include <libconfig.h++>
#include <memory>
#include "IPrimitive.hpp"
#include "IOpglPrimitiveHelper.hpp"
#include "Ray.hpp"
#include "Entity.hpp"

namespace gpu {
    class TrianglePrimitive_gl : public render::IPrimitive {
        public:
            TrianglePrimitive_gl() = default;
            ~TrianglePrimitive_gl() = default;
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;
        private:
            std::shared_ptr<IOpGLPrimitiveHelper> _helper;
    };
}

#endif /* C75316E8_0B95_433B_B883_3CC41C27E055 */
