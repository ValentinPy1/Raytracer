/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ConfigLoader.cpp
*/

#include <ctime>
#include <fstream>
#include "ConfigLoader.hpp"
#include "Camera.hpp"
#include "geometry.hpp"

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
        unsigned int recursionDepth;

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
        cameraSettings.lookupValue("recursionDepth", recursionDepth);

        std::shared_ptr<Camera> cam = std::shared_ptr<Camera>(
            new Camera(
            focalPoint,
            captorWidth,
            captorHeight,
            position,
            rotation,
            recursionDepth)
        );

        std::cout << render::green << "[INFO] " << render::no_color << "Loaded camera:" << std::endl;
        std::cout << render::green << "\tfocal: " << focalPoint << std::endl;
        std::cout << render::green << "\tcaptor: " << captorWidth << "x" << captorHeight << std::endl;
        std::cout << render::green << "\tposition: (" << position.x << ", " << position.y << ", " << position.z << ")" << render::no_color << std::endl;
        std::cout << render::green << "\trotation: (" << rotation.x << ", " << rotation.y << ", " << rotation.z << ")" << render::no_color << std::endl;

        rdr.setCamera(cam);
    }

    void ConfigLoader::loadPlugins(Renderer &rdr)
    {
        const libconfig::Setting &plugins = _cfg.lookup("plugins");
        //get value of wrapper

        render::PluginManager &pm = rdr.getPluginManager();
        std::string wrapper;
        plugins.lookupValue("wrapper", wrapper);
        try {
            rdr.setWrapper(_loader.loadInstance<IWrapper>("wrapper", wrapper));
            std::cout << render::green << "[INFO] " << render::no_color << "Loaded wrapper: " << wrapper << std::endl;
        } catch (const std::exception &e) {
            std::cerr << render::red << "[ERROR] " << render::no_color << "could not load the wrapper: " << e.what() << std::endl;
            exit(84);
        }

        const libconfig::Setting &pluginsValue = plugins.lookup("plugins");
        bool waserror = false;
        for (int i = 0; i < pluginsValue.getLength(); i++) {
            try {
                const libconfig::Setting &plugin = pluginsValue[i];
                std::string path;
                std::string name;
                plugin.lookupValue("path", path);
                plugin.lookupValue("name", name);
                path = path + _mode + ".so";
                pm.loadPlugin(path, name);
            } catch (const std::exception &e) {
                waserror = true;
                std::cerr << render::red << "[ERROR] " << render::no_color << "could not load the plugin: " << e.what() << std::endl;
            }
        }
        if (waserror) {
            char tmp = '\0';
            std::cout << render::blue << "\n[QUESTION] " << render::no_color << "There has been errors loading the objects. Continue anyway? (y/n)" << std::endl;
            std::cin >> tmp;
            if (tmp != 'y')
                exit(84);
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
                libconfig::Setting &primitive = objectsValue[i].lookup("primitive");
                std::string name;
                primitive.lookupValue("type", name);
                name = "lib" + name + ".primitive" + _mode;
                name = _path + name + ".so";
                libconfig::Setting &args = primitive.lookup("args");
                std::shared_ptr<IPrimitive> obj = std::shared_ptr<IPrimitive>(_loader.loadInstance<IPrimitive>(name, name));
                obj->selfInit(args, en.get());
                en->setPrimitive(obj);
                std::cout << render::green << "[INFO] " << render::no_color << "Loaded primitive: " << name << std::endl;
            } catch (std::exception &e) {
                wasError = true;
                std::cerr << render::red << "[ERROR] " << render::no_color << "Failed to load primitive: " << e.what() << std::endl;
            }
            try {
                libconfig::Setting &material = objectsValue[i].lookup("material");
                std::string materialName;
                material.lookupValue("type", materialName);
                materialName = "lib" + materialName + ".material" + _mode;
                materialName = _path + materialName + ".so";
                libconfig::Setting &materialArgs = material.lookup("args");
                std::shared_ptr<IMaterial>mat = std::shared_ptr<IMaterial>(_loader.loadInstance<IMaterial>(materialName + "_" + std::to_string(clock()), materialName));
                mat->selfInit(materialArgs, en.get());
                en->setMaterial(mat);
                rdr.addEntity(en);
                std::cout << render::green << "[INFO] " << render::no_color << "Loaded material: " << materialName << std::endl;
            } catch (std::exception &e) {
                wasError = true;
                std::cerr << render::red << "[ERROR] " << render::no_color << "Failed to load material: " << e.what() << std::endl;
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

    void ConfigLoader::loadLights(Renderer &rdr)
    {
        const libconfig::Setting &lights = _cfg.lookup("lights");
        const libconfig::Setting &lightsValue = lights.lookup("lights");
        bool wasError = false;
        std::string pathLights;

        lights.lookupValue("path", pathLights);
        for (int i = 0; i < lightsValue.getLength(); ++i) {
            libconfig::Setting &args = lightsValue[i].lookup("args");
            std::string type;
            lightsValue[i].lookupValue("type", type);
            type = pathLights + "lib" + type + ".light" + _mode + ".so";
            std::string name;
            lightsValue[i].lookupValue("name", name);
            try {
                std::shared_ptr<ILight> light = std::shared_ptr<ILight>(_loader.loadInstance<ILight>(name, type));
                light->selfInit(args);
                rdr.addLight(light);
            } catch (std::exception &e) {
                wasError = true;
                std::cerr << render::red << "[ERROR] " << render::no_color << "Failed to load light " << name << ": " << e.what() << std::endl;
            }
        }
        if (wasError) {
            char tmp = '\0';
            std::cout << render::blue << "\n[QUESTION] " << render::no_color << "There has been errors loading the lights. Continue anyway? (y/n)" << std::endl;
            std::cin >> tmp;
            if (tmp != 'y')
                exit(84);
        }
    }

    void ConfigLoader::loadParams(Renderer &rdr)
    {
        try {
            const libconfig::Setting &settings = _cfg.lookup("params");
            const libconfig::Setting &params =
            settings.lookup("params");std::cout << "le maquis" << std::endl;
            rdr.setParams(&params);
        } catch (std::exception &e) {
            std::cout << render::green << "[INFO] " << render::no_color << "No params found, using default values" << std::endl;
        }

    }

    void ConfigLoader::loadConfigFile(std::string path, Renderer &rdr)
    {
        try {
            _cfg.readFile(path.c_str());
        } catch (std::exception &e) {
            std::cerr << render::red << "[ERROR] " << render::no_color << "Failed to load config file: " << e.what() << std::endl;
            exit(84);
        }
        const libconfig::Setting &extention = _cfg.lookup("extensions");
        // const libconfig::Setting &mode = _cfg.lookupValue("mode", mode);
        extention.lookupValue("mode", _mode);

        loadParams(rdr);
        loadCamera(rdr);
        loadPlugins(rdr);
        loadObjects(rdr);
        loadLights(rdr);
        // libconfig::Setting &objects = _cfg.lookup("objects");
        // std::cout << "Objects: " << objects.getLength() << std::endl;

    }
}
