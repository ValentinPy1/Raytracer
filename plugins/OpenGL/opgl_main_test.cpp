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

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    struct vec3 {
        float x;
        float y;
        float z;
    };
    struct Objects {
        int type;
        struct vec3 pos[1];
    };

    struct Objects arr[] = {
        {0,  {(struct vec3){0.0f, 0.0f, 0.0f}}}
    };

    ogl::PluginOpenGL opgl;
    opgl.initOpenGL(*(render::Renderer *) nullptr);
    opgl.registerShader("./shaders/vs_learn_triangle.glsl", "vertex", GL_VERTEX_SHADER);
    opgl.registerShader("./shaders/fs_learn_triangle.glsl", "fragment", GL_FRAGMENT_SHADER);
    opgl.registerProgram("render", {"vertex", "fragment"});

    glfwMakeContextCurrent(opgl.getWindow());
    GLuint VBO = opgl.createBuffer();
    opgl.bindBuffer(VBO);
    GLuint VAO = opgl.createVertexArray();
    GLuint SSBO = opgl.createShaderStorageBuffer(sizeof(arr));
    opgl.bindShaderStorageBuffer(SSBO);
    opgl.setShaderStorageBufferData(sizeof(arr), arr, 0, SSBO, "ObjectsBlock", "render");

    opgl.setBufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    opgl.setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    // unbind VAO to configure other objects if needed, and bind it again to draw
    opgl.useProgram("render");
    glDrawArrays(GL_POINTS, 0, 3);
    glfwSwapBuffers(opgl.getWindow());

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exiting" << std::endl;
    return 0;
}
