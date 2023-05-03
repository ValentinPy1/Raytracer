/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientLight.v.hpp
*/

#ifndef E3F48462_7625_411F_9381_50161120187F
    #define E3F48462_7625_411F_9381_50161120187F
    #include "Plugin.hpp"
    #include "Ray.hpp"

namespace render {
    class AmbientLight_v : public Plugin {
        public:
            AmbientLight_v();
        private:
            void applyAmbientLight(render::Ray &ray, const render::Renderer &rdr);

            private:
                sf::Color _color = sf::Color(30, 30, 50);
    };
}


#endif /* E3F48462_7625_411F_9381_50161120187F */
