/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** operations.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/operations.hpp"


#include <SFML/System/Vector3.hpp>

// member to member multiplication
float operator *(sf::Vector3f left, sf::Vector3f right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

// member to member division
float operator /(sf::Vector3f left, sf::Vector3f right)
{
    return left.x / right.x + left.y / right.y + left.z / right.z;
}

// dot product
float operator %(sf::Vector3f left, sf::Vector3f right)
{
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

// cross product
sf::Vector3f operator ^(sf::Vector3f left, sf::Vector3f right)
{
    return sf::Vector3f(
        left.y * right.z - left.z * right.y,
        left.z * right.x - left.x * right.z,
        left.x * right.y - left.y * right.x
    );
}

// member to member addition
sf::Vector3f operator +(sf::Vector3f left, sf::Vector3f right)
{
    return sf::Vector3f(left.x + right.x, left.y + right.y, left.z + right.z);
}

// member to member subtraction
sf::Vector3f operator -(sf::Vector3f left, sf::Vector3f right)
{
    return sf::Vector3f(left.x - right.x, left.y - right.y, left.z - right.z);
}

// scalar multiplication
sf::Vector3f operator *(sf::Vector3f left, float right)
{
    return sf::Vector3f(left.x * right, left.y * right, left.z * right);
}

sf::Vector3f operator *(float left, sf::Vector3f right)
{
    return sf::Vector3f(right.x * left, right.y * left, right.z * left);
}

// scalar multiplication
sf::Vector3f operator *(sf::Vector3f left, int right)
{
    return sf::Vector3f(left.x * right, left.y * right, left.z * right);
}

sf::Vector3f operator *(int left, sf::Vector3f right)
{
    return sf::Vector3f(right.x * left, right.y * left, right.z * left);
}

// scalar division
sf::Vector3f operator /(sf::Vector3f left, float right)
{
    return sf::Vector3f(left.x / right, left.y / right, left.z / right);
}

sf::Vector3f operator /(sf::Vector3f left, int right)
{
    return sf::Vector3f(left.x / right, left.y / right, left.z / right);
}

//scalar division
sf::Vector3f operator /(float left, sf::Vector3f right)
{
    return sf::Vector3f(left / right.x, left / right.y, left / right.z);
}

sf::Vector3f operator /(int left, sf::Vector3f right)
{
    return sf::Vector3f(left / right.x, left / right.y, left / right.z);
}

// scalar addition
sf::Vector3f operator +(sf::Vector3f left, float right)
{
    return sf::Vector3f(left.x + right, left.y + right, left.z + right);
}

sf::Vector3f operator +(sf::Vector3f left, int right)
{
    return sf::Vector3f(left.x + right, left.y + right, left.z + right);
}

sf::Vector3f operator +(float left, sf::Vector3f right)
{
    return sf::Vector3f(right.x + left, right.y + left, right.z + left);
}

sf::Vector3f operator +(int left, sf::Vector3f right)
{
    return sf::Vector3f(right.x + left, right.y + left, right.z + left);
}

// scalar subtraction
sf::Vector3f operator -(sf::Vector3f left, float right)
{
    return sf::Vector3f(left.x - right, left.y - right, left.z - right);
}

sf::Vector3f operator -(sf::Vector3f left, int right)
{
    return sf::Vector3f(left.x - right, left.y - right, left.z - right);
}

sf::Vector3f operator -(float left, sf::Vector3f right)
{
    return sf::Vector3f(left - right.x, left - right.y, left - right.z);
}

sf::Vector3f operator -(int left, sf::Vector3f right)
{
    return sf::Vector3f(left - right.x, left - right.y, left - right.z);
}

std::ostream &operator <<(std::ostream &os, sf::Vector3f vec)
{
    os << "(" << std::to_string(vec.x) << ", " << std::to_string(vec.y) << ", " << std::to_string(vec.z) << ")";
    return os;
}
