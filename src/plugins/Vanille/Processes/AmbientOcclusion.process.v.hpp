/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientOcclusion.process.v.hpp
*/

#ifndef E32F2618_AB3F_4D87_BD6F_80AE5A7C4900
    #define E32F2618_AB3F_4D87_BD6F_80AE5A7C4900
    #include "Plugin.hpp"

namespace vanille {
    class AmbientOcclusion_v : public render::Plugin {
        public:
            AmbientOcclusion_v();
        private:
            float _density = 0.005;
            sf::Color _color = sf::Color::White;
    };
}

#endif /* E32F2618_AB3F_4D87_BD6F_80AE5A7C4900 */
