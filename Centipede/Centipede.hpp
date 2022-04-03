/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "AGame.hpp"
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
    enum Direction {
        Left,
        Right,
        Start,
    };
    Snake();
    Snake(std::vector<vec2int> body);
    ~Snake();
    void updateMove(
        std::vector<Obstacle> obstacleList, int length, int height) noexcept;
    std::vector<Point> getBodyPoint() noexcept;
    void split(std::vector<Snake> snakeList, vec2int pos) noexcept;
    std::vector<vec2int> getBody() const noexcept;
    void dead(std::vector<Snake> snakeList) noexcept;

  private:
    std::vector<vec2int> body = {};
    Direction dir = Start;
};
class Centipede : public AGame
{
  public:
    Centipede();
    ~Centipede();
    void exec(void);
    arcade::Status getStatus(void);

  protected:
  private:
    void start(void) noexcept;
    void displayObstacle(void) noexcept;
    void updatePlayer() noexcept;
    void movePlayer(Events& event) noexcept;
    std::vector<Snake> snakeList = {};
    std::vector<Obstacle> obstacleList = {};
    int tick = 0;
    vec2int player = {WindowX / 2, WindowY - 1};
    bool isDead = false;
};

};
#endif /* !CENTIPEDE_HPP_ */
