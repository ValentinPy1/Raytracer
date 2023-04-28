/*
** EPITECH PROJECT, 2022
** tests
** File description:
** main.cpp
*/

#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <GL/glew.h>
#include "glfw/include/GLFW/glfw3.h"
#include <stdexcept>

#define callgl(fun) getGl<decltype(fun)>(#fun)
template <typename T>
static T getGl(const std::string &name) {
    T var = (T) glfwGetProcAddress(name.c_str());
    if (var == 0)
        throw std::runtime_error("Failed to get function " + name);
    return var;
}

class Opgl {
    public:
        Opgl(unsigned int width, unsigned int height) {
            if (!glfwInit())
                throw std::runtime_error("Failed to init glfw");
            _window = glfwCreateWindow(width, height, "", nullptr, nullptr);
            if (!_window) {
                glfwTerminate();
                throw std::runtime_error("Failed to create window");
            }
            glfwMakeContextCurrent(_window);
            if (glewInit() != GLEW_OK)
                throw std::runtime_error("Failed to init glew");
        };

        ~Opgl() {
            glfwTerminate();
        };

        void setContextCurrent() {
            glfwMakeContextCurrent(_window);
        }

        void setWindow(GLFWwindow *window) { _window = window; }

        void drawNPoints(unsigned int n) {
            glDrawArrays(GL_POINTS, 0, n);
        }

        void clearScr() {
            glClear(GL_COLOR_BUFFER_BIT);
        }
        GLFWwindow *getWindow() const { return _window; }
    private:
        GLFWwindow *_window;
};

class VBO {
    public:
        VBO() {
            callgl(glGenBuffers)(1, &_id);
        }
        ~VBO() {
            callgl(glDeleteBuffers)(1, &_id);
        }
        void bind() {
            callgl(glBindBuffer)(GL_ARRAY_BUFFER, _id);
        }
        void setData(const void *data, size_t size, GLenum usage = GL_STATIC_DRAW) {
            callgl(glBufferData)(GL_ARRAY_BUFFER, size, data, usage);
        }
        void setVertexAttributes(GLuint index, size_t size, GLenum type, GLboolean normalized, size_t stride, const void *pointer) {
            callgl(glVertexAttribPointer)(index, size, type, normalized, stride, pointer);
            callgl(glEnableVertexAttribArray)(index);
        }
    private:
        GLuint _id;
};

class SSBO {
    public:
        SSBO(GLuint bindingPoint, size_t size) :
            _bindingPoint(bindingPoint), _size(size) {
            callgl(glGenBuffers)(1, &_id);
        }

        ~SSBO() {
            callgl(glDeleteBuffers)(1, &_id);
        }

        void bind(GLuint offset = 0) {
            callgl(glBindBufferRange)(GL_SHADER_STORAGE_BUFFER, _bindingPoint, _id, offset, _size);
        }

        void setData(const void *data, GLenum usage = GL_STATIC_DRAW) {
            callgl(glBufferData)(GL_SHADER_STORAGE_BUFFER, _size, data, usage);
            callgl(glBindBufferBase)(GL_SHADER_STORAGE_BUFFER, _bindingPoint, _id);
        }
    private:
        GLuint _id;
        GLuint _bindingPoint;
        size_t _size;
};

class ShaderProgram {
    public:
        ShaderProgram(std::vector<std::string> shaderPath) {
            _id = callgl(glCreateProgram)();
            std::vector<GLuint> shaders;
            for (auto &path : shaderPath) {
                shaders.push_back(loadShader(path));
                callgl(glAttachShader)(_id, shaders.back());
            }
            callgl(glLinkProgram)(_id);
            for (auto &shader : shaders)
                callgl(glDeleteShader)(shader);
        }
        ~ShaderProgram() {
            callgl(glDeleteProgram)(_id);
        }
        void use() {
            callgl(glUseProgram)(_id);
        }
        void setUniform3f(const std::string &uniName, float v0, float v1, float v2) {
            callgl(glUniform3f)(callgl(glGetUniformLocation)(_id, uniName.c_str()), v0, v1, v2);
        }

        void setUniform1f(const std::string &uniName, float v0) {
            callgl(glUniform1f)(callgl(glGetUniformLocation)(_id, uniName.c_str()), v0);
        }

        void setUniform2f(const std::string &uniName, float v0, float v1) {
            callgl(glUniform2f)(callgl(glGetUniformLocation)(_id, uniName.c_str()), v0, v1);
        }

        GLuint getId() const { return _id; }

    private:
        bool strEndsWith(const std::string &str, const std::string &end) {
            if (end.size() > str.size()) return false;
                return std::equal(end.rbegin(), end.rend(), str.rbegin());
        }
        GLuint loadShader(const std::string &path)
        {
            std::cout << "loading " << path << std::endl;
            std::ifstream f(path);
            std::stringstream buffer;
            std::string srcContent;
            const char *src;

            GLuint id;
            GLenum type = (strEndsWith(path, ".vert")) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

            if (!f.is_open())
                throw std::runtime_error("Failed to open shader file");
            buffer << f.rdbuf();
            srcContent = buffer.str();
            src = (char *) srcContent.c_str();

            id = callgl(glCreateShader)(type);
            callgl(glShaderSource)(id, 1, &src, NULL);
            callgl(glCompileShader)(id);

            int  success;
            char infoLog[512];
            callgl(glGetShaderiv)(id, GL_COMPILE_STATUS, &success);
            if (!success) {
                callgl(glGetShaderInfoLog)(id, 512, NULL, infoLog);
                throw std::runtime_error("Failed to compile shader: " + std::string(infoLog));
            }
            return id;
        }

        GLuint _id;
};

int main()
{
    // DEFINITION OF THE VARIABLES WHICH WILL BE PASSED TO THE SHADERS
    int h = 600;
    int w = 600;
    Opgl opgl(w, h);
    opgl.setContextCurrent();

    float vertices[w * h * 2];

    int index = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            vertices[index] = -1.0f + 2.0f * x / w;
            vertices[index + 1] = -1.0f + 2.0f * y / h;
            index += 2;
        }
    }


    struct vec3 {
        float x;
        float y;
        float z;
    };

    struct Obj {
        struct vec3 position;
        struct vec3 rotation;
    };

    struct Obj obj[] = {{
        {0.0, 0.4, 0.4},
        {0.0, 0.0, 0.0}
    },
    {
        {0.0, -0.4, 0.4},
        {0.0, 0.0, 0.0}
    }};

    struct Light {
        struct vec3 position;
        struct vec3 color;
    };

    struct Light lights[] = {{
        {0.0, -0.3, 0.0},
        {0.0, 1.0, 1.0}
    }};

    // CREATING THE PROGRAM AND LINKING THE SHADERS
    ShaderProgram shaderProgram({
        "./vertex.vert",
        "./main.frag",
        "./trace.frag",
        "./intersect.frag",
        "./light.frag",
        "./blinnPhong.frag",
        "./blendColors.frag",
        // "./reflect.frag",
    });
    shaderProgram.use();

    // ASSIGNING THE UNIFORMS
    shaderProgram.setUniform3f("focalPoint", 0.0, 0.0, -1);
    shaderProgram.setUniform2f("u_resolution", w, h);

    // CREATING THE VBO AND ASSIGNING THE DATA, ONE VERTEX PER PIXEL
    VBO vbo;
    vbo.bind();
    vbo.setData(vertices, sizeof(vertices));
    vbo.setVertexAttributes(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);

    // CREATING THE SSBO AND ASSIGNING THE DATA, ALL OF THE OBJECTS IN THE SCENE
    SSBO objBlock(1, sizeof(obj));
    objBlock.bind();
    objBlock.setData(obj);

    // CREATING THE SSBO CONTAINING THE LIGHTS
    SSBO lightBlock(2, sizeof(lights));
    lightBlock.bind();
    lightBlock.setData(lights);

    // DISPLAYING THE WINDOW
    // sleep .1 seconds to let the window appear
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    while (!glfwWindowShouldClose(opgl.getWindow())) {
        opgl.clearScr();
        opgl.drawNPoints(w * h);
        glfwSwapBuffers(opgl.getWindow());
        glfwPollEvents();
    }
    return 0;
}
