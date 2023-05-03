/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientLight.v.cpp
*/

#include <libconfig.h++>
#include "Camera.hpp"
#include "Ray.hpp"
#include "Renderer.hpp"
#include "AmbientLight.v.hpp"

namespace render {
    AmbientLight_v::AmbientLight_v() :
        Plugin(
           nullptr,
            nullptr,
            nullptr,
            1000,
            "AmbientLight"
        )
    {
        _init =  [this](render::Renderer &rdr) {
                try {
                    const libconfig::Setting *setting = rdr.getParams();
                    if (setting == nullptr)
                        throw std::runtime_error("No params set");
                    const libconfig::Setting &ambientLight = setting->lookup("ambientLight");
                    int r, g, b;
                    ambientLight.lookupValue("r", r);
                    ambientLight.lookupValue("g", g);
                    ambientLight.lookupValue("b", b);
                    _color = sf::Color(r, g, b);
                } catch (std::exception &e) {
                    std::cout << render::green << "[INFO] " << render::yellow << "[Ambient Light Plugin] " << render::no_color << "Defaulting ambient color to (rgb) (30,30,50)" << std::endl;
                }
                std::shared_ptr<render::Camera> camera = rdr.getCamera();
                for (auto &r : camera->getRays()) {
                    r.setColor(_color);
                }
            };
        _processRay = [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            applyAmbientLight(ray, rdr);
            return ray;
        };
    }

    void AmbientLight_v::applyAmbientLight(render::Ray &ray,
        __attribute__((unused)) const render::Renderer &rdr) {
        if (!ray.hasIntersections()) {
            ray.setColor(_color);
            return;
        }
        ray.setColor(ray.blendLerp(_color, 0.3));
    }
}

extern "C" {
    render::IPlugin *entryPoint()
    {
        return new render::AmbientLight_v();
    }
}
