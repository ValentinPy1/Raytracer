/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Ray.hpp
*/

#ifndef C31DBD06_DD57_4FBA_8FEB_0C65FC057861
    #define C31DBD06_DD57_4FBA_8FEB_0C65FC057861
    #include <SFML/Graphics.hpp>
    #include "AObject.hpp"
    #include "Render.hpp"
    #include "Light.hpp"

namespace render {
    class Ray;
    class AObject;
    class Camera;
    class Intersection {
        public:
            Intersection(AObject *interceptee, Ray &ray, float distance);
            Intersection(const Intersection &other);
            ~Intersection() = default;

            Intersection &operator=(const Intersection &other);

            float getDistance() const;
            bool isFacingCamera(const Camera &) const;
            sf::Vector3f getNormal() const;
            sf::Color getColor() const;
            IObject *getInterceptee() const;
            sf::Vector3f getPoint() const;
            sf::Vector3f getPointRelativeToCamera(const Camera &camera) const;
            float getShininess() const;
        private:
            float _distance;
            sf::Vector3f _point;
            sf::Vector3f _normal;
            sf::Color _color;
            Ray &_ray;
            IObject *_interceptee;

            float _shininess = 2; // TODO get from objects
    };

    /**
     * @brief Base class for all objects
     *
     */
    class Ray {
        public:
            Ray(const sf::Vector3f &origin, const sf::Vector3f &direction, int reflectionDepth = 3);
            /**
             * @brief Rotate a vector by a rotation vector in degrees
             *
             * @param vector
             * @param rotation
             * @return sf::Vector3f
             */
            static sf::Vector3f normalize(const sf::Vector3f &vector);
            static float getNorm(const sf::Vector3f &vector);
            static sf::Vector3f rotateVector(const sf::Vector3f &vector, const sf::Vector3f &rotation);

            sf::Color cast(const Renderer & renderer);
            Ray &findIntersections(const render::Renderer &renderer);
            Ray &applyLighting(const render::Renderer &renderer);
            Ray &getReflectionColor(const Renderer &renderer);

            bool hasIntersections() const;
            const std::vector<Intersection> &getIntersections() const;
            const sf::Vector3f &getOrigin() const;
            const sf::Vector3f &getDirection() const;
            void addIntersection(const Intersection &intersection);

            sf::Color getColor() const;
            void setColor(const sf::Color &color);

            bool isShadowed(const Renderer &rdr, sf::Vector3f lightPos, sf::Vector3f intersection);

            sf::Color blendMultiply(const sf::Color &color1, const sf::Color &color2);
            sf::Color blendMultiply(const sf::Color &color) const;
            sf::Color blendAdd(const sf::Color &color) const;
            sf::Color blendColor(const sf::Color &color) const;
        private:
            int _reflectionDepth;
            sf::Vector3f _origin;
            sf::Vector3f _direction;
            std::vector<Intersection> _intersections;
            sf::Color _color = sf::Color::Black;
    };

}

#endif /* C31DBD06_DD57_4FBA_8FEB_0C65FC057861 */
