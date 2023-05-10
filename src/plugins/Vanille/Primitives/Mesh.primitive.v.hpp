/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Mesh.primitive.v.hpp
*/

#ifndef D177BBBB_1536_4248_A06A_C92B2A6C6881
    #define D177BBBB_1536_4248_A06A_C92B2A6C6881

#include <libconfig.h++>
#include "IPrimitive.hpp"
#include "Entity.hpp"
#include "Ray.hpp"
#include "DLLoader.hpp"

namespace vanille
{
    class IMeshPart : public render::IPrimitive {
        public:
            virtual ~IMeshPart() = default;
            // virtual void selfInit(libconfig::Setting &setting, render::Entity *parent) = 0;
            // virtual sf::Vector3f getNormalAt(sf::Vector3f &point) = 0;
            // virtual void solve(render::Ray &ray) = 0;

            /**
             * @brief Moves the mesh part by the given offset.
             *
             * @param offset
             */
            virtual void move(sf::Vector3f &offset) = 0;

            /**
             * @brief Rotates the mesh part by the given rotation.
             *
             * @param rotation
             */
            virtual void rotate(sf::Vector3f &rotation, sf::Vector3f center) = 0;

            /**
             * @brief Scales the mesh part by the given factor.
             *
             * @param factor
             */
            virtual void scale(float factor) = 0;
    };

    class TrianglePart : public IMeshPart {
        public:
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;
            void move(sf::Vector3f &offset) override;
            void rotate(sf::Vector3f &rotation, sf::Vector3f center) override;
            void scale(float factor) override;


            sf::Vector3f getRotation() const override;
            sf::Vector3f getTranslation() const override;
            float getScale() const override;
        private:
            void computePointRotation(sf::Vector3f &point, sf::Vector3f &rotation, sf::Vector3f barycenter);
            sf::Vector3f _p1;
            sf::Vector3f _p2;
            sf::Vector3f _p3;
            sf::Vector3f _normal;
            render::Entity *_parent;

            sf::Vector3f _translation;
            sf::Vector3f _rotation;
            float _scale;
    };

    /**
     * @brief This class is a kind of bundle of primitives grouped in a
     * single entity. It can be used to created complex shapes with a unified
     * position. The positions of the parts should be given as local coordinates.
     *
     * @details In the configuration file, the expected format is as follows:
     * {
     *     primitive = {
     *          type = "Mesh";
     *          args = {
     *             primitives = (
     *                // describe the primitives here as usual
     *             );
     *          };
     *     }
     * }
     *
     */
    class Mesh : public render::IPrimitive {
        public:
            void selfInit(libconfig::Setting &setting, render::Entity *parent) override;
            sf::Vector3f getNormalAt(sf::Vector3f &point) override;
            void solve(render::Ray &ray) override;

            sf::Vector3f getRotation() const override;
            sf::Vector3f getTranslation() const override;
            float getScale() const override;
        private:
            /**
             * @brief Loads a part of the mesh from the configuration file.
             *
             * @param setting
             * @param parent
             */
            void loadPart(const libconfig::Setting &setting, render::Entity *parent);
            // std::vector<std::shared_ptr<IMeshPart>> _parts;
            std::vector<std::shared_ptr<IMeshPart>> _parts;
            IMeshPart *_lasthit = nullptr;
            render::DLLoader _loader;

            sf::Vector3f _position = {0, 0, 0};
            sf::Vector3f _rotation = {0, 0, 0};
            float _scale;

            render::Entity *_parent;
    };
} // namespace vanille


#endif /* D177BBBB_1536_4248_A06A_C92B2A6C6881 */
