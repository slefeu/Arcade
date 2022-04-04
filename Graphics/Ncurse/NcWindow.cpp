/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** NcWindow
*/

#include "NcWindow.hpp"

#include <unistd.h>

namespace arcade
{
extern "C" std::unique_ptr<IWindow> createLib()
{
    return (std::make_unique<NcWindow>());
}

NcWindow::NcWindow() noexcept
{
    window = initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    nodelay(window, 1);
    start_color();
    short color = addColors(0, 0, 0);
    short pair = addPair(color, color);
    wbkgd(window, COLOR_PAIR(pair));
}

NcWindow::~NcWindow()
{
    endwin();
}

void NcWindow::setFramerate(int newFramerate) noexcept
{
    framerate = newFramerate;
}

void NcWindow::display()
{
    wrefresh(window);
    std::chrono::milliseconds millisec_since_epoch =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
    if (millisec_since_epoch.count() - lastDisplay.count()
        < (int)((double)1000 / (double)60)) {
            /*printf("Going to wait :%ld\n", (int)(((double)((double)60 / (double)framerate)) * 1000)
            - (millisec_since_epoch.count() - lastDisplay.count()));*/
            std::this_thread::sleep_for(std::chrono::milliseconds(
                (int)((double)1000 / (double)60)
                - (millisec_since_epoch.count() - lastDisplay.count())));
        }
    /*printf("Ecart: %ld, framerate : %d, timeToSleep: %ld \n",
        millisec_since_epoch.count() - lastDisplay.count(),
        framerate,
        (int)(((double)((double)60 / (double)framerate)) * 1000));*/
    lastDisplay = millisec_since_epoch;
}

short NcWindow::addColors(unsigned char r, unsigned char g, unsigned char b)
{
    short tempR;
    short tempB;
    short tempG;
    for (short i = 0; i < nbColors; i++) {
        color_content(i, &tempR, &tempG, &tempB);
        if (tempR == r && tempB == b && tempG == g)
            return i;
    }
    init_color(nbColors, r, g, b);
    nbColors++;
    return (nbColors - 1);
}

short NcWindow::addPair(short color, short backColor) {
    short tempColor;
    short tempBackColor;
    for (short i = 0; i < nbPair; i++) {
        pair_content(i, &tempColor, &tempBackColor);
        if (tempColor == color && backColor == tempBackColor)
            return i;
    }
    init_pair(nbPair, color, backColor);
    nbPair++;
    return (nbPair - 1);
}

void NcWindow::clear()
{
    werase(window);
    //::clear();
}

bool insertkey(Key key, Events& event)
{
    event.key_pressed.push_back(key);
    return true;
}

Status NcWindow::getStatus()
{
    Status tmp = status;

    if (status < Exit)
        status = Nothing;
    return tmp;
}

bool NcWindow::pollEvent(Events& event)
{
    int ch = 0;
    ch = wgetch(window);
    switch (ch) {
        case KEY_DOWN: return insertkey(Down, event);
        case KEY_UP: return insertkey(Up, event);
        case KEY_LEFT: return insertkey(Left, event);
        case KEY_RIGHT: return insertkey(Right, event);
        case KEY_HOME: return insertkey(Home, event);
        case KEY_BACKSPACE: return insertkey(Backspace, event);
        case KEY_DL: return insertkey(Delete, event);
        case KEY_IL: return insertkey(Insert, event);
        case KEY_DC: return insertkey(Delete, event);
        case KEY_IC: return insertkey(Insert, event);
        case KEY_END: return insertkey(End, event);
        case KEY_EXIT: status = Exit; return insertkey(Escape, event);
        case KEY_NPAGE: return insertkey(PageDown, event);
        case KEY_PPAGE: return insertkey(PageUp, event);
        case KEY_ENTER: return insertkey(Enter, event);
        case 27: return insertkey(Escape, event);
        case '0': return insertkey(Num0, event);
        case '1': return insertkey(Num1, event);
        case '2': return insertkey(Num2, event);
        case '3': return insertkey(Num3, event);
        case '4': return insertkey(Num4, event);
        case '5': return insertkey(Num5, event);
        case '6': return insertkey(Num6, event);
        case '7': return insertkey(Num7, event);
        case '8': return insertkey(Num8, event);
        case '9': return insertkey(Num9, event);
        case 'A':
        case 'a': return insertkey(A, event);
        case 'B':
        case 'b': return insertkey(B, event);
        case 'C':
        case 'c': return insertkey(C, event);
        case 'D':
        case 'd': return insertkey(D, event);
        case 'E':
        case 'e': return insertkey(E, event);
        case 'F':
        case 'f': return insertkey(F, event);
        case 'G':
        case 'g': return insertkey(G, event);
        case 'H':
        case 'h': return insertkey(H, event);
        case 'I':
        case 'i': return insertkey(I, event);
        case 'J':
        case 'j': return insertkey(J, event);
        case 'K':
        case 'k': return insertkey(K, event);
        case 'L':
        case 'l': return insertkey(L, event);
        case 'M':
        case 'm': return insertkey(M, event);
        case 'N':
        case 'n': return insertkey(N, event);
        case 'O':
        case 'o': return insertkey(O, event);
        case 'P':
        case 'p': return insertkey(P, event);
        case 'Q':
        case 'q': return insertkey(Q, event);
        case 'R':
        case 'r': return insertkey(R, event);
        case 'S':
        case 's': return insertkey(S, event);
        case 'T':
        case 't': return insertkey(T, event);
        case 'U':
        case 'u': return insertkey(U, event);
        case 'V':
        case 'v': return insertkey(V, event);
        case 'W':
        case 'w': return insertkey(W, event);
        case 'X':
        case 'x': return insertkey(X, event);
        case 'Y':
        case 'y': return insertkey(Y, event);
        case 'Z':
        case 'z': return insertkey(Z, event);
        case ' ': return insertkey(Space, event);
        case KEY_F(1): return insertkey(F1, event);
        case KEY_F(2): return insertkey(F2, event);
        case KEY_F(3): return insertkey(F3, event);
        case KEY_F(4): return insertkey(F4, event);
        case KEY_F(5): return insertkey(F5, event);
        default: return false;
    }
    return false;
}

void NcWindow::setTitle(const std::string& newTitle)
{
    this->title = newTitle;
}

void NcWindow::setSize(const vec2int& newSize)
{
    werase(window);
    wrefresh(window);
    this->size_ = newSize;
    wresize(window, newSize.y, newSize.x);
}

void NcWindow::draw(const Line& infoLine)
{
    int lengthx = abs(infoLine.getPosition().x - infoLine.getLineEnd().x);
    int lengthy = abs(infoLine.getPosition().y - infoLine.getLineEnd().y);
    int length = lengthx + lengthy;

    short color = addColors(
        infoLine.getColor().r, infoLine.getColor().g, infoLine.getColor().b);
    short pair = addPair(color, color);
    wattron(window, COLOR_PAIR(pair));
    for (int i = 0; i < length; i++)
        mvaddch(infoLine.getPosition().y + i * (lengthy / length),
            infoLine.getPosition().x + i * (lengthx / length),
            ' ');
    wattroff(window, COLOR_PAIR(pair));
}

void NcWindow::draw(const Rectangle& infoRectangle)
{
    int lengthx =
        abs(infoRectangle.getPosition().x - infoRectangle.getSize().x);
    int lengthy =
        abs(infoRectangle.getPosition().y - infoRectangle.getSize().y);
    int length = lengthx * lengthy;

    short color = addColors(infoRectangle.getColor().r,
        infoRectangle.getColor().g,
        infoRectangle.getColor().b);
    short pair = addPair(color, color);
    wattron(window, COLOR_PAIR(pair));
    for (int i = 0; i < length; i++) {
        mvaddch(infoRectangle.getPosition().y + (i / lengthx),
            infoRectangle.getPosition().x + (i % lengthx),
            ' ');
    }
    wattroff(window, COLOR_PAIR(pair));
}

void NcWindow::draw(const Point& infoPoint)
{
    short color = addColors(infoPoint.getColor().r,
        infoPoint.getColor().g,
        infoPoint.getColor().b);
    short pair = addPair(color, color);
    wattron(window, COLOR_PAIR(pair));
    mvaddch(infoPoint.getPosition().y, infoPoint.getPosition().x, ' ');
    wattroff(window, COLOR_PAIR(pair));
}

void NcWindow::draw(const Text& infoText)
{
    short backColor = addColors(infoText.getBackColor().r,
        infoText.getBackColor().g,
        infoText.getBackColor().b);
    short color = addColors(
        infoText.getColor().r, infoText.getColor().g, infoText.getColor().b);
    short pair = addPair(color, backColor);
    wattron(window, COLOR_PAIR(pair));
    for (int i = 0; i < infoText.getString().size(); i++)
        mvaddch(infoText.getPosition().y,
            infoText.getPosition().x + i,
            infoText.getString().at(i));
    wattroff(window, COLOR_PAIR(pair));
}

void NcWindow::play(const ASound&)
{
}
}