/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.gl.hpp
*/

#ifndef DFE232F2_BDD4_425F_88E1_A2A163DA444A
    #define DFE232F2_BDD4_425F_88E1_A2A163DA444A
    #include "Wrapper.hpp"
    #include "Plugin.hpp"
    #include "Opgl.hpp"
    #include "ShaderProgram.hpp"
    #include "geometry.hpp"


namespace gpu {
    class Wrapper_gl : public render::IWrapper {
        public:
            Wrapper_gl();
            ~Wrapper_gl();
            void run(render::Renderer &rdr) override;

        private:
            void initCamera();
            void initProgram(render::Renderer &rdr);
            void initObjects3D(render::Renderer &rdr);
            void runWindow(render::Renderer &rdr);


            Opgl _opgl;
            static const int w = 1000;
            static const int h = 1000;
            float * _objVertices = nullptr;
            float *_vertices = nullptr;
            size_t _nObjects = 0;

            std::shared_ptr<ShaderProgram> _shaderProgram = nullptr;
    };
}

#endif /* DFE232F2_BDD4_425F_88E1_A2A163DA444A */
