/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** APlugin.hpp
*/

#pragma once

#include "../PluginManager.hpp"
#include "../Render.hpp"

namespace render {
    class APlugin {
        public:
            APlugin() = default;
            virtual ~APlugin() = default;
        protected:
            init_t _init = nullptr;
            processRay_t _processRay = nullptr;
            postProcess_t _postProcess = nullptr;
            int _priority;
            std::string _name;
    };
}
