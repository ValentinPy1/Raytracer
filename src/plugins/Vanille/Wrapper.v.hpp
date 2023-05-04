/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.hpp
*/

#include <thread>
#include <mutex>
#include "Wrapper.hpp"
#include "Renderer.hpp"
#include "SFML/Graphics.hpp"
#include "Plugin.hpp"

namespace vanille {
    class Wrapper_v : public render::IWrapper {
        public:
            Wrapper_v();
            ~Wrapper_v();
            void run(render::Renderer &rdr) override;
            sf::Color processRay(render::Ray &ray, const render::Renderer &rdr, std::vector<render::processRay_t> &processFuns) const;
            sf::Color processRay(render::Ray &ray, const render::Renderer &rdr) const;
        private:
            void init(render::PluginManager &pm, render::Renderer &rdr) const;
            void postProcess(render::Renderer &rdr, render::PluginManager &pm) const;
            void render(render::Renderer &rdr, render::PluginManager &pm);

            std::vector<render::processRay_t> _processFuns;

            std::mutex _mutex;
    };
}
