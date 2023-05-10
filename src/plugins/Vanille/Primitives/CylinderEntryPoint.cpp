/*
** EPITECH PROJECT, 2022
** ray
** File description:
** CylinderEntryPoint.cpp
*/

#include "IPrimitive.hpp"
#include "Cylinder.primitive.v.hpp"

extern "C" {
    render::IPrimitive *entryPoint()
    {
        return new vanille::CylinderPrimitive_v();
    }
}
