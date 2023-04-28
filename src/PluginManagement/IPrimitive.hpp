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
    #include "SFML/System/Vector3.hpp"

namespace render {
    class Entity;
    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;
            virtual void selfInit(libconfig::Setting &setting, Entity *parent) = 0;
            virtual sf::Vector3f getNormalAt(sf::Vector3f &point) = 0;
            virtual void solve(render::Ray &ray) = 0;
    };
}

#endif // PLUGINPRIMITIVE_HPP
