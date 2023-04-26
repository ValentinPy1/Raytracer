/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ATexture.cpp
*/

#include "ITexture.hpp"

namespace render
{
    float ATexture::getProperty(const std::string &name) const {
        return _properties.at(name);
    }
}
