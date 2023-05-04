/*
** EPITECH PROJECT, 2022
** ray
** File description:
** Mesh.primitive.v.cpp
*/

#include "Mesh.primitive.v.hpp"

// MESH
namespace vanille
{
    void Mesh::selfInit(libconfig::Setting &setting, render::Entity *parent)
    {
        const libconfig::Setting &primitives = setting.lookup("primitives");

        _parent = parent;
        for (int i = 0; i < primitives.getLength(); i++) {
            loadPart(primitives[i], parent);
        }
    }

    void Mesh::loadPart(const libconfig::Setting &primitive, render::Entity *parent)
    {
        std::string name;

        primitive.lookupValue("type", name);
        name = "lib" + name + ".primitive.v";
        name = "src/plugins/" + name + ".so";
        libconfig::Setting &args = primitive.lookup("args");
        IMeshPart *obj = _loader.loadInstance<IMeshPart>(name, name);
        obj->selfInit(args, _parent);
        _parts.push_back(obj);
        // _parts.push_back(std::shared_ptr<IMeshPart>(obj));
    }

    sf::Vector3f Mesh::getNormalAt(sf::Vector3f &point)
    {
        if (_lasthit == nullptr) {
            return sf::Vector3f(0, 0, 0);
        }
        return _lasthit->getNormalAt(point);
    }

    void Mesh::solve(render::Ray &ray)
    {
        for (auto &primitive : _parts) {
            primitive->solve(ray);
            if (ray.hasIntersections()) {
                _lasthit = primitive;
                return;
            }
        }
    }
} // namespace vanille

extern "C" {
    vanille::Mesh *entryPoint() {
        return new vanille::Mesh();
    }
}
