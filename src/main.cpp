/*
** EPITECH PROJECT, 2022
** pipeline
** File description:
** main.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "Ray.hpp"

#include "operations.hpp"
#include "Sphere.hpp"
#include "Light.hpp"

std::tuple<std::string, int> splitArg(char *arg)
{
    std::string argStr = arg;
    std::string argName = "";
    std::string argValue = "";
    size_t i = 0;
    for (; i < argStr.size(); ++i) {
        if (argStr[i] == '=')
            break;
        argName += argStr[i];
    }
    for (; i < argStr.size(); ++i) {
        if (argStr[i] == '=')
            continue;
        argValue += argStr[i];
    }
    return std::make_tuple(argName, std::atoi(argValue.c_str()));
}

void runFromArgs(int argc, char **argv)
{
    int lightSamples = 100;
    int imSide = 500;
    int focalPoint = 50;

    for (int i = 0; i < argc; ++i ) {
        std::tuple<std::string, int> arg = splitArg(argv[i]);
        if (std::get<0>(arg) == "--lightSamples") {
            lightSamples = std::get<1>(arg);
        } else if (std::get<0>(arg) == "--imSide") {
            imSide = std::get<1>(arg);
        } else if (std::get<0>(arg) == "--focalPoint") {
            focalPoint = std::get<1>(arg);
        }
    }
    render::Renderer renderer(lightSamples, imSide, focalPoint);
    renderer.loadScene();
    renderer.render();
}

int main(int argc, char **argv)
{
    srand(0);
    runFromArgs(argc, argv);
}
