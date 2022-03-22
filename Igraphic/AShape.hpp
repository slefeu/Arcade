/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** AShape
*/

#ifndef ASHAPE_HPP_
#define ASHAPE_HPP_

#include "State.hpp"

namespace arcade {
class AShape {
    enum ShapeType { Rectangle, Line, Circle, Point, Undef };

  public:
    AShape();
    virtual ~AShape();

  protected:
    ShapeType type_    = Undef;
    vec2int pos_       = {-1, -1};
    vec2int size_      = {-1, -1};
    color_uint8 color_ = {0, 0, 0};
    bool fill_         = false;

  private:
};
} // namespace arcade

#endif /* !AShape_HPP_ */
