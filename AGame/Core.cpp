/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#include "Core.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Error.hpp"
#include "Text.hpp"

namespace arcade
{
Core::Core(std::vector<std::string>& libs,
    std::vector<std::string>& games,
    std::string& libStart)
    : allLibs(libs)
    , allGames(games)
{
    loadGraphicLib(libStart);
    scoreInfos.score = 0;
    scoreInfos.scoreboard = getScores();
}

void Core::executeLoop()
{
    while (!isEnd) {
        usedLib->clear();
        Status input = usedLib->getStatus();
        if (isMenu)
            displayMenu(input);
        else
            displayGame(input);
        usedLib->display();
    }
    storeScore();
}

void Core::loadGraphicLib(std::string& libName)
{
    std::unique_ptr<IWindow> (*createLib)();
    const std::string path = "lib/" + libName;

    usedLib.reset(nullptr);
    auto a = libLoader.loadLibrary(path, "createLib");
    createLib = reinterpret_cast<std::unique_ptr<IWindow> (*)()>(a);
    usedLib = createLib();
    usedLibName = libName;
}

int Core::findIndexPrevious(
    const int i, const bool isPrevious, const int sizeLib) noexcept
{
    if (isPrevious) {
        if (i == 0)
            return (sizeLib - 1);
        return (i - 1);
    } else {
        if (i == sizeLib - 1)
            return (0);
        return (i + 1);
    }
}

int Core::getLibIndex(std::string& libName,
    std::vector<std::string>& allLib,
    bool isPrevious) noexcept
{
    auto iterator = std::find(begin(allLib), end(allLib), libName);
    if (iterator != std::end(allLib))
        return (findIndexPrevious(
            (iterator - begin(allLib)), isPrevious, allLib.size()));
    return (-1);
}

bool Core::isLetter(Key& key) const noexcept
{
    if (key >= A && key <= Z)
        return (true);
    return (false);
}

bool Core::changePlayerName(Key& key_pressed) noexcept
{
    if (isLetter(key_pressed) && playerName.size() < 10) {
        playerName += key_pressed + 'A';
        return true;
    }
    if (key_pressed == Backspace && !playerName.empty()) {
        playerName.pop_back();
        return true;
    }
    return false;
}

void Core::handleGameEvents() noexcept
{
    Events event;

    usedLib->pollEvent(event);
    for (int i = 0; i < event.key_pressed.size(); i++) {
        if (event.key_pressed[i] == F2) { // next game
            if (prevGameName == "")
                int index = getLibIndex(allGames[0], allGames, false);
            else
                int index = getLibIndex(prevGameName, allGames, false);
            // puis load le jeu
        }
        if (event.key_pressed[i] == F3) { // previous game
            if (prevGameName == "")
                int index = getLibIndex(allGames[0], allGames, false);
            else
                int index = getLibIndex(prevGameName, allGames, false);
            // puis load le jeu
        }
    }
}

unsigned int Core::isDigitEvent(const Key& key) const noexcept
{
    const std::string digits = "0123456789";

    for (int i = 0; i < digits.size(); i++) {
        if (key == digits[i]) {
            return (digits[i]);
        }
    }
    return (-1);
}

void Core::handleMenuEvents(Status& input) noexcept
{
    Events event;

    usedLib->pollEvent(event);
    if (event.getStatus() == Exit || usedLib->getStatus() == Exit) {
        isEnd = true;
        return;
    }
    for (int i = 0; i < event.key_pressed.size(); i++) {
        if (event.key_pressed[i] == F4) { // next_graphics
            int index = getLibIndex(usedLibName, allLibs, false);
            if (index != -1)
                loadGraphicLib(allLibs[index]);
            return;
        }
        if (event.key_pressed[i] == F5) { // previous_graphics
            int index = getLibIndex(usedLibName, allLibs, true);
            if (index != -1)
                loadGraphicLib(allLibs[index]);
            return;
        }
        if (changePlayerName(event.key_pressed[i]))
            return;
        if (int i = isDigitEvent(event.key_pressed[i]) != -1) {
            isMenu = false;
            // launch game that corresponds to allGames[i];
            return;
        }
    }
}

void Core::displayGame(Status& input) noexcept
{
    // faire la loop de jeu
    //à la fin de la loop de jeu, appeller la méthode changeScore() pour
    // checker si le score du joueur peut aller dans le scoreboard;
}

void Core::displayMenu(Status& input) noexcept
{
    handleMenuEvents(input);
    usedLib->draw(Text({23, 0}, "MENU: "));
    usedLib->draw(Text({30, 5}, "Player Name: "));
    if (playerName != "")
        usedLib->draw(Text({30, 7}, playerName));
    displayAvailableLibs();
    displayScore();
}

void Core::displayAvailableLibs() const noexcept
{
    int position = 5;

    usedLib->draw(Text({0, position}, "Graphic libraries availables :"));
    for (int i = 0; i < allLibs.size(); i++) {
        position += 2;
        usedLib->draw(Text({0, position}, allLibs[i]));
    }
    usedLib->draw(Text({0, position + 10}, "Games availables :"));
    for (int i = 0; i < allGames.size(); i++) {
        position += 2;
        usedLib->draw(
            Text({42, position}, allGames[i] + " press " + std::to_string(i)));
    }
}

void Core::changeScore() noexcept
{
    for (int i = 0; i < scoreBoardSize; i++) {
        if (scoreInfos.score > scoreInfos.scoreboard[i].second) {
            if (i == scoreBoardSize - 1) {
                scoreInfos.scoreboard[i].second = scoreInfos.score;
                scoreInfos.scoreboard[i].first = playerName;
            } else {
                scoreInfos.scoreboard.insert(scoreInfos.scoreboard.begin() + i,
                    std::make_pair(playerName, scoreInfos.score));
                scoreInfos.scoreboard.pop_back();
            }
            return;
        }
    }
}

void Core::displayScore() const noexcept
{
    int playerPos = 10;

    usedLib->draw(Text({30, playerPos}, "Scoreboard :"));
    for (int i = 0; i < scoreInfos.scoreboard.size(); i++) {
        playerPos += 2;
        usedLib->draw(Text({30, playerPos}, scoreInfos.scoreboard[i].first));
        usedLib->draw(Text(
            {45, playerPos}, std::to_string(scoreInfos.scoreboard[i].second)));
    }
}

std::string Core::isStorableStr(
    const std::string& toCompare, const std::string& defaultStr) const noexcept
{
    if (toCompare == defaultStr)
        return ("");
    else
        return (toCompare);
}

void Core::storeScore()
{
    const std::string scorePath = "Score/score.txt";
    std::ofstream file(scorePath);

    if (file) {
        for (int i = 0; i < scoreInfos.scoreboard.size(); i++) {
            std::string line =
                isStorableStr(scoreInfos.scoreboard[i].first, "UNKNOWN")
                + isStorableStr(
                    std::to_string(scoreInfos.scoreboard[i].second), "0")
                + '\n';
            file << line;
        }
    } else
        throw(Error("Score file could not be opened correctly"));
}

std::string Core::findPlayerinLine(const std::string& line) const noexcept
{
    const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::size_t lastName = line.find_first_not_of(letters);

    if (lastName == -1 || lastName == 0)
        return ("UNKNOWN");
    else
        return (line.substr(0, lastName));
}

int Core::findScoreinLine(const std::string& line) noexcept
{
    const char* digits = "0123456789";
    const std::size_t firstNumber = line.find_first_of(digits);

    if (firstNumber != std::string::npos) {
        std::size_t lastNumber = line.find_first_not_of(digits, firstNumber);
        if (lastNumber != std::string::npos)
            lastNumber -= firstNumber;
        return (atoi((line.substr(firstNumber, lastNumber)).c_str()));
    } else
        return (0);
}

std::vector<std::pair<std::string, int>> Core::getScores()
{
    const std::string scorePath = "Score/score.txt";
    std::ifstream file(scorePath.c_str());
    auto scoreboard = std::vector<std::pair<std::string, int>>();

    if (file) {
        for (std::string line; getline(file, line);)
            scoreboard.push_back(
                std::make_pair(findPlayerinLine(line), findScoreinLine(line)));
        return (scoreboard);
    } else
        throw(Error("Score file could not be opened correctly"));
}
} // namespace arcade