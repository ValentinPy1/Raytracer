/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.hpp
*/

#include "Wrapper.hpp"
#include "Renderer.hpp"
#include "SFML/Graphics.hpp"
#include "Plugin.hpp"

namespace vanille {
    class Wrapper_v : public render::IWrapper {
        public:
            Wrapper_v(const std::string &name);
            ~Wrapper_v();
            void run(render::Renderer &rdr) override;
        private:
            void init(render::PluginManager &pm, render::Renderer &rdr) const;
            sf::Color processRay(render::Ray &ray, render::PluginManager &pm, render::Renderer &rdr, std::vector<render::processRay_t> &processFuns) const;
            void postProcess(render::Renderer &rdr, render::PluginManager &pm) const;
            void render(render::Renderer &rdr, render::PluginManager &pm) const;
    };
}
