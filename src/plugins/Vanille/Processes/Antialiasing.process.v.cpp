/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AntiAliasing.process.v.cpp
*/

#include "Renderer.hpp"
#include "Camera.hpp"
#include "Plugin.hpp"
#include "Wrapper.v.hpp"

// extern "C" {
//     render::Plugin *entryPoint()
//     {
//         return new render::Plugin(
//             // [](render::Renderer &rdr) {
//             //     render::Camera &camera = *rdr.getCamera();
//             //     sf::Image &captor = camera.getCaptor();
//             //     camera.setCaptorSize({captor.getSize().x * 2, captor.getSize().y * 2});
//             // },

//             [](render::Renderer & rdr) {
//                 if (dynamic_cast<vanille::Wrapper_v *>(&rdr.getWrapper()) == nullptr)
//                     throw render::Renderer::IncompatibleException("Antialiasing not compatible with current wrapper");
//                 render::Camera &camera = *rdr.getCamera();
//                 for (auto &r : camera.getRays()) {
//                     r.setRecursionParameter("antialiasingSample", 1);
//                 }
//             },

//             [](render::Ray &ray, const render::Renderer &rdr) -> render::Ray &{
//                 auto stop = ray.getRecursionParameter("antialiasingSample");
//                 if (stop <= 0)
//                     return ray;

//                 std::vector<sf::Color> colors;
//                 for (int i = 0; i < 10; ++i) {
//                     auto direction = (render::Ray::normalize(ray.getDirection() + sf::Vector3f(
//                         (float) (rand() % 100) / 100.0f - 0.5f,
//                         (float) (rand() % 100) / 100.0f - 0.5f,
//                         (float) (rand() % 100) / 100.0f - 0.5f
//                     )));
//                     render::Ray newRay(newRay.getOrigin(), direction);
//                     newRay.setRecursionParameter("antialiasingSample", stop - 1);
//                     newRay.setRecursionParameter("recursionDepth", ray.getRecursionParameter("recursionDepth")); // TODO copy all rec params
//                     colors.push_back(dynamic_cast<vanille::Wrapper_v &>(rdr.getWrapper()).processRay(newRay, rdr));
//                 }
//                 sf::Color average = sf::Color::Black;
//                 for (auto &c : colors) {
//                     average += c;
//                 }
//                 average.r /= colors.size();
//                 average.g /= colors.size();
//                 average.b /= colors.size();
//                 ray.setColor(average);
//                     return ray;
//             },
//             nullptr,
//             // [](render::Renderer &rdr) {
//             //     render::Camera &camera = *rdr.getCamera();
//             //     sf::Image &captor = camera.getCaptor();
//             //     sf::Image newCaptor;
//             //     newCaptor.create(captor.getSize().x / 2, captor.getSize().y / 2);
//             //     for (unsigned int y = 0; y < newCaptor.getSize().y; y++) {
//             //         for (unsigned int x = 0; x < newCaptor.getSize().x; x++) {
//             //             sf::Color color = captor.getPixel(x * 2, y * 2);
//             //             color += captor.getPixel(x * 2 + 1, y * 2);
//             //             color += captor.getPixel(x * 2, y * 2 + 1);
//             //             color += captor.getPixel(x * 2 + 1, y * 2 + 1);
//             //             color = sf::Color(color.r / 4, color.g / 4, color.b / 4);
//             //             newCaptor.setPixel(x, y, color);
//             //         }
//             //     }
//             //     camera.setCaptor(newCaptor);
//             // },
//             0,
//             "AntiAliasing"
//         );
//     }
// }

extern "C" {
    render::Plugin *entryPoint() {
        return new render::Plugin(
            [](render::Renderer &rdr) {
                std::shared_ptr<render::Camera> camera = rdr.getCamera();
                std::map<std::string, int> params = camera->getRays()[0].getAllRecursionParameters();
                rdr.setCamera(std::make_shared<render::Camera>(
                    camera->getFocalDistance(),
                    camera->getCaptor().getSize().x * 2,
                    camera->getCaptor().getSize().y * 2,
                    camera->getPosition(),
                    camera->getRotation(),
                    camera->getRecursionDepth()
                ));
                for (auto &r : camera->getRays()) {
                    for (auto &p : params) {
                        r.setRecursionParameter(p.first, p.second);
                    }
                }
            },
            nullptr,
            [](render::Renderer &rdr) {
                std::shared_ptr<render::Camera> camera = rdr.getCamera();
                sf::Image &captor = camera->getCaptor();
                sf::Image newCaptor;
                newCaptor.create(captor.getSize().x / 2, captor.getSize().y / 2);
                for (unsigned int y = 0; y < newCaptor.getSize().y; y++) {
                    for (unsigned int x = 0; x < newCaptor.getSize().x; x++) {
                        sf::Color color = captor.getPixel(x * 2, y * 2);
                        color += captor.getPixel(x * 2 + 1, y * 2);
                        color += captor.getPixel(x * 2, y * 2 + 1);
                        color += captor.getPixel(x * 2 + 1, y * 2 + 1);
                        color = sf::Color(color.r / 4, color.g / 4, color.b / 4);
                        newCaptor.setPixel(x, y, color);
                    }
                }
                camera->setCaptor(newCaptor);
            },
            0,
            "AntiAliasing"
        );
    }
}
