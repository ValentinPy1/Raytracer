/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Renderer.cpp
*/

#include "Renderer.hpp"

namespace render {
    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    PluginManager &Renderer::getPluginManager()
    {
        return _pluginManager;
    }

    void Renderer::render()
    {
        // TODO CALL WRAPPER
    }

    void Renderer::setCamera(std::shared_ptr<Camera> camera)
    {
        _camera = camera;
    }

    void Renderer::addEntity(std::shared_ptr<Entity> entity);
    {
        _entities.push_back(entity);
    }
}