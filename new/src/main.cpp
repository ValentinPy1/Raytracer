/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main.cpp
*/

#include <string>
#include "Renderer.cpp"
#include "ConfigLoader.cpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;

    ConfigLoader configLoader;
    Renderer renderer;

    configLoader.loadConfig(std::string(argv[1]), renderer);
    renderer.render();
}