/*
** EPITECH PROJECT, 2022
** ray
** File description:
** geometry.hpp
*/

#ifndef C9B1B91F_25EA_4255_B745_D588361FC535
    #define C9B1B91F_25EA_4255_B745_D588361FC535

namespace geo {
    struct vec3 {
        float x;
        float y;
        float z;

        // member to member addition
        vec3 operator+(const vec3 &other) const;
        // member to member substraction
        vec3 operator-(const vec3 &other) const;
        // dot product
        float operator*(const vec3 &other) const;
        // member to member division
        vec3 operator/(const vec3 &other) const;
        // cross product
        vec3 operator^(const vec3 &other) const;
        // scalar multiplication
        vec3 operator*(float scalar) const;
        // scalar division
        vec3 operator/(float scalar) const;
    };
}

#endif /* C9B1B91F_25EA_4255_B745_D588361FC535 */
