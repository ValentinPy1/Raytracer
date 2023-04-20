/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginPrimitive.hpp
*/

#ifndef PLUGINPRIMITIVE_HPP
    #define PLUGINPRIMITIVE_HPP
    #include <libconfig.h++>
    #include "PluginManager.hpp"

namespace render {
    class APluginPrimitive : public virtual Plugin {
        public:
            virtual void selfInit(libconfig::Setting &setting) = 0;
        protected:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
    };
}


#endif // PLUGINPRIMITIVE_HPP
