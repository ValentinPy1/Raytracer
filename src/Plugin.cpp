/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Plugin.cpp
*/

#include "PluginManager.hpp"

namespace render {

    Plugin::Plugin(
        void (*initFun)(render::Renderer&),
        void (*processRayFun)(render::Ray&, const render::Renderer&),
        void (*postProcessFun)(render::Renderer&),
        unsigned int priority) :
        _init(initFun),
        _processRay(processRayFun),
        _postProcess(postProcessFun),
        _priority(priority)
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

    unsigned int Plugin::getPriority() const {
        return _priority;
    }
}
