/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Text
*/

#pragma once
#include "State.hpp"

namespace arcade
{
class Text
{
  public:
    Text() noexcept = default;
    Text(const vec2int& pos,
        const std::string_view&,
        const color_uint8&,
        const color_uint8);
    Text(const Text& other) noexcept = default;
    Text(Text&& other) noexcept = default;
    ~Text() noexcept = default;

    Text& operator=(const Text& rhs) noexcept = default;
    Text& operator=(Text&& rhs) noexcept = default;

    void setString(const std::string&);
    std::string getString() const;
    void setColor(const color_uint8&);
    color_uint8 getColor() const;
    void setBackColor(const color_uint8& back_color);
    color_uint8 getBackColor() const;
    void setPosition(const vec2int& pos);
    vec2int getPosition() const;

  protected:
    vec2int pos_ = {0, 0};
    std::string txt_ = "";
    color_uint8 color_ = {255, 255, 255};
    color_uint8 back_color_ = {0, 0, 0};
};
} // namespace arcade