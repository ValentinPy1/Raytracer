/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Plugin.cpp
*/

#include "PluginManager.hpp"

namespace render {

    Plugin::Plugin() :
        _init(nullptr),
        _processRay(nullptr),
        _postProcess(nullptr),
        _priority(0),
        _name("")
    {
    }

    Plugin::Plugin(
        init_t initFun,
        processRay_t processRayFun,
        postProcess_t postProcessFun,
        int priority,
        const std::string &name) :
        _init(initFun),
        _processRay(processRayFun),
        _postProcess(postProcessFun),
        _priority(priority),
        _name(name)
    {
    }

    void Plugin::init(render::Renderer &rdr) const
    {
        if (_init)
            _init(rdr);
    }

    void Plugin::processRay(render::Ray &ray, const render::Renderer &rdr) const
    {
        if (_processRay)
            _processRay(ray, rdr);
    }

    void Plugin::postProcess(render::Renderer &rdr) const
    {
        if (_postProcess)
            _postProcess(rdr);
    }

    int Plugin::getPriority() const {
        return _priority;
    }

    init_t Plugin::getInit() const noexcept
    {
        return _init;
    }

    processRay_t Plugin::getProcessRay() const noexcept
    {
        return _processRay;
    }

    postProcess_t Plugin::getPostProcess() const noexcept
    {
        return _postProcess;
    }

    const std::string &Plugin::getName() const noexcept
    {
        return _name;
    }
}
