/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** IPlugin.hpp
*/

#pragma once

#include <functional>
#include <string>
#include <memory>
#include <vector>

namespace render {
    class Renderer;
    class Ray;

    /**
     * @brief and init_t function will be automatically called
     * before the rendering process starts.
     *
     */
    typedef std::function<void(render::Renderer &)> init_t;

    /**
     * @brief A processRay_t function will be called for each ray
     * before it is casted, accounting for the priority of the plugin.
     *
     */
    typedef std::function<render::Ray &(render::Ray &, const render::Renderer &)> processRay_t;

    /**
     * @brief A postProcess_t function will be called after the rendering
     * process is finished, accounting for the priority of the plugin.
     *
     */
    typedef std::function<void(render::Renderer &)> postProcess_t;

    class IPlugin {
        public:
            virtual void init(render::Renderer &rdr) const = 0;
            virtual void processRay(render::Ray &ray, const render::Renderer &rdr) const = 0;
            virtual void postProcess(render::Renderer &rdr) const = 0;
            virtual int getPriority() const = 0;
            virtual init_t getInit() const noexcept = 0;
            virtual processRay_t getProcessRay() const noexcept = 0;
            virtual postProcess_t getPostProcess() const noexcept = 0;
            virtual const std::string &getName() const = 0;
    };
}
