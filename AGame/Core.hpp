/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#pragma once
#include <memory>
#include <vector>

#include "IGame.hpp"
#include "Utils.hpp"
namespace arcade
{
class Core
{
  public:
    Core(std::unique_ptr<IWindow>,
        std::vector<std::string>&,
        std::vector<std::string>&) noexcept;
    Core(const Core& other) noexcept = default;
    Core(Core&& other) noexcept = default;
    ~Core() noexcept = default;

    Core& operator=(const Core& rhs) noexcept = default;
    Core& operator=(Core&& rhs) noexcept = default;
    void executeLoop();

  protected:
  private:
    std::unique_ptr<IWindow> usedLib;
    std::vector<std::string> allLibs;
    std::vector<std::string> allGames;
    std::unique_ptr<IGame> chosenGame = nullptr;
    bool isEnd = false;
    bool isMenu = true;
    std::string playerName;

    void displayMenu(Status&) noexcept;
    void displayGame(Status&) noexcept;
    void changePlayerName(Events&) noexcept;
    bool isLetter(Key& key) const noexcept;
    void displayAvailableLibs() const noexcept;
};
} // namespace arcade