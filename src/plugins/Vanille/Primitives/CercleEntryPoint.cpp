/*
** EPITECH PROJECT, 2022
** ray
** File description:
** CercleEntryPoint.cpp
*/

#include "IPrimitive.hpp"
#include "Cercle.primitive.v.hpp"

extern "C"
{
    render::IPrimitive *entryPoint()
    {
        return new vanille::CerclePrimitive_v();
    }
}
