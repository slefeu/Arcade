/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Shape
*/

#include "AShape.hpp"

namespace arcade
{
AShape::AShape(const vec2int& pos, const color_uint8& color)
    : shapePosition(pos)
    , shapeColor(color){};

void AShape::setPosition(const vec2int& newPosition)
{
    shapePosition = newPosition;
}

void AShape::setColor(const color_uint8& newColor)
{
    shapeColor = newColor;
}

color_uint8 AShape::getColor() const
{
    return (shapeColor);
}

vec2int AShape::getPosition() const
{
    return (shapePosition);
}

Rectangle::Rectangle(const vec2int& pos,
    const vec2int& newSize,
    const color_uint8& color,
    bool filled)
    : AShape(pos, color)
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

Point::Point(
    const vec2int& position, const color_uint8& color)
    : AShape(position, color){};

Line::Line(const vec2int& positionStart,
    const vec2int& positionEnd,
    const color_uint8& color)
    : AShape(positionStart, color)
    , endLinePosition(positionEnd){};

void Line::setLineEnd(const vec2int& newPosition)
{
    endLinePosition = newPosition;
}

vec2int Line::getLineEnd() const
{
    return (endLinePosition);
}

} // namespace arcade