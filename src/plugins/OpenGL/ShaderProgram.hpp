/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ShaderProgram.hpp
*/

#ifndef F34F6F48_E495_4AD6_912E_E6C8A165AD33
#define F34F6F48_E495_4AD6_912E_E6C8A165AD33

#include "Opgl.hpp"

namespace gpu {
    class ShaderProgram {
        public:
            ShaderProgram(std::vector<std::string> shaderPath);

            ~ShaderProgram();

            void use();

            void setUniform3f(const std::string &uniName, float v0, float v1, float v2);

            void setUniform1f(const std::string &uniName, float v0);

            void setUniform2f(const std::string &uniName, float v0, float v1);

            GLuint getId() const;

        private:
            bool strEndsWith(const std::string &str, const std::string &end);

            GLuint loadShader(const std::string &path);

            GLuint _id;
    };
}

#endif /* F34F6F48_E495_4AD6_912E_E6C8A165AD33 */
