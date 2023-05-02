/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginManager.hpp
*/

#pragma once

#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>
#include <map>
#include <functional>
#include <tuple>
#include <memory>
#include "IPlugin.hpp"
#include "Plugin.hpp"
#include "DLLoader.hpp"

namespace render {
    class Renderer;


    /**
     * @brief A class that stores and manages plugins. The plugins can later
     * be used to call the functions they contain.
     *
     */
    class PluginManager {
        public:
            PluginManager();
            ~PluginManager();

            /**
             * @brief Load a plugin from a path and a library name.
             * Registers it so that it can be called and used later.
             *
             * @param path
             * @param libName
             */
            void loadPlugin(const std::string &path, const std::string &libName);

            /**
             * @brief Load all plugins from a directory.
             *
             * @param pluginsDir
             */
            void autoLoadPlugins(const std::string &pluginsDir = "./plugins");

            /**
             * @brief Load all plugins from a list of paths and library names.
             *
             * @param plugins A vector of tuples containing the path and the library name, in that order.
             */
            void loadPlugins(const std::vector<std::tuple<std::string, std::string>> &plugins);

            /**
             * @brief Returns all of the non null init functions of the plugins,
             * sorted by priority of execution.
             *
             * @return std::vector<Plugin::init_t>
             */
            std::vector<init_t> getInitFunctions() const;

            /**
             * @brief Returns all of the non null processRay functions of the plugins,
             * sorted by priority of execution.
             *
             * @return std::vector<Plugin::processRay_t>
             */
            std::vector<processRay_t> getProcessRayFunctions();

            /**
             * @brief Returns all of the non null postProcess functions of the plugins,
             * sorted by priority of execution.
             *
             * @return std::vector<Plugin::postProcess_t>
             */
            std::vector<postProcess_t> getPostProcessFunctions() const;

            /**
             * @brief Given a string, returns a pointer to the plugin with the same name.
             *
             * @param libName
             * @return IPlugin*
             */
            IPlugin *require(const std::string &libName);

            /**
             * @brief Returns a vector of all the plugins.
             *
             * @return std::vector<Plugin>
             */
            const std::vector<std::shared_ptr<IPlugin>> &getPlugins() const noexcept;
        private:
            DLLoader _loader;
            std::vector<std::shared_ptr<IPlugin>> _plugins;
    };
}
