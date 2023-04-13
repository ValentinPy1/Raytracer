/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Light.hpp
*/


#ifndef LIGHT_HPP
    #define LIGHT_HPP
    #include <SFML/Graphics.hpp>

namespace render {
        class Ray;
        class Renderer;
        class Light {
            public:
                Light(
                    const sf::Vector3f &position,
                    const sf::Color &color,
                    const float &intensity = 1,
                    const float &radius = 0,
                    int nSamples = 1);
                ~Light() = default;

                sf::Vector3f getPosition() const;
                float getDistanceTo(const sf::Vector3f &point);
                sf::Color getColor() const;
                float getIntensity() const;
                sf::Color getBlinnPhongColor(
                    const sf::Vector3f &lightDir, const sf::Vector3f &normal,
                    const sf::Vector3f &viewDir, float shininess);
                sf::Color sample(Ray &ray, const Renderer &renderer);
            private:
                sf::Color sampleHardLight(Ray &ray, const Renderer &renderer);
                sf::Color sampleSoftLight(Ray &ray, const Renderer &renderer);
                sf::Color averageSamples(std::vector<sf::Color> &samples);
                sf::Vector3f _position;
                sf::Color _color;
                float _intensity;
                float _radius;
                int _nSamples = 1;
        };

};

#endif // LIGHT_HPP
