/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** operations.cpp
*/

#ifndef OPERATIONS_HPP
    #define OPERATIONS_HPP
    #include <SFML/Graphics.hpp>

// member to member multiplication
float operator *(sf::Vector3f left, sf::Vector3f right);
// member to member division
float operator /(sf::Vector3f left, sf::Vector3f right);
// dot product
float operator %(sf::Vector3f left, sf::Vector3f right);
// cross product
sf::Vector3f operator ^(sf::Vector3f left, sf::Vector3f right);
// member to member addition
sf::Vector3f operator +(sf::Vector3f left, sf::Vector3f right);
// member to member subtraction
sf::Vector3f operator -(sf::Vector3f left, sf::Vector3f right);

// scalar multiplication
sf::Vector3f operator *(sf::Vector3f left, float right);
sf::Vector3f operator *(float a, sf::Vector3f b);
// scalar multiplication
sf::Vector3f operator *(sf::Vector3f left, int right);
sf::Vector3f operator *(int a, sf::Vector3f b);
// scalar division
sf::Vector3f operator /(sf::Vector3f left, float right);
sf::Vector3f operator /(sf::Vector3f left, int right);
//scalar division
sf::Vector3f operator /(float left, sf::Vector3f right);
sf::Vector3f operator /(int left, sf::Vector3f right);
// scalar addition
sf::Vector3f operator +(sf::Vector3f left, float right);
sf::Vector3f operator +(sf::Vector3f left, int right);
// scalar addition
sf::Vector3f operator +(float left, sf::Vector3f right);
sf::Vector3f operator +(int left, sf::Vector3f right);
// scalar subtraction
sf::Vector3f operator -(sf::Vector3f left, float right);
sf::Vector3f operator -(sf::Vector3f left, int right);
// scalar subtraction
sf::Vector3f operator -(float left, sf::Vector3f right);
sf::Vector3f operator -(int left, sf::Vector3f right);

std::ostream &operator <<(std::ostream &os, sf::Vector3f vec);

#endif // OPERATIONS_HPP
