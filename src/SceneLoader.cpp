/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** SceneLoader.cpp
*/

#include "SceneLoader.hpp"

namespace conf {
    SceneLoader::SceneLoader()
    {
    }

    SceneLoader::~SceneLoader()
    {
    }

    void SceneLoader::addConfigPath(const std::string &path)
    {
        _configPaths.push_back(path);
    }
}
