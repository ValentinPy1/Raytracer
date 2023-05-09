/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.cpp
*/

#include <thread>
#include <ctime>
#include <fstream>
#include "Plugin.hpp"
#include "../plugins/Vanille/Wrapper.v.hpp"
#include "Ray.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

namespace vanille {
    Wrapper_v::Wrapper_v()
    {
    }

    Wrapper_v::~Wrapper_v() {
    }

    void Wrapper_v::init(render::PluginManager &pm, render::Renderer &rdr) const
    {
        std::vector<render::init_t> initFuns = pm.getInitFunctions();

        for (auto &fun : initFuns)
            fun(rdr);
    }

    sf::Color Wrapper_v::processRay(render::Ray &ray, const render::Renderer &rdr, std::vector<render::processRay_t> &processFuns) const
    {
        for (auto &fun : processFuns)
            ray = fun(ray, rdr);
        return ray.getColor();
    }
    sf::Color Wrapper_v::processRay(render::Ray &ray, const render::Renderer &rdr) const
    {
        for (auto &fun : _processFuns) {
            ray = fun(ray, rdr);
        }
        return ray.getColor();
    }

    void Wrapper_v::postProcess(render::Renderer &rdr, render::PluginManager &pm) const
    {
        std::vector<render::postProcess_t> postFuns = pm.getPostProcessFunctions();
        for (auto &fun : postFuns)
            fun(rdr);
    }

    void Wrapper_v::saveToPPM(const sf::Image &captor, const std::string &path) const
    {
        std::ofstream file(path);
        sf::Color color;

        file << "P3" << std::endl;
        file << captor.getSize().x << " " << captor.getSize().y << std::endl;
        file << "255" << std::endl;
        for (unsigned int y = 0; y < captor.getSize().y; y++) {
            for (unsigned int x = 0; x < captor.getSize().x; x++) {
                color = captor.getPixel(x, y);
                file << (int) color.r << " " << (int) color.g << " " << (int) color.b << std::endl;
            }
        }
        file.close();
    }

    void Wrapper_v::render(render::Renderer &rdr, render::PluginManager &pm)
    {
        clock_t start = clock();
        render::Camera &camera = *rdr.getCamera();
        sf::Image &captor = camera.getCaptor();
        std::vector<render::Ray> &rays = camera.getRays();
        std::vector<render::processRay_t> processFuns = pm.getProcessRayFunctions();
        _processFuns = processFuns;

        size_t total = camera.getCaptor().getSize().x * camera.getCaptor().getSize().y;
        size_t hundreth = total / 100;
        size_t step = 0;
        float progress = 0;
        int barWidth = 70;
        std::cout << render::green << "[INFO] " << render::yellow << "Rendering... " << render::no_color << std::endl;
        for (unsigned int i = 0; i < camera.getCaptor().getSize().x; i++) {
            for (unsigned int j = 0; j < camera.getCaptor().getSize().y; j++) {
                render::Ray ray = rays[i * camera.getCaptor().getSize().y + j];
                sf::Color tmp = processRay(ray, rdr, processFuns);
                camera.getCaptor().setPixel(i, j, tmp);
                step++;
                if (step % hundreth == 0) {
                    progress = (float) step / total;
                    std::cout << "[";
                    int pos = barWidth * progress;
                    for (int i = 0; i < barWidth; ++i) {
                        if (i < pos) std::cout << "=";
                        else if (i == pos) std::cout << ">";
                        else std::cout << " ";
                    }
                    std::cout << "] " << int(progress * 100.0) << " %\r";
                    std::cout.flush();
                }
            }
        }
        std::cout << render::green << "[INFO] " << render::yellow << "Applying post process to the image... " << render::no_color << std::endl;
        postProcess(rdr, pm);
        std::cout << render::green << "[INFO] " << render::yellow << "Done in " << (double) (clock() - start) / CLOCKS_PER_SEC << " seconds."  << render::no_color << std::endl;
        captor.saveToFile("test.png");
        saveToPPM(captor, "test.ppm");
    }

    void Wrapper_v::run(render::Renderer &rdr)
    {
        auto pm = rdr.getPluginManager();

        init(pm, rdr);
        render(rdr, pm);
    }
}
