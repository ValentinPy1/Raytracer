/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** ConfigLoader.hpp
*/


#ifndef CONFIGLOADER_HPP
#define CONFIGLOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <libconfig.h++>
#include <memory>
#include <iostream>
#include <functional>
#include "Render.hpp"
#include "PluginManager.hpp"
#include "plugins/IPrimitive.hpp"
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
            void loadObjects(Renderer &rdr);

        private:
            libconfig::Config _cfg;
            std::string _mode;
            PluginManager _pluginManager;
            std::string current_plugin;
            DLLoader _loader;
            std::string _path = "./plugins/";
    };
}

#endif // CONFIGLOADER_HPP
