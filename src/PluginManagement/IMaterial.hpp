/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** IMaterial.hpp
*/

#ifndef CD083D2B_2A78_484C_BB7C_288689F106B1
    #define CD083D2B_2A78_484C_BB7C_288689F106B1
    #include <string>
    #include <map>
    #include <libconfig.h++>
    #include "PluginManager.hpp"
    #include "geometry.hpp"

namespace render {
    class Entity;
    class IMaterial {
        public:
            /**
             * @brief Returns a physical property of the material from its name.
             * If the name is not associated with any property, returns 0.
             *
             * @param name
             * @return float
             */
            virtual float getProperty(const std::string &name) const = 0;

            /**
             * @brief The self init method will be called once by the
             * config loader to load the setting called "args" in the config.
             * This setting will contain plugin specific arguments that will
             * be used by the plugin itself to initialize its internal state.
             *
            */
            virtual void selfInit(libconfig::Setting &setting) = 0;

            /**
             * @brief Get the Color object by setting its RGB values in place
             * in the provided references.
             *
             * @param r
             * @param g
             * @param b
             * @param point
             */
            virtual void getColor(int &r, int &g, int &b, geo::vec3 point) const = 0;
    };
}

#endif /* CD083D2B_2A78_484C_BB7C_288689F106B1 */
