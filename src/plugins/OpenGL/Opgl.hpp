/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Opgl.hpp
*/

#ifndef CB2BFC86_7722_46D2_A7EB_FD81891B085E
    #define CB2BFC86_7722_46D2_A7EB_FD81891B085E
    #include <thread>
    #include <string>
    #include <vector>
    #include <sstream>
    #include <fstream>
    #include <cstring>
    #include <iostream>
    #include <GL/glew.h>
    #include "glfw/include/GLFW/glfw3.h"
    #include <stdexcept>

    #include "geometry.hpp"

#define callgl(fun) gpu::Opgl::getGl<decltype(fun)>(#fun)

namespace gpu {

    struct Light {
        geo::vec3 position;
        geo::vec3 color;
    };

    struct Obj {
        geo::vec3 position;
        geo::vec3 rotation;
    };

    /**
     * @brief This class encapsulate the OpenGL context and window.
     * It provides a helper to call the opengl functions.
     *
     */
    class Opgl {
    public:
        class IncompatibleException : public std::logic_error{
            public:
                IncompatibleException(const std::string &msg) : std::logic_error(msg) {};
        };

        /**
         * @brief Construct a new Opgl object. Creates a window and a context.
         *
         * @param width
         * @param height
         */
        Opgl(unsigned int width, unsigned int height);

        /**
         * @brief Destroy the Opgl object, window and context.
         *
         */
        ~Opgl();

        /**
         * @brief Set the current context of OpenGL to that of this object.
         *
         */
        void setContextCurrent();

        /**
         * @brief assigns the internal window pointer.
         *
         * @param window
         */
        void setWindow(GLFWwindow *window);

        /**
         * @brief Draw n points as vertices.
         *
         * @param n
         */
        void drawNPoints(unsigned int n);

        /**
         * @brief Clear the screen.
         *
         */
        void clearScr();
        GLFWwindow *getWindow() const;

        /**
         * @brief Get a gl function pointer from its name.
         * OpenGL are not stored a the same place on all operating systems
         * and their actual lacation can only be known at runtime. Use this
         * combined with the callgl define in order to get a function pointer.
         *
         * @tparam T
         * @param name
         * @return T
         */
        template <typename T>
        static T getGl(const std::string &name) {
            T var = (T) glfwGetProcAddress(name.c_str());
            if (var == 0)
                throw std::runtime_error("Failed to get function " + name);
            return var;
        }
    private:
        GLFWwindow *_window;
};
}

#endif /* CB2BFC86_7722_46D2_A7EB_FD81891B085E */
