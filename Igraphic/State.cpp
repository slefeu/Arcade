/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** State
*/

#include "State.hpp"

namespace arcade {

bool Events::isPressed(Key key) {
    for (std::size_t i = 0; i < key_pressed.size(); i++)
        if (key_pressed[i] == key)
            return true;
    return false;
}

Events& Events::operator<<(const Events& event) {
    mouse.left |= event.mouse.left;
    mouse.right |= event.mouse.right;
    mouse.middle |= event.mouse.middle;
    mouse.pos = mouse.pos;
    has_to_stop |= event.has_to_stop;
    for (std::size_t i = 0; i < event.key_pressed.size(); i++) {
        key_pressed.push_back(event.key_pressed[i]);
    }
    return *this;
}
};
