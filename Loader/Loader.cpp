/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#include "Loader.hpp"
#include "Error.hpp"

void* Loader::loadLibrary(const std::string& filename, const char* functionName)
{
    void* createLib = nullptr;

    if (openedLib != nullptr)
        closeLibrary();
    openedLib = openShared(filename);
    dlerror();
    createLib = dlsym(openedLib, functionName);

    if (dlerror() != nullptr)
        throw(Error("Library format not compatible, dlsym failed."));
    return (createLib);
}

void* Loader::openShared(const std::string& filename)
{
    void* myLibrary = dlopen(filename.c_str(), RTLD_NOW);

    if (!myLibrary)
        throw Error(dlerror());
    return (myLibrary);
}

void Loader::closeLibrary()
{
    if (dlclose(openedLib) != 0)
        throw(Error(dlerror()));
    openedLib = nullptr;
}