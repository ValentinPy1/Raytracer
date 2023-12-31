/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Camera.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <random>
#include "Camera.hpp"
#include "Ray.hpp"

namespace render {

    Camera::Camera(float focalPoint, int captorWidth, int captorHeight,
        const sf::Vector3f &position, const sf::Vector3f &rotation, unsigned int recursionDepth)
        : _position(position), _rotation(rotation), _recursionDepth(recursionDepth)
    {
        _focalPoint = computeFocalPoint(focalPoint);
        _focalDistance = -focalPoint;
        _captor.create(captorWidth, captorHeight, sf::Color::Black);

        setPosition(position);
        setRotation(rotation);

        generateRays();
    }

    void Camera::generateRays()
    {
        int captorWidth = _captor.getSize().x;
        int captorHeight = _captor.getSize().y;
        float pixHeight = (float) _captorSize.y / (float) captorHeight * scale;
        float pixWidth = (float) _captorSize.x / (float) captorWidth * scale;

        for (int x = -captorWidth / 2.0f; x < captorWidth / 2.0f; x++) {
            for (int y = -captorHeight / 2.0f; y < captorHeight / 2.0f; y++) {
                sf::Vector3f direction = Ray::normalize(sf::Vector3f(
                    (float) x * pixWidth,
                    (float) y * pixHeight,
                    _focalDistance
                ));
                _rays.emplace_back(_focalPoint, direction, _recursionDepth);
                // std::cerr << direction.x << " " << direction.y << " " << direction.z << " " << _focalPoint.x << " " << _focalPoint.y << " " << _focalPoint.z << std::endl;
            }
        }
    }

    float Camera::getFocalDistance() const
    {
        return -_focalDistance;
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

    std::vector<render::Ray> Camera::getRays() const
    {
        return _rays;
    }

    std::vector<render::Ray> &Camera::getRays()
    {
        return _rays;
    }

    void Camera::setFocalPoint(float focalPoint)
    {
        _focalPoint = computeFocalPoint(focalPoint);
        _rays.clear();
        generateRays();
    }

    void Camera::setCaptorSize(const sf::Vector2i &captorSize)
    {
        _captorSize = captorSize;
        _captor.create(captorSize.x, captorSize.y, sf::Color::Black);
        _rays.clear();
        generateRays();
    }

    void Camera::setScale(float scale)
    {
        Camera::scale = scale;
        _rays.clear();
        generateRays();
    }

    unsigned int Camera::getRecursionDepth() const
    {
        return _recursionDepth;
    }

    void Camera::setCaptor(sf::Image &captor)
    {
        _captor = captor;
    }



    void Camera::setPosition(const sf::Vector3f &position)
    {
        _position = position;

        for (auto& ray : _rays) {
            ray.setOrigin(_position);
        }
    }

    void Camera::setRotation(const sf::Vector3f &rotation)
    {
        _rotation = rotation;

        for (auto& ray : _rays) {
            ray.setDirection(Ray::rotateVector(ray.getDirection(), _rotation));
        }
    }

}
