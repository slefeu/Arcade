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
  public:
    AShape() = default;
    AShape(const vec2int& pos, const color_uint8& color) : pos_(pos), color_(color){};
    ~AShape() = default;

    void setPos(const vec2int& pos) {
        pos_ = pos;
    };
    vec2int getPos() const {
        return pos_;
    };
    void setColor(const color_uint8& color) {
        color_ = color;
    };
    color_uint8 getColor() const {
        return color_;
    };

  protected:
    vec2int pos_       = {-1, -1};
    color_uint8 color_ = {0, 0, 0};
};

class Rectangle : public AShape {
  public:
    Rectangle(const vec2int& pos, const vec2int& size, const color_uint8& color = {255, 255, 255},
              bool filled = true)
        : AShape(pos, color), fill(filled), size_(size){};
    ~Rectangle() = default;

    void setSize(const vec2int& size) {
        size_ = size;
    };
    vec2int getSize() const {
        return size_;
    };
    bool fill = true;

  private:
    vec2int size_ = {0, 0};
};

class Point : public AShape {
  public:
    Point() = default;
    Point(const vec2int& pos, const color_uint8& color = {255, 255, 255}) : AShape(pos, color){};
    ~Point() = default;
};

class Circle : public AShape {
  public:
    Circle() = default;
    Circle(const vec2int& pos, const unsigned int& radius,
           const color_uint8& color = {255, 255, 255}, bool filled = true)
        : AShape(pos, color), fill(filled), radius_(radius){};
    ~Circle() = default;

    void setRadius(const unsigned int& radius) {
        radius_ = radius;
    };
    unsigned int getRadius() const {
        return radius_;
    };
    bool fill = true;

  private:
    unsigned int radius_ = 0;
};

class Line : public AShape {
  public:
    Line() = default;
    Line(const vec2int& pos_a, const vec2int& pos_b, const color_uint8& color = {255, 255, 255})
        : AShape(pos_a, color), pos_b_(pos_b){};
    ~Line() = default;

    void setSecondPos(const vec2int& pos) {
        pos_b_ = pos;
    };
    vec2int getSecondPos() const {
        return pos_b_;
    };

  private:
    vec2int pos_b_ = {0, 0};
};
} // namespace arcade
#endif /* !AShape_HPP_ */