/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#include "Core.hpp"

namespace arcade
{
Core::Core(std::unique_ptr<AWindow> lib,
    std::vector<std::string>& libs,
    std::vector<std::string>& games) noexcept
  : usedLib(std::move(lib))
  , allLibs(libs)
  , allGames(games)
{
}

void Core::executeLoop()
{
}

} // namespace arcade