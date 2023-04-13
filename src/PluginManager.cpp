/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginManager.cpp
*/

#include <filesystem>
#include <string>
#include <functional>
#include "Render.hpp"
#include "PluginManager.hpp"

namespace render {

    PluginManager::PluginManager()
    {
    }

    PluginManager::~PluginManager()
    {
    }

    void PluginManager::loadPlugin(const std::string &path, const std::string &libName)
    {
        void (*init)(render::Renderer&)= nullptr;
        void (*processRay)(render::Ray &ray, const render::Renderer &rdr) = nullptr;
        void (*postProcess)(render::Renderer &rdr) = nullptr;
        unsigned int (*getPriority)() = nullptr;
        unsigned int priority = 0;

        try {
            _loader.load(path, libName);
        } catch (DLLoader::DLLoaderException &e) {
            std::cerr << e.what() << std::endl;
            throw e;
        }
        try {
            init = _loader.loadSymbol<decltype(init)>(libName, "init");
        } catch (DLLoader::DLLoaderException &e) {}
        try {
            processRay = _loader.loadSymbol<decltype(processRay)>(libName, "processRay");
        } catch (DLLoader::DLLoaderException &e) {}
        try {
            postProcess = _loader.loadSymbol<decltype(postProcess)>(libName, "postProcess");
        } catch (DLLoader::DLLoaderException &e) {}
        try {
            getPriority = _loader.loadSymbol<decltype(getPriority)>(libName, "getPriority");
            if (getPriority)
                priority = getPriority();

        } catch (DLLoader::DLLoaderException &e) {}
        _plugins.emplace_back(init, processRay, postProcess, priority);
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

    Plugin::init_t Plugin::getInit() const noexcept
    {
        return _init;
    }

    Plugin::processRay_t Plugin::getProcessRay() const noexcept
    {
        return _processRay;
    }

    Plugin::postProcess_t Plugin::getPostProcess() const noexcept
    {
        return _postProcess;
    }
}
