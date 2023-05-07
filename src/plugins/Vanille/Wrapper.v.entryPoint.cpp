/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.v.entryPoint.cpp
*/

#include "Wrapper.v.hpp"


extern "C" {
    render::IWrapper *entryPoint()
    {
        return new vanille::Wrapper_v();
    }
}
