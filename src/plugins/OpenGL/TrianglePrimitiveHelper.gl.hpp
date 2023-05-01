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
    class TrianglePrimitiveHelper : public IOpGLPrimitiveHelper, public virtual render::Plugin{
        public:
            TrianglePrimitiveHelper();
            ~TrianglePrimitiveHelper();
            void selfInit(libconfig::Setting &setting) override;
            std::vector<geo::vec3> getVertices() override;
        private:
            std::vector<geo::vec3> _vertices;
    };
} // namespace gpu



#endif /* BCA6C82E_9438_4D6E_8C6F_5E61006960DF */
