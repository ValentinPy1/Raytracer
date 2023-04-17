/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.gl.hpp
*/

#include "PluginManager.hpp"
#include "Wrapper.hpp"

namespace ogl {
    class Wrapper_gl : public render::AWrapper {
        public:
            Wrapper_gl(
                const std::string &name);
            ~Wrapper_gl() = default;
            void run(render::Renderer &rdr) override;
        private:
            void initWrapper_gl(render::Renderer &rdr);
            void buildShaders(render::Renderer &rdr);
            render::PluginOpenGL *_opengl = nullptr;
    };
}
