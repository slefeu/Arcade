/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "IWindow.hpp"

namespace arcade
{
constexpr int charSize = 21;

class SfWindow : public IWindow
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
    void play(const ASound&) final;
    Status getStatus() final;
    void destroy();
  protected:
    Status status;

  private:
    sf::RenderWindow window_;
    vec2int size_ = {1600, 900};
    std::string title = "Arcade";
    sf::Font font;
};
} // namespace arcade