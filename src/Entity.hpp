/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Entity.cpp
*/

#pragma once

#include "IMaterial.hpp"
#include "IPrimitive.hpp"
#include "PluginManager.hpp"

namespace render {
    class Entity {
        public:
            Entity() = default;
            std::shared_ptr<IPrimitive> getPrimitive() const;
            std::shared_ptr<IMaterial> getMaterial() const;

            void setPrimitive(std::shared_ptr<IPrimitive> primitive);
            void setMaterial(std::shared_ptr<IMaterial> material);

            std::shared_ptr<IPlugin> getPlugin(const std::string &name);
            void addPlugin(std::shared_ptr<IPlugin> plugin);

        private:
            std::shared_ptr<IPrimitive> _primitive = nullptr;
            std::shared_ptr<IMaterial> _material = nullptr;
            std::map<std::string, std::shared_ptr<IPlugin>> _plugins;
    };
}
