/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "IGame.hpp"

class Centipede : public arcade::IGame {
  public:
    Centipede();
    ~Centipede();
    int exec(void);
    arcade::Status getStatus(void);
  protected:
  private:
};

#endif /* !CENTIPEDE_HPP_ */
