/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#ifndef LOADER_HPP_
#define LOADER_HPP_

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

#endif /* !LOADER_HPP_ */
