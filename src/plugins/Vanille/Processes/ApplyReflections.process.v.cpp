/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ApplyReflections.v.hpp
*/

#include <string>
#include "Renderer.hpp"
#include "Ray.hpp"
#include "Wrapper.hpp"
#include "IPlugin.hpp"
#include "Camera.hpp"
#include "Wrapper.v.hpp"

extern "C" {
    render::IPlugin *entryPoint()
    {
        return new render::Plugin(
            [](render::Renderer &rdr) {
                unsigned int reflectionDepth = rdr.getCamera()->getRecursionDepth();
                auto wrapper = dynamic_cast<vanille::Wrapper_v *>(&(rdr.getWrapper()));
                if (wrapper == nullptr)
                    throw render::Renderer::IncompatibleException(render::red + "[ERROR] " + render::no_color + "ApplyReflections.process.v is not compatible with the current wrapper");
                for (auto &r : rdr.getCamera()->getRays()) {
                    r.setRecursionParameter("reflectionDepth", reflectionDepth);
                }
            },

            [](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
                if (ray.getRecursionParameter("reflectionDepth") <= 0)
                    return ray;
                if (!ray.hasIntersections()) {
                    ray.setColor(ray.blendLerp(sf::Color::Black, 0.1f));
                    return ray;
                }
                auto intersection = ray.getIntersections()[0];
                float reflectivity = intersection.getInterceptee()->getMaterial()->getProperty("reflectivity");
                if (reflectivity <= 0)
                    return ray;
                sf::Vector3f normal = intersection.getNormal();
                sf::Vector3f direction = ray.getDirection();
                sf::Vector3f reflection = direction - 2.0f * normal * (normal.x * direction.x + normal.y * direction.y + normal.z * direction.z);
                sf::Vector3f origin = intersection.getPoint() + reflection * 0.1f;

                render::Ray newRay(origin, reflection, ray.getRecursionParameter("reflectionDepth") - 1);
                auto recParams = ray.getAllRecursionParameters();
                for (auto &p : recParams) {
                    newRay.setRecursionParameter(p.first, p.second);
                }
                newRay.setRecursionParameter("reflectionDepth", ray.getRecursionParameter("reflectionDepth") - 1);
                dynamic_cast<vanille::Wrapper_v *>(&(rdr.getWrapper()))->processRay(newRay, rdr);
                sf::Color reflColor = newRay.getColor();
                reflColor = (sf::Color) {
                    static_cast<sf::Uint8>(reflColor.r),
                    static_cast<sf::Uint8>(reflColor.g),
                    static_cast<sf::Uint8>(reflColor.b)
                };
                // ray.setColor(ray.blendAdd(reflColor));
                ray.setColor(ray.blendLerp(reflColor, reflectivity));
                // ray.setColor(ray.blendMultiply(reflColor));
                return ray;
            },

            nullptr,
            10000,
            "applyReflections"
        );
    }
}
