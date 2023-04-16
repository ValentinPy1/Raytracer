/*
** EPITECH PROJECT, 2022
** ray
** File description:
** opgl_main_test.cpp
*/

#include <thread>
#include <chrono>
#include <iostream>
#include "plugins/PluginOpenGL.hpp"

int main()
{
    ogl::PluginOpenGL opgl;
    opgl.initOpenGL(*(render::Renderer *)nullptr);
    opgl.registerShader("./shaders/vs_learn_triangle.glsl", "vertex", GL_VERTEX_SHADER);
    opgl.registerShader("./shaders/fs_learn_triangle.glsl", "fragment", GL_FRAGMENT_SHADER);
    opgl.registerProgram("triangle", {"vertex", "fragment"});
    // callgl(glfwMakeContextCurrent)(opgl.getWindow());
    glfwMakeContextCurrent(opgl.getWindow());
    unsigned int VAO;
    callgl(glGenVertexArrays)(1, &VAO);

    unsigned int VBO;
    callgl(glGenBuffers)(1, &VBO);

    callgl(glBindVertexArray)(VAO);
    callgl(glBindBuffer)(GL_ARRAY_BUFFER, VBO);
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    callgl(glBufferData)(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    callgl(glVertexAttribPointer)(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    callgl(glEnableVertexAttribArray)(0);

    // unbind VAO to configure other objects if needed, and bind it again to draw
    opgl.startProgram("triangle");
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(opgl.getWindow());


    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exiting" << std::endl;
    return 0;
}
