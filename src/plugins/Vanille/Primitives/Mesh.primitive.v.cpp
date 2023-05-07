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
        const libconfig::Setting &position = setting.lookup("position");
        const libconfig::Setting &rotation = setting.lookup("rotation");
        setting.lookupValue("scale", _scale);
        position.lookupValue("x", _position.x);
        position.lookupValue("y", _position.y);
        position.lookupValue("z", _position.z);
        rotation.lookupValue("x", _rotation.x);
        rotation.lookupValue("y", _rotation.y);
        rotation.lookupValue("z", _rotation.z);

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
        IMeshPart *obj = new TrianglePart();
        obj->selfInit(args, _parent);
        reinterpret_cast<TrianglePart *>(obj)->scale(_scale);
        obj->move(_position);
        obj->rotate(_rotation, _position);
        _parts.push_back(std::shared_ptr<IMeshPart>(obj));
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
                _lasthit = primitive.get();
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
