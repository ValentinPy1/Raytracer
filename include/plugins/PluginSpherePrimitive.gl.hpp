/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginSpherePrimitive.gl.hpp
*/

#ifndef PLUGINSPHEREPRIMITIVE_GL_HPP
    #define PLUGINSPHEREPRIMITIVE_GL_HPP
    #include "./PluginOpenGL.hpp"
    #include "../PluginManager.hpp"
    #include "APluginPrimitive.hpp"

namespace ogl {
    class SpherePrimitive_gl : public virtual render::APluginPrimitive {
        public:
            SpherePrimitive_gl();
            ~SpherePrimitive_gl();
            void initSpherePrimitive_gl(render::Renderer &rdr);
            void selfInit(libconfig::Setting setting) override;
        private:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
            PluginOpenGL *_opengl = nullptr;
            GLuint vao;
            GLuint vbo;
    };
}

#endif // PLUGINSPHEREPRIMITIVE_GL_HPP
