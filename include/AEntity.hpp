/*
** EPITECH PROJECT, 2022
** ray
** File description:
** IEntity.hpp
*/

#pragma once

#include <map>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include "ConfigLoader.hpp"
#include "PluginManager.hpp"

namespace render {
    class IEntity {
        public:
            virtual ~IEntity() = default;
            virtual void selfInit(PluginManager &pm) = 0;
            virtual void *getFunPtr(const std::string &name) = 0;
            virtual void setFunPtr(const std::string &name, void *ptr) = 0;
    };

    class AEntity3D : public IEntity {
        public:
            virtual ~AEntity3D() = default;
            virtual void selfInit(PluginManager &pm, libconfig::Settings &settings) = 0;
            void *getFunPtr(const std::string &name);
            void setFunPtr(const std::string &name, void *ptr);
        protected:
            std::map<std::string, void *> _funPtrs;
    };
} // namespace render
