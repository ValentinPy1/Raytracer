/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Bloom.process.v.hpp
*/

#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Plugin.hpp"
#include "Camera.hpp"
#include "Plugin.hpp"
#include "Renderer.hpp"
#include "Ray.hpp"

namespace vanille
{
    /**
     * @brief A plugin that applies a bloom effect to the scene as a post
     * process treatement. The algorithm consists in blurring the image
     * with a gaussian kernel, then applying a threshold to the blurred image
     * to turn it black and white, then blurring the black and white image to
     * make it bleed. Finally, the blurred black and white image is added to
     * the original image.
     *
     */
    class Bloom_v : public render::Plugin {
        public:
            Bloom_v();
            ~Bloom_v() = default;
        private:
            /**
             * @brief Applies the bloom effect to the image. This function is
             * called by the _postProcess function of the Plugin base class.
             *
             * @param img
             * @return sf::Image&
             */
            sf::Image &applyBloom(sf::Image &img);

            /**
             * @brief Applies a gaussian blur to the image.
             *
             * @param img
             * @return sf::Image
             */
            sf::Image applyGaussianBlur(const sf::Image &img);

            /**
             * @brief Get each color values of the image in order to match the
             * convolution kernel.
             *
             * @param c
             * @param img
             * @param x
             * @param y
             */
            void setKernel(sf::Color c[3][3], const sf::Image &img, unsigned int x, unsigned int y);

            float _threshold = 0.5f;
            unsigned int _intensity = 1;
            std::array<std::array<float, 3>, 3> _gaussKernel = {
                {{0.075, 0.124, 0.075},
                {0.124, 0.204, 0.124},
                {0.075, 0.124, 0.075}}
            };
    };
} // namespace vanille
