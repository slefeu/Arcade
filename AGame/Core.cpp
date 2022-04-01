/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#include "Core.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Error.hpp"
#include "Text.hpp"

namespace arcade
{
Core::Core(std::unique_ptr<AWindow> lib,
    std::vector<std::string>& libs,
    std::vector<std::string>& games) noexcept
    : usedLib(std::move(lib))
    , allLibs(libs)
    , allGames(games)
    , playerName("")
{
    scoreInfos.score = 0;
    scoreInfos.scoreboard = getScores();
}

Core::~Core()
{
    changeScore();
    storeScore();
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
}

void Core::displayGame(Status& input) noexcept
{
    // faire la loop de jeu
    //à la fin de la loop de jeu, appeller la méthode changeScore() pour checker
    // si le score du joueur peut aller dans le scoreboard;
}

void Core::displayMenu(Status& input) noexcept
{
    Events event;

    usedLib->draw(Text({35, 0}, ("MENU")));
    usedLib->pollEvent(event);
    if (event.getStatus() == Exit || usedLib->getStatus() == Exit) {
        isEnd = true;
        return;
    }
    changePlayerName(event);
    usedLib->draw(Text({35, 5}, "Player Name: "));
    if (playerName != "")
        usedLib->draw(Text({35, 7}, playerName));
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
        usedLib->draw(Text({42, position}, allGames[i]));
    }
}

// void changeGraphicLib()
// {
// }

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

    usedLib->draw(Text({35, playerPos}, "Scoreboard :"));
    for (int i = 0; i < scoreInfos.scoreboard.size(); i++) {
        playerPos += 2;
        usedLib->draw(Text({35, playerPos}, scoreInfos.scoreboard[i].first));
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

bool Core::isLetter(Key& key) const noexcept
{
    if (key >= A && key <= Z)
        return (true);
    return (false);
}

void Core::changePlayerName(Events& event) noexcept
{
    for (int i = 0; i < event.key_pressed.size(); i++) {
        if (isLetter(event.key_pressed[i]) && playerName.size() < 10)
            playerName += event.key_pressed[i] + 'A';
        if (event.key_pressed[i] == Backspace && !playerName.empty())
            playerName.pop_back();
    }
}
} // namespace arcade