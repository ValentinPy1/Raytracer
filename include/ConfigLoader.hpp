/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** ConfigLoader.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <libconfig.h++>
#include <memory>
#include <iostream>
#include <functional>
#include "Render.hpp"
#include "PluginManager.hpp"

namespace render {
    class Renderer;
    class ConfigLoader
    {
        public:
            ConfigLoader();
            ~ConfigLoader();
            void loadConfigFile(std::string path, Renderer &rdr);
            void loadCamera(Renderer &rdr);
            void loadPlugins(Renderer &rdr);

        private:
            libconfig::Config _cfg;
            std::string _mode;
            PluginManager _pluginManager;
            std::string current_plugin;
    };
}
