/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Renderer.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "PluginManager.hpp"
#include "Wrapper.hpp"
#include "ILight.hpp"

namespace render {

    static const std::string red = "\033[31m";
    static const std::string green = "\033[32m";
    static const std::string yellow = "\033[33m";
    static const std::string blue = "\033[34m";
    static const std::string magenta = "\033[35m";
    static const std::string no_color = "\033[0m";

    class Camera;
    class Renderer {
        public:
            Renderer() = default;
            ~Renderer() = default;

            PluginManager &getPluginManager();
            void addEntity(std::shared_ptr<Entity> entity);
            void setCamera(std::shared_ptr<render::Camera> camera);
            void setWrapper(IWrapper *wrapper);
            void setAmbientLight(const sf::Color &color);
            void addLight(std::shared_ptr<ILight> light);

            Camera &getCamera() const;
            sf::Color getAmbientLight() const;
            std::vector<std::shared_ptr<ILight>> getLights() const;
            std::vector<std::shared_ptr<Entity>> getEntities() const;
            void render();
        private:
            PluginManager _pluginManager;
            std::vector<std::shared_ptr<Entity>> _entities;
            std::shared_ptr<IWrapper> _wrapper;
            std::shared_ptr<Camera> _camera;
            sf::Color _ambientLight;
            std::vector<std::shared_ptr<ILight>> _lights;
    };
}
