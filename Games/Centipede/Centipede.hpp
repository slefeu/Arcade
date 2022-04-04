/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#pragma once

#include <chrono>
#include <thread>

#include "IGame.hpp"
#include "Utils.hpp"

namespace arcade
{
constexpr int WindowX = 30;
constexpr int WindowY = 25;
constexpr int NbOstacle = 40;

struct Obstacle {
    int life;
    vec2int pos;
};

class Snake
{
  public:
    Snake() noexcept;
    Snake(const std::vector<vec2int>&) noexcept;
    Snake(const Snake& other) noexcept = default;
    Snake(Snake&& other) noexcept = default;

    ~Snake() noexcept = default;

    Snake& operator=(const Snake& rhs) noexcept = default;
    Snake& operator=(Snake&& rhs) noexcept = default;

    enum Direction {
        Left,
        Right,
        Start,
    };

    void updateMove(std::vector<Obstacle>&, int, int) noexcept;
    std::vector<Point> getBodyPoint() const noexcept;
    void split(std::vector<Snake>&, vec2int&) noexcept;
    std::vector<vec2int> getBody() const noexcept;
    bool dead(std::vector<Snake>&) noexcept;
    Direction getDirection() const noexcept;

  private:
    std::vector<vec2int> body;
    Direction direction = Start;
};

class Centipede final : public IGame
{
  public:
    Centipede() noexcept = default;
    Centipede(const Centipede& other) noexcept = default;
    Centipede(Centipede&& other) noexcept = default;
    virtual ~Centipede() noexcept = default;

    Centipede& operator=(const Centipede& rhs) noexcept = default;
    Centipede& operator=(Centipede&& rhs) noexcept = default;

    void exec(IWindow&, Events& event) noexcept final;
    Status getStatus();

  protected:
  private:
    void start(IWindow& window) noexcept;
    void displayObstacle(IWindow& window) const noexcept;
    void displayFire(IWindow& window) const noexcept;
    void updatePlayer(IWindow& window) noexcept;
    void movePlayer(Events&) noexcept;
    void tryShoot(Events&) noexcept;
    void updateShoot() noexcept;
    bool collideSnake() noexcept;
    bool collideObstacle() noexcept;
    bool didPlayerCollide(const vec2int&) noexcept;
    bool isPlayerHit() const noexcept;
    void damageObstacle(Obstacle&) noexcept;
    int getScore() const noexcept;
    bool obstacleContain(
        const std::vector<Obstacle>&, const Obstacle&) const noexcept;
    bool isStartingPos(const vec2int&) const noexcept;
    void displayEndText(IWindow& window) noexcept;
    void displayStat(IWindow& window) noexcept;

    // attributes
    Events event;
    std::vector<Snake> snakeList = {};
    std::vector<Obstacle> obstacleList = {};
    long int tick = 0;
    vec2int player = {WindowX / 2, WindowY - 1};
    bool isDead = false;
    bool hasWin = false;
    bool isFinish = false;
    bool hasMoved = false;
    int nbSnake = 0;
    vec2int fire = {-1, -1};
    int score = 0;
};
};