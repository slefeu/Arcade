/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** AShape
*/

#pragma once
#include "State.hpp"

namespace arcade {
class AShape {
  public:
    AShape() = default;
    AShape(const vec2int&, const color_uint8&);
    ~AShape() = default;

  //setters and getters
    void setPosition(const vec2int&);
    vec2int getPosition() const;
    void setColor(const color_uint8&);
    color_uint8 getColor() const;

  protected:
    vec2int shapePosition = {-1, -1};
    color_uint8 shapeColor = {0, 0, 0};
};

class Rectangle : public AShape {
  public:
    Rectangle(const vec2int&, const vec2int&, const color_uint8&, bool);
    ~Rectangle() = default;

    void setRectangleSize(const vec2int&);
    vec2int getRectangleSize() const;
    void setFillValue(bool);
    bool getFillValue() const;

  private:
    bool isFilled = true;
    vec2int rectangleSize = {0, 0};
};

class Point : public AShape {
  public:
    Point() = default;
    Point(const vec2int&, const color_uint8&);
    ~Point() = default;
};

class Circle : public AShape {
  public:
    Circle() = default;
    Circle(const vec2int&, const unsigned int&, const color_uint8&, bool);
    ~Circle() = default;

    void setRadius(unsigned int);
    unsigned int getRadius() const;
    void setFillValue(bool);
    bool getFillValue() const;

  private:
    bool isFilled = true;
    unsigned int circleRadius = 0;
};

class Line : public AShape {
  public:
    Line() = default;
    Line(const vec2int&, const vec2int&, const color_uint8&);
    ~Line() = default;

    void setLineEnd(const vec2int& pos);
    vec2int getLineEnd() const;

  private:
    vec2int endLinePosition = {0, 0};
};
} // namespace arcade