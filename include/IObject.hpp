/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** IObject.hpp
*/

#ifndef IOBJECT_HPP
    #define IOBJECT_HPP
    #include "IObject.hpp"
    #include "Ray.hpp"

namespace render
{
    /**
     * @brief Base class for all objects
     *
     */
    class Ray;
    class Camera;
    class IObject {
        public:
            virtual ~IObject() = default;
            virtual bool solve(render::Ray &ray) = 0;
            virtual sf::Vector3f getNormal(const sf::Vector3f &point) const = 0;

            virtual sf::Color getColor() const = 0;
            virtual float getShininess() const = 0;
            virtual float getReflectivity() const = 0;
            virtual float getTransparency() const = 0;
            virtual float getRefractiveIndex() const = 0;
            virtual float getDiffuse() const = 0;
            virtual float getSpecular() const = 0;
            virtual float getAmbient() const = 0;
            virtual void setShininess(float shininess) = 0;
            virtual void setReflectivity(float reflectivity) = 0;
            virtual void setTransparency(float transparency) = 0;
            virtual void setRefractiveIndex(float refractiveIndex) = 0;
            virtual void setDiffuse(float diffuse) = 0;
            virtual void setSpecular(float specular) = 0;
            virtual void setAmbient(float ambient) = 0;
    };

} // namespace geo




#endif // IOBJECT_HPP
