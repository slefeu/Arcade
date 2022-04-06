/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#include "SfWindow.hpp"

#include <iostream>

namespace arcade
{
extern "C" std::unique_ptr<IWindow> createLib()
{
    return (std::make_unique<SfWindow>());
}

SfWindow::SfWindow()
{
    window_.create(
        sf::VideoMode(size_.x * charSize, size_.y * charSize, 32), "Arcade");
    font.loadFromFile("assets/font.ttf");
}

SfWindow::~SfWindow()
{
    if (window_.isOpen())
        window_.close();
}

void SfWindow::setFramerate(int framerate) noexcept
{
    window_.setFramerateLimit(framerate);
}

void SfWindow::setTitle(const std::string& title)
{
    window_.setTitle(title);
}

void SfWindow::setSize(const vec2int& size)
{
    size_ = size;
    window_.create(
        sf::VideoMode(size_.x * charSize, size_.y * charSize, 32), "Arcade");
}

void SfWindow::draw(const Line& infoLine)
{
    sf::Color color(
        infoLine.getColor().r, infoLine.getColor().g, infoLine.getColor().b);
    std::array<sf::Vertex, 2> line = {
        sf::Vertex(sf::Vector2f(
            static_cast<float>(infoLine.getPosition().x * charSize),
            static_cast<float>(infoLine.getPosition().y * charSize))),
        sf::Vertex(
            sf::Vector2f(static_cast<float>(infoLine.getLineEnd().x * charSize),
                static_cast<float>(infoLine.getLineEnd().y * charSize)))};
    line[0].color = color;
    window_.draw(line.data(), charSize, sf::Lines);
}

void SfWindow::draw(const Point& infoPoint)
{
    Rectangle rect;
    rect.setPosition(infoPoint.getPosition());
    rect.setColor(infoPoint.getColor());
    rect.setFillValue(false);
    rect.setSize({1, 1});
    draw(rect);
}

void SfWindow::draw(const Rectangle& infoRectangle)
{
    sf::RectangleShape rectangle(
        sf::Vector2f(static_cast<float>(infoRectangle.getSize().x * charSize),
            static_cast<float>(infoRectangle.getSize().y * charSize)));
    sf::Color color(infoRectangle.getColor().r,
        infoRectangle.getColor().g,
        infoRectangle.getColor().b);
    rectangle.setOutlineColor(color);
    rectangle.setOutlineThickness(-charSize);
    if (!infoRectangle.getFillValue())
        rectangle.setFillColor(sf::Color::Transparent);
    else {
        rectangle.setFillColor(color);
    }
    rectangle.setPosition(sf::Vector2f(
        static_cast<float>(infoRectangle.getPosition().x * charSize),
        static_cast<float>(infoRectangle.getPosition().y * charSize)));
    window_.draw(rectangle);
}

void SfWindow::draw(const Text& infoText)
{
    sf::Text text;
    sf::Color color(
        infoText.getColor().r, infoText.getColor().g, infoText.getColor().b);
    sf::Color backColor(infoText.getBackColor().r,
        infoText.getBackColor().g,
        infoText.getBackColor().b);
    text.setPosition(
        sf::Vector2f(static_cast<float>(infoText.getPosition().x * charSize),
            static_cast<float>(infoText.getPosition().y * charSize)));
    text.setFont(font);
    text.setString(infoText.getString());
    text.setFillColor(color);
    text.setOutlineColor(backColor);
    text.setOutlineThickness(1);
    text.setCharacterSize(21);
    window_.draw(text);
}

void SfWindow::play(const ASound& sound)
{
}

void SfWindow::display()
{
    window_.display();
}

void SfWindow::clear()
{
    window_.clear();
}

Status SfWindow::getStatus() noexcept
{
    Status tmp = status;

    if (status < Exit)
        status = Nothing;
    return tmp;
}

bool SfWindow::pollEvent(Events& rEvent)
{
    auto event = sf::Event{};

    while (window_.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                rEvent.key_pressed.push_back(Key(event.key.code));
                return true;
            case sf::Event::Closed: status = Exit; return true;
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button) {
                    case sf::Mouse::Right:
                        rEvent.mouse.right = true;
                        rEvent.mouse.pos = {
                            event.mouseButton.x, event.mouseButton.y};
                        return true;
                    case sf::Mouse::Middle:
                        rEvent.mouse.middle = true;
                        rEvent.mouse.pos = {
                            event.mouseButton.x, event.mouseButton.y};
                        return true;
                    case sf::Mouse::Left:
                        rEvent.mouse.left = true;
                        rEvent.mouse.pos = {
                            event.mouseButton.x, event.mouseButton.y};
                        return true;
                    default: return false;
                }
            case sf::Event::MouseMoved:
                rEvent.mouse.pos = {event.mouseMove.x, event.mouseMove.y};
                return true;
            default: return false;
        };
    }
    return false;
}
} // namespace arcade
