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
#include <algorithm>
#include "Renderer.hpp"
#include "PluginManager.hpp"
#include "Plugin.hpp"

namespace render {

    PluginManager::PluginManager()
    {
    }

    PluginManager::~PluginManager()
    {
        std::cout << render::green << "[INFO] " << render::no_color << "Unloading plugins..." << std::endl;
    }

    void PluginManager::loadPlugin(const std::string &path, const std::string &libName)
    {
        _loader.load(path, libName);
        auto plugin = std::shared_ptr<IPlugin>(_loader.loadInstance<IPlugin>(libName));
        if (plugin->getPriority() < 0)
            return;
        _plugins.push_back(plugin);
        std::sort(_plugins.begin(), _plugins.end(), [](const std::shared_ptr<IPlugin> &a, const std::shared_ptr<IPlugin> &b) {
            return a->getPriority() < b->getPriority();
        });
        std::cout << render::green << "[INFO] " << render::no_color << "Loaded plugin: " << libName << std::endl;
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
            if (plugin->getInit())
                ret.push_back(plugin->getInit());
        }
        return ret;
    }

    std::vector<processRay_t> PluginManager::getProcessRayFunctions() const
    {
        std::vector<processRay_t> ret;
        for (const auto &plugin : _plugins) {
            if (plugin->getProcessRay())
                ret.push_back(plugin->getProcessRay());
        }
        return ret;
    }

    std::vector<postProcess_t> PluginManager::getPostProcessFunctions() const
    {
        std::vector<postProcess_t> ret;

        for (const auto &plugin : _plugins) {
            if (plugin->getPostProcess())
                ret.push_back(plugin->getPostProcess());
        }
        return ret;
    }

    void PluginManager::loadPlugins(const std::vector<std::tuple<std::string, std::string>> &plugins)
    {
        for (const auto &plugin : plugins) {
            try {
                loadPlugin(std::get<0>(plugin), std::get<1>(plugin));
            } catch (DLLoader::DLLoaderException &e) {
                std::cerr << render::red << "[ERROR] Failed to load plugin: " << render::no_color
                    << std::get<0>(plugin) << e.what() << std::endl;
            }
        }
    }

    IPlugin *PluginManager::require(const std::string &name)
    {
        for (auto &plugin : _plugins) {
            if (plugin->getName() == name)
                return plugin.get();
        }
        throw std::runtime_error("Plugin not found: " + name);
    }

    const std::vector<std::shared_ptr<IPlugin>> &PluginManager::getPlugins() const noexcept
    {
        return _plugins;
    }
}
