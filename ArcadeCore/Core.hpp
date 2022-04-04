/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#pragma once
#include <chrono>
#include <memory>
#include <thread>
#include <vector>

#include "IGame.hpp"
#include "Loader.hpp"
#include "Utils.hpp"

namespace arcade
{
struct score {
    int score;
    std::vector<std::pair<std::string, int>> scoreboard;
};

constexpr int scoreBoardSize = 5;

class Core
{
  public:
    Core(std::vector<std::string>&, std::vector<std::string>&, std::string&);
    Core(const Core& other) noexcept = default;
    Core(Core&& other) noexcept = default;
    ~Core() noexcept = default;

    Core& operator=(const Core& rhs) noexcept = default;
    Core& operator=(Core&& rhs) noexcept = default;
    void executeLoop();

  protected:
  private:
    std::unique_ptr<IWindow> usedLib;
    std::string usedLibName;
    std::vector<std::string> allLibs;
    std::vector<std::string> allGames;
    std::unique_ptr<IGame> chosenGame = nullptr;
    bool isEnd = false;
    bool isMenu = true;
    std::string playerName = "";
    std::string gameName = "";
    score scoreInfos;
    Loader libLoader;
    Loader gameLoader;
    std::string prevGameName = "";

    // methods
    void displayMenu(Events&);
    void displayGame(Events&);
    void handleMenuEvents(Events&);
    void handleGameEvents(Events&);
    void handleCoreEvents(Events& event);
    Events handleGameEvents();
    bool changePlayerName(Key&) noexcept;
    bool isLetter(Key&) const noexcept;
    int findIndexPrevious(const int, const bool, const int) noexcept;
    int getLibIndex(std::string&, std::vector<std::string>&, bool) noexcept;
    void loadGraphicLib(std::string&);
    void loadGameLib(std::string&);
    void displayAvailableLibs() const noexcept;
    void storeScore();
    void changeScore() noexcept;
    void displayScore() const noexcept;
    std::vector<std::pair<std::string, int>> getScores();
    std::string findPlayerinLine(const std::string&) const noexcept;
    int findScoreinLine(const std::string&) noexcept;
    std::string isStorableStr(
        const std::string&, const std::string&) const noexcept;
    unsigned int isDigitEvent(const Key& key) const noexcept;
};

} // namespace arcade