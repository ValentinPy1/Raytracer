/*
** EPITECH PROJECT, 2022
** ray
** File description:
** VBO.hpp
*/

#ifndef FFFA16CB_416D_4CCE_8276_1455D1BCB5DA
#define FFFA16CB_416D_4CCE_8276_1455D1BCB5DA

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

namespace gpu {

    /**
     * @brief A VBO (virtual buffer object) is a buffer of data
     * that can be used by the GPU. Each piece of data stored in the buffer
     * will be used by the GPU to draw a vertex, which means that it will spawn
     * a parallel thread for for each piece of data in the buffer.
     *
     */
    class VBO {
        public:
            /**
             * @brief Construct a new VBO object.
             *
             */
            VBO();

            /**
             * @brief Destroy the VBO object.
             *
             */
            ~VBO();

            /**
             * @brief Bind the VBO to the current context. All futur calls to
             * OpenGL will use this VBO.
             *
             */
            void bind();

            /**
             * @brief Set the data of the VBO. Use VBO::bind() before calling this function.
             *
             * @param data
             * @param size
             * @param usage
             */
            void setData(const void *data, size_t size, GLenum usage = GL_STATIC_DRAW);

            /**
             * @brief Set the vertex attributes of the VBO. Use VBO::bind() before calling this function.
             * Setting the vertex attributes will tell OpenGL how to interpret the data in the VBO,
             * meaning that it will tell it how to parse the array of data.
             *
             * @param index the index at which the parsing will start
             * @param size the number of components per vertex attribute. Must be 1, 2, 3 or 4.
             * @param type the GLtype of the data stored in the pointer argument
             * @param normalized GLboolean that tells OpenGL if the data should be normalized between 0 and 1
             * @param stride the size of a single element in the array of data. If 0, OpenGL will assume that the data is tightly packed.
             * @param pointer the pointer to the actual data.
             */
            void setVertexAttributes(GLuint index, size_t size, GLenum type, GLboolean normalized, size_t stride, const void *pointer);
        private:
            GLuint _id;
    };
}

#endif /* FFFA16CB_416D_4CCE_8276_1455D1BCB5DA */
