/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "AWindow.hpp"

namespace arcade
{
class SfWindow : public AWindow
{
  public:
    SfWindow();
    ~SfWindow();
    void display() final;
    void clear() final;
    bool pollEvent(Events&) final;
    void setTitle(const std::string&) final;
    void setSize(const vec2int&) final;
    void draw(const Line&) final;
    void draw(const Rectangle&) final;
    void draw(const Point&) final;
    void draw(const Text&) final;
    void draw(const ASprite&) final;
    void play(const ASound&) final;

  protected:
  private:
    sf::RenderWindow window_;
    vec2int size_ = {-1, -1};
    std::string title = "";
};
} // namespace arcade