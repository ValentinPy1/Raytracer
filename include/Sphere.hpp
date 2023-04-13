/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Sphere.hpp
*/

#ifndef SPHERE_HPP
    #define SPHERE_HPP
    #include "Ray.hpp"
    #include "AObject.hpp"
    #include "Camera.hpp"

namespace render {
    class Sphere : public AObject {
        public:
            Sphere(const sf::Vector3f &origin, float radius, const sf::Color &color = sf::Color::White);
            ~Sphere() = default;
            bool solve(render::Ray &ray) override;
            sf::Vector3f getNormal(const sf::Vector3f &point) const override;
        private:
            sf::Vector3f _origin;
            float _radius;
    };
}

#endif // SPHERE_HPP
