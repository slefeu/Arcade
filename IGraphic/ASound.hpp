/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** ASound
*/

#pragma once

#include "State.hpp"

namespace arcade
{
class ASound
{
  public:
    ASound() = default;
    virtual ~ASound() = default;

  protected:
    std::string path = "";
    int volume = 0;

  private:
};
} // namespace arcade