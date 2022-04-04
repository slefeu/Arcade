/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Nibbler
*/

#include "Nibbler.hpp"


namespace arcade {

void Nibbler::start(void) noexcept {
    std::vector<std::string> listNameMap = listMap();
    int choice = (rand() % listMap().size());
    std::ifstream file(listNameMap.at(choice).c_str());

    if (file) {
        for (std::string line; getline(file, line);)
            scoreboard.push_back(
                std::make_pair(findPlayerinLine(line), findScoreinLine(line)));
        return (scoreboard);
    } else
        throw(Error("Score file could not be opened correctly"));
}

std::vector<std::string> Nibbler::listMap()
{
    const std::string path = "Nibbler/map";
    std::vector<std::string> allFiles = {};
    DIR* dir = opendir(path.c_str());
    struct dirent* ent;

    if (dir != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            std::string file = ent->d_name;
            allFiles.push_back(file);
        }
        closedir(dir);
    } else
        throw(ArgumentError("Could not open the folder lib"));
    return (allFiles);
}

void Nibbler::exec(IWindow&, Events& event) noexcept
{
}
}
