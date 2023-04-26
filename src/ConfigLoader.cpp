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

        cameraSettings.lookupValue("focal", focalPoint);
        libconfig::Setting &captorSetting = cameraSettings.lookup("captor");
        captorSetting.lookupValue("width", captorWidth);
        captorSetting.lookupValue("height", captorHeight);
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
        rdr.setCamera(cam);
    }

    void ConfigLoader::loadPlugins(Renderer &rdr)
    {
        const libconfig::Setting &plugins = _cfg.lookup("plugins");
        //get value of wrapper

        std::string wrapper;
        plugins.lookupValue("wrapper", wrapper);
        try {
            rdr.setWrapper(_loader.loadInstance<IWrapper>("wrapper", wrapper));
            std::cout << render::green << "[INFO] " << render::no_color << "loaded wrapper: " << wrapper << std::endl;
        } catch (const std::exception &e) {
            std::cerr << render::red << "[ERROR] " << render::no_color << "could not load the wrapper: " << e.what() << std::endl;
            exit(84);
        }

        const libconfig::Setting &pluginsValue = plugins.lookup("plugins");
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
                // load the material
                libconfig::Setting &material = objectsValue[i].lookup("material");
                std::string materialName = material;
                materialName = materialName + _mode;
                materialName = _path + materialName + ".so";
                // std::shared_ptr<IMaterial> mat = std::shared_ptr<IMaterial>(_loader.loadInstance<IMaterial>(material, materialName));
                IMaterial *mat = _loader.loadInstance<IMaterial>(material, materialName);
                std::cout << mat << std::endl;
                delete mat;
                std::cout << "mat: " << std::endl;
                // en->setMaterial(mat);
                rdr.addEntity(en);
            } catch (std::exception &e) {
                wasError = true;
                std::cerr << render::red << "[ERROR] " << render::no_color << "Failed to load object: " << e.what() << std::endl;
            }
        }
        if (wasError) {
            char tmp = '\0';
            std::cout << render::blue << "\n[QUESTION] " << render::no_color << "There has been errors loading the objects. Continue anyway? (y/n)" << std::endl;
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
