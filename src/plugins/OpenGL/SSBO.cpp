/*
** EPITECH PROJECT, 2022
** ray
** File description:
** SSBO.cpp
*/

#include "Opgl.hpp"
#include "SSBO.hpp"

namespace gpu {
    SSBO::SSBO(GLuint bindingPoint, size_t size) :
        _bindingPoint(bindingPoint), _size(size) {
        callgl(glGenBuffers)(1, &_id);
    }

    SSBO::~SSBO() {
        callgl(glDeleteBuffers)(1, &_id);
    }

    void SSBO::bind(GLuint offset) {
        callgl(glBindBufferRange)(GL_SHADER_STORAGE_BUFFER, _bindingPoint, _id, offset, _size);
    }

    void SSBO::setData(const void *data, GLenum usage) {
        callgl(glBufferData)(GL_SHADER_STORAGE_BUFFER, _size, data, usage);
        callgl(glBindBufferBase)(GL_SHADER_STORAGE_BUFFER, _bindingPoint, _id);
    }
}
