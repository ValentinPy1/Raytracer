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
        auto closestInter = render::Intersection(_parent, ray, 100000000);

        std::vector<render::Intersection> intersectBackup;
        for (auto &inter : ray.getIntersections()) {
            intersectBackup.push_back(inter);
        }

        ray.getIntersections().clear();
        for (auto &primitive : _parts) {
            primitive->solve(ray);
            if (not ray.hasIntersections()) {
                continue;
            }
            if (ray.getIntersections().back().getDistance() < closestInter.getDistance()) {
                closestInter = ray.getIntersections().back();
                _lasthit = primitive.get();
            }
            ray.getIntersections().clear();
        }
        if (intersectBackup.size() == 0) {
            ray.addIntersection(closestInter);
            return;
        }

        auto closestOld = intersectBackup[0];
        for (auto &inter : intersectBackup) {
            if (inter.getDistance() < closestOld.getDistance()) {
                closestOld = inter;
            }
        }
        if (closestInter.getDistance() < closestOld.getDistance()) {
            ray.addIntersection(closestInter);
        } else {
            ray.addIntersection(closestOld);
        }
    }

    // delt with internally
    sf::Vector3f Mesh::getRotation() const
    {
        return {0, 0, 0};
    }
    // delt with internally
    sf::Vector3f Mesh::getTranslation() const
    {
        return {0, 0, 0};
    }
    // delt with internally
    float Mesh::getScale() const
    {
        return 0;
    }
} // namespace vanille

extern "C" {
    vanille::Mesh *entryPoint() {
        return new vanille::Mesh();
    }
}
