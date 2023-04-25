/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main.cpp
*/

#include <string>
#include "ConfigLoader.hpp"
#include "Renderer.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;

    render::ConfigLoader configLoader;
    render::Renderer renderer;

    configLoader.loadConfigFile(std::string(argv[1]), renderer);
    renderer.render();
}
