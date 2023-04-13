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
#include <functional>
#include "Ray.hpp"

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
            T *loadInstance(const std::string &path, const std::string &libName) {
                void *handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!handle) {
                    throw DLLoaderException("Cannot open library: " + std::string(dlerror()));
                }
                dlerror();
                T *instance = reinterpret_cast<T *>(dlsym(handle, "entryPoint"));
                const char *dlsym_error = dlerror();
                if (dlsym_error) {
                    throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(dlsym_error));
                }
                _handles.push_back(handle);
                _handleNames.push_back(libName);
                return instance;
            }

            /**
             * @brief Load a dynamic library from a path and a library name.
             * The handle is simply registered in the DLLoader object, and
             * no instance is returned.
             *
             * @param path
             * @param libName
             */
            void load(const std::string &path, const std::string &libName);

            template <typename T>
            T loadSymbol(const std::string &libName, const std::string &symbolName) {
                for (size_t i = 0; i < _handleNames.size(); i++) {
                    if (_handleNames[i] == libName) {
                        T sym = reinterpret_cast<T>(dlsym(_handles[i], symbolName.c_str()));
                        const char *dlsym_error = dlerror();
                        if (dlsym_error) {
                            throw DLLoaderException("Cannot load symbol '" + symbolName + "': " + std::string(dlsym_error));
                        }
                        return sym;
                    }
                }
                throw DLLoaderException("Cannot find library " + libName);
            }
        private:
            std::vector<void *> _handles;
            std::vector<std::string> _handleNames;
    };

    /**
     * A plugin is an object loaded from a dynamic library (.so file with an entryPoint function).
     * This object should have several function defined, which could be set to
     * nullptr if needed:
     *  - void (*init)(render::Renderer &rdr) (called when the plugin is loaded)
     * - void (*processRay)(render::Ray &ray, const render::Renderer &rdr) (called when a ray is casted)
     * - void (*postProcess)(render::Renderer &rdr) (called when the rendering is done
     *
     * A plugin should also have an attribute "priority" which is an unsigned integer
     * loaded using the "getPriority" function of the library. This attribute
     * is used to determine the order in which the plugins are called, the lower
     * the priority, the sooner the plugin is called. If two plugins have the
     * same priority, the order is undefined.
     */
    class Plugin {
        public:
            Plugin() = delete;
            Plugin(void (*)(render::Renderer&), void (*)(render::Ray&, const render::Renderer&), void (*)(render::Renderer&), unsigned int priority);
            ~Plugin() = default;
            void init(render::Renderer &rdr) const;
            void processRay(render::Ray &ray, const render::Renderer &rdr) const;
            void postProcess(render::Renderer &rdr) const;
            unsigned int getPriority() const;
        private:
            void (*_init)(render::Renderer &rdr) = nullptr;
            void (*_processRay)(render::Ray &ray, const render::Renderer &rdr) = nullptr;
            void (*_postProcess)(render::Renderer &rdr) = nullptr;
            unsigned int _priority;
    };

    /**
     * @brief A class that stores and manages plugins.
     */
    class PluginManager {
        public:
            PluginManager();
            ~PluginManager();

        private:
            void loadPlugin(const std::string &path, const std::string &libName);
            void autoLoadPlugins(const std::string &pluginsDir = "./plugins");

            DLLoader _loader;
            std::vector<Plugin> _plugins;
    };
}
