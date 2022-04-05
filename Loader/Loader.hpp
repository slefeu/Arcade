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
    Loader() noexcept = default;
    Loader(const Loader&) noexcept = delete; // copy constructor
    Loader(Loader&&) noexcept = default;     // move constructor
    ~Loader();

    Loader& operator=(const Loader&) noexcept = delete; //= par copy
    Loader& operator=(Loader&&) noexcept = default;     //= par move

    void* loadLibrary(const std::string&, const char*);
    void closeLibrary();

  protected:
  private:
    void* openShared(const std::string&);
    void* openedLib = nullptr;
};