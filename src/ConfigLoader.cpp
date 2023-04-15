/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ConfigLoader.cpp
*/

#include "ConfigLoader.hpp"
#include "Render.hpp"
namespace render {
    ConfigLoader::ConfigLoader()
    {
    }

    void ConfigLoader::loadConfigFile(std::string path, Renderer &rdr)
    {
        try {
            _cfg.readFile(path.c_str());
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
        Camera camera;
        // camera.captorWidth = _cfg.lookup("camera.resolution.width");
        // camera.captorHeight = _cfg.lookup("camera.resolution.height");
        // camera._focalPoint = _cfg.lookup("camera.fieldOfView");
        // camera._position = _cfg.lookup("camera.position");
        // how can i send a sf::Vector3f to the camera.setPosition function ?
        sf::Vector3f position;
        position.x = _cfg.lookup("camera.position.x");
        position.y = _cfg.lookup("camera.position.y");
        position.z = _cfg.lookup("camera.position.z");
        camera.setPosition(position);
        // camera.setPosition(_cfg.lookup("camera.position.x"), _cfg.lookup("camera.position.y"), _cfg.lookup("camera.position.z"));
        camera.setFocalPoint(_cfg.lookup("camera.fieldOfView"));
        rdr.setCamera(camera);
    }
}