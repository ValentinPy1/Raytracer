/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Renderer.hpp
*/

#ifndef EEFC4E04_4D3A_47D5_A160_5A1E8DB75BD9
    #define EEFC4E04_4D3A_47D5_A160_5A1E8DB75BD9
    #include <vector>
    #include <memory>
    #include "Entity.hpp"
    #include "PluginManager.hpp"
    #include "Camera.hpp"

namespace render {
    class Renderer {
        public:
            Renderer();
            ~Renderer();

            PluginManager &getPluginManager();
            void addEntity(std::shared_ptr<Entity> entity);

            void setCamera(std::shared_ptr<Camera> camera);
        private:
            PluginManager _pluginManager;
            std::vector<Entity> _entities;
            // std::shared_ptr<IWrapper> _wrapper;
            std::shared_ptr<Camera> camera;
            // std::vector <Light> _lights;

    };
}

#endif /* EEFC4E04_4D3A_47D5_A160_5A1E8DB75BD9 */
