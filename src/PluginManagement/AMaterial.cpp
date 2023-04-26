/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AMaterial.cpp
*/

#include "IMaterial.hpp"

namespace render
{
    float AMaterial::getProperty(const std::string &name) const {
        return _properties.at(name);
    }
}
