/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** NcWindow
*/

#include "NcWindow.hpp"

namespace arcade {
NcWindow::NcWindow()
{
    initscr();
}

NcWindow::~NcWindow()
{
}

void NcWindow::display() {

}

void NcWindow::clear() {

}

bool NcWindow::pollEvent(Events&) {

}

void NcWindow::setTitle(const std::string&) {

}

void NcWindow::setSize(const vec2int&) {

}

void NcWindow::draw(const Line&) {

}

void NcWindow::draw(const Circle&) {

}

void NcWindow::draw(const Rectangle&) {

}

void NcWindow::draw(const Point&) {

}

void NcWindow::draw(const Text&) {

}

void NcWindow::draw(const ASprite&) {

}

void NcWindow::play(const ASound&) {

}
}