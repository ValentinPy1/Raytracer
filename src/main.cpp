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
    int i = 0;
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
    render::Renderer renderer(50);
    // renderer.loadScene();
    // renderer.render();
    runFromArgs(argc, argv);
    // render::Ray r({0, 0, 0}, {0, 1, 0});
    // renderer.getObjects().push_back(std::make_shared<render::Sphere>(render::Sphere({0, 2, 0}, 1, sf::Color::Red)));
    // renderer.addLight(render::Light({0, 1, 1}, sf::Color::White));
    // r.findIntersections(renderer);
    // std::cout << "number of intersections: " << r.getIntersections().size() << std::endl;
    // for (auto &i : r.getIntersections()) {
    //     std::cout << "intersection at " << i.getPoint() << std::endl;
    // }
    // r.applyLighting(renderer);
    // std::cout << "color in main: " << (int) r.getColor().r << ", " << (int) r.getColor().g << ", " << (int) r.getColor().b << std::endl;
}
