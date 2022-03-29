/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfWindow
*/

#include "SfWindow.hpp"

namespace arcade {

extern "C" std::unique_ptr<AWindow> createLib() {
    return std::make_unique<SfWindow>;
}

SfWindow::SfWindow() {
    this->window_.create(sf::VideoMode(800, 600), "SFML");
}

SfWindow::~SfWindow() {
    if (window_.isOpen())
        window_.close();
}

void SfWindow::setTitle(const std::string& title) {
    this->window_.setTitle(title);
}

void SfWindow::setSize(const vec2int& size) {
    this->size_ = size;
    this->window_.setSize(sf::Vector2u(size.x, size.y));
}

void SfWindow::draw(const Line& infoLine) {
    sf::Vertex line[] = {sf::Vertex(sf::Vector2f(infoLine.getPosition().x * charSize,
                                                 infoLine.getPosition().y * charSize)),
                         sf::Vertex(sf::Vector2f(infoLine.getLineEnd().x * charSize,
                                                 infoLine.getLineEnd().y * charSize))};

    window_.draw(line, 2, sf::Lines);
}

void SfWindow::draw(const Point&) {
}

void SfWindow::draw(const Circle& infoCircle) {
    sf::CircleShape circle(infoCircle.getRadius() * charSize);
    circle.setPosition(
        sf::Vector2f(infoCircle.getPosition().x * charSize, infoCircle.getPosition().y * charSize));
    window_.draw(circle);
}

void SfWindow::draw(const Rectangle& infoReactangle) {
    sf::RectangleShape rectangle(
        sf::Vector2f(infoReactangle.getSize().x * charSize, infoReactangle.getSize().y * charSize));
    rectangle.setPosition(
        sf::Vector2f(infoReactangle.getPosition().x * charSize, infoReactangle.getPosition().y * charSize));
    window_.draw(rectangle);
}

void SfWindow::draw(const Text& infoText) {
    sf::Text text;
    sf::Color color(infoText.getColor().r, infoText.getColor().g, infoText.getColor().b);
    sf::Color backColor(infoText.getBackColor().r, infoText.getBackColor().g,
                        infoText.getBackColor().b);
    text.setPosition(sf::Vector2f(infoText.getPos().x * charSize, infoText.getPos().y * charSize));
    text.setString(infoText.getString());
    text.setFillColor(color);
    text.setOutlineColor(backColor);
    window_.draw(text);
}

void SfWindow::draw(const ASprite&) {
}

void SfWindow::play(const ASound&) {
}

void SfWindow::display(void) {
    window_.create(sf::VideoMode(this->size_.x, this->size_.y), "SFML");
    if (this->title != "")
        window_.setTitle(this->title);
}

void SfWindow::clear(void) {
    window_.clear();
}

bool SfWindow::pollEvent(Events& rEvent) {
    sf::Event event;
    while (window_.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            rEvent.getKeyPressed().push_back(Key(event.key.code));
            return true;
        case sf::Event::Closed:
            rEvent.stopGame = true;
            return true;
        case sf::Event::MouseButtonPressed:
            switch (event.mouseButton.button) {
            case sf::Mouse::Right:
                rEvent.mouse.right = true;
                rEvent.mouse.pos   = {event.mouseButton.x, event.mouseButton.y};
                return true;
            case sf::Mouse::Middle:
                rEvent.mouse.middle = true;
                rEvent.mouse.pos    = {event.mouseButton.x, event.mouseButton.y};
                return true;
            case sf::Mouse::Left:
                rEvent.mouse.left = true;
                rEvent.mouse.pos  = {event.mouseButton.x, event.mouseButton.y};
                return true;
            default:
                return false;
            }
        case sf::Event::MouseMoved:
            rEvent.mouse.pos = {event.mouseMove.x, event.mouseMove.y};
            return true;
        default:
            return false;
        };
    }
    return false;
}
} // namespace arcade
