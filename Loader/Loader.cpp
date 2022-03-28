/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#include "Loader.hpp"

void *Loader::loadLibrary(std::string fileName)
{
    void *myLibrary = dlopen(fileName.c_str(), RTLD_NOW);

    if (!myLibrary)
        throw Error(fileName + " :" + dlerror());
    return (myLibrary);
}

static void Loader::closeLibrary(void *library);
{
    dlclose(library);
}
