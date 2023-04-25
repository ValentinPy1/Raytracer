/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AWRapper.cpp
*/

#include "plugins/Wrapper.hpp"

namespace render {
    AWrapper::AWrapper(
        render::init_t init,
        render::processRay_t processRay,
        render::postProcess_t postProcess,
        int priority,
        const std::string &name
    ) :
        _init(init),
        _processRay(processRay),
        _postProcess(postProcess),
        _priority(priority),
        _name(name)
    {
    }

    int AWrapper::getPriority() const {
        return _priority;
    }

    const std::string &AWrapper::getName() const {
        return _name;
    }

    void AWrapper::init(render::Renderer &rdr) const {
        if (_init)
            _init(rdr);
    }

    void AWrapper::processRay(render::Ray &ray, const render::Renderer &rdr) const {
        if (_processRay)
            _processRay(ray, rdr);
    }

    void AWrapper::postProcess(render::Renderer &rdr) const {
        if (_postProcess)
            _postProcess(rdr);
    }

    init_t AWrapper::getInit() const noexcept {
        return _init;
    }

    processRay_t AWrapper::getProcessRay() const noexcept {
        return _processRay;
    }

    postProcess_t AWrapper::getPostProcess() const noexcept {
        return _postProcess;
    }
}
