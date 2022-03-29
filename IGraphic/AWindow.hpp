/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Awindow
*/

#pragma once

#include "ASound.hpp"
#include "ASprite.hpp"
#include "AShape.hpp"
#include "State.hpp"
#include "Text.hpp"
#include <memory>

namespace arcade {

class AWindow {
  public:
    AWindow() = default;
    virtual ~AWindow() = default;

    virtual void display() = 0;
    virtual void clear() = 0;
    virtual bool pollEvent(Events&) = 0;

    virtual void setTitle(const std::string& title) = 0;
    virtual void setSize(const vec2int& size)       = 0;
    constexpr int getCharSize() const;
    bool getStatus() const;

    virtual void draw(const Line&)      = 0;
    virtual void draw(const Point&)     = 0;
    virtual void draw(const Circle&)    = 0;
    virtual void draw(const Rectangle&) = 0;
    virtual void draw(const Text&)      = 0;
    virtual void draw(const ASprite&)   = 0;
    virtual void play(const ASound&)    = 0;

  protected:
    bool status = true;
  private:
    constexpr int charSize = 21;

};
} // namespace arcade