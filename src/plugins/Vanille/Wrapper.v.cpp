/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.cpp
*/

#include <ctime>
#include "Plugin.hpp"
#include "../plugins/Vanille/Wrapper.v.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

namespace vanille {
    Wrapper_v::Wrapper_v(const std::string &name)
    {
    }

    Wrapper_v::~Wrapper_v() {
        std::cout << "destroying wrapper" << std::endl;
    }

    void Wrapper_v::init(render::PluginManager &pm, render::Renderer &rdr) const
    {
        std::vector<render::init_t> initFuns = pm.getInitFunctions();
        for (auto &fun : initFuns)
            fun(rdr);
    }

    sf::Color Wrapper_v::processRay(render::Ray &ray, render::PluginManager &pm, render::Renderer &rdr, std::vector<render::processRay_t> &processFuns) const
    {
        for (auto &fun : processFuns)
            fun(ray, rdr);
        return ray.getColor();
    }

    void Wrapper_v::postProcess(render::Renderer &rdr, render::PluginManager &pm) const
    {
        std::vector<render::postProcess_t> postFuns = pm.getPostProcessFunctions();
        for (auto &fun : postFuns)
            fun(rdr);
    }

    void Wrapper_v::render(render::Renderer &rdr, render::PluginManager &pm) const
    {
        clock_t start = clock();
        render::Camera &camera = rdr.getCamera();
        sf::Image &captor = camera.getCaptor();
        std::vector<render::Ray> &rays = camera.getRays();
        std::vector<render::processRay_t> processFuns = pm.getProcessRayFunctions();

        sf::Vector2u captorSize = captor.getSize();
        unsigned int width = captorSize.x;
        unsigned int height = captorSize.y;

        std::cout << render::green << "[INFO] " << render::yellow << "Rendering... " << render::no_color << std::endl;

        for (unsigned int y = 0; y < height; y++) {
            for (unsigned int x = 0; x < width; x++) {
                sf::Color color = processRay(rays[y * width + x], pm, rdr, processFuns);
                captor.setPixel(x, y, color);
            }
        }
        std::cout << render::green << "[INFO] " << render::yellow << "Applying post process to the image... " << render::no_color << std::endl;
        postProcess(rdr, pm);
        std::cout << render::green << "[INFO] " << render::yellow << "Done in " << (double) (clock() - start) / CLOCKS_PER_SEC << " seconds."  << render::no_color << std::endl;
        captor.saveToFile("test.png");
    }

    void Wrapper_v::run(render::Renderer &rdr)
    {
        auto pm = rdr.getPluginManager();

        init(pm, rdr);
        render(rdr, pm);
    }

    extern "C" {
        render::IWrapper *entryPoint()
        {
            return new Wrapper_v("wrapper");
        }
    }
}
