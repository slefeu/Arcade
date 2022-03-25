/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** ASprite
*/

#pragma once

namespace arcade {
class ASprite {
  public:
    ASprite() = default;
    virtual ~ASprite() = default;

  protected:
    vec2int position       = {-1, -1};
    vec2int size      = {-1, -1};
    color_uint8 color = {0, 0, 0};
    bool fill         = false;

  private:
};
} // namespace arcade