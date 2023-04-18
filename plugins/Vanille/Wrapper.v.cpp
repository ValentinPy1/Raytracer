/*
** EPITECH PROJECT, 2022
** raytracerv2
** File description:
** Wrapper.v.cpp
*/

#include "plugins/Wrapper.v.hpp"
#include "Ray.hpp"

namespace vanille {
    Wrapper_v::Wrapper_v(
        const std::string &name) :
        render::AWrapper(
            nullptr,
            nullptr,
            nullptr,
            0,
            name
    ), _rdr(nullptr), _pm(nullptr)
    {}

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

    // void Wrapper_v::showProgressBar(int total, std::string msg) const
    // {
    //    int barWidth = 70;
    //     _progress++;
    //     std::cout << msg << " [";
    //     int pos = barWidth * _progress / total;
    //     for (int i = 0; i < barWidth; ++i) {
    //         if (i < pos) std::cout << "=";
    //         else if (i == pos) std::cout << ">";
    //         else std::cout << " ";
    //     }
    //     std::cout << "] " << int(_progress * 100.0 / total) << "%\r";
    //     std::cout.flush();
    // }

    void Wrapper_v::render() const
    {
        //  _logs.log("Rendering scene...");
        // clock_t start = clock();

        render::Camera &camera = _rdr->getCamera();
        sf::Image &captor = camera.getCaptor();
        std::vector<render::Ray> rays = camera.getRays();
        unsigned int width = captor.getSize().x;
        unsigned int height = captor.getSize().y;

        for (unsigned int y = 0; y < height; y++) {
            for (unsigned int x = 0; x < width; x++) {
                sf::Color color = processRay(rays[y * width + x]);
                captor.setPixel(x, y, color);
            }
            // showProgressBar(height, "Rendering");
        }

        postProcess();

        // _logs.log("Scene rendered, saving picture...");
        // camera.getCaptor().saveToFile("rendered.png");
        // _logs.log("Picture saved");
        // std::cout << "\nDone rendering in " << (clock() - start) / (double) CLOCKS_PER_SEC << "s" << std::endl;
    }

    void Wrapper_v::run(render::Renderer &rdr)
    {
        _rdr = &rdr;
        _pm = &_rdr->getPluginManager();

        init();
        render();
    }
}
