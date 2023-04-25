/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ConfigLoader.cpp
*/

#include "ConfigLoader.hpp"
#include "Camera.hpp"
#include <fstream>

#include <iostream>
namespace render {
    ConfigLoader::ConfigLoader()
    {
    }

    ConfigLoader::~ConfigLoader()
    {
    }

    void ConfigLoader::loadCamera(Renderer &rdr)
    {
        const libconfig::Setting &cameraSettings = _cfg.lookup("camera");
        int focalPoint;
        int captorWidth;
        int captorHeight;
        sf::Vector3f position;
        sf::Vector3f rotation;

        cameraSettings.lookupValue("focalPoint", focalPoint);
        cameraSettings.lookupValue("captorWidth", captorWidth);
        cameraSettings.lookupValue("captorHeight", captorHeight);
        libconfig::Setting &positionSetting = cameraSettings.lookup("position");
        positionSetting.lookupValue("x", position.x);
        positionSetting.lookupValue("y", position.y);
        positionSetting.lookupValue("z", position.z);
        libconfig::Setting &rotationSetting = cameraSettings.lookup("rotation");
        rotationSetting.lookupValue("x", rotation.x);
        rotationSetting.lookupValue("y", rotation.y);
        rotationSetting.lookupValue("z", rotation.z);

        std::shared_ptr<Camera> cam = std::make_shared<Camera>(
            focalPoint,
            captorWidth,
            captorHeight,
            position,
            rotation
        );
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
            // std::cout << "path: " << path << std::endl;
            _pluginManager.loadPlugin(path, name);
        }
    }

    void ConfigLoader::loadObjects(Renderer &rdr)
    {
        const libconfig::Setting &objects = _cfg.lookup("objects");
        const libconfig::Setting &objectsValue = objects.lookup("objects");
        bool wasError = false;
        for (int i = 0; i < objectsValue.getLength(); i++) {
            std::shared_ptr<Entity> en = std::make_shared<Entity>();
            try {
                libconfig::Setting &args = objectsValue[i].lookup("args");
                libconfig::Setting &primitive = objectsValue[i].lookup("primitive");
                std::string name = primitive;
                name = name + _mode;
                name = _path + name + ".so";
                std::shared_ptr<IPrimitive> obj = std::shared_ptr<IPrimitive>(_loader.loadInstance<IPrimitive>(primitive, name));
                obj->selfInit(args);
                en->setPrimitive(obj);
                // TODO load the texture as well
                rdr.addEntity(en);
            } catch (std::exception &e) {
                wasError = true;
                std::cerr << "Failed to load object: " << e.what() << std::endl;
            }
        }
        if (wasError) {
            char tmp = '\0';
            std::cout << "There has been errors loading the objects. Continue anyway? (y/n)" << std::endl;
            std::cin >> tmp;
            if (tmp != 'y')
                exit(84);
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
        loadObjects(rdr);
        // libconfig::Setting &objects = _cfg.lookup("objects");
        // std::cout << "Objects: " << objects.getLength() << std::endl;

    }
}
