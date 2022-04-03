#include "Utils.hpp"

namespace arcade
{
bool Events::isPressed(const Key key) const noexcept
{
    for (std::size_t i = 0; i < key_pressed.size(); i++)
        if (key_pressed[i] == key)
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

    for (std::size_t i = 0; i < event.key_pressed.size(); i++) {
        key_pressed.push_back(event.key_pressed[i]);
    }
    return *this;
}
}