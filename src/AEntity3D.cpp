/*
** EPITECH PROJECT, 2022
** ray
** File description:
** AEntity3D.cpp
*/

#include "AEntity3D.hpp"

namespace render {
    void *AEntity3D::getFunPtr(const std::string &name) {
        return _funPtrs[name];
    }

    void AEntity3D::setFunPtr(const std::string &name, void *ptr) {
        _funPtrs[name] = ptr;
    }

    void *AEntity3D::getFunPtr(const std::string &name) {
        return _funPtrs[name];
    }
}
