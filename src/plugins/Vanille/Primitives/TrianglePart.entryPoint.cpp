/*
** EPITECH PROJECT, 2022
** ray
** File description:
** TrianglePart.entryPoint.cpp
*/

#include "Mesh.primitive.v.hpp"

extern "C" {
    vanille::TrianglePart *entryPoint()
    {
        return new vanille::TrianglePart();
    }
}
