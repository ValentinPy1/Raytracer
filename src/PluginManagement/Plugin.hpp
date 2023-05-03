/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Plugin.hpp
*/

#pragma once

#include "IPlugin.hpp"

namespace render {
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
}
