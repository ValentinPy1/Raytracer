/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** APluginProcess.hpp
*/

#pragma once

#include "PluginManager.hpp"

namespace render {
    class APluginProcess : public virtual Plugin {
        public:
            virtual void selfInit(libconfig::Setting setting) = 0;
        protected:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
    };
}