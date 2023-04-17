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
    #include "PluginManager.hpp"

namespace render {
    class Ray;
    class IObject;

    static const std::string red = "\033[31m";
    static const std::string green = "\033[32m";
    static const std::string yellow = "\033[33m";
    static const std::string blue = "\033[34m";
    static const std::string magenta = "\033[35m";
    static const std::string no_color = "\033[0m";

    /**
     * @brief The Logger class is responsible for logging messages in a file so
     * that the user can see what is happening in the program.
     *
     */
    class Logger {
        public:

            Logger();
            ~Logger();

            /**
             * @brief Log a message in the log file with the [INFO] prefix.
             *
             * @param message
             */
            void log(const std::string &message);

            /**
             * @brief Log a message in the log file with the [ERROR] prefix.
             *
             * @param message
             */
            void logError(const std::string &message);

            /**
             * @brief Log a message in the log file with the [WARNING] prefix.
             *
             * @param message
             */
            void logWarning(const std::string &message);
        private:
            std::ofstream _logFile;
    };

    /**
     * @brief The Camera class is responsible for generating the rays.
     * Just like a real camera, it has a focal point, as well as a
     * captor (which is the device onto which the light is projected).
     *
     * The rays are generated from the focal point, and pass through each pixel
     * of the captor.
     *
     */
    class Camera {
    public:
        Camera(float focalPoint = 10, int captorWidth = 0, int captorHeight = 0, const sf::Vector3f &position = sf::Vector3f(0, 0, 0), const sf::Vector3f &rotation = sf::Vector3f(0, 0, 0));
        ~Camera() = default;

        /**
         * @brief Return the captor of the camera.
         *
         * @return sf::Image&
         */
        sf::Image &getCaptor();

        /**
         * @brief Returns the position of the camera in the 3D space.
         *
         * @return sf::Vector3f
         */
        sf::Vector3f getPosition() const;

        /**
         * @brief Returns the rotation of the camera in the 3D space.
         *
         * @return sf::Vector3f
         */
        sf::Vector3f getRotation() const;

        /**
         * @brief Returns the focal point of the camera as a point in space.
         *
         * @return sf::Vector3f
         */
        sf::Vector3f getFocalPoint() const;

        /**
         * @brief Returns the rays generated by the camera.
         *
         * @return std::vector<render::Ray>&
         */
        std::vector<render::Ray> &getRays();

        /**
         * @brief Sets the position of the camera in the 3D space.
         *
         * @param position
         */
        void setPosition(const sf::Vector3f &position);

        /**
         * @brief Sets the rotation of the camera in the 3D space.
         *
         * @param rotation
         */
        void setRotation(const sf::Vector3f &rotation);

        /**
         * @brief Sets the focal point of the camera.
         *
         * @param focalPoint
         */
        void setFocalPoint(float focalPoint);

        /**
         * @brief Sets the size of the captor in world unit.
         *
         * @param size
         */
        void setCaptorSize(const sf::Vector2i &size);

        /**
         * @brief Sets the focal scale of the world.
         *
         * @param scale
         */
        void setScale(float scale);

    private:
        /**
         * @brief Generates the rays from the focal point to the captor.
         *
         */
        void generateRays();

        /**
         * @brief Computes the position of the focal point from the specified
         * focal distance and the position of the camera.
         *
         * @param focalPoint , the distance between the camera and the focal point.
         * @return sf::Vector3f
         */
        sf::Vector3f computeFocalPoint(float focalPoint) const;

        /**
         * @brief All of the rays generated by the camera.
         *
         */
        std::vector<render::Ray> _rays;

        /**
         * @brief The position of the camera in the 3D space.
         *
         */
        sf::Vector3f _position = {0, 0, 0};

        /**
         * @brief The rotation of the camera in the 3D space.
         *
         */
        sf::Vector3f _rotation = {0, 0, 0};

        /**
         * @brief The focal point of the camera.
         *
         */
        sf::Vector3f _focalPoint;

        /**
         * @brief The captor of the camera.
         *
         */
        sf::Image _captor;

        /**
         * @brief The size of the captor in world unit.
         *
         */
        sf::Vector2i _captorSize = {10, 10}; // in world units

        /**
         * @brief The focal scale of the world.
         *
         */
        float scale = 10;
    };

    /**
     * @brief The renderer class is the main class of the raytracer.
     * It is responsible for the rendering of the scene, holding the objects
     * the camera, and the lights.
     *
     */
    class Renderer {
        public:
            Renderer(int lightSamples = 10, int imSide = 1000, int focalPoint = 50);
            ~Renderer() = default;
            /**
             * @brief returns all the objects in the scene, without the lights.
             *
             * @return std::vector<std::shared_ptr<render::IObject>>
             */
            std::vector<std::shared_ptr<render::IObject>> getObjects() const;

            /**
             * @brief Loads the scene from a config file.
             *
             */
            void loadScene();

            /**
             * @brief executes the rendering of the scene and saves the image.
             *
             */
            void render();

            /**
             * @brief Returns the Camera object.
             *
             * @param object
             */
            Camera &getCamera();

            /**
             * @brief ASets the Ambient light of the scene, that is the default
             * color to be rendered when a ray hits an object but
             * is in the shadow.
             *
             * @param object
             */
            void setAmbientLight(const sf::Color &color);

            /**
             * @brief Returns the ambient light of the scene.
             *
             * @param object
             */
            sf::Color getAmbientLight() const;

            /**
             * @brief returns all the lights of the scene.
             *
             * @return std::vector<Light>
             */
            std::vector<Light> getLights() const;

            /**
             * @brief Adds an Light to the scene.
             *
             * @param object
             */
            void addLight(const Light &light);

            /**
             * @brief Adds multiple lights to the scene.
             *
             * @param object
             */
            void addLights(const std::vector<Light> &lights);

            /**
             * @brief Calls the rendering pipeline on a whole line of pixels
             * from the camera's captor.
             *
             * @param object
             */
            void updatePixelLine(int i);

            /**
             * @brief Call the init function of all the plugins that have one.
             * Loads all the plugins and the scene.
             *
             */
            void init();


            /**
            * @brief Sets the position of the camera in the 3D space.
            *
            * @param position
            */
            void setCamera(Camera &camera);


            /**
             * @brief Adds an object to the scene.
             *
             * @param object
             */
            void pushObject(std::shared_ptr<render::IObject> object);

        private:
            /**
             * @brief Processes a ray and returns the color of the object it hits.
             * This function uses only the rendering pipeline defined by the
             * loaded plugins.
             *
             * @param ray
             * @return * sf::Color
             */
            sf::Color processRay(Ray &ray) const;

            /**
             * @brief To be called after the rendering is done. This function
             * will call all the post processing functions found in the
             * plugins.
             *
             */
            void postProcess();

            /**
             * @deprecated, will be removed in the future.
             */
            void setupPipeline();

            /**
             * @brief Shows a progress bar in the console. The value of the
             * progress gets incremented everytime this function is called.
             * This function is thread safe.
             *
             * @param object
             */
            void showProgressBar(int total, std::string message = "");

            /**
             * @brief All the functions found from plugins that will be called
             * when a ray is processed.
             *
             */
            std::vector<processRay_t> _rayProcess;

            /**
             * @brief All the functions found from plugins that will be called
             * after the rendering is done.
             *
             */
            std::vector<postProcess_t> _postProcess;

            /**
             * @brief The plugin manager that will load all the plugins.
             *
             */
            PluginManager _pluginManager;

            /**
             * @brief The progress of the rendering. This value is incremented
             * everytime the showProgressBar function is called.
             *
             */
            int _progress = 0;

            /**
             * @brief List of all of the objects of the Scene. Note that Lights
             * are not considered objects.
             *
             */
            std::vector<std::shared_ptr<render::IObject>> _objects;

            /**
             * @brief The Camera of the scene.
             *
             */
            Camera _camera;

            /**
             * @brief
             *
             * @deprecated
             */
            pp::Pipeline<render::Ray &, Renderer &, render::Ray &> _pipeline;

            /**
             * @brief The logger of the renderer. Use this object to log
             * messages during runtime without having to worry about
             * displaying to many things in the console: the messages will be saved
             * in a file.
             *
             */
            Logger _logs;

            /**
             * @brief The ambient light of the scene. This is the default color
             * to be rendered when a ray hits an object but is in the shadow.
             *
             */
            sf::Color _ambientLight = {50, 33, 25};

            /**
             * @brief The lights of the scene.
             *
             */
            std::vector<Light> _lights;

            /**
             * @brief The number of samples to be taken for each light.
             * A Higher number will result in a more realistic rendering
             * but will also take longer to render.
             *
             */
            int _lightSamples;

            /**
             * @brief The object that will be used to lock the progress bar
             * and other objects during rendering.
             *
             */
            std::mutex _mutex;
    };
}

#endif /* C9603BB3_6860_40CC_8EF4_BDE779380824 */
