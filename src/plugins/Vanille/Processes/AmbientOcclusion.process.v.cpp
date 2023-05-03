/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientOcclusion.process.v.cpp
*/

#include <cmath>
#include "Renderer.hpp"
#include "Plugin.hpp"
#include "Ray.hpp"
#include "AmbientOcclusion.process.v.hpp"

namespace vanille
{
    AmbientOcclusion_v::AmbientOcclusion_v() : render::Plugin(
        [this](render::Renderer &rdr) {
            try {
                const libconfig::Setting *setting = rdr.getParams();
                if (setting == nullptr)
                    throw std::runtime_error("No params set");
                const libconfig::Setting &ambientOcclusion = setting->lookup("ambientOcclusion");
                ambientOcclusion.lookupValue("density", _density);
                int r, g, b;
                ambientOcclusion.lookupValue("r", r);
                ambientOcclusion.lookupValue("g", g);
                ambientOcclusion.lookupValue("b", b);
                _color = sf::Color(r, g, b);
            } catch (std::exception &e) {
                std::cout << render::green << "[INFO] " << render::yellow << "[Ambient Occlusion Plugin] " << render::no_color << "Defaulting ambient color to (rgb) (30,30,50)" << std::endl;
            }
        },
        [this](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
            float distance = (ray.hasIntersections()) ? ray.getIntersections()[0].getDistance() : 1000000;
            ray.setColor(ray.blendLerp(
                _color,
                1 - exp(-_density * distance)
            ));
            // std::cout << exp(-_density * distance) << "   " << distance << std::endl;
            return ray;
        },
        nullptr,
        10100,
        "ambient_occlusion"
    )
    {
    }
} // namespace vanille


extern "C" {
    render::IPlugin *entryPoint()
    {
        return new vanille::AmbientOcclusion_v();
    }
}
