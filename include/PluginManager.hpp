/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginManager.hpp
*/

#ifndef PLUGINMANAGER_HPP
    #define PLUGINMANAGER_HPP

#include <vector>
#include <string>
#include <dlfcn.h>
#include <iostream>
#include <functional>
// #include "Ray.hpp"
// #include "Render.hpp"

namespace render {
    class Renderer;
    class Ray;
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

            /**
             * @brief Load a dynamic library from a path and a library name,
             * and return a pointer to the object returned by the "entryPoint" function.
             *
             * @tparam T
             * @param path
             * @param libName
             * @return T*
             */
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
            /**
             * @brief A vector containing the handles of the loaded libraries.
             * These handles are stored for future reference, and are used to
             * close the libraries when the DLLoader object is destroyed.
             *
             */
            std::vector<void *> _handles;

            /**
             * @brief A vector containing the names of the loaded libraries.
             * These names are used to find the correct library when a symbol
             * is requested, from the index of the name of the library in this
             * vector.
             *
             */
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

            /**
             * @brief Calls the init function if it is not nullptr.
             *
             * @param rdr
             */
            void init(render::Renderer &rdr) const;

            /**
             * @brief Calls the processRay function if it is not nullptr.
             *
             * @param ray
             * @param rdr
             */
            void processRay(render::Ray &ray, const render::Renderer &rdr) const;

            /**
             * @brief Calls the postProcess function if it is not nullptr.
             *
             * @param rdr
             */
            void postProcess(render::Renderer &rdr) const;

            /**
             * @brief Returns the priority of the plugin.
             *
             * @return unsigned int
             */
            unsigned int getPriority() const;

            typedef void (*init_t)(render::Renderer &rdr);
            typedef void (*processRay_t)(render::Ray &ray, const render::Renderer &rdr);
            typedef void (*postProcess_t)(render::Renderer &rdr);

            /**
             * @brief Get the pointer to the function _init.
             * Note that this function can be nullptr.
             *
             * @return init_t
             */
            init_t getInit() const noexcept;

            /**
             * @brief Get the pointer to the function _processRay.
             * Note that this function can be nullptr.
             *
             * @return processRay_t
             */
            processRay_t getProcessRay() const noexcept;

            /**
             * @brief Get the pointer to the function _postProcess.
             * Note that this function can be nullptr.
             *
             * @return postProcess_t
             */
            postProcess_t getPostProcess() const noexcept;
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

#endif // PLUGINMANAGER_HPP
