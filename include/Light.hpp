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

        /**
         * @brief The light class represents a default light source, as a flat
         * disk.
         *
         */
        class Light {
            public:
                Light(
                    const sf::Vector3f &position,
                    const sf::Color &color,
                    const float &intensity = 1,
                    const float &radius = 0,
                    int nSamples = 1);
                ~Light() = default;

                /**
                 * @brief Returns the position of the light in the world.
                 *
                 * @return sf::Vector3f
                 */
                sf::Vector3f getPosition() const;

                /**
                 * @brief Returns the distance between the light and a point.
                 *
                 * @param point
                 * @return float
                 */
                float getDistanceTo(const sf::Vector3f &point);

                /**
                 * @brief Returns the color of the light.
                 *
                 * @return sf::Color
                 */
                sf::Color getColor() const;

                /**
                 * @brief Returns the intensity of the light.
                 *
                 * @return float
                 */
                float getIntensity() const;

                /**
                 * @brief Get the Blinn Phong Color light, that is the
                 * color of a surface exposed to the light using the
                 * Blinn-Phong shading model.
                 *
                 * @param lightDir
                 * @param normal
                 * @param viewDir
                 * @param shininess
                 * @return sf::Color
                 */
                sf::Color getBlinnPhongColor(
                    const sf::Vector3f &lightDir, const sf::Vector3f &normal,
                    const sf::Vector3f &viewDir, float shininess);

                /**
                 * @brief Returns the color of the light at a given point.
                 * If the radius of the light, sampleHardLight will be used
                 * once, which is quite fast. If the radius is greater than 0,
                 * sampleSoftLight will be used, which is slower: _nSamples
                 * samples will be taken randomely in the radius of the
                 * light and averaged to get the final color of the surface.
                 * This produces soft shadows.
                 *
                 * @param ray
                 * @param renderer
                 * @return sf::Color
                 */
                sf::Color sample(Ray &ray, const Renderer &renderer);
            private:
                /**
                 * @brief Returns the color of the light at a given point,
                 * assuming the light is a point light.
                 *
                 * @param ray
                 * @param renderer
                 * @return sf::Color
                 */
                sf::Color sampleHardLight(Ray &ray, const Renderer &renderer);

                /**
                 * @brief Returns the color of the light at a given point,
                 * assuming the light is a disk light. _nSamples samples
                 * will be taken randomely in the radius of the light and
                 * averaged to get the final color of the surface.
                 * This produces soft shadows.
                 * This function is relatively slow.
                 *
                 * @param ray
                 * @param renderer
                 * @return sf::Color
                 */
                sf::Color sampleSoftLight(Ray &ray, const Renderer &renderer);

                /**
                 * @brief Returns the average color of a vector of samples of colors.
                 *
                 * @param samples
                 * @return sf::Color
                 */
                sf::Color averageSamples(std::vector<sf::Color> &samples);

                /**
                 * @brief The position of the light in the world.
                 *
                 */
                sf::Vector3f _position;

                /**
                 * @brief The color of the light.
                 *
                 */
                sf::Color _color;

                /**
                 * @brief The intensity of the light, that is how bright it shines.
                 * Use it to temperate the color.
                 *
                 */
                float _intensity;

                /**
                 * @brief The radius of the light, if it is a disk light.
                 * The greater the radius, the softer the shadows.
                 *
                 */
                float _radius;

                /**
                 * @brief The number of samples to take when sampling the light.
                 * The greater the number, the softer clearer the image, but
                 * it can get very slow.
                 *
                 */
                int _nSamples = 1;
        };

};

#endif // LIGHT_HPP
