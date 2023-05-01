/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Entity.cpp
*/

#include "IPlugin.hpp"
#include "Entity.hpp"

namespace render
{
    std::shared_ptr<IPrimitive> Entity::getPrimitive() const
    {
        return _primitive;
    }

    void Entity::setPrimitive(std::shared_ptr<IPrimitive> primitive)
    {
        _primitive = primitive;
    }

    void Entity::setMaterial(std::shared_ptr<IMaterial>material)
    {
        _material = material;
    }

    std::shared_ptr<IMaterial>Entity::getMaterial() const
    {
        return _material;
    }

    std::shared_ptr<IPlugin> Entity::getPlugin(const std::string &name)
    {
        if (_plugins.find(name) != _plugins.end())
            return _plugins[name];
        return nullptr;
    }

    void Entity::addPlugin(std::shared_ptr<IPlugin> plugin)
    {
        _plugins[plugin->getName()] = plugin;
    }

} // namespace render
