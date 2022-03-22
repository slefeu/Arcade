/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** ASprite
*/

#ifndef ASPRITE_HPP_
#define ASPRITE_HPP_

namespace arcade {
class ASprite {
  public:
    ASprite();
    virtual ~ASprite();

  protected:
    vec2int pos_       = {-1, -1};
    vec2int size_      = {-1, -1};
    color_uint8 color_ = {0, 0, 0};
    bool fill_         = false;

  private:
};
} // namespace arcade

#endif /* !ASPRITE_HPP_ */
