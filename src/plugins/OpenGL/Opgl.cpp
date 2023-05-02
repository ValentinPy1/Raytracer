/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Opgl.cpp
*/

#include "Opgl.hpp"

namespace gpu {
    Opgl::Opgl(unsigned int width, unsigned int height) {
            if (!glfwInit())
                throw std::runtime_error("Failed to init glfw");
            _window = glfwCreateWindow(width, height, "", nullptr, nullptr);
            if (!_window) {
                glfwTerminate();
                throw std::runtime_error("Failed to create window");
            }
            glfwMakeContextCurrent(_window);
            if (glewInit() != GLEW_OK)
                throw std::runtime_error("Failed to init glew");
        };

    Opgl::~Opgl() {
        glfwTerminate();
    };

    void Opgl::setContextCurrent() {
        glfwMakeContextCurrent(_window);
    }

    void Opgl::setWindow(GLFWwindow *window) {
         _window = window;
    }

    void Opgl::drawNPoints(unsigned int n) {
        glDrawArrays(GL_POINTS, 0, n);
    }

    void Opgl::clearScr() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    GLFWwindow *Opgl::getWindow() const { return _window; }
}
