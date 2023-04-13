/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP
    #define PLANE_HPP

    #include "AObject.hpp"

namespace render {
    class Plane : public AObject {
        public:
            Plane(const sf::Vector3f &positionVector, const sf::Vector3f &normal, const sf::Color &color = sf::Color::White);
            ~Plane() = default;
            bool solve(render::Ray &ray) override;
            sf::Vector3f getNormal(const sf::Vector3f &point) const override;
        private:

            sf::Vector3f _origin;
            sf::Vector3f _normal;
            sf::Color _color;
    };
}

#endif // PLANE_HPP
