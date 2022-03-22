/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Awindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include "AShape.hpp"
#include "AText.hpp"
#include "Asound.hpp"
#include "Asprite.hpp"
#include "State.hpp"
#include <memory>

namespace arcade {
class Awindow {
  public:
    Awindow();
    virtual ~Awindow();
    virtual void display(void)     = 0;
    virtual void clear(void)       = 0;
    virtual Events pollEvent(void) = 0;
    virtual bool drawn(AShape)     = 0;
    virtual bool drawn(AText)      = 0;
    virtual bool drawn(ASprite)    = 0;
    virtual bool drawn(ASound)     = 0;

  protected:
  private:
};
} // namespace arcade

#endif /* !IWINDOW_HPP_ */
