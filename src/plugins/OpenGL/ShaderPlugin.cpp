/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ShaderPlugin.cpp
*/

#include "ShaderPlugin.hpp"

namespace gpu {
    ShaderPlugin::ShaderPlugin(const std::string &associatedShaderPath,
    const std::string &name) :
        Plugin(
            nullptr,
            nullptr,
            nullptr,
            0,
            name
        ),
        _associatedShaderPath(associatedShaderPath)
    {
    }

    ShaderPlugin::~ShaderPlugin()
    {
    }

    const std::string &ShaderPlugin::getPath()
    {
        return _associatedShaderPath;
    }
}
