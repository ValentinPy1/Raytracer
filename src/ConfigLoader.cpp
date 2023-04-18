/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ConfigLoader.cpp
*/

#include "Ray.hpp"
#include "ConfigLoader.hpp"
#include <fstream>

#include "Sphere.hpp"
#include "Plane.hpp"

namespace render {
    ConfigLoader::ConfigLoader()
    {
    }

    ConfigLoader::~ConfigLoader()
    {
    }

    void ConfigLoader::loadCamera(Renderer &rdr)
    {
        Camera camera;
        const libconfig::Setting &cameraSettings = _cfg.lookup("camera");
        int width, height;
        cameraSettings.lookupValue("resolution.width", width);
        cameraSettings.lookupValue("resolution.height", height);
        double fieldOfView;
        cameraSettings.lookupValue("fieldOfView", fieldOfView);

        libconfig::Setting &position = cameraSettings.lookup("position");
        float x, y, z;
        position.lookupValue("x", x);
        position.lookupValue("y", y);
        position.lookupValue("z", z);
        sf::Vector3f pos = sf::Vector3f(x, y, z);

        libconfig::Setting &rotation = cameraSettings.lookup("rotation");
        float rx, ry, rz;
        rotation.lookupValue("x", rx);
        rotation.lookupValue("y", ry);
        rotation.lookupValue("z", rz);
        camera.setPosition(pos);
        rdr.setCamera(camera);
    }

    void ConfigLoader::loadPrimitive(Renderer &rdr)
    {

    }

    void ConfigLoader::loadConfigFile(std::string path, Renderer &rdr)
    {
        try {
            _cfg.readFile(path.c_str());
        } catch (std::exception &e) {
            std::cout << "ERROR CHACAL"<< std::endl;
            std::cerr << e.what() << std::endl;
            exit(84);
        }
        loadCamera(rdr);
        loadPrimitive(rdr);
        // libconfig::Setting &objects = _cfg.lookup("objects");
        // std::cout << "Objects: " << objects.getLength() << std::endl;

    // for (int i = 0; i < objects.getLength(); i++) {
    //     libconfig::Setting &object = objects[i];
    //     std::string type;
    //     object.lookupValue("type", type);
    //     if (type == "sphere") {
    //         libconfig::Setting &position = object.lookup("position");
    //         float x, y, z;
    //         position.lookupValue("x", x);
    //         position.lookupValue("y", y);
    //         position.lookupValue("z", z);
    //         sf::Vector3f pos = sf::Vector3f(x, y, z);
    //         float radius;
    //         object.lookupValue("radius", radius);
    //         std::string color;
    //         object.lookupValue("color", color);
    //         sf::Color col;
    //         if (color == "red")
    //             col = sf::Color::Red;
    //         else if (color == "green")
    //             col = sf::Color::Green;
    //         else if (color == "blue")
    //             col = sf::Color::Blue;
    //         else if (color == "yellow")
    //             col = sf::Color::Yellow;
    //         else if (color == "magenta")
    //             col = sf::Color::Magenta;
    //         else if (color == "cyan")
    //             col = sf::Color::Cyan;
    //         else if (color == "white")
    //             col = sf::Color::White;
    //         else if (color == "black")
    //             col = sf::Color::Black;
    //         else if (color == "transparent")
    //             col = sf::Color::Transparent;
    //         else
    //             col = sf::Color::Black;
    //         rdr.pushObject(std::make_shared<Sphere>(pos, radius, col));
    //     } else if (type == "plane") {
    //         libconfig::Setting &position = object.lookup("position");
    //         float x, y, z;
    //         position.lookupValue("x", x);
    //         position.lookupValue("y", y);
    //         position.lookupValue("z", z);
    //         sf::Vector3f pos = sf::Vector3f(x, y, z);
    //         libconfig::Setting &normal = object.lookup("normal");
    //         float nx, ny, nz;
    //         normal.lookupValue("x", nx);
    //         normal.lookupValue("y", ny);
    //         normal.lookupValue("z", nz);
    //         sf::Vector3f norm = sf::Vector3f(nx, ny, nz);
    //         std::string color;
    //         object.lookupValue("color", color);
    //         sf::Color col;
    //     }

    // rdr.pushObject(std::make_shared<Plane>(sf::Vector3f(0, 0, 10), sf::Vector3f(0, 0, 1), sf::Color::Green));

    }
}