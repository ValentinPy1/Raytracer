/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** SceneLoader.hpp
*/

#ifndef SCENELOADER_HPP
    #define SCENELOADER_HPP
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include <string>
namespace conf {
    class SceneLoader {
        public:
            SceneLoader();
            ~SceneLoader();

            void addConfigPath(const std::string &path);
        private:
            std::vector<std::string> _configPaths;
    };
}


#endif // SCENELOADER_HPP
