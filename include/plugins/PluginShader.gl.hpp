/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginShader.hpp
*/

#ifndef PLUGINSHADER_HPP
    #define PLUGINSHADER_HPP
    #include <string>
    #include "PluginManager.hpp"

namespace ogl
{
    class PluginShader : public render::Plugin
    {
        public:
            PluginShader(const std::string &path, unsigned int type, const std::string &name, int priority);
            ~PluginShader();
            std::string getShaderPath();
            unsigned int getShaderType();
        protected:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
            std::string _path;
            unsigned int _type;
    };
} // namespace ogl


#endif // PLUGINSHADER_HPP
