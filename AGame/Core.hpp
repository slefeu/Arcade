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
#include "AWindow.hpp"

namespace arcade
{
class Core
{
  public:
    Core(std::unique_ptr<AWindow>,
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
    std::unique_ptr<AWindow> usedLib;
    std::vector<std::string> allLibs;
    std::vector<std::string> allGames;
    // std::unique_ptr<AGame> chosenGame;
};
} // namespace arcade