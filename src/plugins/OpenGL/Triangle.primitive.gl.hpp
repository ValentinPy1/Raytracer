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
    /**
     * @brief This class is used to create a triangle primitive for GPU mode.
     * It is not compatible with CPU mode (vanilla). See render::IPrimitive for more details.
     *
     */
    class TrianglePrimitive_gl : public render::IPrimitive {
        public:
            TrianglePrimitive_gl() = default;
            ~TrianglePrimitive_gl() = default;
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;

            /**
             * @brief
             * @warning do no use as this is a functionaliy made for vanilla.
             * The GPU mode moved this functionnality in a shader.
             *
             * @param point
             * @return sf::Vector3f
             */
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;

            /**
             * @brief
             * @warning do no use as this is a functionaliy made for vanilla.
             * The GPU mode moved this functionnality in a shader.
             *
             * @param ray
             */
            void solve(render::Ray &ray) override;
        private:
            std::shared_ptr<IOpGLPrimitiveHelper> _helper;
    };
}

#endif /* C75316E8_0B95_433B_B883_3CC41C27E055 */
