/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ITexture.hpp
*/

#ifndef CD083D2B_2A78_484C_BB7C_288689F106B1
    #define CD083D2B_2A78_484C_BB7C_288689F106B1
    #include <string>

namespace render {
    class ITexture {
        public:
            virtual float getProperty(const std::string &name) const = 0;
    };
}

#endif /* CD083D2B_2A78_484C_BB7C_288689F106B1 */
