/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** State
*/

#include "State.hpp"

namespace arcade
{
std::vector<Key> Events::getKeyPressed() const
{
    return (keyPressed);
}

void Events::setKeyPressed(std::vector<Key>& newKey)
{
    keyPressed = newKey;
}

bool Events::isPressed(Key key) const
{
    for (std::size_t i = 0; i < keyPressed.size(); i++)
        if (keyPressed[i] == key)
            return true;
    return false;
}

Events& Events::operator<<(const Events& event)
{
    mouse.left |= event.mouse.left;
    mouse.right |= event.mouse.right;
    mouse.middle |= event.mouse.middle;
    mouse.pos = event.mouse.pos;
    stopGame |= event.stopGame;

    for (std::size_t i = 0; i < event.keyPressed.size(); i++) {
        keyPressed.push_back(event.keyPressed[i]);
    }
    return *this;
}
} // namespace arcade