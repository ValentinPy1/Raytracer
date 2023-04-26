/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** DLLoader.hpp
*/

#pragma once

#include <dlfcn.h>
#include <string>

namespace render {
    /**
     * @brief A class that loads dynamic libraries from a .so file
     * containing an "entryPoint" function that returns a pointer to an object.
     *
     */
    class DLLoader {
        public:
            class DLLoaderException : public std::exception {
                public:
                    DLLoaderException(const std::string &message);
                    ~DLLoaderException() = default;
                    const char *what() const noexcept override;
                private:
                    std::string _message;
            };

            DLLoader();
            ~DLLoader();

            /**
             * @brief Load a dynamic library from a path and a library name,
             * and return a pointer to the object returned by the "entryPoint" function.
             *
             * @tparam T
             * @param path
             * @param libName
             * @return T*
             */
            template <typename T>
            T *loadInstance(const std::string &libName, const std::string &path = "") {
                void *handle = nullptr;
                if (_libHandles.find(libName) != _libHandles.end()) {
                    handle = _libHandles[libName];
                } else {
                    handle = dlopen(path.c_str(), RTLD_LAZY);
                    if (!handle) {
                        throw DLLoaderException("Cannot open library: " + std::string(dlerror()));
                    }
                    dlerror();
                    _libHandles[libName] = handle;
                }
                try {
                    T *(*entryPoint)() = reinterpret_cast<T *(*)()>(dlsym(handle, "entryPoint"));
                    const char *dlsym_error = dlerror();
                    if (dlsym_error) {
                        throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(dlsym_error));
                    }
                    return entryPoint();
                } catch (const std::exception &e) {
                    throw DLLoaderException("Cannot load symbol 'entryPoint': " + std::string(e.what()));
                }
            }

            /**
             * @brief Load a dynamic library from a path and a library name.
             * The handle is simply registered in the DLLoader object, and
             * no instance is returned.
             *
             * @param path
             * @param libName
             */
            void load(const std::string &path, const std::string &libName);

            template <typename T>
            T loadSymbol(const std::string &libName, const std::string &symbolName) {
                if (_libHandles.find(libName) == _libHandles.end()) {
                    throw DLLoaderException("Cannot find library " + libName);
                }
                try {
                    T sym = reinterpret_cast<T>(dlsym(_libHandles[libName], symbolName.c_str()));
                    const char *dlsym_error = dlerror();
                    if (dlsym_error) {
                        throw DLLoaderException("Cannot load symbol '" + symbolName + "': " + std::string(dlsym_error));
                    }
                    return sym;
                } catch (const std::exception &e) {
                    throw DLLoaderException("Cannot load symbol '" + symbolName + "': " + std::string(e.what()));
                }
            }
        private:
            /**
             * @brief A vector containing the handles of the loaded libraries.
             * This vector is used to close the libraries when the DLLoader object is destroyed.
             * It can also be used to load new symbols from the libraries from
             * the library name.
             *
             */
            std::map<std::string, void *> _libHandles;
    };
}