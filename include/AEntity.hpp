/*
** EPITECH PROJECT, 2022
** ray
** File description:
** IEntity.hpp
*/

#pragma once

#include <map>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include "ConfigLoader.hpp"
#include "PluginManager.hpp"

namespace render {
    class Entity {
        public:
            void setPlugin(std::shared_ptr<IPlugin> plugin);

            template <typename P>
            std::shared_ptr<P> getPlugin(const std::string &name) {
                for (auto &plugin : _plugins) {
                    if (plugin->getName() == name) {
                        return std::dynamic_pointer_cast<P>(plugin);
                    }
                }
                return nullptr;
            }
        private:
            std::vector<std::shared_ptr<IPlugin>> _plugins;
    };
} // namespace render
