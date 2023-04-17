/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** ConfigLoader.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <libconfig.h++>
#include <memory>
#include <iostream>
#include <functional>
#include "Render.hpp"

namespace render {
    class Renderer;
    class ConfigLoader
    {
        public:
            ConfigLoader();
            ~ConfigLoader() = default;
            void loadConfigFile(std::string path, Renderer &rdr);

        private:
            libconfig::Config _cfg;
    };
}
