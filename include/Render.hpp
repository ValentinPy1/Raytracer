/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Render.hpp
*/

#ifndef C9603BB3_6860_40CC_8EF4_BDE779380824
    #define C9603BB3_6860_40CC_8EF4_BDE779380824
    #include <vector>
    #include <fstream>
    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <thread>
    #include <mutex>
    #include "Pipeline.hpp"
    #include "Light.hpp"

namespace render {
    class Ray;
    class IObject;
    class Logger {
        public:
            Logger();
            ~Logger();
            void log(const std::string &message);
            void logError(const std::string &message);
            void logWarning(const std::string &message);
        private:
            std::ofstream _logFile;
    };

    class Camera {
    public:
        Camera(float focalPoint, int captorWidth, int captorHeight, const sf::Vector3f &position, const sf::Vector3f &rotation);
        ~Camera() = default;

        sf::Image &getCaptor();
        sf::Vector3f getPosition() const;
        sf::Vector3f getRotation() const;
        sf::Vector3f getFocalPoint() const;
        std::vector<render::Ray> &getRays();
        void updatePixelLine(int i, std::vector<Ray> &rays, Renderer &rdr);

    private:
        sf::Vector3f computeFocalPoint(float focalPoint) const;

        std::vector<render::Ray> _rays;
        sf::Vector3f _position = {0, 0, 0};
        sf::Vector3f _rotation = {0, 0, 0};
        sf::Vector3f _focalPoint;
        sf::Image _captor;
        sf::Vector2i _captorSize = {10, 10}; // in world units
        float scale = 10;
    };

    class Renderer {
        public:
            Renderer(int lightSamples = 10, int imSide = 1000, int focalPoint = 50);
            ~Renderer() = default;
            std::vector<std::shared_ptr<render::IObject>> getObjects() const;
            void loadScene();
            void render();
            Camera &getCamera();
            void setAmbientLight(const sf::Color &color);
            sf::Color getAmbientLight() const;
            std::vector<Light> getLights() const;
            void addLight(const Light &light);
            void addLights(const std::vector<Light> &lights);
            void updatePixelLine(int i);

        private:
            void setupPipeline();
            void showProgressBar(int total, std::string message = "");
            int _progress = 0;
            std::vector<std::shared_ptr<render::IObject>> _objects;
            Camera _camera;
            pp::Pipeline<render::Ray &, Renderer &, render::Ray &> _pipeline;
            Logger _logs;
            sf::Color _ambientLight = {50, 33, 25};
            std::vector<Light> _lights;
            int _lightSamples;
            std::mutex _mutex;
    };
}

#endif /* C9603BB3_6860_40CC_8EF4_BDE779380824 */
