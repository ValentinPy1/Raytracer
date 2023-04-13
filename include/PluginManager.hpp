/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginManager.hpp
*/

#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>

namespace pl {

    /**
     * @brief A class that loads dynamic libraries from a .so file
     * containing an "entryPoint" function that returns a pointer to an object.
     *
     */
    class DLLoader {
        public:
            class DLLoaderException : public std::exception {
                public:
                    DLLoaderException(const std::string &message);
                    ~DLLoaderException() = default;
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };

            DLLoader();
            ~DLLoader();
            template <typename T>
            T *load(const std::string &path) {
                void *handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!handle) {
                    throw DLLoaderException("Cannot open library: " + std::string(dlerror()));
                }
                _handles.push_back(handle);
                dlerror();
                T *instance = reinterpret_cast<T *>(dlsym(handle, "entryPoint"));
                const char *dlsym_error = dlerror();
                if (dlsym_error) {
                    throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(dlsym_error));
                }
                return instance;
            }
        private:
            std::vector<void *> _handles;
    };

    /**
     * @brief A class that manages plugins.
     * A plugin is an object loaded from a dynamic library, with a function
     *
     */
    class PluginManager {
        public:
            PluginManager();
            ~PluginManager();

        private:
            void loadPlugins();
            void autoLoadPlugins(const std::string &pluginsDir);

            DLLoader _loader;
    }
}
