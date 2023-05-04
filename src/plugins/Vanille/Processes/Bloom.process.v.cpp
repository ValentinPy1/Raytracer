/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Bloom.process.v.cpp
*/

#include "Bloom.process.v.hpp"
#include <memory>

// namespace vanille {
// Bloom_v::Bloom_v() :
//     render::Plugin(
//         nullptr,
//         nullptr,
//         nullptr,
//         10200,
//         "bloom"
//     )
//     {
//         _postProcess = [this](render::Renderer &rdr) {
//             sf::Image img = rdr.getCamera()->getCaptor();
//             rdr.getCamera()->setCaptor(applyBloom(img));
//         };
//         _gaussianKernel = std::shared_ptr<ConvolutionKernel<3>>(new ConvolutionKernel<3>({
//             std::array<float, 3>{0.075, 0.125, 0.075},
//             std::array<float, 3>{0.125, 0.204, 0.125},
//             std::array<float, 3>{0.075, 0.125, 0.075}
//         }));
//     }

//     sf::Image &Bloom_v::applyBloom(sf::Image &img)
//     {
//         sf::Image blurred = img;
//         std::cout << "applying gaussian blur" << std::endl;
//         for (int i = 0; i < _intensity; ++i)
//             blurred = applyGaussianBlur(blurred);
//         std::cout << "applying threshold" << std::endl;
//         sf::Image thresholded = blurred;
//         float tmp = 0;
//         sf::Color tmpColor(sf::Color::Black);
//         for (unsigned int x = 0; x < img.getSize().x; x++)
//             for (unsigned int y = 0; y < img.getSize().y; y++) {
//                 tmpColor = blurred.getPixel(x, y);
//                 tmp = tmpColor.r + tmpColor.g + tmpColor.b;
//                 tmp /= 3.0f;
//                 tmp /= 255.0f;
//                 thresholded.setPixel(x, y, tmp > _threshold ? sf::Color::White : sf::Color::Black);
//             }

//         for (int i = 0; i < _intensity; ++i)
//             thresholded = applyGaussianBlur(thresholded);

//         for (unsigned int x = 0; x < img.getSize().x; x++)
//             for (unsigned int y = 0; y < img.getSize().y; y++) {
//                 img.setPixel(x, y, img.getPixel(x, y) + thresholded.getPixel(x, y));
//             }
//         return img;
//     }

//     sf::Image Bloom_v::applyGaussianBlur(const sf::Image &img)
//     {
//         sf::Image blurred = img;
//         // #pragma clang loop vectorize(assume_safety)
//         for (unsigned int x = 0; x < img.getSize().x; x++)
//             for (unsigned int y = 0; y < img.getSize().y; y++)
//                 blurred.setPixel(x, y, _gaussianKernel->getWeightedAverage(img, x, y));
//         return blurred;
//     }
// }

namespace vanille {
    Bloom_v::Bloom_v() {
        _postProcess = [this](render::Renderer &rdr) {
            sf::Image img = rdr.getCamera()->getCaptor();
            rdr.getCamera()->setCaptor(applyBloom(img));
        };
    }

    void Bloom_v::setKernel(sf::Color c[3][3], const sf::Image &img, unsigned int i, unsigned int j)
    {
        for (int x = -1; x < 2; x++)
            for (int y = -1; y < 2; y++) {
                if (i + x < 0 || j + y < 0 || i + x >= img.getSize().x || j + y >= img.getSize().y)
                    c[x + 1][y + 1] = sf::Color::Black;
                else
                    c[x + 1][y + 1] = img.getPixel(i + x, j + y);
            }
    }

    sf::Image Bloom_v::applyGaussianBlur(const sf::Image &img) {
        sf::Image blurred = img;
        sf::Color c[3][3];
        sf::Color tmp;

        for (unsigned int x = 0; x < img.getSize().x; x++)
            for (unsigned int y = 0; y < img.getSize().y; y++) {
                setKernel(c, img, x, y);
                tmp.r = _gaussKernel[0][0] * c[0][0].r + _gaussKernel[0][1] * c[0][1].r + _gaussKernel[0][2] * c[0][2].r +
                        _gaussKernel[1][0] * c[1][0].r + _gaussKernel[1][1] * c[1][1].r + _gaussKernel[1][2] * c[1][2].r +
                        _gaussKernel[2][0] * c[2][0].r + _gaussKernel[2][1] * c[2][1].r + _gaussKernel[2][2] * c[2][2].r;
                tmp.g = _gaussKernel[0][0] * c[0][0].g + _gaussKernel[0][1] * c[0][1].g + _gaussKernel[0][2] * c[0][2].g +
                        _gaussKernel[1][0] * c[1][0].g + _gaussKernel[1][1] * c[1][1].g + _gaussKernel[1][2] * c[1][2].g +
                        _gaussKernel[2][0] * c[2][0].g + _gaussKernel[2][1] * c[2][1].g + _gaussKernel[2][2] * c[2][2].g;
                tmp.b = _gaussKernel[0][0] * c[0][0].b + _gaussKernel[0][1] * c[0][1].b + _gaussKernel[0][2] * c[0][2].b +
                        _gaussKernel[1][0] * c[1][0].b + _gaussKernel[1][1] * c[1][1].b + _gaussKernel[1][2] * c[1][2].b +
                        _gaussKernel[2][0] * c[2][0].b + _gaussKernel[2][1] * c[2][1].b + _gaussKernel[2][2] * c[2][2].b;
                blurred.setPixel(x, y, tmp);
            }
        return blurred;
    }

    sf::Image &Bloom_v::applyBloom(sf::Image &img) {
        sf::Image blurred = img;
        for (char i = 0; i < _intensity; ++i) {
            blurred = applyGaussianBlur(blurred);
        }
        sf::Image thresholded = blurred;
        float tmp = 0;
        sf::Color tmpColor(sf::Color::Black);
        for (size_t i = 0; i < thresholded.getSize().x; ++i) {
            for (size_t j = 0; j < thresholded.getSize().y; ++j) {
                tmpColor = blurred.getPixel(i, j);
                tmp = tmpColor.r + tmpColor.g + tmpColor.b;
                tmp /= 3.0f;
                tmp /= 255.0f;
                thresholded.setPixel(i, j, tmp > _threshold ? sf::Color::White : sf::Color::Black);
            }
        }
        for (char i = 0; i < _intensity; ++i) {
            thresholded = applyGaussianBlur(thresholded);
        }
        for (size_t i = 0; i < img.getSize().x; ++i) {
            for (size_t j = 0; j < img.getSize().y; ++j) {
                img.setPixel(i, j, img.getPixel(i, j) + thresholded.getPixel(i, j));
            }
        }
        return img;
    }
}

extern "C" {
    render::Plugin *entryPoint() {
        return new vanille::Bloom_v();
    }
}
