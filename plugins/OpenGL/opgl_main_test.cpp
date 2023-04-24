/*
** EPITECH PROJECT, 2022
** ray
** File description:
** opgl_main_test.cpp
*/

#include <thread>
#include <chrono>
#include <iostream>
#include <cstring>
#include "plugins/PluginOpenGL.hpp"

int main()
{
    // CREATING THE VERTEX VALUES
    float vertices[640 * 480 * 3];

    int h = 480;
    int w = 640;
    int index = 0;
    for(float i = -h / 2.0 ; i < h / 2.0; i++) {
        for(float j = -w / 2.0; j < w / 2.0; j++) {
            vertices[index++] = (float) j / (float) (w * 0.5); // x coordinate
            vertices[index++] = (float) i / (float) (h * 0.5); // y coordinate
            vertices[index++] = 0; // z coordinate
        }
    }

    std::cout << "wrote vertices" << std::endl;
    struct vec3 {
        float x;
        float y;
        float z;
    };
    struct Objects {
        struct vec3 pos[1];
    };

    struct vec3 arr[1] = {{(struct vec3){0.7f, 0.0f, 0.0f}}};

    // COMPILING THE SHADERS
    ogl::PluginOpenGL opgl;
    opgl.initOpenGL(*(render::Renderer *) nullptr);
    opgl.registerShader("./shaders/vs_learn_triangle.glsl", "vertex", GL_VERTEX_SHADER);
    opgl.registerShader("./shaders/fs_learn_triangle.glsl", "fragment", GL_FRAGMENT_SHADER);
    opgl.registerProgram("render", {"vertex", "fragment"});
    opgl.useProgram("render");

    // SETTING UP THE CONTEXT AND DECLARING BUFFERS
    glfwMakeContextCurrent(opgl.getWindow());
    GLuint VBO = opgl.createBuffer();
    opgl.bindBuffer(VBO);
    // GLuint SSBO = opgl.createShaderStorageBuffer(sizeof(arr));

    // FILLING IN THE VERTEX DATA
    opgl.bindBuffer(VBO);
    opgl.setBufferData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    opgl.setVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), vertices);

    // adding the objects
    // GLuint ssbo;
    // callgl(glCreateBuffers)(1, &ssbo);
    // callgl(glBindBufferRange)(GL_SHADER_STORAGE_BUFFER, 1, ssbo, 0, sizeof(arr));
    // callgl(glBufferData)(GL_SHADER_STORAGE_BUFFER, sizeof(arr), arr, GL_DYNAMIC_COPY);
    // callgl(glBindBufferBase)(GL_SHADER_STORAGE_BUFFER, 1, ssbo);

    GLuint ssbo = opgl.createShaderStorageBuffer(sizeof(arr), GL_DYNAMIC_COPY);
    opgl.bindShaderStorageBuffer(ssbo, 1, 0, sizeof(arr));
    opgl.setShaderStorageBufferData(ssbo, sizeof(arr), 1, arr, GL_DYNAMIC_COPY);

    //SETTING UP THE UNIFORMS
    opgl.setUniform3f("focalPoint", "render", 0.0f, 0.0f, -1.0f);

    // DRAWING
    glDrawArrays(GL_POINTS, 0, sizeof(vertices) / sizeof(float) / 3);
    glfwSwapBuffers(opgl.getWindow());

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exiting" << std::endl;
    return 0;
}
