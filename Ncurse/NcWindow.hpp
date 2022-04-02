/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** NcWindow
*/

#pragma once
#include <ncurses.h>

#include "IWindow.hpp"

namespace arcade
{

class NcWindow : public IWindow
{
  public:
    NcWindow() noexcept;
    NcWindow(const NcWindow&) noexcept = default;
    NcWindow(NcWindow&&) noexcept = default;
    virtual ~NcWindow() noexcept;

    NcWindow& operator=(const NcWindow& rhs) noexcept = default;
    NcWindow& operator=(NcWindow&& rhs) noexcept = default;

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

  protected:
    Status status;

  private:
    WINDOW* window;
    std::string title = "";
    vec2int size_ = {50, 35};
};
}