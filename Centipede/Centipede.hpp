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
class Centipede : public AGame {
  public:
    Centipede();
    ~Centipede();
    int exec(void);
    arcade::Status getStatus(void);
  protected:
  private:
    std::vector<Snake> snakeList;
    std::vector<Obstacle> obstacleList;
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
        void updateMove() noexcept;
        void display(std::unique_ptr<AWindow> window) noexcept;
        void split(std::vector<Snake> snakeList, vec2int pos) noexcept;
        std::vector<vec2int> getBody() const noexcept;

      private:
        std::vector<vec2int> body;
};

struct Obstacle {
    int life;
    vec2int pos;
};

};
#endif /* !CENTIPEDE_HPP_ */
