/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** NcWindow
*/

#ifndef NCWINDOW_HPP_
#define NCWINDOW_HPP_

#include "AWindow.hpp"
#include <ncurses.h>

namespace arcade {
class NcWindow : public AWindow {
    public:
        NcWindow();
        ~NcWindow();
        void display() final;
        void clear() final;
        bool pollEvent(Events&) final;
        void setTitle(const std::string&) final;
        void setSize(const vec2int&) final;
        void draw(const Line&) final;
        void draw(const Circle&) final;
        void draw(const Rectangle&) final;
        void draw(const Point&) final;
        void draw(const Text&) final;
        void draw(const ASprite&) final;
        void play(const ASound&) final;

      protected:
      private:
};
}

#endif /* !NCWINDOW_HPP_ */