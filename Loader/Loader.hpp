/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#pragma once

#include "Awindow.hpp"
#include "Error.hpp"
#include <dlfcn.h>
#include <fstream>
#include <iostream>
#include <sstream>

class Loader {
    public:
        Loader() = delete;
        ~Loader() = delete;

        static void *loadLibrary(std::string fileName);
        static void closeLibrary(void *library);
      protected:
      private:
};