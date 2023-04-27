/*
** EPITECH PROJECT, 2022
** ray
** File description:
** DLLoader.cpp
*/

#include "Renderer.hpp"
#include "PluginManager.hpp"

namespace render {
    DLLoader::DLLoaderException::DLLoaderException(const std::string &message) :
        _message(message)
    {
    }

    const char *render::DLLoader::DLLoaderException::what() const noexcept {
        return _message.c_str();
    }

    DLLoader::DLLoader() {
    }

    DLLoader::~DLLoader() {
        std::cout << render::green << "[INFO] " << render::no_color << "Closing libraries: " << std::flush;
        for (auto &handle : _libHandles) {
            std::cout << render::green << "[INFO] " << render::no_color <<"Closing " << handle.first << ": \r\t\t\t\t\t\t" << std::flush;
            // dlclose(handle.second);
            std::cout << render::green << "OK" << render::no_color << std::endl;
        }
        _libHandles.clear();
    }

    void DLLoader::load(const std::string &path, const std::string &libName) {
        void *handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!handle) {
            throw DLLoaderException("Cannot open library: " + std::string(dlerror()));
        }
        dlerror();
        const char *dlsym_error = dlerror();
        if (dlsym_error) {
            throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(dlsym_error));
        }
        _libHandles[libName] = handle;
    }

}
