/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Renderer.hpp
*/

#pragma once

#include <vector>
#include <memory>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "PluginManager.hpp"
#include "Wrapper.hpp"
#include "ILight.hpp"
#include "renderColors.hpp"

namespace render {

    class Camera;
    class Renderer {
        public:
            class IncompatibleException : public std::runtime_error {
                public:
                    IncompatibleException(const std::string &what) : std::runtime_error(what) {}
            };

            Renderer() = default;
            ~Renderer() = default;

            PluginManager &getPluginManager();
            void addEntity(std::shared_ptr<Entity> entity);
            void setCamera(std::shared_ptr<render::Camera> camera);
            void setWrapper(IWrapper *wrapper);
            void setAmbientLight(const sf::Color &color);
            void addLight(std::shared_ptr<ILight> light);

            std::shared_ptr<Camera> getCamera() const;
            std::shared_ptr<Camera> getCamera();
            sf::Color getAmbientLight() const;
            std::vector<std::shared_ptr<ILight>> getLights() const;
            std::vector<std::shared_ptr<Entity>> getEntities() const;
            IWrapper &getWrapper() const;
            void render();

            void setCustomValue(const std::string &name, float value);
            float getCustomValue(const std::string &name) const;

            void setParams(const libconfig::Setting *params);
            const libconfig::Setting *getParams() const;
        private:
            PluginManager _pluginManager;
            std::vector<std::shared_ptr<Entity>> _entities;
            std::shared_ptr<IWrapper> _wrapper;
            std::shared_ptr<Camera> _camera;
            sf::Color _ambientLight;
            std::vector<std::shared_ptr<ILight>> _lights;
            std::map<std::string, float> _customValues;
            const libconfig::Setting *_params = nullptr;
    };
}
