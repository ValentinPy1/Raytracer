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
    /**
     * @brief This wrapper implements the raytracing algorithm using OpenGL.
     * The actual rendering pipeline should be written in shader files and
     * loaded as plugins in the config file.
     *
     */
    class Wrapper_gl : public render::IWrapper {
        public:
            Wrapper_gl();
            ~Wrapper_gl();

            /**
             * @brief The run function runs the whole rendering pipeline,
             * after having initialized the camera, the program and the objects.
             *
             * @param rdr
             */
            void run(render::Renderer &rdr) override;

        private:
            /**
             * @brief Converts the rays of the camera to vertices for the
             * Vertex shaders.
             *
             */
            void initCamera();

            /**
             * @brief Initializes the shader program from the list of shaders
             * in the plugins section of the config file.
             *
             * @param rdr
             */
            void initProgram(render::Renderer &rdr);

            /**
             * @brief Initializes the objects from the list of objects in the
             * config file.
             *
             * @param rdr
             */
            void initObjects3D(render::Renderer &rdr);

            /**
             * @brief Runs the window and the rendering loop.
             *
             */
            void runWindow();

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
