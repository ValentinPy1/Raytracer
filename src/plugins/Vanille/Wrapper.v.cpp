/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.cpp
*/

#include "Plugin.hpp"
#include "../plugins/Vanille/Wrapper.v.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

namespace vanille {
    Wrapper_v::Wrapper_v(const std::string &name)
    {
    }

    void Wrapper_v::init() const
    {
        std::vector<render::init_t> initFuns = _pm->getInitFunctions();
        for (auto &fun : initFuns)
            fun(*_rdr);
    }

    sf::Color Wrapper_v::processRay(render::Ray &ray) const
    {
        std::vector<render::processRay_t> processFuns = _pm->getProcessRayFunctions();
        for (auto &fun : processFuns)
            fun(ray, *_rdr);
        return ray.getColor();
    }

    void Wrapper_v::postProcess() const
    {
        std::vector<render::postProcess_t> postFuns = _pm->getPostProcessFunctions();
        for (auto &fun : postFuns)
            fun(*_rdr);
    }

    void Wrapper_v::render() const
    {
        render::Camera &camera = _rdr->getCamera();
        sf::Image &captor = camera.getCaptor();
        std::vector<render::Ray> &rays = camera.getRays();

        sf::Vector2u captorSize = captor.getSize();
        unsigned int width = captorSize.x;
        unsigned int height = captorSize.y;
        for (unsigned int y = 0; y < height; y++) {
            for (unsigned int x = 0; x < width; x++) {
                sf::Color color = processRay(rays[y * width + x]);
                captor.setPixel(x, y, color);
            }
        }
        postProcess();
        captor.saveToFile("test.png");
    }

    void Wrapper_v::run(render::Renderer &rdr)
    {
        _rdr = &rdr;
        _pm = &_rdr->getPluginManager();

        init();
        render();
    }

    extern "C" {
        render::IWrapper *entryPoint()
        {
            return new Wrapper_v("wrapper");
        }
    }
}
