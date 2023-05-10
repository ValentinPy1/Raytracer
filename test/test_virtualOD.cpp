/*
** EPITECH PROJECT, 2022
** ray
** File description:
** test_virtualOD.cpp
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.hpp>
#include "Ray.hpp"

#define EPS 0.0001
#define showVect(vec) std::cout << #vec << " " << vec.x << " " << vec.y << " " << vec.z << std::endl;

void assert_vec_equal(sf::Vector3f v1, sf::Vector3f v2)
{
    cr_assert_float_eq(v1.x, v2.x, EPS);
    cr_assert_float_eq(v1.y, v2.y, EPS);
    cr_assert_float_eq(v1.z, v2.z, EPS);
}

Test(virtual_position, all_cases)
{
    sf::Vector3f translation(1, 0, 0);
    sf::Vector3f rotation(0, 90, 0);
    float scale(1);

    sf::Vector3f origin(0, 0, 0);
    sf::Vector3f direction(0, 1, 0);

    // simple translation
    render::Ray r1 = render::Ray(origin, direction, 0);
    auto v1 = r1.getVirtualOrigin({0, 0, 0}, translation, scale);
    sf::Vector3f expected1(-1, 0, 0);
    assert_vec_equal(v1, expected1);
    v1 = r1.getVirtualDirection({0, 0, 0});
    expected1 = sf::Vector3f(0, 1, 0);
    assert_vec_equal(v1, expected1);

    // simple rotation
    render::Ray r2 = render::Ray(origin, direction, 0);
    auto v2 = r2.getVirtualOrigin(rotation, {0, 0, 0}, scale);
    sf::Vector3f expected2(0, 0, 0);
    assert_vec_equal(v2, expected2);
    v2 = r2.getVirtualDirection(rotation);
    expected2 = sf::Vector3f(0, 1, 0);
    assert_vec_equal(v2, expected2);

    // simple scaling
    origin = {10, 10, 10};
    render::Ray r3 = render::Ray(origin, direction, 0);
    auto v3 = r3.getVirtualOrigin({0, 0, 0}, {0, 0, 0}, 10);
    sf::Vector3f expected3(1, 1, 1);
    assert_vec_equal(v3, expected3);
}

Test(virtual_normal, easytest)
{
    sf::Vector3f rotation(0, 90, 0);
    sf::Vector3f normal(1, 0, 0);
    render::Ray r = render::Ray({0, 0, 0}, {0, 1, 0}, 0);

    auto v = render::Ray::getVirtualNormal(normal, rotation);
    sf::Vector3f expected(0, 0, 1);
    assert_vec_equal(v, expected);
}
