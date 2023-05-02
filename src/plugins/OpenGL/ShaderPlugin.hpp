/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ShaderPlugin.hpp
*/

#ifndef C3070E63_64C1_478A_9FC9_AF1A18E1CC06
#define C3070E63_64C1_478A_9FC9_AF1A18E1CC06
#include <Plugin.hpp>

namespace gpu
{
    class ShaderPlugin : public render::Plugin {
        public:
            ShaderPlugin(const std::string &associatedShaderPath, const std::string &name);
            ~ShaderPlugin();
            const std::string &getPath();
        private:
            std::string _associatedShaderPath;
    };
} // namespace gpu

#endif /* C3070E63_64C1_478A_9FC9_AF1A18E1CC06 */
