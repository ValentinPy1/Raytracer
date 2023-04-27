/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Renderer.cpp
*/

#include "Renderer.hpp"

namespace render {
    PluginManager &Renderer::getPluginManager()
    {
        return _pluginManager;
    }

    void Renderer::render()
    {
        _wrapper->run(*this);
    }

    void Renderer::setCamera(std::shared_ptr<Camera> camera)
    {
        _camera = camera;
    }

    void Renderer::addEntity(std::shared_ptr<Entity> entity)
    {
        _entities.push_back(entity);
    }

    void Renderer::setWrapper(IWrapper *wrapper)
    {
        _wrapper = std::shared_ptr<IWrapper>(wrapper);
    }

    Camera &Renderer::getCamera() const
    {
        if (_camera == nullptr)
            throw std::runtime_error("No camera set");
        return *_camera;
    }

    void Renderer::setAmbientLight(const sf::Color &color)
    {
        _ambientLight = color;
    }

    std::vector<std::shared_ptr<Entity >> Renderer::getEntities() const
    {
        return _entities;
    }
}
