#include "Arcade.hpp"
#include "Loader.hpp"
#include <dirent.hpp>

Arcade::Arcade(int ac, char **av)
{
    if (ac != 2) {
        usage();
        throw Error("Please start again with the right arguments.");
    }
    void *initLib = Loader::loadLibrary(av[1]); // faire un try and catch ???
    allLibraries = getLibraries();
    if (allLibraries.empty)
        throw Error("No libraries found in folder lib/");
    allGames = getGames();
    if (allGames.empty)
        throw Error("No games found in folder lib/");
    arcadeCore = std::make_unique<Arcade::Core>(initLib, allLibraries, allGames);
}

std::vector<std::string> &Arcade::getDirectoryFiles()
{
    const std::string path = "lib";
    std::vector<std::string> allFiles = std::vector<std::string>();
    DIR *dir = opendir(path.c_str());
    struct dirent *ent;

    if (dir != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            printf ("%s\n", ent->d_name);
        }
    closedir(dir);
    } else
        throw(Error("Could not open the folder lib"));
}

std::vector<std::unique_ptr<arcade::AGame>> Arcade::getGames()
{

}

std::vector<std::unique_ptr<arcade::AWindow>> Arcade::getLibraries()
{
}

void Arcade::usage()
{
    std::cout << "USAGE for ARCADE:" << std::endl
    << "\t./arcade " << "./lib/library.so" << std::endl << std::endl 
	<< "This will be the library used to start the arcade" << std::endl
    << "It must be located in the lib folder" << std::endl;
}

void Arcade::launchGame()
{
    arcadeCore->executeLoop();
}

Arcade::~Arcade()
{
    //doit close toutes nos libraires en faisant une boucle sur allLibraries
}