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
    int h = 600;
    int w = 600;
    float vertices[w * h * 3];

    int index = 0;
    for(float i = -h / 2.0 ; i < h / 2.0; i++) {
        for(float j = -w / 2.0; j < w / 2.0; j++) {
            vertices[index++] = (float) j / (float) (w * 0.5); // x coordinate
            vertices[index++] = (float) i / (float) (h * 0.5); // y coordinate
            vertices[index++] = 0; // z coordinate
        }
    }
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

    // adding the lights
    struct Light {
        struct vec3 position;
        struct vec3 color;
        float radius;
    };

    struct Light lights[1] = {{(struct vec3){0.0f, 0.1f, 0.0f}, (struct vec3){1.0f, 1.0f, 1.0f}, 1.0f}};
    GLuint bindingPoint = 2;
    GLuint sslights = opgl.createShaderStorageBuffer(sizeof(lights), GL_DYNAMIC_COPY);
    opgl.bindShaderStorageBuffer(sslights, bindingPoint, 0, sizeof(lights));
    opgl.setShaderStorageBufferData(sslights, sizeof(lights), bindingPoint, lights, GL_DYNAMIC_COPY);

    // adding the objects
    GLuint ssbo = opgl.createShaderStorageBuffer(sizeof(arr), GL_DYNAMIC_COPY);
    opgl.bindShaderStorageBuffer(ssbo, 1, 0, sizeof(arr));
    opgl.setShaderStorageBufferData(ssbo, sizeof(arr), 1, arr, GL_DYNAMIC_COPY);

    //SETTING UP THE UNIFORMS
    opgl.setUniform3f("focalPoint", "render", 0.0f, 0.0f, -1.0f);
    opgl.setUniform2f("u_resolution", "render", w, h);

    // DRAWING
    glDrawArrays(GL_POINTS, 0, sizeof(vertices) / sizeof(float) / 3);
    glfwSwapBuffers(opgl.getWindow());

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exiting" << std::endl;
    return 0;
}
