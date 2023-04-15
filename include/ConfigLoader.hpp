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
    class Entity3D {
        public:
            Entity3D();
            ~Entity3D();

            template <typename T>
            void addComponent(std::string name, T component, void (*destructor)(T *))
            {
                if (_components.find(name) == _components.end())
                    _components[name] = std::vector<void *>();
                _components[name] = component;
                _destroyAll.push_back(std::unique_ptr<void *, void (*)(void *)>(component, (void (*)(void *))destructor));
            }

            template <typename T>
            T *getComponent(std::string name)
            {
                if (_components.find(name) == _components.end())
                    throw std::runtime_error("Component not found: " + name);
                return (T *)_components[name];
            }
        private:
            std::map<std::string, void *> _components;
            std::vector<std::unique_ptr<void *, std::function<void (void*)>>> _destroyAll;
    };

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