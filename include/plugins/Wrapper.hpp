/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.cpp
*/

#ifndef WRAPPER_HPP
    #define WRAPPER_HPP
    #include "PluginManager.hpp"
    #include "Render.hpp"

namespace render {
    class AWrapper : public Plugin {
        public:
            ~AWrapper() = default;
            virtual void run(render::Renderer &rdr) = 0;
        protected:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
    };
}

#endif // WRAPPER_HPP
