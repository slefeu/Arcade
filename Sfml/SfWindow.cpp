/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#include "SfWindow.hpp"

namespace arcade {
SfWindow::SfWindow() {
}

SfWindow::~SfWindow() {
}

void SfWindow::setTitle(const std::string &title) {
    this->window_.setTitle(title);
}

void SfWindow::setSize(const vec2int& size) {
    this->size_ = size;
    this->window_.setSize(sf::Vector2u(size.x, size.y));
}
} // namespace arcade
