/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginShader.cpp
*/

#include "plugins/PluginShader.gl.hpp"

namespace ogl
{
    PluginShader::PluginShader(const std::string &path, unsigned int type, const std::string &name, int priority) :
        render::Plugin(
            nullptr,
            nullptr,
            nullptr,
            priority,
            name
        ), _path(path), _type(type)
    {
    }

    PluginShader::~PluginShader()
    {
    }

    std::string PluginShader::getShaderPath()
    {
        return _path;
    }

    unsigned int PluginShader::getShaderType()
    {
        return _type;
    }
}
