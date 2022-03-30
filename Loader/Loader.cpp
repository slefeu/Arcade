/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#include "Loader.hpp"
#include "Error.hpp"

void* Loader::loadLibrary(std::string& filename, const char* functionName)
{
  void* createLib = nullptr;
  openedLib = openShared(filename);
  dlerror();
  createLib = dlsym(openedLib, functionName);

<<<<<<< HEAD
    if (!myLibrary)
        throw Error(fileName + " :" + dlerror());
    return (myLibrary);
    std::string error = std::string(dlerror());
=======
  if (dlerror() != nullptr)
    throw(Error("Library format not compatible, dlsym failed."));
  return (createLib);
>>>>>>> eb7b8644ef95def3d71ff90f1b5def985e155475
}

void* Loader::openShared(std::string& filename)
{
  void* myLibrary = dlopen(filename.c_str(), RTLD_NOW);

  if (!myLibrary)
    throw Error(dlerror());
  return (myLibrary);
}

void Loader::closeLibrary(void* library)
{
  dlclose(library);
}

void* Loader::getOpenedLib() const
{
  return (openedLib);
}
