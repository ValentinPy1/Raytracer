/*
** EPITECH PROJECT, 2022
** ray
** File description:
** TrianglePrimitiveHelper.gl.cpp
*/

#include "TrianglePrimitiveHelper.gl.hpp"
#include "geometry.hpp"

namespace gpu {
    TrianglePrimitiveHelper::TrianglePrimitiveHelper() :
        Plugin(
            nullptr,
            nullptr,
            nullptr,
            0,
            "opglPrimitiveHelper"
        )
    {
    }

    TrianglePrimitiveHelper::~TrianglePrimitiveHelper()
    {
    }

    void TrianglePrimitiveHelper::selfInit(libconfig::Setting &setting)
    {
        libconfig::Setting &verticeArray = setting.lookup("vertices");
        for (int i = 0; i < 3; ++i) {
            float x, y, z;
            verticeArray[i].lookupValue("x", x);
            verticeArray[i].lookupValue("y", y);
            verticeArray[i].lookupValue("z", z);
            _vertices.push_back((geo::vec3) {x, y, z});
        }
    }

    std::vector<geo::vec3> TrianglePrimitiveHelper::getVertices()
    {
        return _vertices;
    }
}
