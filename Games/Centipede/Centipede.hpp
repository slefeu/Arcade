/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#pragma once

#include "IGame.hpp"
#include "Utils.hpp"
#include <chrono>
#include <thread>

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

    void updateMove(std::vector<Obstacle>&, int, int) noexcept;
    std::vector<Point> getBodyPoint() const noexcept;
    void split(std::vector<Snake>&, vec2int&) noexcept;
    std::vector<vec2int> getBody() const noexcept;
    void dead(std::vector<Snake>&) noexcept;

    enum Direction {
        Left,
        Right,
        Start,
    };

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

    void exec(IWindow&);
    Status getStatus();

  protected:
  private:
    void start(IWindow&) noexcept;
    void displayObstacle(IWindow&) const noexcept;
    void displayFire(IWindow&) const noexcept;
    void updatePlayer(IWindow&) noexcept;
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

    // attributes
    std::vector<Snake> snakeList = {};
    std::vector<Obstacle> obstacleList = {};
    int tick = 0;
    vec2int player = {WindowX / 2, WindowY - 1};
    bool isDead = false;
    bool hasWin = false;
    bool hasMoved = false;
    int nbSnake = 0;
    vec2int fire = {-1, -1};
    int score = 0;
};
};