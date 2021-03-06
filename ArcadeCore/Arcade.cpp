#include "Arcade.hpp"

#include <dirent.h>

#include <filesystem>

namespace arcade
{
Arcade::Arcade(int ac, char** av)
{
    if (ac != 2) {
        usage();
        throw ArgumentError("Please start again with the right arguments.");
    }
    std::vector<std::string> allFiles = getLibFiles();
    std::vector<std::string> allLibs = setLibraries(allFiles);
    if (allLibs.empty())
        throw Error("No libraries found in folder lib");
    if (allLibs.size() < 3)
        throw Error("Not enough graphic libraries found in folder lib");
    std::vector<std::string> allGames = setGames(allFiles);
    if (allGames.empty())
        throw Error("No games found in folder lib");
    std::string libStart = getFirstLibName(av[1]);
    arcadeCore = std::make_unique<Core>(allLibs, allGames, libStart);
}

std::string Arcade::getFirstLibName(const std::string& name)
{
    auto filename = std::filesystem::path{name}.filename();

    if (isGraphicLibrary(filename)) {
        filename = name.substr(name.find("arcade_"));
        return (static_cast<std::string>(filename));
    }
    throw(ArgumentError("Wrong library used to start the arcade"));
}

bool Arcade::isLibFile(const std::string& file) noexcept
{
    if (file == "." || file == "..")
        return (false);
    if (file.find_last_of('.') == std::string::npos)
        return false;
    if (file.substr(file.find_last_of('.')) != ".so")
        return (false);
    return (true);
}

std::vector<std::string> Arcade::getLibFiles()
{
    const std::string path = "lib";
    auto allFiles = std::vector<std::string>();
    DIR* dir = opendir(path.c_str());
    struct dirent* ent = nullptr;

    if (dir != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            std::string file = ent->d_name;
            if (isLibFile(file))
                allFiles.push_back(file);
        }
        closedir(dir);
    } else
        throw(ArgumentError("Could not open the folder lib"));
    return (allFiles);
}

bool Arcade::isGraphicLibrary(const std::string& filename) noexcept
{
    std::vector<std::string> possibleNames = {"arcade_ndk++.so",
        "arcade_aalib.so",
        "arcade_libcaca.so",
        "arcade_allegro5.so",
        "arcade_xlib.so",
        "arcade_gtk+.so",
        "arcade_sfml.so",
        "arcade_ncurses.so",
        "arcade_sdl2.so",
        "arcade_irrlicht.so",
        "arcade_opengl.so",
        "arcade_vulkan.so",
        "arcade_qt5.so"};

    for (auto const& i : possibleNames) {
        if (filename == i)
            return (true);
    }
    return (false);
}

bool Arcade::isGameLibrary(const std::string& filename) noexcept
{
    std::vector<std::string> possibleNames = {"arcade_nibbler.so",
        "arcade_pacman.so",
        "arcade_qix.so",
        "arcade_centipede.so",
        "arcade_solarfox.so"};

    for (auto const& i : possibleNames) {
        if (filename == i)
            return (true);
    }
    return (false);
}

std::vector<std::string> Arcade::setLibraries(
    std::vector<std::string>& allFiles)
{
    auto allLibs = std::vector<std::string>();

    for (auto const& i : allFiles) {
        if (isGraphicLibrary(i)) {
            allLibs.push_back(i);
        }
    }
    return (allLibs);
}

std::vector<std::string> Arcade::setGames(std::vector<std::string>& allFiles)
{
    auto allGames = std::vector<std::string>();

    for (auto const& i : allFiles) {
        if (isGameLibrary(i)) {
            allGames.push_back(i);
        }
    }
    return (allGames);
}

void Arcade::usage() noexcept
{
    std::cout << "USAGE for ARCADE:" << std::endl
              << "\t./arcade "
              << "./lib/library.so" << std::endl
              << std::endl
              << "This will be the library used to start the arcade"
              << std::endl
              << "It must be located in the lib folder" << std::endl;
}

void Arcade::launchGame()
{
    arcadeCore->executeLoop();
}

} // namespace arcade