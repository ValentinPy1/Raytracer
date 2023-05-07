/*
** EPITECH PROJECT, 2022
** ray
** File description:
** FlatMaterial.gl.hpp
*/

#ifndef EF460525_0DC1_4762_B0F5_F64B6DFB981A
#define EF460525_0DC1_4762_B0F5_F64B6DFB981A
#include <map>
#include "IMaterial.hpp"

namespace gpu {
    class FlatMaterial_gl : public render::IMaterial {
        public:
            FlatMaterial_gl(int r, int g, int b);
            float getProperty(const std::string &name) const override;
            void getColor(int &r, int &g, int &b, geo::vec3 point) const override;
            void selfInit(libconfig::Setting &setting, render::Entity *en) override;
        private:
            float _r;
            float _g;
            float _b;

            std::map<std::string, float> _properties;
    };
}

#endif /* EF460525_0DC1_4762_B0F5_F64B6DFB981A */
