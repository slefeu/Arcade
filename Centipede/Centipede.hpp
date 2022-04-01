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

namespace arcade {

constexpr int WindowX = 30;
constexpr int WindowY = 25;
constexpr int NbOstacle = 40;
class Centipede : public AGame {
  public:
    Centipede();
    ~Centipede();
    void exec(void);
    arcade::Status getStatus(void);
  protected:
  private:
    void start(void) noexcept;
    void displayObstacle(void) noexcept;
    std::vector<Snake> snakeList = {};
    std::vector<Obstacle> obstacleList = {};
};

class Snake {
    public:
        enum Direction {
            Left,
            Right,
            Start,
        };
        Snake();
        Snake(std::vector<vec2int> body);
        ~Snake();
        void updateMove(std::vector<Obstacle> obstacleList, int length, int height) noexcept;
        std::vector<Point> getBodyPoint() noexcept;
        void split(std::vector<Snake> snakeList, vec2int pos) noexcept;
        std::vector<vec2int> getBody() const noexcept;

      private:
        std::vector<vec2int> body = {};
        Direction dir = Start;
};

struct Obstacle {
    int life;
    vec2int pos;
};

};
#endif /* !CENTIPEDE_HPP_ */
