/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Directional.light.v.hpp
*/

#ifndef C0A9BDC3_26C9_45F7_BDE9_E67C449E0EA3
    #define C0A9BDC3_26C9_45F7_BDE9_E67C449E0EA3
    #include <SFML/Graphics.hpp>
    #include "ILight.hpp"
    #include "LightModel.hpp"
    #include "Ray.hpp"

namespace vanille {

    /**
     * @brief A directional light is a light that comes from a single direction.
     * it can be used to simulate the sun.
     *
     * How to use in the config file:
     *
     * ```config
     * light: {
     *    type: "Directional.light";
     *    color: (r = 255; g = 255; b =255;);
     *    direction: (x = 0; y = 0; z = 0;);
     *    applyMode: "BlinnPhong";
     *    shadowSamples: 10;
     * };
     * ```
     *
     */
    class DirectionalLight_v : public render::ILight {
        public:
            DirectionalLight_v() = default;
            void sample(render::Ray &ray, const render::Renderer &rdr) override;
            void selfInit(const libconfig::Setting &setting) override;
        private:
            void castShadow(sf::Color &color, render::Intersection &intersect, const render::Renderer &rdr);

            sf::Color _color;
            sf::Vector3f _direction;
            std::string _applyMode;
            int _shadowSamples;
    };
}


#endif /* C0A9BDC3_26C9_45F7_BDE9_E67C449E0EA3 */
