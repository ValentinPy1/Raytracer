/*
** EPITECH PROJECT, 2022
** ecs
** File description:
** Ecs.hpp
*/

#ifndef ECS_HPP
    #define ECS_HPP
    #include <vector>
    #include <map>
    #include <string>
    #include <typeinfo>
    #include <dlfcn.h>
    #include <array>
    #include <stdexcept>
    #include <iostream>

namespace ecs {

    /**
     * @brief The sequence struct is used to hold a sequence of integers.
     * Create it using the gen_seq template.
     *
     * @tparam N
     */
    template <int... N>
    struct sequence {};

    /**
     * @brief The gen_seq struct is used to generate a sequence of integers.
     * It is used to generate the sequence of indices of the components.
     *
     * Use it as follows:
     *
     * @code{.cpp}
     * gen_seq<5>::type seq; // seq is a sequence<0, 1, 2, 3, 4>
     * @endcode
     *
     * @tparam N
     * @tparam S
     */
    template <int N, int... S>
    struct gen_seq : gen_seq<N - 1, N - 1, S...> {};

    /**
     * @brief The gen_seq struct is used to generate a sequence of integers.
     * Do not use this specialization, use the gen_seq template instead.
     *
     * @tparam S
     */
    template <int... S>
    struct gen_seq<0, S...> {
        typedef sequence<S...> type;
    };

    /**
     * @brief The Ecs class implements a Entity Component System designed
     * to be somewhat generic.
     * The components should be dynamic libraries that are loaded at runtime
     * when the Ecs is created.
     *
     */
    typedef void *Component;
    typedef int Entity;

    /**
     * @brief The cptInfo_s struct contains the information about a component.
     * It contains a handle to the dynamic library, a pointer to the create
     * function which returns a pointer to the component, a pointer to the destroy
     * function which takes a pointer to the component as a parameter in order to
     * destroy it, and the typeId of the component.
     *
     * Upon creation, the structure will load the dynamic library, and get the
     * create and destroy functions.
     * Upon destruction, the structure will close the dynamic library.
     *
     */
    typedef struct cptInfo_s {
        void *handle;
        void *(*create)();
        void (*destroy)(void *);

        std::string typeId;

        cptInfo_s(const char *libpath, const std::string &typeId) : typeId(typeId) {
            handle = dlopen(libpath, RTLD_LAZY);
            if (!handle)
                throw std::invalid_argument(dlerror());
            create = (void *(*)()) dlsym(handle, "create");
            destroy = (void (*)(void *)) dlsym(handle, "destroy");
            if (!create || !destroy)
                throw std::invalid_argument(dlerror());
        };

        ~cptInfo_s() {
            dlclose(handle);
        }
    } cptInfo_t;

    /**
     * @brief The Ecs class implements a Entity Component System designed
     * to be somewhat generic.
     * The components should be dynamic libraries that are loaded at runtime
     * when the Ecs is created, and the libraries should contain a create function
     * that returns a pointer to the component, and a destroy function that takes
     * a pointer to the component as a parameter in order to destroy it.
     * The components should be passed as template parameters to the Ecs class.
     * Note that all the components should have a void update(Entity, Ecs<System, CptTypes...> &) method.
     *
     * @tparam System The type of the system that the Ecs will handle. The system
     * should be a class that has an update method with the following signature:
     * void update(void *cptPtr, Entity en, Ecs<System, CptTypes...> &ecs);
     * @tparam CptTypes The types of the components that the Ecs will handle.
     *@code{.cpp}


        class MySys {
            public:
                void update(ecs::Ecs<MySys, Cpt1, Cpt2> &ecs) {
                    auto entities = ecs.getEntitiesIds();

                    for (auto &entity : entities) {
                        ecs.updateEntity(entity);
                    }
                }
        };

        int main()
        {
            ecs::Ecs<MySys, Cpt1, Cpt2> ecs = ecs::Ecs<MySys, Cpt1, Cpt2>({
                "./libone.so",
                "./libtwo.so"
            });

            ecs::Entity en = ecs.createEntity();
            ecs.addComponent<Cpt1>(en);
            ecs.addComponent<Cpt2>(en);
            ecs.update();
            ecs.eraseEntity(en);
            return 0;
        }


     *@endcode
     */
    template <typename System, typename... CptTypes>
    class Ecs {
        public:
            Ecs() = delete;

            /**
             * @brief Construct a new Ecs object by loading all the dynamic libraries
             * that contain the components.
             *
             * @param libPath
             */
            Ecs(const std::vector<std::string> &libPath) {
                std::vector<std::string> typeInfos = {typeid(CptTypes).name()...};

                if (libPath.size() != sizeof...(CptTypes))
                    throw std::invalid_argument("The number of libraries should be equal to the number of components");
                for (auto &lib : libPath) {
                    _cptInfos.push_back(new cptInfo_t(lib.c_str(), typeInfos[_cptInfos.size()]));
                }
            }

            /**
             * @brief Destroy the Ecs object by destroying all the components
             * and closing the dynamic libraries.
             *
             */
            ~Ecs() {
                for (auto &entity : _entities) {
                    for (auto &cpt : entity.second) {
                        for (auto &cptPtr : cpt) {
                            for (auto &cptInfo : _cptInfos) {
                                if (typeid(cptPtr).name() == cptInfo->typeId) {
                                    cptInfo->destroy(cptPtr);
                                }
                            }
                        }
                    }
                }
                for (auto &cptInfo : _cptInfos) {
                    delete cptInfo;
                }
            }

            /**
             * @brief Get the Component of the given type for the given entity.
             * If the entity does not have a component of the given type, an
             * exception is thrown.
             *
             * @tparam T
             * @param entity
             * @return std::vector<T>&
             */
            template<typename T>
            std::vector<T *> getComponents(Entity entity) {
                for (size_t i = 0; i < sizeof...(CptTypes); i++) {
                    if (typeid(T).name() == _cptInfos[i]->typeId) {
                        std::vector<T *> tmp;
                        for (auto &cpt : _entities[entity][i])
                            tmp.push_back(reinterpret_cast<T *>(cpt));
                        return tmp;
                    }
                }
                throw std::invalid_argument("The component type does not exist");
            }

            /**
             * @brief Add a component of the given type to the given entity.
             * If the given type is not handled by the Ecs, an exception is thrown.
             *
             * @tparam T
             * @param entity
             */
            template<typename T>
            void addComponent(Entity entity) {
                for (size_t i = 0; i < sizeof...(CptTypes); i++) {
                    if (typeid(T).name() == _cptInfos[i]->typeId) {
                        T *tmp = reinterpret_cast<T *>(_cptInfos[i]->create());
                        _entities[entity][i].push_back(tmp);
                        _cptInfos[i]->destroy(tmp);
                        return;
                    }
                }
                throw std::invalid_argument("The component type does not exist");
            }

            /**
             * @brief Create a Entity object
             * The id of the Entity will be the size of the entities map.
             *
             * @return Entity
             */
            Entity createEntity() {
                for (auto &entity : _entities) {
                    bool found = false;
                    for (auto id : _usedIds) {
                        if (id == entity.first) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        _usedIds.push_back(entity.first);
                        return entity.first;
                    }
                }
                _usedIds.push_back(_entities.size());
                _entities[_entities.size()];
                return _entities.size() -  1;
            }

            /**
             * @brief Destroy the Entity object
             * The id of the Entity will be the size of the entities map.
             *
             * @param entity
             */
            void eraseEntity(Entity entity) {
                for (auto &cpt : _entities[entity]) {
                    for (auto &cptPtr : cpt) {
                        for (auto &cptInfo : _cptInfos) {
                            if (typeid(cptPtr).name() == cptInfo->typeId) {
                                cptInfo->destroy(cptPtr);
                                std::cout << "destroyed" << std::endl;
                                break;
                            }
                        }
                    }
                }
                size_t eraseMe = -1;
                for (size_t i = 0; i < _usedIds.size(); i++) {
                    if (_usedIds[i] == entity) {
                        eraseMe = i;
                        break;
                    }
                }
                if (eraseMe != -1)
                    _usedIds.erase(_usedIds.begin() + eraseMe);
            }

            std::vector<Entity> getEntitiesIds() {
                return _usedIds;
            }

            /**
             * @brief Update the Ecs by calling the System's update function.
             * This function is defined by the user. Use this if you need to
             * handle the updates of the components yourself.
             *
             */
            void update() {
                _system.update(*this);
            }


            void updateEntity(Entity en) {
                internalUpdateEntity(en, typename gen_seq<sizeof...(CptTypes)>::type());
            }

        private:

            /**
             * @brief Updates all components of a given type. The index at which
             * the components of the given component type is stored in the
             * ECS must be provided.
             *
             * @tparam C
             * @param en    The id of the entity to update.
             * @param index The index at which the components of the given component type is stored in the ECS.
             */
            template <typename C>
            void updateCpt(Entity en, size_t index) {
                for (auto &cpt : _entities[en][index]) {
                    reinterpret_cast<C *>(cpt)->update();
                }
            }

            /**
             * @brief Internal function used to update all the components of an entity.
             * This function is used to call the updateCpt function for all the component types.
             * It is to be called with a sequence of integers from 0 to the number of component types,
             * which is used to call the updateCpt function for all the component types.
             * This sequence is generated using the gen_seq template.
             *
             * @code {.cpp}
             * gen_seq<3>::type() // Generates the sequence {0, 1, 2} which can then be expanded
             * @endcode
             *
             *
             * @param en
             * @param seq
             */
            template <int... N>
            void internalUpdateEntity(Entity en, sequence<N...>) {
                (void)std::initializer_list<int>{(
                    updateCpt<CptTypes>(en, N), 0)...
                };
            }

            /**
             * @brief The map containing all the entities and their components.
             *
             */
            std::map<Entity, std::array<std::vector<Component>, sizeof...(CptTypes)>> _entities;

            /**
             * @brief The vector containing all the component types and their
             * associated functions, as well as the handle to the dynamic library used
             * to load the components.
             *
             */
            std::vector<cptInfo_t *> _cptInfos;

            /**
             * @brief The vector containing all the ids of the entities that are currently used.
             *
             */
            std::vector<Entity> _usedIds;
            System _system;
    };
}

#endif // ECS_HPP
