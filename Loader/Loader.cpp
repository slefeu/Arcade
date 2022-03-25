/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Loader
*/

#include "Loader.hpp"

Loader::Loader(std::string fileName) {
    std::ifstream ifs(fileName);
    std::ostringstream os;
    if (ifs.is_open() && ifs.good()) {
        os << ifs.rdbuf();
        std::string res = os.str();
        this->buffer    = res;
        return;
    } else {
        throw Error("Invalid file");
    }
}

void* Loader::openShared(std::string fileName) {
    void* my_lib          = dlopen("./libasm.so", RTLD_LAZY);
    if (!my_lib)
        throw Error(fileName + " :" + dlerror());
    //dlsym(my_lib, "strchr");
    dlclose(my_lib);
}

std::unique_ptr<arcade::AWindow> Loader::loadLibrairy(std::string fileName) {
    
}

Loader::~Loader()
{
}