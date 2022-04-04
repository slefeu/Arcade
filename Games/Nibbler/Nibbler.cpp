/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

namespace arcade
{
void Nibbler::start(void) noexcept
{
    try {
        parseList();
    } catch (Error const& error) {
        initDefault();
    }
}

void Nibbler::initBody(vec2int pos) noexcept
{
    body.push_back(pos);
    body.push_back({pos.x - 1, pos.y});
    body.push_back({pos.x - 2, pos.y});
    body.push_back({pos.x - 3, pos.y});
}

void Nibbler::initDefault()
{
    obstacleList = {};
    appleList = {};
    initBody({WindowX / 2, WindowY / 2});
    for (int y = 0; y <= WindowY; y++) {
        for (int x = 0; x <= WindowX; x++) {
            if (y == 0 || y == WindowY) {
                obstacleList.push_back({x, y});
                continue;
            }
            if (x == 0 || x == WindowX) {
                obstacleList.push_back({x, y});
                continue;
            }
            if (x % 4 == 0 && y % 4 == 0) {
                appleList.push_back({x, y});
                continue;
            }
        }
    }
}

void Nibbler::parseList()
{
    srand(time(NULL));
    std::vector<std::string> listNameMap = listMap();
    int choice = (rand() % listMap().size());
    std::string path = "Nibbler/map/" + listNameMap.at(choice);
    std::ifstream file(path.c_str());
    int y = 0;

    if (file) {
        for (std::string line; getline(file, line);) {
            for (int x = 0; x < line.size() && x <= WindowX; x++) {
                if (line.at(x) == 'w')
                    obstacleList.push_back({x, y});
                if (line.at(x) == 'a')
                    appleList.push_back({x, y});
                if (line.at(x) == 's')
                    initBody({x, y});
            }
            y++;
        }
    } else
        throw(Error("Map file could not be opened correctly"));
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
        throw(ArgumentError("Could not open the folder Nibbler/map"));
    return (allFiles);
}

void Nibbler::exec(IWindow&, Events& event) noexcept
{
}
}
