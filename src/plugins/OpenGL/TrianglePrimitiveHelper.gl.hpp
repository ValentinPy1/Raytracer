/*
** EPITECH PROJECT, 2022
** ray
** File description:
** TrianglePrimitiveHelper.gl.hpp
*/

#ifndef BCA6C82E_9438_4D6E_8C6F_5E61006960DF
#define BCA6C82E_9438_4D6E_8C6F_5E61006960DF
#include <libconfig.h++>
#include "Plugin.hpp"
#include "IOpglPrimitiveHelper.hpp"

namespace gpu
{
    /**
     * @brief This class is used to create a triangle primitive.
     * It is not directly a primitive, but shoudl be wrapped in a IPrimitive object,
     * and loaded as a plugin withing the IPrimitive::selfInit() function.
     *
     */
    class TrianglePrimitiveHelper : public IOpGLPrimitiveHelper, public virtual render::Plugin{
        public:
            TrianglePrimitiveHelper();
            ~TrianglePrimitiveHelper();

            /**
             * @brief this will set the vertices of the triangle, from a config file
             * setting in the following format:
             *
             * @code {.conf}
             * args = {vertices = (
                {
                    x = 0.0; y = 0.0; z = 0.0;
                },
                {
                    x = 0.0; y = 0.0; z = 10.0;
                },
                {
                    x = 10.0; y = 0.0; z = 0.0;
                }
             * @endcode
             *
             *
             *
             * @param setting
             */
            void selfInit(libconfig::Setting &setting) override;

            /**
             * @brief Returns a vector containing all the vertices of the triangle.
             *
             * @return std::vector<geo::vec3>
             */;
            std::vector<geo::vec3> getVertices() override;
        private:
            std::vector<geo::vec3> _vertices;
    };
} // namespace gpu



#endif /* BCA6C82E_9438_4D6E_8C6F_5E61006960DF */
