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
#include <map>
#include <functional>
#include <memory>
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
            T *loadInstance(const std::string &libName, const std::string &path = "") {
                void *handle = nullptr;
                if (_libHandles.find(libName) != _libHandles.end()) {
                    handle = _libHandles[libName];
                } else {
                    handle = dlopen(path.c_str(), RTLD_LAZY);
                    if (!handle) {
                        throw DLLoaderException("Cannot open library: " + std::string(dlerror()));
                    }
                    dlerror();
                    _libHandles[libName] = handle;
                }
                try {
                    T *(*entryPoint)() = reinterpret_cast<T *(*)()>(dlsym(handle, "entryPoint"));
                    const char *dlsym_error = dlerror();
                    if (dlsym_error) {
                        throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(dlsym_error));
                    }
                    return entryPoint();
                } catch (const std::exception &e) {
                    throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(e.what()));
                }
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
                if (_libHandles.find(libName) == _libHandles.end()) {
                    throw DLLoaderException("Cannot find library " + libName);
                }
                try {
                    T sym = reinterpret_cast<T>(dlsym(_libHandles[libName], symbolName.c_str()));
                    const char *dlsym_error = dlerror();
                    if (dlsym_error) {
                        throw DLLoaderException("Cannot load symbol '" + symbolName + "': " + std::string(dlsym_error));
                    }
                    return sym;
                } catch (const std::exception &e) {
                    throw DLLoaderException("Cannot load symbol '" + symbolName + "': " + std::string(e.what()));
                }
            }
        private:
            /**
             * @brief A vector containing the handles of the loaded libraries.
             * This vector is used to close the libraries when the DLLoader object is destroyed.
             * It can also be used to load new symbols from the libraries from
             * the library name.
             *
             */
            std::map<std::string, void *> _libHandles;
    };

    /**
     * @brief and init_t function will be automatically called
     * before the rendering process starts.
     *
     */
    typedef std::function<void(render::Renderer &)> init_t;

    /**
     * @brief A processRay_t function will be called for each ray
     * before it is casted, accounting for the priority of the plugin.
     *
     */
    typedef std::function<render::Ray &(render::Ray &, const render::Renderer &)> processRay_t;

    /**
     * @brief A postProcess_t function will be called after the rendering
     * process is finished, accounting for the priority of the plugin.
     *
     */
    typedef std::function<void(render::Renderer &)> postProcess_t;

    class IPlugin {
    public:
        virtual void init(render::Renderer &rdr) const = 0;
        virtual void processRay(render::Ray &ray, const render::Renderer &rdr) const = 0;
        virtual void postProcess(render::Renderer &rdr) const = 0;
        virtual int getPriority() const = 0;
        virtual init_t getInit() const noexcept = 0;
        virtual processRay_t getProcessRay() const noexcept = 0;
        virtual postProcess_t getPostProcess() const noexcept = 0;
        virtual const std::string &getName() const = 0;
    };



    /**
     * @brief A plugin is an object loaded from a dynamic library (.so file with an entryPoint function).
     * This object should have several function defined, which could be set to
     * nullptr if not needed:
     *
     * A plugin should also have an attribute "priority" which is an unsigned integer
     * loaded using the "getPriority" function of the library. This attribute
     * is used to determine the order in which the plugins are called, the lower
     * the priority, the sooner the plugin is called. If two plugins have the
     * same priority, the order is undefined.
     *
     * The plugin library must also provide a function entryPoint which
     * returns a pointer to a Plugin object.
     * This Instance would then have been set up manually by the developer.
     * This allows for more flexibility, using one of the following design pattern:
     *
     * 1. Inheritance
     * @code {.cpp}
     *
     * class MyPlugin : public Plugin {
     *    public:
     *     MyPlugin() : Plugin(customInit, customProcessRay, customPostProcess, 0) {}
     *    ~MyPlugin() = default;
     *  private:
     *     // ...
     *     Foo _customMemberFun();
     *     Bar _customAttribute;
     *  };
     * @endcode
     *
     * 2. Use of lambda expressions to capture a helper class
     * @code {.cpp}
     *
     * class HelperClass {
     *  public:
     *    HelperClass() = default;
     *   ~HelperClass() = default;
     *  void customMemberFun() {
     *   // ...
     * }
     *
     * Plugin *entryPoint() {
     *   class MyPlugin : public Plugin {
     *      std::shared_ptr<HelperClass> _helper;
     *     init_t customInit = [helper](render::Renderer &rdr) {
     *         helper->customMemberFun();
     *         // ...
     *    };
     *     // similar process for processRay and postProcess
     *    return new Plugin(customInit, customProcessRay, customPostProcess, 0);
     * }
     * @endcode
     */
    class Plugin : public virtual IPlugin {
        public:
            Plugin();
            Plugin(
                init_t init,
                processRay_t processRay,
                postProcess_t postProcess,
                int priority,
                const std::string &name
            );
            ~Plugin() = default;

            /**
             * @brief Calls the init function if it is not nullptr.
             *
             * @param rdr
             */
            void init(render::Renderer &rdr) const override;

            /**
             * @brief Calls the processRay function if it is not nullptr.
             *
             * @param ray
             * @param rdr
             */
            void processRay(render::Ray &ray, const render::Renderer &rdr) const override;

            /**
             * @brief Calls the postProcess function if it is not nullptr.
             *
             * @param rdr
             */
            void postProcess(render::Renderer &rdr) const override;

            /**
             * @brief Returns the priority of the plugin.
             *
             * @return unsigned int
             */
            int getPriority() const override;

            /**
             * @brief Get the pointer to the function _init.
             * Note that this function can be nullptr.
             *
             * @return init_t
             */
            init_t getInit() const noexcept override;

            /**
             * @brief Get the pointer to the function _processRay.
             * Note that this function can be nullptr.
             *
             * @return processRay_t
             */
            processRay_t getProcessRay() const noexcept override;

            /**
             * @brief Get the pointer to the function _postProcess.
             * Note that this function can be nullptr.
             *
             * @return postProcess_t
             */
            postProcess_t getPostProcess() const noexcept override;
            const std::string &getName() const noexcept override;
        protected:
            init_t _init = nullptr;
            processRay_t _processRay = nullptr;
            postProcess_t _postProcess = nullptr;
            int _priority;
            std::string _name;
    };

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
            std::vector<processRay_t> getProcessRayFunctions() const;

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
            const std::vector<Plugin> &getPlugins() const noexcept;
        private:

            DLLoader _loader;
            std::vector<Plugin> _plugins;
    };
}

#endif // PLUGINMANAGER_HPP
