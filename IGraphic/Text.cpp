#include "Text.hpp"

namespace arcade
{
Text::Text(const vec2int& pos,
    const std::string_view& txt,
    const color_uint8& color = {255, 255, 255},
    const color_uint8 back_color = {0, 0, 0})
  : pos_(pos)
  , txt_(txt)
  , color_(color)
  , back_color_(back_color){};

void Text::setString(const std::string& txt)
{
    txt_ = txt;
};
std::string Text::getString() const
{
    return txt_;
};
void Text::setColor(const color_uint8& color)
{
    color_ = color;
};
color_uint8 Text::getColor() const
{
    return color_;
};
void Text::setBackColor(const color_uint8& back_color)
{
    back_color_ = back_color;
};
color_uint8 Text::getBackColor() const
{
    return back_color_;
};
void Text::setPosition(const vec2int& pos)
{
    pos_ = pos;
};
vec2int Text::getPosition() const
{
    return pos_;
};
}