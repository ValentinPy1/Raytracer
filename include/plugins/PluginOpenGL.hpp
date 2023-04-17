/*
** EPITECH PROJECT, 2022
** ray
** File description:
** PluginOpenGL.hpp
*/

#ifndef PLUGINOPENGL_HPP
    #define PLUGINOPENGL_HPP
    #include <memory>
    #include <thread>
    #include <mutex>
    #include <map>
    #include <string>
    #include <memory>
    #include <GL/glew.h>
    #include "../../plugins/OpenGL/glfw/include/GLFW/glfw3.h"
    #include "plugins/PluginShader.gl.hpp"

    #include "../../include/PluginManager.hpp"
    #define callgl(fun) ogl::PluginOpenGL::getGl<decltype(fun)>(#fun)

namespace ogl {

    /**
     * @brief A class to encapsulate a shader written in GLSL.
     * Choose the type of shader with the shaderType parameter,
     * which can be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
     * The code for the shader will be loaded and compiled
     * from the file at srcPath.
     *
     */
    class Shader {
        public:
            Shader(int shaderType, std::string srcPath);
            ~Shader();
            unsigned int id;
            std::string srcContent;
            char *src;
            int type;
    };

    /**
     * @brief A class to encapsulate a shader program.
     * A shader program is a collection of shaders that
     * are linked together to form a complete shader.
     * The shaders are passed as a vector of Shader objects.
     *
     * Once the program has been created, the user can freely bind vertex
     * Arrays, etc, and calling glDrawArrays will use the program.
     *
     * @note The shaders are not deleted when the program is deleted.
     * This is because the shaders may be used by other programs.
     */
    class ShaderProgram {
        public:
            ShaderProgram(std::vector<std::shared_ptr<Shader>> shaders);
            ~ShaderProgram();
            unsigned int id;
    };

    /**
     * @brief A class to encapsulate the OpenGL plugin.
     * This plugin is responsible for initializing the OpenGL context, as well as
     * creating and managing the shaders and programs used by the renderer.
     *
     * This plugin does not provide any implementation of objects, only the
     * infrastructure to render them.
     *
     */
    class PluginOpenGL : public render::Plugin {
        public:
            PluginOpenGL();
            ~PluginOpenGL();
            /**
             * @brief Initialize the OpenGL context. This function is exposed
             * to the renderer so that it can be called from the main thread.
             *
             * @param rdr
             */
            void initOpenGL(render::Renderer &rdr);

            /**
             * @brief Closes the window and terminates the OpenGL context.
             *
             */
            void terminate();

            /**
             * @brief Register a shader using the given name.
             * The shader will be loaded from the file at srcPath, and deleted when the
             * plugin is destroyed.
             *
             * @param srcPath
             * @param shaderName
             * @param shaderType
             */
            void registerShader(const std::string &srcPath, const std::string &shaderName, int shaderType);
            void registerShader(const PluginShader &shader);

            /**
             * @brief Register a shader program using the given name.
             * The program is created from the shaders with the given names which
             * will be chained and linked together. This program will be
             * used as the render pipeline for OpenGL if the startProgram function
             * is called with the name of this program.
             *
             * @param programName
             * @param shaderNames
             */
            void registerProgram(const std::string &programName, std::initializer_list<std::string> shaderNames);

            /**
             * @brief Start the program with the given name.
             *  This means that the program will be used as the render pipeline
             * for OpenGL, when the glDrawArrays function is called.
             *
             * @param programName
             */
            void startProgram(const std::string &programName);

            /**
             * @brief Get the Window object from the plugin, which can be used
             * to set the context of the openGL calls, or to get the size of the window, etc...
             *
             * @warning do not free this pointer, it is managed by the plugin.
             * @return GLFWwindow*
             */
            GLFWwindow *getWindow() const;
            template <typename T>
            static T getGl(const std::string &name) {
                T var = (T) glfwGetProcAddress(name.c_str());
                if (var == 0)
                    throw std::runtime_error("Failed to get function " + name);
                return var;
            }
        private:
            /**
             * @brief The main loop of the plugin, which is run in a separate thread.
             *
             * @deprecated this function's functionality should be moved to a master thread.
             *
             */
            void doWindowLoop();

            render::init_t _init = nullptr;
            render::processRay_t _processRay = nullptr;
            render::postProcess_t _postProcess = nullptr;
            int _priority;
            std::shared_ptr<GLFWwindow> _window;

            std::thread _displayThread;
            std::mutex _mutex;

            bool _isInitialized = false;

            std::map<std::string, std::shared_ptr<Shader>> _shaderMap;
            std::map<std::string, std::shared_ptr<ShaderProgram>> _programMap;
    };
}

#endif // PLUGINOPENGL_HPP
