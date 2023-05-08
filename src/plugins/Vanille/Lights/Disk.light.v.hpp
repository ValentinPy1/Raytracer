/*
** EPITECH PROJECT, 2022
** ray
** File description:
** DiskLight.v.hpp
*/

#ifndef DDAC58D7_C0F4_4F98_9151_2D32C5D2A45C
    #define DDAC58D7_C0F4_4F98_9151_2D32C5D2A45C

#include <libconfig.h++>
#include "Ray.hpp"
#include "Renderer.hpp"
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
     *    name = "yes yes yes";
     *    type = "DiskLight.light";
     *    args = {
     *          color: (r = 255; g = 255; b =255;);
                position: (x = 0; y = 0; z = 0;);
                radius: 10.0;
                applyMode: "BlinnPhong";
                shadowSamples: 10;
            };
     * };
     * ```
     *
     */
    class DiskLight : public render::ILight {
        public:
            DiskLight() = default;
            ~DiskLight() = default;
            void sample(render::Ray &ray, const render::Renderer &rdr) override;
            void selfInit(const libconfig::Setting &setting) override;
        private:
            sf::Color sampleHardLight(render::Ray &ray, const render::Renderer &rdr, const sf::Vector3f &lightpos);
            sf::Color averageSamples(std::vector<sf::Color> &samples);
            bool pointIsShadowed(const render::Renderer &rdr, const sf::Vector3f &intersection, const sf::Vector3f &lightpos);

            sf::Color _color;
            sf::Vector3f _position;
            sf::Vector3f _rotation;
            std::string _applyMode;
            int _nSamples;
            float _radius;
            float _intensity;
            render::LightModel _lightModel;

    };
}

#endif /* DDAC58D7_C0F4_4F98_9151_2D32C5D2A45C */
