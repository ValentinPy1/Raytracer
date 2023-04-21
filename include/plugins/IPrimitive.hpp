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
    class IPrimitive {
        public:
            virtual void selfInit(libconfig::Setting &setting) = 0;
    };
}

#endif // PLUGINPRIMITIVE_HPP
