/*
** EPITECH PROJECT, 2022
** ray
** File description:
** IOpglPrimitiveHelper.hpp
*/

#ifndef EF34A8D3_0899_4ABA_AF90_29A295005BF0
    #define EF34A8D3_0899_4ABA_AF90_29A295005BF0
    #include <libconfig.h++>
    #include <vector>
    #include "geometry.hpp"

namespace gpu
{
    /**
     * @brief This interface should be inherited from alonside the IPlugin interface,
     * in order to create loadable primitives for the GPU mode.
     *
     */
    class IOpGLPrimitiveHelper {
        public:
            virtual ~IOpGLPrimitiveHelper() = default;

            /**
             * @brief This function will be called by the IPrimitive::selfInit() function.
             *
             * @param setting
             */
            virtual void selfInit(libconfig::Setting &setting) = 0;

            /**
             * @brief This function will be called by the IPrimitive::getVertices() function.
             *  It returns all the vertices of the primitive.
             * @return std::vector<geo::vec3>
             */
            virtual std::vector<geo::vec3> getVertices() = 0;
    };
} // namespace gpu


#endif /* EF34A8D3_0899_4ABA_AF90_29A295005BF0 */
