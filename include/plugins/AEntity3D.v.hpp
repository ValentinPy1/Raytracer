/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Entity.v.hpp
*/

#ifndef ENTITY_V_HPP
    #define ENTITY_V_HPP
    #include <SFML/Graphics.hpp>
    #include "AEntity.hpp"

namespace render
{
    class Ray;
    class AEntity3D_v : public AEntity3D {
        public:
            virtual ~Entity3D_v() = default;
            virtual void selfInit(PluginManager &pm, libconfig::Settings &settings) = 0;
            virtual void solve(Ray &ray) = 0;
            virtual sf::Vector3f getNormal(const sf::Vector3f &point) const = 0;
            virtual sf::Color getColor(const sf::Vector3f &point) const = 0;
        private:

    };
} // namespace render

#endif // ENTITY_V_HPP
