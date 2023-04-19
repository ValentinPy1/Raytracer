/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginManager.cpp
*/

#include <filesystem>
#include <string>
#include <memory>
#include <functional>
#include <exception>
#include "Render.hpp"
#include "PluginManager.hpp"

namespace render {

    PluginManager::PluginManager()
    {
    }

    PluginManager::~PluginManager()
    {
        std::cout << "plugin manager: destructor" << std::endl;
    }

    void PluginManager::loadPlugin(const std::string &path, const std::string &libName)
    {
        _loader.load(path, libName);
        Plugin plugin = *std::unique_ptr<Plugin>(_loader.loadInstance<Plugin>(libName));
        if (plugin.getPriority() < 0)
            return;
        _plugins.push_back(plugin);
        std::sort(_plugins.begin(), _plugins.end(), [](const Plugin &a, const Plugin &b) {
            return a.getPriority() < b.getPriority();
        });
    }

    void PluginManager::autoLoadPlugins(const std::string &pluginsDir)
    {
        for (const auto &entry : std::filesystem::directory_iterator(pluginsDir)) {
            if (entry.path().extension() == ".so") {
                try {
                    loadPlugin(entry.path().string(), entry.path().stem().string());
                    std::cout << render::green << "[INFO] Loaded plugin: " << render::no_color
                        << entry.path().stem().string() << std::endl;
                } catch (DLLoader::DLLoaderException &e) {
                    std::cerr << render::red << "[ERROR] Failed to load plugin: " << render::no_color
                        << e.what() << std::endl;
                }
            }
        }
    }

    std::vector<init_t> PluginManager::getInitFunctions() const
    {
        std::vector<init_t> ret;

        for (const auto &plugin : _plugins) {
            if (plugin.getInit())
                ret.push_back(plugin.getInit());
        }
        return ret;
    }

    std::vector<processRay_t> PluginManager::getProcessRayFunctions() const
    {
        std::vector<processRay_t> ret;

        for (const auto &plugin : _plugins) {
            if (plugin.getProcessRay())
                ret.push_back(plugin.getProcessRay());
        }
        return ret;
    }

    std::vector<postProcess_t> PluginManager::getPostProcessFunctions() const
    {
        std::vector<postProcess_t> ret;

        for (const auto &plugin : _plugins) {
            if (plugin.getPostProcess())
                ret.push_back(plugin.getPostProcess());
        }
        return ret;
    }

    void PluginManager::loadPlugins(const std::vector<std::tuple<std::string, std::string>> &plugins)
    {
        for (const auto &plugin : plugins) {
            try {
                loadPlugin(std::get<0>(plugin), std::get<1>(plugin));
                std::cout << render::green << "[INFO] Loaded plugin: " << render::no_color
                    << std::get<0>(plugin) << std::endl;
            } catch (DLLoader::DLLoaderException &e) {
                std::cerr << render::red << "[ERROR] Failed to load plugin: " << render::no_color
                    << std::get<0>(plugin) << e.what() << std::endl;
            }
        }
    }

    IPlugin *PluginManager::require(const std::string &name)
    {
        for (auto &plugin : _plugins) {
            if (plugin.getName() == name)
                return &plugin;
        }
        throw std::runtime_error("Plugin not found: " + name);
    }

    const std::vector<Plugin> &PluginManager::getPlugins() const noexcept
    {
        return _plugins;
    }
}
