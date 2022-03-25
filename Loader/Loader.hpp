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
        Loader();
        ~Loader();
        static std::unique_ptr<arcade::AWindow> loadLibrairy(std::string fileName);

      protected:
      private:
        void *openShared(std::string fileName);
};

#endif /* !LOADER_HPP_ */
