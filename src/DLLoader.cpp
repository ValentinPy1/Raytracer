/*
** EPITECH PROJECT, 2022
** ray
** File description:
** DLLoader.cpp
*/

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
        for (auto &handle : _libHandles) {
            std::cout << "Closing " << handle.first << std::endl;
            dlclose(handle.second);
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
