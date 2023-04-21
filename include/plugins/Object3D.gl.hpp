/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Object3D.gl.hpp
*/

#pragma once

namespace ogl {
    struct vec3 {
        float x;
        float y;
        float z;
    };

    struct vec4 {
        float x;
        float y;
        float z;
        float w;
    };

    struct Object3D_gl {
        int type;
        vec3 args[];
    };
}
