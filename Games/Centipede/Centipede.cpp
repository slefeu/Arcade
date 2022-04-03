/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#include "Centipede.hpp"

namespace arcade
{
extern "C" std::unique_ptr<IGame> createGame()
{
    return (std::make_unique<Centipede>());
}

int Centipede::getScore() const noexcept
{
    return (score);
}

static bool isTheSamePos(const vec2int& first, const vec2int& two) noexcept
{
    return (first.x == two.x && first.y == two.y);
}

bool Centipede::obstacleContain(
    const std::vector<Obstacle>& list, const Obstacle& obs) const noexcept
{
    for (int i = 0; i < list.size(); i++) {
        if (isTheSamePos(list.at(i).pos, obs.pos))
            return true;
    }
    return false;
}

void Centipede::start(IWindow& window) noexcept
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
    obstacleList = newObstacleList;
    window.setSize({WindowX, WindowY});
}

void Centipede::displayObstacle(IWindow& window) const noexcept
{
    for (Obstacle obs : obstacleList) {
        Point point;
        point.setPosition(obs.pos);
        point.setColor({0,
            (unsigned char)(20 * obs.life),
            (unsigned char)(20 * obs.life)});
        window.draw(point);
    }
}

bool Centipede::isStartingPos(const vec2int& pos) const noexcept
{
    return (pos.x == -1 && pos.y == -1);
}

void Centipede::tryShoot(Events& event) noexcept
{
    if (event.isPressed(Space) && isStartingPos(fire)) {
        fire.x = player.x;
        fire.y = player.y;
    }
}

bool Centipede::collideSnake(void) noexcept
{
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

void Centipede::damageObstacle(Obstacle& obstacle) noexcept
{
    obstacle.life = obstacle.life - 1;
    if (obstacle.life == 0) {
        score = score + 10;
        for (int i = 0; i < obstacleList.size(); i++) {
            if (obstacleList.at(i).pos.x == obstacle.pos.x
                && obstacleList.at(i).pos.y == obstacle.pos.y) {
                obstacleList.erase(obstacleList.begin() + i);
                return;
            }
        }
    }
}

bool Centipede::collideObstacle() noexcept
{
    for (Obstacle obstacle : obstacleList) {
        if (obstacle.pos.x != fire.x)
            continue;
        if (obstacle.pos.y == fire.y) {
            damageObstacle(obstacle);
            return true;
            ;
        }
    }
    return false;
}

void Centipede::updateShoot() noexcept
{
    if (isStartingPos(fire))
        return;
    fire = {fire.x, fire.y - 1};
    if (fire.y < 0 || collideObstacle() || collideSnake()) {
        fire = {-1, -1};
        return;
    }
}

void Centipede::displayFire(IWindow& window) const noexcept
{
    if (isStartingPos(fire))
        return;
    Point fireDisplay;
    fireDisplay.setPosition(fire);
    fireDisplay.setColor({255, 255, 51});
    window.draw(fireDisplay);
}

bool Centipede::isPlayerHit(void) const noexcept
{
    for (Snake snake : snakeList) {
        for (vec2int fragment : snake.getBody()) {
            if (fragment.x == player.x && fragment.y == player.y) {
                return true;
            }
        }
    }
    return false;
}

void Centipede::updatePlayer(IWindow& window) noexcept
{
    Events event;
    window.pollEvent(event);
    movePlayer(event);
    if (isPlayerHit())
        isDead = true;
    tryShoot(event);
    if (tick % 10 == 0)
        hasMoved = false;
    Point playerPoint;
    playerPoint.setColor({100, 100, 100});
    playerPoint.setPosition(player);
    window.draw(playerPoint);
}

void Centipede::exec(IWindow& window)
{
    if (tick == 0)
        start(window);
    displayObstacle(window);
    if (tick % 2 == 0)
        updateShoot();
    if (tick % 10 == 0) {
        if (snakeList.size() == 0) {
            if (nbSnake == 20)
                hasWin = true;
            Snake newSnake = Snake();
            snakeList.push_back(newSnake);
            nbSnake++;
        }
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
            window.draw(point);
        }
    }
    displayFire(window);
    updatePlayer(window);
    tick++;
}

bool Centipede::didPlayerCollide(const vec2int& loc) noexcept
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
    if (hasMoved)
        return;
    int minY = WindowY * 0.8;
    if (event.isPressed(Up)) {
        if (player.y - 1 >= minY
            && !didPlayerCollide({player.x, player.y - 1})) {
            player.y = player.y - 1;
            hasMoved = true;
            return;
        }
    }
    if (event.isPressed(Down)) {
        if (player.y + 1 <= WindowY
            && !didPlayerCollide({player.x, player.y + 1})) {
            player.y = player.y + 1;
            hasMoved = true;
            return;
        }
    }
    if (event.isPressed(Left)) {
        if (player.x - 1 >= 0 && !didPlayerCollide({player.x - 1, player.y})) {
            player.x = player.x - 1;
            hasMoved = true;
            return;
        }
    }
    if (event.isPressed(Right)) {
        if (player.x + 1 <= WindowX
            && !didPlayerCollide({player.x + 1, player.y})) {
            player.x = player.x + 1;
            hasMoved = true;
            return;
        }
    }
}

Status Centipede::getStatus()
{
    if (isDead) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        return Exit;
    }
    if (hasWin) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        return Exit;
    }
    return Nothing;
}

void Snake::updateMove(
    std::vector<Obstacle>& obstacleList, int length, int height) noexcept
{
    if (direction == Start) {
        if (rand() % 2 == 0)
            direction = Right;
        else
            direction = Left;
    }
    if (direction == Right) {
        if (body.at(0).x + 1 >= length) {
            body.emplace(body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
            body.pop_back();
            direction = Left;
            return;
        }
        for (Obstacle obs : obstacleList) {
            if (isTheSamePos({body.at(0).x + 1, body.at(0).y}, obs.pos)) {
                body.emplace(
                    body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
                body.pop_back();
                direction = Left;
                return;
            }
        }
        body.emplace(body.begin(), vec2int{body.at(0).x + 1, body.at(0).y});
        body.pop_back();
        return;
    }
    if (direction == Left) {
        if (body.at(0).x - 1 <= 0) {
            body.emplace(body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
            body.pop_back();
            direction = Right;
            return;
        }
        for (Obstacle obs : obstacleList) {
            if (isTheSamePos({body.at(0).x - 1, body.at(0).y}, obs.pos)) {
                body.emplace(
                    body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
                body.pop_back();
                direction = Right;
                return;
            }
        }
        body.emplace(body.begin(), vec2int{body.at(0).x - 1, body.at(0).y});
        body.pop_back();
    }
}

std::vector<Point> Snake::getBodyPoint() const noexcept
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

void Snake::dead(std::vector<Snake>& snakeList) noexcept
{
    for (int i = 0; i < snakeList.size(); i++) {
        if (isTheSamePos(snakeList.at(i).getBody().at(0), body.at(0))
            && snakeList.at(i).getBody().size() == 0) {
            snakeList.erase(snakeList.begin() + i);
            break;
        }
    }
}

void Snake::split(std::vector<Snake>& snakeList, vec2int& pos) noexcept
{
    std::vector<vec2int> newBody;
    bool found = false;
    for (int i = 0; i < body.size(); i++) {
        if (isTheSamePos(body.at(i), pos)) {
            found = true;
            continue;
        }
        if (found)
            newBody.push_back(body.at(i));
    }
    for (int i = 0; i < newBody.size(); i++)
        body.pop_back();
    body.pop_back(); // remove fragment who was hit
    Snake newSnake = Snake(newBody);
    if (direction == Right)
        newSnake.direction == Left;
    else
        newSnake.direction == Right;
    snakeList.push_back(newSnake);
    if (body.size() == 0) {
        dead(snakeList);
    }
}

std::vector<vec2int> Snake::getBody() const noexcept
{
    return (body);
}

Snake::Snake() noexcept
{
    body = {
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
}

Snake::Snake(const std::vector<vec2int>& newBody) noexcept
    : body(newBody)
{
}

};