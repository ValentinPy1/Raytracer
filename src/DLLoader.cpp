/*
** EPITECH PROJECT, 2022
** ray
** File description:
** DLLoader.cpp
*/

#include "PluginManager.hpp"

DLLoader::DLLoaderException::DLLoaderException(const std::string &message) :
     _message(message)
{
}

const char *DLLoader::DLLloaderException::what() const noexcept {
    return _message.c_str();
}

pl::DLLoader::DLLoader() {
}

pl::DLLoader::~DLLoader() {
    for (auto &handle : _handles) {
        dlclose(handle);
    }
    _handles.clear();
}
