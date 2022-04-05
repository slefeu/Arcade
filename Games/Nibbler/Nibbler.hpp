/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <dirent.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>

#include "Error.hpp"
#include "IGame.hpp"

namespace arcade
{
constexpr int WindowX = 19;
constexpr int WindowY = 19;
class Nibbler : public IGame
{
  public:
    Nibbler() noexcept = default;
    Nibbler(const Nibbler& other) noexcept = default;
    Nibbler(Nibbler&& other) noexcept = default;
    virtual ~Nibbler() noexcept = default;

    Nibbler& operator=(const Nibbler& rhs) noexcept = default;
    Nibbler& operator=(Nibbler&& rhs) noexcept = default;

    void exec(IWindow&, Events& event) noexcept final;
    void restart() noexcept final;
    Status getStatus() final;
    int getScore() const noexcept final;

    enum Direction { NbRight, NbLeft, NbDown, NbUp };

  protected:
  private:
    Events event;
    void start(IWindow&);
    std::vector<std::string> listMap(void);
    void parseList(void);
    void initDefault(void) noexcept;
    void initBody(vec2int pos) noexcept;
    void displayPlayer(IWindow&) noexcept;
    void displayObstacle(IWindow&) noexcept;
    void displayApple(IWindow&) noexcept;
    bool didCollideWall(const vec2int&) noexcept;
    void movePlayer(void) noexcept;
    void changeDirection(void);
    void updatePlayer(IWindow& window) noexcept;
    bool isPlayerHit(void) const noexcept;
    void tryEat(void) noexcept;
    void respawnApple(int nbApple) noexcept;
    void displayEndText(IWindow& window) noexcept;
    void displayStat(IWindow& window) noexcept;
    std::vector<vec2int> getValidPos(void) noexcept;
    std::vector<vec2int> body = {};
    std::vector<vec2int> obstacleList = {};
    std::vector<vec2int> appleList = {};
    bool hasMoved = false;
    bool isDead = false;
    bool hasWin = false;
    bool isFinish = false;
    int score = 0;
    int tick = 0;
    Direction direction = NbRight;
};
}

#endif /* !NIBBLER_HPP_ */
