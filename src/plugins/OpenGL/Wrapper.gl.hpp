/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Wrapper.gl.hpp
*/

#ifndef DFE232F2_BDD4_425F_88E1_A2A163DA444A
    #define DFE232F2_BDD4_425F_88E1_A2A163DA444A
    #include "Wrapper.hpp"
    #include "Plugin.hpp"

namespace gpu {
    class Wrapper_gl : {
        public:
            Wrapper_v(onst std::string &name);
            ~Wrapper_v() = default;
            void run(render::Renderer &rdr) override;
        private:

    };
}

#endif /* DFE232F2_BDD4_425F_88E1_A2A163DA444A */
