/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** AObject.hpp
*/

#ifndef AOBJECT_HPP
    #define AOBJECT_HPP
    #include <map>
    #include <string>
    #include "IObject.hpp"
namespace render {
    class AObject : public IObject {
        public:
            AObject() = default;
            ~AObject() = default;

            float getShininess() const override;
            float getReflectivity() const override;
            float getTransparency() const override;
            float getRefractiveIndex() const override;
            float getDiffuse() const override;
            float getSpecular() const override;
            float getAmbient() const override;
            sf::Color getColor() const override;

            void setShininess(float shininess) override;
            void setReflectivity(float reflectivity) override;
            void setTransparency(float transparency) override;
            void setRefractiveIndex(float refractiveIndex) override;
            void setDiffuse(float diffuse) override;
            void setSpecular(float specular) override;
            void setAmbient(float ambient) override;

        protected:
            sf::Color _color;
            std::map<std::string, float> _properties {
                {"shininess", 0},
                {"reflectivity", 0.5},
                {"transparency", 0},
                {"refractive_index", 1},
                {"diffuse", 1},
                {"specular", 1},
                {"ambient", 1},
            };
    };
}

#endif // AOBJECT_HPP
