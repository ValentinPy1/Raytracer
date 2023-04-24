/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** APlugin.hpp
*/

#pragma once

#include "../PluginManager.hpp"
#include "../Render.hpp"

namespace vanille {
    class APlugin {
        public:
            APlugin() = default;
            virtual ~APlugin() = default;
        protected:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
            std::string _name;
    };
}
