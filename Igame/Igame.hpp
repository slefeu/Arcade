/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Igame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "Agraphic.hpp"
#include <memory>

namespace arcade {
class Igame {
  public:
    Igame(){};

    Igame(Igame&&)      = delete;
    Igame(const Igame&) = delete;
    Igame& operator=(Igame&&) = delete;
    Igame& operator=(const Igame&) = delete;

    virtual std::unique_ptr<Agraphic>&& exec(std::unique_ptr<Agraphic>&&) = 0;
    virtual bool status(void)                                             = 0;

  protected:
    std::unique_ptr<Agraphic> lib;
};
} // namespace arcade

#endif /* !IGAME_HPP_ */
