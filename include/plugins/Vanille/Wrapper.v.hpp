/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.hpp
*/

#include "Wrapper.hpp"
#include "SFML/Graphics.hpp"

namespace vanille {
    class Wrapper_v : public render::AWrapper {
        public:
            Wrapper_v(const std::string &name);
            ~Wrapper_v() = default;
            void run(render::Renderer &rdr) override;
        private:
            void init() const;
            sf::Color processRay(render::Ray &ray) const;
            void postProcess() const;
            void showProgressBar(int total, std::string msg = "") const;
            void render() const;
            render::Renderer *_rdr;
            render::PluginManager *_pm;
            // int _progress;
            // render::Logger _logs;
    };
}
