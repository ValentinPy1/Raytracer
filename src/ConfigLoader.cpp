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

    void ConfigLoader::loadPlugins(Renderer &rdr)
    {
        const libconfig::Setting &plugins = _cfg.lookup("plugins");
        //get value of wrapper

        std::string wrapper;
        plugins.lookupValue("wrapper", wrapper);
        const libconfig::Setting &pluginsValue = plugins.lookup("plugins");
        std::cout << "Wrapper: " << wrapper << std::endl;
        for (int i = 0; i < pluginsValue.getLength(); i++) {
            const libconfig::Setting &plugin = pluginsValue[i];
            std::string path;
            std::string name;
            plugin.lookupValue("path", path);
            plugin.lookupValue("name", name);
            path = path + _mode + ".so";
            std::cout << "path: " << path << std::endl;
            _pluginManager.loadPlugin(path, name);
        }
    }

    void ConfigLoader::loadConfigFile(std::string path, Renderer &rdr)
    {
        try {
            _cfg.readFile(path.c_str());
        } catch (std::exception &e) {
            std::cout << "ERROR CHACAL" << std::endl;
            std::cerr << e.what() << std::endl;
            exit(84);
        }
        const libconfig::Setting &extention = _cfg.lookup("extensions");
        // const libconfig::Setting &mode = _cfg.lookupValue("mode", mode);
        extention.lookupValue("mode", _mode);

        loadCamera(rdr);
        loadPlugins(rdr);
        // libconfig::Setting &objects = _cfg.lookup("objects");
        // std::cout << "Objects: " << objects.getLength() << std::endl;

    }
}