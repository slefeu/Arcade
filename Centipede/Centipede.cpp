/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#include "Centipede.hpp"

namespace arcade {


Centipede::Centipede()
{
}

Centipede::~Centipede()
{
}

int Centipede::exec(void)
{
}

Status Centipede::getStatus(void)
{
}

void Snake::updateMove() {
    
}

void Snake::display(std::unique_ptr<AWindow> window)
{
    Point bodyFragment;
    bodyFragment.setColor({200, 10, 10});
    for (int i = 0; i < body.size(); i++) {
        bodyFragment.setPosition(body.at(i));
        if (i == 1)
            bodyFragment.setColor({250, 10, 10});
        window->draw(bodyFragment);
    }
}

bool isTheSamePos(vec2int first, vec2int two)
{
    return (first.x == two.x && first.y == two.y);
}

void Snake::split(std::vector<Snake> snakeList, vec2int pos)
{
    std::vector<vec2int> newBody;
    bool finded = false;
    for (int i = 0; i < body.size(); i++) {
        if (isTheSamePos(body.at(i), pos)) {
            finded = true;
            continue;
        }
        if (finded)
            newBody.push_back(body.at(i));
    }
    for (int i = 0; i < newBody.size(); i++)
        body.pop_back();
    body.pop_back(); //remove fragment who was hit
    Snake newSnake = Snake(newBody);
    snakeList.push_back(newSnake);
    if (body.size() == 0) {
        for (int i = 0; i < snakeList.size(); i++) {
            if (isTheSamePos(snakeList.at(i).getBody().at(0), this->body.at(0))) {
                snakeList.erase(snakeList.begin() + i);
                break;
            }
        }
    }
}

std::vector<vec2int> Snake::getBody() const {
    return this->body;
}

};