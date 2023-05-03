/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.gl.cpp
*/

#include <ctime>
#include "renderColors.hpp"
#include "Renderer.hpp"
#include "Wrapper.gl.hpp"
#include "IOpglPrimitiveHelper.hpp"
#include "ShaderPlugin.hpp"
#include "Wrapper.hpp"
#include "Opgl.hpp"
#include "VBO.hpp"
#include "SSBO.hpp"

namespace gpu {
    Wrapper_gl::Wrapper_gl() :
        _opgl(w, h)
    {
        _opgl.setContextCurrent();
    }

    Wrapper_gl::~Wrapper_gl()
    {
        if (_vertices)
            delete[] _vertices;
        if (_objVertices)
            delete[] _objVertices;
    }

    void Wrapper_gl::run(render::Renderer &rdr)
    {
        try {
            std::cout << render::green << "[INFO] " << render::yellow << "Initializing shader pipeline..." << render::no_color << std::endl;
            initProgram(rdr);
            std::cout << render::green << "[INFO] " << render::yellow << "Initializing vertices..." << render::no_color << std::endl;
            initCamera();
            std::cout << render::green << "[INFO] " << render::yellow << "Initializing objects..." << render::no_color << std::endl;
            initObjects3D(rdr);
        } catch (std::exception &e) {
            std::cerr << render::red << "[ERROR] " << render::no_color << e.what() << std::endl;
            exit(84);
        }
        runWindow();
    }

    void Wrapper_gl::runWindow()
    {
        _opgl.setContextCurrent();
        _shaderProgram->use();

        struct Light lights[] = {{ // TODO actual lights from config
            {0.0, -0.3, 0.0},
            {0.0, 1.0, 1.0}
        }};


        // ASSIGNING THE UNIFORMS
        _shaderProgram->setUniform3f("focalPoint", 0.0, 0.0, -1);
        _shaderProgram->setUniform2f("u_resolution", w, h);

        // CREATING THE VBO AND ASSIGNING THE DATA, ONE VERTEX PER PIXEL
        VBO vbo;
        vbo.bind();
        vbo.setData(_vertices, sizeof(float) * w * h * 2);
        vbo.setVertexAttributes(0, 3, GL_FLOAT, GL_FALSE, 0, _vertices);

        // CREATING THE SSBO AND ASSIGNING THE DATA, ALL OF THE OBJECTS IN THE SCENE
        SSBO objBlock(1, sizeof(float) * 3 * 3 * _nObjects);
        objBlock.bind();
        objBlock.setData(_objVertices);

        // CREATING THE SSBO CONTAINING THE LIGHTS
        SSBO lightBlock(2, sizeof(lights));
        lightBlock.bind();
        lightBlock.setData(lights);

        clock_t tick = clock();
        std::cout << render::green << "[INFO] " << render::yellow << "Rendering..." << render::no_color << std::endl;
        while (!glfwWindowShouldClose(_opgl.getWindow())) {
            _opgl.clearScr();
            _opgl.drawNPoints(w * h);
            glfwSwapBuffers(_opgl.getWindow());
            glfwPollEvents();
            std::cout << render::green << "[INFO] " << render::yellow << "FPS: " << CLOCKS_PER_SEC / (clock() - tick) << render::no_color << "\r";
            tick = clock();
        }
    }

    void Wrapper_gl::initCamera()
    {
        int index = 0;

        if (_vertices != nullptr)
            delete[] _vertices;
        _vertices = new float[w * h * 2]();
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                _vertices[index] = -1.0f + 2.0f * x / w;
                _vertices[index + 1] = -1.0f + 2.0f * y / h;
                index += 2;
            }
        }
    }

    void Wrapper_gl::initObjects3D(render::Renderer &rdr) {
        std::vector<std::shared_ptr<render::Entity>>  entities = rdr.getEntities();
        size_t index = 0;
        if (_objVertices != nullptr)
            delete[] _objVertices;
        _objVertices = new float[entities.size() * 3 * 3]();
        std::cout << render::green << "[INFO] " << render::yellow << "Found " << entities.size() << " entities" << render::no_color << std::endl;
        _nObjects = entities.size();
        for (auto e : entities) {
            auto opglInitializer = e->getPlugin("opglPrimitiveHelper");
            if (!opglInitializer)
                continue;
            auto opglPrimHelper = std::dynamic_pointer_cast<gpu::IOpGLPrimitiveHelper>(opglInitializer);
            if (!opglPrimHelper)
                continue;
            auto tmpVertices = opglPrimHelper->getVertices();
            if (index + 2 >= entities.size() * 3)
                throw std::runtime_error("Too many vertices");
            for (auto v : tmpVertices) {
                _objVertices[index] = v.x;
                _objVertices[index + 1] = v.y;
                _objVertices[index + 2] = v.z;
                index += 3;
            }
        }
    }

    void Wrapper_gl::initProgram(render::Renderer &rdr)
    {
        std::vector<std::string> shaders;

        for (auto p : rdr.getPluginManager().getPlugins()) {
            auto shaderPlugin = std::dynamic_pointer_cast<gpu::ShaderPlugin>(p);
            if (!shaderPlugin) {
                std::cerr << render::yellow << "[WARNING]: " << render::no_color << "Plugin " << p->getName() << " is not compatible with OpenGL." << std::endl;
                continue;
            }
            shaders.push_back(shaderPlugin->getPath());
            std::cout << render::green << "[INFO]: " << render::no_color << "Plugin " << p->getName() << " registered." << std::endl;
        }
        try {
            _shaderProgram = std::make_shared<ShaderProgram>(shaders);
        } catch (std::exception &e) {
            std::cerr << render::red << "[ERROR] : " << render::no_color << e.what() << std::endl;
            exit(84);
        }
    }
}

extern "C" {
    render::IWrapper *entryPoint()
    {
        return new gpu::Wrapper_gl();
    }
}
