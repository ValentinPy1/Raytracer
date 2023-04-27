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
    #include "geometry.hpp"

namespace render {
    class IMaterial {
        public:
            virtual float getProperty(const std::string &name) const = 0;
            virtual void getColor(int &r, int &g, int &b, geo::vec3 point) const = 0;
    };

    // class AMaterial : public IMaterial {
    //     public:
    //         AMaterial() = default;
    //         ~AMaterial() = default;
    //         float getProperty(const std::string &name) const override;
    //     protected:
    //         std::map<std::string, float> _properties;
    // };
}

#endif /* CD083D2B_2A78_484C_BB7C_288689F106B1 */
