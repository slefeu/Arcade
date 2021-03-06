/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Shape
*/

#include "Shape.hpp"

namespace arcade
{
Shape::Shape(const vec2int& pos, const color_uint8& color)
    : shapePosition(pos)
    , shapeColor(color){};

void Shape::setPosition(const vec2int& newPosition)
{
    shapePosition = newPosition;
}

void Shape::setColor(const color_uint8& newColor)
{
    shapeColor = newColor;
}

color_uint8 Shape::getColor() const
{
    return (shapeColor);
}

vec2int Shape::getPosition() const
{
    return (shapePosition);
}

Rectangle::Rectangle(const vec2int& pos,
    const vec2int& newSize,
    const color_uint8& color,
    bool filled)
    : Shape(pos, color)
    , isFilled(filled)
    , size(newSize){};

void Rectangle::setSize(const vec2int& newSize)
{
    size = newSize;
}

vec2int Rectangle::getSize() const
{
    return (size);
}

void Rectangle::setFillValue(bool newValue)
{
    isFilled = newValue;
}

bool Rectangle::getFillValue() const
{
    return (isFilled);
}

Point::Point(const vec2int& position, const color_uint8& color)
    : Shape(position, color){};

Line::Line(const vec2int& firstPosition,
    const vec2int& lastPosition,
    const color_uint8& color)
    : Shape(firstPosition, color)
    , endLinePosition(lastPosition){};

void Line::setLineEnd(const vec2int& newPosition)
{
    endLinePosition = newPosition;
}

vec2int Line::getLineEnd() const
{
    return (endLinePosition);
}

} // namespace arcade