/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Camera.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Render.hpp"
#include "Ray.hpp"

namespace render {

    Camera::Camera(float focalPoint, int captorWidth, int captorHeight,
        const sf::Vector3f &position, const sf::Vector3f &rotation)
        : _position(position), _rotation(rotation)
    {
        float pixHeight = (float) _captorSize.y / (float) captorHeight * scale;
        float pixWidth = (float) _captorSize.x / (float) captorWidth * scale;
        std::ofstream raySave("ray.txt");

        _focalPoint = computeFocalPoint(focalPoint);
        _captor.create(captorWidth, captorHeight, sf::Color::Black);

        for (int w = -captorWidth / 2.0f; w < captorWidth / 2.0f; w++) {
            for (int h = -captorHeight / 2.0f; h < captorHeight / 2.0f; h++) {
                sf::Vector3f direction = Ray::normalize(sf::Vector3f(w * pixWidth, 0, h * pixHeight) - _focalPoint);
                _rays.emplace_back(_focalPoint, direction);

                if (rand() % 1000 < 1)
                    raySave << ("Ray -- (" + std::to_string(_focalPoint.x) + ", " + std::to_string(_focalPoint.y) + ", " + std::to_string(_focalPoint.z) + ") -- ")
                    + ("direction: (" + std::to_string(direction.x) + ", " + std::to_string(direction.y) + ", " + std::to_string(direction.z) + ")\n");
            }
        }
        raySave.close();
    }

    sf::Vector3f Camera::computeFocalPoint(float focalPoint) const
    {
        return render::Ray::rotateVector(sf::Vector3f(0, 0, focalPoint), _rotation)
            + _position;
    }

    sf::Image &Camera::getCaptor()
    {
        return _captor;
    }

    sf::Vector3f Camera::getPosition() const
    {
        return _position;
    }

    sf::Vector3f Camera::getRotation() const
    {
        return _rotation;
    }

    sf::Vector3f Camera::getFocalPoint() const
    {
        return _focalPoint;
    }

    std::vector<render::Ray> &Camera::getRays()
    {
        return _rays;
    }
}
