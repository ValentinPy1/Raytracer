/*
** EPITECH PROJECT, 2022
** ray
** File description:
** SSBO.hpp
*/

#ifndef A2417C61_F0C5_4EEB_AA9E_75CFA83748E3
#define A2417C61_F0C5_4EEB_AA9E_75CFA83748E3

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
#include "Opgl.hpp"

namespace gpu {
    /**
     * @brief A SSBO (shader storage buffer object) is a buffer of data that
     * can be used by the GPU. The data stored in this buffer is shared between
     * all vertex (thread) of the GPU. It can be used to define a global array
     * of data with a size decided at runtime.
     *
     */
    class SSBO {
        public:
            /**
             * @brief Construct a new SSBO object.
             *
             * @param bindingPoint the binding point of the SSBO in the shaders. Must be the same in all shaders. It is HARD CODED in the shaders.
             * @param size the size of the buffer in bytes
             */
            SSBO(GLuint bindingPoint, size_t size);

            /**
             * @brief Destroy the SSBO object.
             *
             */
            ~SSBO();

            /**
             * @brief Bind the SSBO to the current context. All futur calls to
             * OpenGL will use this SSBO.
             *
             * @param offset
             */
            void bind(GLuint offset = 0);

            /**
             * @brief Set the data of the SSBO. Use SSBO::bind() before calling this function.
             *
             * @param data
             * @param usage
             */
            void setData(const void *data, GLenum usage = GL_STATIC_DRAW);
        private:
            GLuint _id;
            GLuint _bindingPoint;
            size_t _size;
    };
}

#endif /* A2417C61_F0C5_4EEB_AA9E_75CFA83748E3 */
