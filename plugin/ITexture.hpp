/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ITexture.hpp
*/

#pragma once

#include <libconfig.h++>
#include "PluginManager.hpp"

namespace render {
    class ITexture : public virtual IPlugin {
        public:
            virtual void selfInit(libconfig::Setting &setting) = 0;
            virtual void *getMaterialInfo(const std::string &propertyName) = 0;
    };
}
