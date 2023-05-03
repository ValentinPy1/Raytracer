/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientOcclusion.process.v.cpp
*/

#include "Renderer.hpp"
#include "Plugin.hpp"
#include "AmbientOcclusion.process.v.hpp"

namespace vanille
{
    AmbientOcclusion_v::AmbientOcclusion_v() : render::Plugin(
        nullptr, // TODO density from config params
        [](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {

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
