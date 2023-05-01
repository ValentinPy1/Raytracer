/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ILight.hpp
*/

#ifndef E899917E_04EC_4B05_A236_1D5E4B127BAF
    #define E899917E_04EC_4B05_A236_1D5E4B127BAF
    #include <libconfig.h++>
    #include "Renderer.hpp"

namespace render
{
    /**
     * @brief Interface for lights. In the config file, in order to create a light object,
     * you need to specify the type of the light (by specifying which base plugin to use)
     * and the parameters of the light. The exact parameters may depend on which plugin is used.
     *
     * A light does not need to inherit from the Plugin class, but it may avoid a segfault
     * if somebody tries to load it as a plugin.
     *
     */
    class ILight {
        public:
        virtual ~ILight() = default;

        /**
         * @brief This function is called by the config loader. Each light should
         * initialize itself with the parameters given in the config file, and throw an exception
         * if the parameters are invalid.
         *
         * @param setting
         */
        virtual void selfInit(const libconfig::Setting &setting) = 0;
        /**
         * @brief This function should update the color of the ray depending on
         * the type of the light. The ray should be updated in place.
         *
         * @param ray
         * @param rdr
         */
        virtual void sample(Ray &ray, const Renderer &rdr) = 0;
    };
} // namespace render


#endif /* E899917E_04EC_4B05_A236_1D5E4B127BAF */
