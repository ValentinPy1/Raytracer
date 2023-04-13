/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** AObject.cpp
*/

#include "AObject.hpp"

namespace render
{
    float AObject::getShininess() const { return _properties.at("shininess"); }
    float AObject::getReflectivity() const { return _properties.at("reflectivity"); }
    float AObject::getTransparency() const { return _properties.at("transparency"); }
    float AObject::getRefractiveIndex() const { return _properties.at("refractive_index"); }
    float AObject::getDiffuse() const { return _properties.at("diffuse"); }
    float AObject::getSpecular() const { return _properties.at("specular"); }
    float AObject::getAmbient() const { return _properties.at("ambient"); }
    sf::Color AObject::getColor() const { return _color; }

    void AObject::setShininess(float shininess) { _properties["shininess"] = shininess; }
    void AObject::setReflectivity(float reflectivity) { _properties["reflectivity"] = reflectivity; }
    void AObject::setTransparency(float transparency) { _properties["transparency"] = transparency; }
    void AObject::setRefractiveIndex(float refractiveIndex) { _properties["refractive_index"] = refractiveIndex; }
    void AObject::setDiffuse(float diffuse) { _properties["diffuse"] = diffuse; }
    void AObject::setSpecular(float specular) { _properties["specular"] = specular; }
    void AObject::setAmbient(float ambient) { _properties["ambient"] = ambient; }
}
