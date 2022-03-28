#include "Arcade.hpp"
#include "Loader.hpp"
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
    //init le core ici !!!
}

std::vector<std::unique_ptr<arcade::AGame>> Arcade::getGames()
{

}

std::vector<std::unique_ptr<arcade::AWindow>> Arcade::getLibraries()
{

void Arcade::usage()
{
    std::cout << "USAGE for ARCADE:" << std::endl
    << "\t./arcade " << "./lib/library.so" << std::endl << std::endl 
	<< "This will be the library used to start the arcade" << std::endl
    << "It must be located in the lib folder" << std::endl;
}
    
}