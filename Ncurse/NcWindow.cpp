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
    keypad(stdscr, TRUE);
    noecho();
    start_color();
}

NcWindow::~NcWindow()
{
    endwin(); 
}

void NcWindow::display() {
    refresh();
}

void NcWindow::clear() {
    clear();
    erase();
}

bool NcWindow::pollEvent(Events&) {
    int ch = 0;
    ch = getch();
}

void NcWindow::setTitle(const std::string& newTitle) {
    this->title = newTitle;
}

void NcWindow::setSize(const vec2int& newSize) {
    this->size_ = newSize
}

void NcWindow::draw(const Line& infoLine) {
    int lengthx = abs(infoLine.getPosition().x - infoLine.getLineEnd().x);
    int lengthy = abs(infoLine.getPosition().y - infoLine.getLineEnd().y);
    int length = lengthx + lengthy;

    init_color(COLOR_RED, infoLine.getColor().r, infoLine.getColor().g, infoLine.getColor().b);
    init_color(COLOR_BLUE, infoLine.getColor().r, infoLine.getColor().g, infoLine.getColor().b);
    init_pair(2, COLOR_BLUE, COLOR_RED);
    attron(COLOR_PAIR(2));
    for (int i = 0; i < length; i++)
        mvaddch(infoLine.getPosition().y + i * (lengthy / length), infoLine.getPosition().x + i * (lengthx / length), (char)" ");
    attroff(COLOR_PAIR(2));
}

void NcWindow::draw(const Circle& infoCircle) {
}

void NcWindow::draw(const Rectangle& infoRectangle) {
    int lengthx = abs(infoRectangle.getPosition().x - infoRectangle.getSize().x);
    int lengthy = abs(infoRectangle.getPosition().y - infoRectangle.getSize().y);
    int length = lengthx * lengthy;

    init_color(COLOR_RED, infoRectangle.getColor().r, infoRectangle.getColor().g, infoRectangle.getColor().b);
    init_color(COLOR_BLUE, infoRectangle.getColor().r, infoRectangle.getColor().g, infoRectangle.getColor().b);
    init_pair(2, COLOR_BLUE, COLOR_RED);
    attron(COLOR_PAIR(2));
    for (int i = 0; i < length; i++) {
        mvaddch(infoRectangle.getPosition().y + (i / lengthx), infoRectangle.getPosition().x + (i % lengthx), (char)" ");
    }
    attroff(COLOR_PAIR(2));
}

void NcWindow::draw(const Point& infoPoint) {
    init_color(COLOR_RED, infoPoint.getColor().r, infoPoint.getColor().g, infoPoint.getColor().b);
    init_color(COLOR_BLUE, infoPoint.getColor().r, infoPoint.getColor().g, infoPoint.getColor().b);
    init_pair(2, COLOR_BLUE, COLOR_RED);
    attron(COLOR_PAIR(2));
    mvaddch(infoPoint.getPosition().y, infoPoint.getPosition().x, (char)" ");
    attroff(COLOR_PAIR(2));
}

void NcWindow::draw(const Text& infoText) {
    init_color(COLOR_RED, infoText.getBackColor().r, infoText.getBackColor().g, infoText.getBackColor().b);
    init_color(COLOR_BLUE, infoText.getColor().r, infoText.getColor().g, infoText.getColor().b);
    init_pair(2, COLOR_BLUE, COLOR_RED);
    attron(COLOR_PAIR(2));
    for (int i = 0; i < infoText.getString().size(); i++)
        mvaddch(infoText.getPosition().y, infoText.getPosition().x, infoText.getString().at(i));
    attroff(COLOR_PAIR(2));
}

void NcWindow::draw(const ASprite&) {

}

void NcWindow::play(const ASound&) {

}
}