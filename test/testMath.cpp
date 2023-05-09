/*
** EPITECH PROJECT, 2022
** ray
** File description:
** testMath.cpp
*/

#include <iostream>
#include <criterion/criterion.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "operations.hpp"
#include "geometry.hpp"
#include "Ray.hpp"

#define EPS 0.001f

Test(rotation_X, deg90)
{
    sf::Vector3f v(1, 1, 1);
    auto rot = render::Ray::rotateX(v, M_PI / 2);
    cr_assert_float_eq(rot.x, 1, EPS);
    cr_assert_float_eq(rot.y, -1, EPS);
    cr_assert_float_eq(rot.z, 1, EPS);
}

Test(rotation_Y, deg90)
{
    sf::Vector3f v(1, 1, 1);
    auto rot = render::Ray::rotateY(v, M_PI / 2);
    cr_assert_float_eq(rot.x, 1, EPS);
    cr_assert_float_eq(rot.y, 1, EPS);
    cr_assert_float_eq(rot.z, -1, EPS);
}

Test(rotation_Z, deg90)
{
    sf::Vector3f v(1, 1, 1);
    auto rot = render::Ray::rotateZ(v, M_PI / 2);
    cr_assert_float_eq(rot.x, -1, EPS);
    cr_assert_float_eq(rot.y, 1, EPS);
    cr_assert_float_eq(rot.z, 1, EPS);
}


Test(rotation_Componsite, deg909090)
{
    sf::Vector3f v(20, 7, 8);
    auto rot = render::Ray::rotateVector(v, {90, 90, 90});
    cr_assert_float_eq(rot.x, 8, EPS);
    cr_assert_float_eq(rot.y, 7, EPS);
    cr_assert_float_eq(rot.z, -20, EPS);
}
