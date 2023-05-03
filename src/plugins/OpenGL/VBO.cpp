/*
** EPITECH PROJECT, 2022
** ray
** File description:
** VBO.cpp
*/

#include "Opgl.hpp"
#include "VBO.hpp"

namespace gpu {
    VBO::VBO()
    {
        callgl(glGenBuffers)(1, &_id);
    }

    VBO::~VBO()
    {
        callgl(glDeleteBuffers)(1, &_id);
    }

    void VBO::bind() {
        callgl(glBindBuffer)(GL_ARRAY_BUFFER, _id);
    }

    void VBO::setData(const void *data, size_t size, GLenum usage) {
        callgl(glBufferData)(GL_ARRAY_BUFFER, size, data, usage);
    }

    void VBO::setVertexAttributes(GLuint index, size_t size, GLenum type, GLboolean normalized, size_t stride, const void *pointer) {
        callgl(glVertexAttribPointer)(index, size, type, normalized, stride, pointer);
        callgl(glEnableVertexAttribArray)(index);
    }
}
