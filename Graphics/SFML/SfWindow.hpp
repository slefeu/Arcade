/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

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
    void setFramerate(int framerate) noexcept final;
    Status getStatus() noexcept final;

  protected:
    Status status = Nothing;

  private:
    sf::RenderWindow window_;
    std::string title = "Arcade";
    sf::Font font;
    vec2int size_ = {50, 35};
};
} // namespace arcade