/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#pragma once
#include <memory>
#include <vector>

#include "AGame.hpp"
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
    Core(std::unique_ptr<AWindow>,
        std::vector<std::string>&,
        std::vector<std::string>&) noexcept;
    Core(const Core& other) noexcept = default;
    Core(Core&& other) noexcept = default;
    ~Core();

    Core& operator=(const Core& rhs) noexcept = default;
    Core& operator=(Core&& rhs) noexcept = default;
    void executeLoop();

  protected:
  private:
    std::unique_ptr<AWindow> usedLib;
    std::vector<std::string> allLibs;
    std::vector<std::string> allGames;
    std::unique_ptr<AGame> chosenGame = nullptr;
    bool isEnd = false;
    bool isMenu = true;
    std::string playerName;
    score scoreInfos;

    // methods
    void displayMenu(Status&) noexcept;
    void displayGame(Status&) noexcept;
    void changePlayerName(Events&) noexcept;
    bool isLetter(Key& key) const noexcept;
    bool isLetter() const noexcept;
    void displayAvailableLibs() const noexcept;
    void storeScore();
    void changeScore() noexcept;
    void displayScore() const noexcept;
    std::vector<std::pair<std::string, int>> getScores();
    std::string findPlayerinLine(const std::string&) const noexcept;
    int findScoreinLine(const std::string&) noexcept;
    std::string isStorableStr(
        const std::string&, const std::string&) const noexcept;
};

} // namespace arcade