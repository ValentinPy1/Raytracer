/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginSpherePrimitive.gl.hpp
*/

#ifndef PLUGINSPHEREPRIMITIVE_GL_HPP
    #define PLUGINSPHEREPRIMITIVE_GL_HPP
    #include "PluginOpenGL.hpp"
    #include "../PluginManager.hpp"
    #include "IPrimitive.hpp"
    #include "plugins/Object3D.gl.hpp"

namespace ogl {
    class SpherePrimitive_gl : public virtual render::IPrimitive {
        public:
            SpherePrimitive_gl();
            ~SpherePrimitive_gl();
            void selfInit(libconfig::Setting &setting) override;
        protected:
            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
            PluginOpenGL *_opengl = nullptr;
            GLuint vao;
            GLuint vbo;

            ogl::vec3 _center;
            ogl::vec3 _rotation;
            float _radius;
    };
}

#endif // PLUGINSPHEREPRIMITIVE_GL_HPP
