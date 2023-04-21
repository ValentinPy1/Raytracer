/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Entity.cpp
*/

#include "AEntity.hpp"

namespace render {
    Entity::Entity() {
    }

    void Entity::setPrimitive(IPrimitive *primitive) {
        _primitive = std::shared_ptr<IPrimitive>(primitive);
    }

    void Entity::setPlugin(std::shared_ptr<IPlugin> plugin) {
        _plugins.push_back(plugin);
    }
}
