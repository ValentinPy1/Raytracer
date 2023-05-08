/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AmbientLight.process.v.hpp
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

            void loadFlatColor(render::Renderer &rdr);
            void loadGradient(render::Renderer &rdr);
            void loadTexture(render::Renderer &rdr);
            void applyColor(render::Ray &ray, const render::Renderer &rdr, sf::Color color);
            void applyFlatColor(render::Ray &ray, const render::Renderer &rdr);
            void applyGradient(render::Ray &ray, const render::Renderer &rdr);
            void applyTexture(render::Ray &ray, const render::Renderer &rdr);
            void applyAmbientLight(render::Ray &ray, const render::Renderer &rdr);

            sf::Vector2u getProjection(sf::Vector3f vector);
            void generateGradient(void);

            private:
                enum class Type {
                    FLAT,
                    GRADIENT,
                    TEXTURE
                };
                Type _type = Type::FLAT;
                sf::Color _color = sf::Color(30, 30, 50);
                std::vector<sf::Color> _gradientColors = {sf::Color(247, 91, 39), sf::Color(125, 185, 232)};
                std::vector<sf::Color> _gradient;
                std::string _texturePath = "";
                sf::Texture _texture;
                sf::Image _image;
    };
}


#endif /* E3F48462_7625_411F_9381_50161120187F */
