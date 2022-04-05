#include "Utils.hpp"

namespace arcade
{
bool Events::isPressed(const Key key) const noexcept
{
    for (auto const& i : key_pressed)
        if (i == key)
            return (true);
    return (false);
};

Status Events::getStatus() const noexcept
{
    if (isPressed(Escape))
        return Exit;
    if (isPressed(Backspace))
        return Back_to_menu;
    if (isPressed(F1))
        return Restart;
    if (isPressed(F2))
        return Next_game;
    if (isPressed(F3))
        return Previous_game;
    if (isPressed(F4))
        return Next_graphics;
    if (isPressed(F5))
        return Previous_graphics;
    return Nothing;
}

Events& Events::operator<<(const Events& event)
{
    mouse.left |= event.mouse.left;
    mouse.right |= event.mouse.right;
    mouse.middle |= event.mouse.middle;
    mouse.pos = event.mouse.pos;

    for (auto const& i : event.key_pressed) {
        key_pressed.push_back(i);
    }
    return *this;
}
}