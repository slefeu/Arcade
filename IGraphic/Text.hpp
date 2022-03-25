/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "State.hpp"

namespace arcade {
class Text {
  public:
    Text() = default;
    Text(const vec2int& pos, const std::string_view& txt,
         const color_uint8& color = {255, 255, 255}, const color_uint8 back_color = {0, 0, 0})
        : pos_(pos), txt_(txt), color_(color), back_color_(back_color){};
    ~Text() = default;

    void setString(const std::string& txt) {
        txt_ = txt;
    };
    std::string getString() const {
        return txt_;
    };
    void setColor(const color_uint8& color) {
        color_ = color;
    };
    color_uint8 getColor() const {
        return color_;
    };
    void setBackColor(const color_uint8& back_color) {
        back_color_ = back_color;
    };
    color_uint8 getBackColor() const {
        return back_color_;
    };
    void setPos(const vec2int& pos) {
        pos_ = pos;
    };
    vec2int getPos() const {
        return pos_;
    };

  protected:
    vec2int pos_            = {0, 0};
    std::string txt_        = "";
    color_uint8 color_      = {255, 255, 255};
    color_uint8 back_color_ = {0, 0, 0};
};
} // namespace arcade

#endif /* !TEXT_HPP_ */
