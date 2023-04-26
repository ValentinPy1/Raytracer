    /*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.cpp
*/

#ifndef WRAPPER_HPP
    #define WRAPPER_HPP

namespace render {
    class Renderer;

    /**
     * @brief Interface for the wrapper. A wrapper is a plugin that is responsible
     * for managing the other plugins and the rendering process.
     *
     * Note that the IWrapper interface does not inherit from Plugin. Classes that
     * implement IWrapper will be loaded using the plugin manager however, so they
     * must inherit from the Plugin class as well as IWrapper.
     *
     */
    class IWrapper {
        public:
            ~IWrapper() = default;
            virtual void run(render::Renderer &rdr) = 0;
    };
}

#endif // WRAPPER_HPP
