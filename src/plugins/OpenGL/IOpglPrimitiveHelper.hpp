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
    class IOpGLPrimitiveHelper {
        public:
            virtual ~IOpGLPrimitiveHelper() = default;
            virtual void selfInit(libconfig::Setting &setting) = 0;
            virtual std::vector<geo::vec3> getVertices() = 0;
    };
} // namespace gpu


#endif /* EF34A8D3_0899_4ABA_AF90_29A295005BF0 */
