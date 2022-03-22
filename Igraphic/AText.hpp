/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** AText
*/

#ifndef ATEXT_HPP_
#define ATEXT_HPP_

#include "State.hpp"

namespace arcade {
class AText {
  public:
    AText();
    virtual ~AText();
    virtual void drawText(const vec2int& pos, const std::string& txt, const color_uint8& color,
                          const color_uint8 back_color = {0, 0, 0}) = 0;

  protected:
    vec2int pos_            = {-1, -1};
    std::string txt_        = "";
    color_uint8 color_      = {0, 0, 0};
    color_uint8 back_color_ = {0, 0, 0};

  private:
};
} // namespace arcade

#endif /* !ATEXT_HPP_ */
