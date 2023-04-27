/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main.cpp
*/

#include <string>
#include <ctime>
#include "ConfigLoader.hpp"
#include "Renderer.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << render::red << "[ERROR] " << render::no_color << "Usage: ./pipeline config_file" << std::endl;
        return 84;
    }
    srand(time(NULL));
    render::ConfigLoader configLoader;
    render::Renderer renderer;

    configLoader.loadConfigFile(std::string(argv[1]), renderer);
    std::cout << render::green << "[INFO] " << render::yellow << "Loaded config file without errors" << render::no_color << std::endl;
    renderer.render();
    return 0;
}
