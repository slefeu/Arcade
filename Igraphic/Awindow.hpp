/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Awindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include "Asound.hpp"
#include "Asprite.hpp"
#include "Shape.hpp"
#include "State.hpp"
#include "Text.hpp"
#include <memory>

namespace arcade {
class AWindow {
  public:
    AWindow();
    virtual ~AWindow();

    virtual void display(void)     = 0;
    virtual void clear(void)       = 0;
    virtual Events pollEvent(void) = 0;
    bool status(void) {
        return status_;
    };
    virtual void setTitle(const std::string& title) = 0;
    virtual void setSize(const vec2int& size)       = 0;

    virtual void draw(const Line&)      = 0;
    virtual void draw(const Point&)     = 0;
    virtual void draw(const Circle&)    = 0;
    virtual void draw(const Rectangle&) = 0;
    virtual void draw(const Text&)      = 0;
    virtual void draw(const ASprite&)   = 0;
    virtual void play(const ASound&)    = 0;

  protected:
    bool status_ = true;
};
} // namespace arcade

#endif /* !IWINDOW_HPP_ */
