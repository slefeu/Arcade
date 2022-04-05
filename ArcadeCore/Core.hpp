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
    ~Core() = default;

    Core& operator=(const Core& rhs) noexcept = default;
    Core& operator=(Core&& rhs) noexcept = default;
    void executeLoop();

  protected:
  private:
    Loader libLoader;
    Loader gameLoader;
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
    std::string prevGameName = "";

    // methods
    void displayMenu(Events&);
    void displayGame(Events&);
    void handleMenuEvents(Events&);
    void handleGameEvents(Events&);
    void handleCoreEvents(Events& event);
    Events handleGameEvents();
    bool changePlayerName(Key&) noexcept;
    static bool isLetter(Key&) noexcept;
    static int findIndexPrevious(const int, const bool, const int) noexcept;
    static int getLibIndex(std::string&, std::vector<std::string>&, bool) noexcept;
    void loadGraphicLib(std::string&);
    void loadGameLib(std::string&);
    void displayBindings(int) noexcept;
    void displayAvailableLibs() noexcept;
    void storeScore();
    void changeScore() noexcept;
    void displayScore() const noexcept;
    static std::vector<std::pair<std::string, int>> getScores();
    static std::string findPlayerinLine(const std::string&) noexcept;
    static int findScoreinLine(const std::string&) noexcept;
    static void resetEvent(Events&) noexcept;
    static std::string isStorableStr(
        const std::string&, const std::string&) noexcept;
    static int isDigitEvent(const Key&) noexcept;
};

} // namespace arcade