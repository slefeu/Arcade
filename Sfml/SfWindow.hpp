/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#ifndef SFWINDOW_HPP_
#define SFWINDOW_HPP_

#include "Awindow.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace arcade {
class SfWindow : public AWindow {
  public:
    SfWindow();
    ~SfWindow();
    virtual void display(void) override;
    virtual void clear(void) override;
    virtual bool pollEvent(Events&) override;
    bool status(void) {
        return status_;
    };
    virtual void setTitle(const std::string& title) override;
    virtual void setSize(const vec2int& size) override;

    virtual void draw(const Line&) override;
    virtual void draw(const Point&) override;
    virtual void draw(const Circle&) override;
    virtual void draw(const Rectangle&) override;
    virtual void draw(const Text&) override;
    virtual void draw(const ASprite&) override;
    virtual void play(const ASound&) override;

  protected:
  private:
    sf::RenderWindow window_;
    vec2int size_     = {-1, -1};
    std::string title = "";
};
} // namespace arcade

#endif /* !SFWINDOW_HPP_ */
