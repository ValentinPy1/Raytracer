/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Entity.cpp
*/

#include "Entity.hpp"

namespace render
{
    std::vector<std::shared_ptr<IPrimitive>> Entity::getPrimitive() const
    {
        return _primitive;
    }

    void Entity::setPrimitive(std::vector<std::shared_ptr<IPrimitive>> primitive)
    {
        _primitive = primitive;
    }

    void Entity::setTexture(std::shared_ptr<ITexture> texture)
    {
        _texture = texture;
    }

    std::shared_ptr<ITexture> Entity::getTexture() const
    {
        return _texture;
    }

    std::shared_ptr<IPlugin> Entity::getPlugin(const std::string &name) const
    {
        return _plugins[name];
    }

    void Entity::setPlugin(std::shared_ptr<IPlugin> plugin)
    {
        _plugins[plugin->getName()] = plugin;
    }

} // namespace render
