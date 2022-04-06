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

vec2int Centipede::getSize() const noexcept
{
    return (vec2int{WindowX, WindowY + 4});
}

static bool isTheSamePos(const vec2int& first, const vec2int& two) noexcept
{
    return (first.x == two.x && first.y == two.y);
}

bool Centipede::obstacleContain(
    const std::vector<Obstacle>& list, const Obstacle& obs) noexcept
{
    return (std::any_of(list.begin(), list.end(), [&](Obstacle const& i) {
        return isTheSamePos(i.pos, obs.pos);
    }));
}

void Centipede::start(IWindow& window) noexcept
{
    std::srand(std::time(nullptr));
    std::vector<Obstacle> newObstacleList = {};
    for (int i = 0; i < NbOstacle; i++) {
        int x = std::rand() % WindowX;
        int y = std::rand() % static_cast<int>(WindowY * 0.8);
        while (obstacleContain(newObstacleList, {5, {x, y}})) {
            x = std::rand() % WindowX;
            y = std::rand() % static_cast<int>(WindowY * 0.8);
        }
        newObstacleList.push_back({5, {x, y}});
    }
    obstacleList = newObstacleList;
    window.setSize({WindowX, WindowY + 4});
    window.setFramerate(120);
}

void Centipede::restart() noexcept
{
    event = Events();
    snakeList = {};
    obstacleList = {};
    tick = 0;
    player = {WindowX / 2, WindowY - 1};
    isDead = false;
    hasWin = false;
    isFinish = false;
    hasMoved = false;
    nbSnake = 0;
    fire = {-1, -1};
    score = 0;
}

void Centipede::displayObstacle(IWindow& window) const noexcept
{
    for (Obstacle obs : obstacleList) {
        Point point;
        point.setPosition(obs.pos);
        point.setColor({0,
            static_cast<unsigned char>((20 * obs.life)),
            static_cast<unsigned char>((20 * obs.life))});
        window.draw(point);
    }
}

bool Centipede::isStartingPos(const vec2int& pos) noexcept
{
    return (pos.x == -1 && pos.y == -1);
}

void Centipede::tryShoot() noexcept
{
    if (event.isPressed(Space) && isStartingPos(fire)) {
        fire.x = player.x;
        fire.y = player.y;
    }
}

bool Centipede::collideSnake() noexcept
{
    for (Snake& snake : snakeList) {
        for (vec2int& fragment : snake.getBody()) {
            if (fragment.x == fire.x && fragment.y == fire.y) {
                snake.split(snakeList, fragment);
                obstacleList.push_back({5, {fire.x, fire.y}});
                score = score + 30;
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
    for (Obstacle& obstacle : obstacleList) {
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

bool Centipede::isPlayerHit() const noexcept
{
    for (Snake const& snake : snakeList) {
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
    movePlayer();
    isDead = isPlayerHit();
    tryShoot();
    if (tick % 10 == 0)
        hasMoved = false;
    Point playerPoint;
    playerPoint.setColor({100, 100, 100});
    playerPoint.setPosition(player);
    window.draw(playerPoint);
}

void Centipede::displayEndText(IWindow& window) const noexcept
{
    Text endText;
    endText.setPosition({(WindowX / 2) - 2, WindowY / 2});
    if (isDead) {
        endText.setString("You Lose !");
        endText.setColor({255, 1, 1});
    }
    if (hasWin) {
        endText.setString("Victory !");
        endText.setColor({1, 255, 1});
    }
    endText.setBackColor({0, 0, 0});
    window.draw(endText);
}

void Centipede::displayStat(IWindow& window) noexcept
{
    Text scoreText;
    Text waveText;
    Line border;
    border.setPosition({0, WindowY + 1});
    border.setLineEnd({WindowX, WindowY + 1});
    border.setColor({1, 30, 255});
    scoreText.setPosition({5, WindowY + 3});
    waveText.setPosition({5, WindowY + 2});
    scoreText.setString("Score: " + std::to_string(score));
    if (nbSnake > 20)
        nbSnake = 20;
    waveText.setString("Wave: " + std::to_string(nbSnake) + " ("
                       + std::to_string(20 - nbSnake) + " remaining)");
    window.draw(border);
    window.draw(scoreText);
    window.draw(waveText);
}

void Centipede::exec(IWindow& window, Events& newEvent) noexcept
{
    this->event = newEvent;
    if (tick == 0)
        start(window);
    displayObstacle(window);
    if (tick % 2 == 0)
        updateShoot();
    if (tick % 10 == 0) {
        if (snakeList.empty()) {
            if (nbSnake == 20)
                hasWin = true;
            Snake newSnake = Snake();
            snakeList.push_back(newSnake);
            nbSnake++;
        }
        int sizeSnakeList = static_cast<int>(snakeList.size());
        for (auto i = 0; i < sizeSnakeList; i++) {
            snakeList.at(i).updateMove(obstacleList, WindowX);
            if (Snake::dead(snakeList)) {
                score = score - 50;
                i--;
                sizeSnakeList--;
            }
        }
    }
    for (Snake& snake : snakeList) {
        for (Point point : snake.getBodyPoint()) {
            window.draw(point);
        }
    }
    displayFire(window);
    updatePlayer(window);
    displayEndText(window);
    displayStat(window);
    window.setFramerate(120);
    tick++;
}

bool Centipede::didPlayerCollide(const vec2int& loc) noexcept
{
    return std::any_of(
        obstacleList.begin(), obstacleList.end(), [&](Obstacle const& obs) {
            return (obs.pos.x == loc.x && obs.pos.y == loc.y);
        });
}

void Centipede::movePlayer() noexcept
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

Status Centipede::getStatus() noexcept
{
    if (isFinish && isDead) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        return Exit;
    }
    if (isFinish && hasWin) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        restart();
        return Nothing;
    }
    if (isDead || hasWin) {
        isFinish = true;
        return Nothing;
    }
    return Nothing;
}

Snake::Direction Snake::getDirection() const noexcept
{
    return direction;
}

void Snake::updateMove(std::vector<Obstacle>& obstacleList, int length) noexcept
{
    if (body.empty())
        return;
    if (direction == Start) {
        if (rand() % 2 == 0)
            this->direction = Right;
        else
            this->direction = Left;
    }
    if (direction == Right) {
        if (body.at(0).x + 1 >= length) {
            body.emplace(body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
            body.pop_back();
            this->direction = Left;
            return;
        }
        for (Obstacle obs : obstacleList) {
            if (isTheSamePos({body.at(0).x + 1, body.at(0).y}, obs.pos)) {
                body.emplace(
                    body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
                body.pop_back();
                this->direction = Left;
                return;
            }
        }
        body.emplace(body.begin(), vec2int{body.at(0).x + 1, body.at(0).y});
        body.pop_back();
        return;
    }
    if (direction == Left) {
        if (body.at(0).x - 1 < 0) {
            body.emplace(body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
            body.pop_back();
            this->direction = Right;
            return;
        }
        for (Obstacle obs : obstacleList) {
            if (isTheSamePos({body.at(0).x - 1, body.at(0).y}, obs.pos)) {
                body.emplace(
                    body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
                body.pop_back();
                this->direction = Right;
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
    bodyFragment.setColor({200, 10, 200});
    for (int i = 0; i < body.size(); i++) {
        bodyFragment.setPosition(body.at(i));
        if (i == 1)
            bodyFragment.setColor({250, 10, 10});
        newBody.push_back(bodyFragment);
    }
    return newBody;
}

bool Snake::dead(std::vector<Snake>& snakeList) noexcept
{
    int sizeSnakeList = static_cast<int>(snakeList.size());
    for (int i = 0; i < sizeSnakeList; i++) {
        if ((snakeList.at(i).getBody().empty()
                || snakeList.at(i).getBody().at(0).y > WindowY)) {
            snakeList.erase(snakeList.begin() + i);
            return true;
        }
    }
    return false;
}

void Snake::split(std::vector<Snake>& snakeList, vec2int& pos) noexcept
{
    std::vector<vec2int> newBody;
    bool found = false;
    for (auto const& i : body) {
        if (isTheSamePos(i, pos)) {
            found = true;
            continue;
        }
        if (found)
            newBody.push_back(i);
    }
    for (int i = 0; i < newBody.size(); i++)
        body.pop_back();
    body.pop_back(); // remove fragment who was hit
    Snake newSnake = Snake(newBody);
    newSnake.direction = direction;
    if (!newSnake.getBody().empty())
        snakeList.push_back(newSnake);
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

Snake::Snake(std::vector<vec2int> newBody) noexcept
    : body(std::move(newBody))
{
}

};