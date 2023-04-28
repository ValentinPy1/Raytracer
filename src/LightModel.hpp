/*
** EPITECH PROJECT, 2022
** ray
** File description:
** BlinnPhongModel.hpp
*/

#ifndef B2DE25F7_B6F8_4B54_8910_22701F87A22D
    #define B2DE25F7_B6F8_4B54_8910_22701F87A22D
    #include <SFML/Graphics.hpp>
    #include <map>
    #include <string>
    #include "Ray.hpp"

namespace render {

    /**
     * @brief This class is a static class that contains all the light models
     * available to use. One can apply use a light model by calling the function pointer
     * corresponding to the light model, by accessing it through its name in the
     * models map.
     *
     * ```C++
     * sf::Color color = LightModel::models.at("BlinnPhong")(<args>);
     *```
     *
     */
    class LightModel {
        public:
            static sf::Color apply(
                const std::string &S,
                const sf::Color &lightColor,
                const sf::Vector3f lightDirection,
                const sf::Vector3f &surfaceNormal,
                const sf::Vector3f &viewDirection,
                const float lightDistance,
                const float shininess,
                const float intensity
            );
            static sf::Color applyBlinnPhong(
                const sf::Color &lightColor,
                const sf::Vector3f lightDirection,
                const sf::Vector3f &surfaceNormal,
                const sf::Vector3f &viewDirection,
                const float lightDistance,
                const float shininess,
                const float intensity
            );

        typedef decltype(&LightModel::applyBlinnPhong) lightModelApplier_t;
        static const std::map<std::string, lightModelApplier_t> models;
    };

    static const std::map<std::string, LightModel::lightModelApplier_t> models = {
           {"BlinnPhong", &LightModel::applyBlinnPhong}
    };
}

#endif /* B2DE25F7_B6F8_4B54_8910_22701F87A22D */
