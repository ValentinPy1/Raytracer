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
#include "PluginManager.hpp"

namespace render {
    class Renderer;
    class ConfigLoader
    {
        public:
            ConfigLoader();
            ~ConfigLoader();
            void loadConfigFile(std::string path, Renderer &rdr);

        private:
            void loadCamera(Renderer &rdr);
            void loadPlugins(Renderer &rdr);
            void loadObjects(Renderer &rdr);
            void loadLights(Renderer &rdr);
            void loadParams(Renderer &rdr);

            libconfig::Config _cfg;
            std::string _mode;
            PluginManager _pluginManager;
            std::string current_plugin;
            DLLoader _loader;
            std::string _path = "./src/plugins/";
    };
}


