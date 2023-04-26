/*
** EPITECH PROJECT, 2022
** ray
** File description:
** geometry.cpp
*/

#include "geometry.hpp"

namespace geo
{
    vec3 vec3::operator+(const vec3 &other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    vec3 vec3::operator-(const vec3 &other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    float vec3::operator*(const vec3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    vec3 vec3::operator/(const vec3 &other) const
    {
        return {x / other.x, y / other.y, z / other.z};
    }

    // cross product 3D
    vec3 vec3::operator^(const vec3 &other) const
    {
        return {y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x};
    }

    vec3 vec3::operator*(float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    vec3 vec3::operator/(float scalar) const
    {
        return {x / scalar, y / scalar, z / scalar};
    }

} // namespace geo
