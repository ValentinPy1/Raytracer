/*
** EPITECH PROJECT, 2022
** ray
** File description:
** applyTransparency.process.v.cpp
*/

#include <cmath>
#include "Renderer.hpp"
#include "Ray.hpp"
#include "Wrapper.hpp"
#include "IPlugin.hpp"
#include "Camera.hpp"
#include "Wrapper.v.hpp"
#include "operations.hpp"

extern "C" {
    render::IPlugin *entryPoint()
    {
        return new render::Plugin(
            [](render::Renderer &rdr) {
                unsigned int refractionDepth = rdr.getCamera()->getRecursionDepth();
                for (auto &r : rdr.getCamera()->getRays()) {
                    r.setRecursionParameter("refractionDepth", refractionDepth);
                }
            },
            [](render::Ray &ray, const render::Renderer &rdr) -> render::Ray & {
                if (ray.getRecursionParameter("refractionDepth") <= 0 or not ray.hasIntersections())
                    return ray;
                auto intersection = ray.getIntersections()[0];
                float transparency = intersection.getInterceptee()->getMaterial()->getProperty("transparency");
                if (transparency <= 0)
                    return ray;
                sf::Vector3f normal = intersection.getNormal();
                sf::Vector3f direction = ray.getDirection();
                float n1 = 1.0f;
                float n2 = intersection.getInterceptee()->getMaterial()->getProperty("refractionIndex");
                float n = n1 / n2;
                float cosI = render::Ray::normalize(direction) * render::Ray::normalize(normal);
                float sinT2 = n * n * (1.0f - cosI * cosI);
                if (sinT2 > 1.0f)
                    return ray;
                float cosT = std::sqrt(1.0f - sinT2);
                sf::Vector3f refraction = n * direction + (n * cosI - cosT) * normal;
                sf::Vector3f origin = intersection.getPoint() + refraction * 0.1f;
                render::Ray newRay(origin, refraction, ray.getRecursionParameter("refractionDepth") - 1);
                auto recParams = ray.getAllRecursionParameters();
                for (auto &p : recParams) {
                    newRay.setRecursionParameter(p.first, p.second);
                }
                newRay.setRecursionParameter("refractionDepth", ray.getRecursionParameter("refractionDepth") - 1);
                dynamic_cast<vanille::Wrapper_v *>(&(rdr.getWrapper()))->processRay(newRay, rdr);
                sf::Color refrColor = newRay.getColor();
                ray.setColor(ray.blendLerp(refrColor, transparency));
                return ray;
            },
            nullptr,
            10005,
            "applyTransparency"
        );
    }
}

