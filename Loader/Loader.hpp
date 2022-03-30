/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#pragma once

#include <dlfcn.h>
#include <fstream>
#include <iostream>
#include <sstream>

class Loader
{
public:
  Loader() = default;
  ~Loader() = default;

  void *loadLibrary(std::string &, const char *);
  void closeLibrary(void *);
  void *getOpenedLib() const;

protected:
private:
  void *openShared(std::string &);
  void *openedLib = nullptr;
};