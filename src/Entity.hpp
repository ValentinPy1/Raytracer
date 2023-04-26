/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Entity.cpp
*/

#pragma once

#include "ITexture.hpp"
#include "IPrimitive.hpp"
#include "PluginManager.hpp"

namespace render {
    class Entity {
        public:
            Entity() = default;
            std::shared_ptr<IPrimitive> getPrimitive() const;
            std::shared_ptr<ITexture> getTexture() const;

            void setPrimitive(std::shared_ptr<IPrimitive> primitive);
            void setTexture(std::shared_ptr<ITexture> texture);

            std::shared_ptr<IPlugin> getPlugin(const std::string &name);
            void addPlugin(std::shared_ptr<IPlugin> plugin);

        private:
            std::shared_ptr<IPrimitive> _primitive;
            std::shared_ptr<ITexture> _texture;
            std::map<std::string, std::shared_ptr<IPlugin>> _plugins;
    };
}
