/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#include "Centipede.hpp"

namespace arcade
{
extern "C" std::unique_ptr<AGame> createGame()
{
    return (std::make_unique<Centipede>());
}

Centipede::Centipede()
{
}

Centipede::~Centipede()
{
}

bool isTheSamePos(vec2int first, vec2int two)
{
    return (first.x == two.x && first.y == two.y);
}

bool obstacleContain(std::vector<Obstacle> list, Obstacle obs)
{
    for (int i = 0; i < list.size(); i++) {
        if (isTheSamePos(list.at(i).pos, obs.pos))
            return true;
    }
    return false;
}

void Centipede::start() noexcept
{
    std::vector<Obstacle> newObstacleList = {};
    for (int i = 0; i < NbOstacle; i++) {
        int x = rand() % WindowX;
        int y = rand() % static_cast<int>(WindowY * 0.8);
        while (obstacleContain(newObstacleList, {5, {x, y}})) {
            x = rand() % WindowX;
            y = rand() % static_cast<int>(WindowY * 0.8);
        }
        newObstacleList.push_back({x, y});
    }
    this->obstacleList = newObstacleList;
    this->window->setSize({WindowX, WindowY});
}

void Centipede::displayObstacle() noexcept
{
    for (Obstacle obs : obstacleList) {
        Point point;
        point.setPosition(obs.pos);
        point.setColor({0,
            (unsigned char)(20 * obs.life),
            (unsigned char)(20 * obs.life)});
        this->window->draw(point);
    }
}

bool isStartingPos(vec2int pos) {
    return (pos.x == -1 && pos.y == -1);
}

void Centipede::tryShoot(Events& event) noexcept {
    if (event.isPressed(Space) && isStartingPos(fire)) {
        fire.x = player.x;
        fire.y = player.y;
    }
}

bool Centipede::colideSnake(void) noexcept {
    for (Snake snake : snakeList) {
        for (vec2int fragment : snake.getBody()) {
            if (fragment.x == fire.x && fragment.y == fire.y) {
                snake.split(snakeList, fragment);
                obstacleList.push_back({5, {fire.x, fire.y}});
                score = score + 20;
                return true;
            }
        }
    }
    return false;
}

void Centipede::damageObstacle(Obstacle obstacle) noexcept {
    obstacle.life = obstacle.life - 1;
    if (obstacle.life == 0) {
        score = score + 10;
        for (int i = 0; i < obstacleList.size(); i++) {
            if (obstacleList.at(i).pos.x == obstacle.pos.x && obstacleList.at(i).pos.y == obstacle.pos.y) {
                obstacleList.erase(obstacleList.begin() + i);
                return;
            }
        }
    }
}

bool Centipede::colideObstacle(void) noexcept {
    for (Obstacle obstacle : obstacleList) {
        if (obstacle.pos.x != fire.x)
            continue;
        if (obstacle.pos.y == fire.y) {
            damageObstacle(obstacle);
            return true;;
        }
    }
    return false;
}

void Centipede::updateShoot(void) noexcept {
    if (isStartingPos(fire))
        return;
    fire = {fire.x, fire.y - 1};
    if (fire.y < 0 || colideObstacle() || colideSnake()) {
        fire = {-1, -1};
        return;
    }
}

void Centipede::displayFire() noexcept {
    if (isStartingPos(fire))
        return;
    Point fireDisplay;
    fireDisplay.setPosition(fire);
    fireDisplay.setColor({255, 255, 51});
    window->draw(fireDisplay);
}

bool Centipede::isPlayerHit(void) noexcept {
    for (Snake snake : snakeList) {
        for (vec2int fragment : snake.getBody()) {
            if (fragment.x == player.x && fragment.y == player.y) {
                return true;
            }
        }
    }
    return false;
}

void Centipede::updatePlayer() noexcept
{
    Events event;
    window->pollEvent(event);
    movePlayer(event);
    if (isPlayerHit())
        isDead = true;
    tryShoot(event);
    if (tick % 10 == 0)
        hasMooved = false;
    Point playerPoint;
    playerPoint.setColor({100, 100, 100});
    playerPoint.setPosition(player);
    window->draw(playerPoint);
}

void Centipede::exec(void)
{
    if (tick == 0)
        start();
    displayObstacle();
    if (tick % 2 == 0)
        updateShoot();
    if (tick % 10 == 0) {
        if (snakeList.size() == 0)
            snakeList.push_back(Snake());
        for (Snake snake : snakeList) {
            snake.updateMove(obstacleList, WindowX, WindowY);
            if (snake.getBody().at(0).y > WindowY) {
                snake.dead(snakeList);
                score = score - 100;
            }
        }
    }
    for (Snake snake : snakeList) {
        for (Point point : snake.getBodyPoint()) {
            window->draw(point);
        }
    }
    displayFire();
    updatePlayer();
    tick++;
}

bool Centipede::didPlayerCollide(vec2int loc) noexcept
{
    for (Obstacle obstacle : obstacleList) {
        if (obstacle.pos.x != loc.x)
            continue;
        if (obstacle.pos.y == loc.y) {
            return true;
        }
    }
    return false;
}

void Centipede::movePlayer(Events& event) noexcept
{
    if (hasMooved)
        return;
    int minY = WindowY * 0.8;
    if (event.isPressed(Up)) {
        if (player.y - 1 >= minY && !didPlayerCollide({player.x, player.y - 1})) {
            player.y = player.y - 1;
            hasMooved = true;
            return;
        }
    }
    if (event.isPressed(Down)) {
        if (player.y + 1 <= WindowY
            && !didPlayerCollide({player.x, player.y + 1})) {
            player.y = player.y + 1;
            hasMooved = true;
            return;
        }
    }
    if (event.isPressed(Left)) {
        if (player.x - 1 >= 0 && !didPlayerCollide({player.x - 1, player.y})) {
            player.x = player.x - 1;
            hasMooved = true;
            return;
        }
    }
    if (event.isPressed(Right)) {
        if (player.x + 1 <= WindowX
            && !didPlayerCollide({player.x + 1, player.y})) {
            player.x = player.x + 1;
            hasMooved = true;
            return;
        }
    }
}

Status Centipede::getStatus(void)
{
    if (isDead)
        return Exit;
    return Nothing;
}

void Snake::updateMove(
    std::vector<Obstacle> obstacleList, int length, int height) noexcept
{
    if (dir == Start) {
        if (rand() % 2 == 0)
            dir = Right;
        else
            dir = Left;
    }
    if (dir == Right) {
        if (this->body.at(0).x + 1 >= length) {
            this->body.emplace(this->body.begin(),
                vec2int{this->body.at(0).x, this->body.at(0).y + 1});
            this->body.pop_back();
            dir = Left;
            return;
        }
        for (Obstacle obs : obstacleList) {
            if (isTheSamePos(
                    {this->body.at(0).x + 1, this->body.at(0).y}, obs.pos)) {
                this->body.emplace(this->body.begin(),
                    vec2int{this->body.at(0).x, this->body.at(0).y + 1});
                this->body.pop_back();
                dir = Left;
                return;
            }
        }
        this->body.emplace(this->body.begin(),
            vec2int{this->body.at(0).x + 1, this->body.at(0).y});
        this->body.pop_back();
        return;
    }
    if (dir == Left) {
        if (this->body.at(0).x - 1 <= 0) {
            this->body.emplace(this->body.begin(),
                vec2int{this->body.at(0).x, this->body.at(0).y + 1});
            this->body.pop_back();
            dir = Right;
            return;
        }
        for (Obstacle obs : obstacleList) {
            if (isTheSamePos(
                    {this->body.at(0).x - 1, this->body.at(0).y}, obs.pos)) {
                this->body.emplace(this->body.begin(),
                    vec2int{this->body.at(0).x, this->body.at(0).y + 1});
                this->body.pop_back();
                dir = Right;
                return;
            }
        }
        this->body.emplace(this->body.begin(),
            vec2int{this->body.at(0).x - 1, this->body.at(0).y});
        this->body.pop_back();
    }
}

std::vector<Point> Snake::getBodyPoint() noexcept
{
    Point bodyFragment;
    std::vector<Point> newBody;
    bodyFragment.setColor({200, 10, 10});
    for (int i = 0; i < body.size(); i++) {
        bodyFragment.setPosition(body.at(i));
        if (i == 1)
            bodyFragment.setColor({250, 10, 10});
        newBody.push_back(bodyFragment);
    }
    return newBody;
}

void Snake::dead(std::vector<Snake> snakeList) noexcept {
    for (int i = 0; i < snakeList.size(); i++) {
        if (isTheSamePos(snakeList.at(i).getBody().at(0), this->body.at(0))
            && snakeList.at(i).getBody().size() == 0) {
            snakeList.erase(snakeList.begin() + i);
            break;
        }
    }
}

void Snake::split(std::vector<Snake> snakeList, vec2int pos) noexcept
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
    body.pop_back(); // remove fragment who was hit
    Snake newSnake = Snake(newBody);
    if (this->dir == Right)
        newSnake.dir == Left;
    else
        newSnake.dir == Right;
    snakeList.push_back(newSnake);
    if (body.size() == 0) {
        dead(snakeList);
    }
}

std::vector<vec2int> Snake::getBody() const noexcept
{
    return this->body;
}

Snake::Snake()
{
    this->body = {
        {WindowX / 2, 0},
        {WindowX / 2, -1},
        {WindowX / 2, -2},
        {WindowX / 2, -3},
        {WindowX / 2, -4},
        {WindowX / 2, -5},
        {WindowX / 2, -6},
        {WindowX / 2, -7},
        {WindowX / 2, -8},
        {WindowX / 2, -9},
    };
    this->dir = Start;
}

};