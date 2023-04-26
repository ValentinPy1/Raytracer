/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Renderer.hpp
*/

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
    #include <memory>
    #include "Entity.hpp"
    #include "PluginManager.hpp"
    #include "Wrapper.hpp"

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

            Camera &getCamera() const;
            void render();
        private:
            PluginManager _pluginManager;
            std::vector<std::shared_ptr<Entity>> _entities;
            std::shared_ptr<IWrapper> _wrapper;
            std::shared_ptr<Camera> _camera;
            // std::vector <Light> _lights;

    };
}


#endif // RENDERER_HPP
