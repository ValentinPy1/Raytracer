/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Renderer.cpp
*/

#include <iostream>
#include <cmath>
#include <functional>
#include "Sphere.hpp"
#include "Pipeline.hpp"
#include "Plane.hpp"
#include "Ray.hpp"
#include "operations.hpp"

#define max(a, b) (((a > b) ? a : b))

namespace render {
    Renderer::Renderer(int lightSamples, int imSide, int focalPoint)
        : _camera(-focalPoint, imSide, imSide, sf::Vector3f(0, 0, 0), sf::Vector3f(90, 0, 0)), _lightSamples(lightSamples)
    {
        setupPipeline();
        std::cout << "renderer created" << std::endl;
        _logs.log("Renderer created");
        _logs.log("Camera set to (" +
            std::to_string(_camera.getPosition().x) + ", " +
            std::to_string(_camera.getPosition().y) + ", " +
            std::to_string(_camera.getPosition().z) + ")");
        _logs.log("Camera is rotated by (" +
            std::to_string(_camera.getRotation().x) + ", " +
            std::to_string(_camera.getRotation().y) + ", " +
            std::to_string(_camera.getRotation().z) + ")");
        _logs.log("Camera focal point is (" +
            std::to_string(_camera.getFocalPoint().x) + ", " +
            std::to_string(_camera.getFocalPoint().y) + ", " +
            std::to_string(_camera.getFocalPoint().z) + ")");
        _logs.log("Deduced camera direction is (" +
            std::to_string(Ray::normalize(_camera.getFocalPoint() - _camera.getPosition()).x) + ", " +
            std::to_string(Ray::normalize(_camera.getFocalPoint() - _camera.getPosition()).y) + ", " +
            std::to_string(Ray::normalize(_camera.getFocalPoint() - _camera.getPosition()).z) + ")");
    }

    void Renderer::setupPipeline()
    {
        _pipeline.push_back([](__attribute__((unused)) render::Ray &self, Renderer &rdr, render::Ray &ray)->render::Ray &{
            return ray.findIntersections(rdr);
        });
        _pipeline.push_back([](__attribute__((unused)) render::Ray &self, Renderer &rdr, render::Ray &ray)->render::Ray &{
            return ray.applyLighting(rdr);
        });
    }

    std::vector<std::shared_ptr<render::IObject>> Renderer::getObjects() const
    {
        return _objects;
    }

    Camera &Renderer::getCamera()
    {
        return _camera;
    }

    void Renderer::loadScene()
    {
        // _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(-20, 0, 0), 20, sf::Color::Red));
        // _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(-40, 10, 25), 10, sf::Color::Blue));
        // _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(10, 5, 10), 5, sf::Color::Red));
        // addLight(Light({40, 10, 20}, sf::Color::White, 0.6));

        // _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(-20, -10, 0), 8, sf::Color::Red));
        // _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(-20, -10, 0) / 2, 2, sf::Color::Yellow));

        _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(-10, 5, -5), 4, sf::Color::Yellow));
        _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(0, 10, -7), 4, sf::Color::Blue));
        _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(0, 20, -15), 9, sf::Color::Red));
        // _objects.push_back(std::make_shared<Sphere>(sf::Vector3f(0, 5, -10), 4, sf::Color::Blue));
        _objects.push_back(std::make_shared<Plane>(sf::Vector3f(0, 0, 10), sf::Vector3f(0, 0, 1), sf::Color::Green));
        addLight(Light({0, 5, -20}, sf::Color::White, 1, 10, _lightSamples));
    }

    void Renderer::showProgressBar(int total, std::string message)
    {
        int barWidth = 70;
        ++_progress;
        std::cout << message << " [";
        int pos = barWidth * _progress / total;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(_progress * 100.0 / total) << "%\r";
        std::cout.flush();
    }

    void Renderer::updatePixelLine(int i)
    {
        auto rays = _camera.getRays();
        for (unsigned int j = 0; j < _camera.getCaptor().getSize().y; j++) {
            sf::Color tmp = rays[i * _camera.getCaptor().getSize().y + j].cast(*this);
            {
                std::lock_guard<std::mutex> lock(_mutex);
                _camera.getCaptor().setPixel(i, j, tmp);
                showProgressBar(_camera.getCaptor().getSize().x * _camera.getCaptor().getSize().y, "Rendering scene");
            }
        }
    }

    void Renderer::render()
    {
        std::vector<std::thread> threads;
        _logs.log("Rendering scene...");
        size_t k = 0;
        auto rays = _camera.getRays();
        for (unsigned int i = 0; i < _camera.getCaptor().getSize().x; i++) {
            while (threads.size() > std::thread::hardware_concurrency() / 2) {
                threads[0].join();
                threads.erase(threads.begin());
            }
            threads.push_back(std::thread(&Renderer::updatePixelLine, this, i));
        }

        for (auto &thread : threads)
            thread.join();

        _logs.log("Scene rendered, saving picture...");
        _camera.getCaptor().saveToFile("rendered.png");
        _logs.log("Picture saved");
    }

    void Renderer::setAmbientLight(const sf::Color &color)
    {
        _ambientLight = color;
    }

    sf::Color Renderer::getAmbientLight() const
    {
        return _ambientLight;
    }

    void Renderer::addLight(const Light &light)
    {
        _lights.push_back(light);
    }

    std::vector<Light> Renderer::getLights() const
    {
        return _lights;
    }

    void Renderer::addLights(const std::vector<Light> &lights)
    {
        for (auto light : lights)
            addLight(light);
    }
}
