/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Shape
*/

#include "AShape.hpp"

namespace arcade {

AShape::AShape(const vec2int& pos, const color_uint8& color) : shapePosition(pos), shapeColor(color)
{
};

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

Rectangle::Rectangle(const vec2int& pos, const vec2int& size, const color_uint8& color = {255, 255, 255}, bool filled = true)
        : AShape(pos, color), isFilled(filled), rectangleSize(size)
{
};

void Rectangle::setRectangleSize(const vec2int& newSize)
{
    rectangleSize = newSize;
}

vec2int Rectangle::getRectangleSize() const
{
    return (rectangleSize);
}

void Rectangle::setFillValue(bool newValue)
{
    isFilled = newValue;
}

bool Rectangle::getFillValue() const
{
    return (isFilled);
}

Point::Point(const vec2int& position, const color_uint8& color = {255, 255, 255}) : AShape(position, color)
{
};

Circle::Circle(const vec2int& pos, const unsigned int& radius,
           const color_uint8& color = {255, 255, 255}, bool filled = true)
        : AShape(pos, color), isFilled(filled), circleRadius(radius)
{
};

void Circle::setRadius(const unsigned int newRadius)
{
    circleRadius = newRadius;
}

unsigned int Circle::getRadius() const
{
    return (circleRadius);
}

void Circle::setFillValue(bool newValue)
{
    isFilled = newValue;
}

bool Circle::getFillValue() const
{
    return (isFilled);
}

Line::Line(const vec2int& positionStart, const vec2int& positionEnd, const color_uint8& color = {255, 255, 255})
        : AShape(positionStart, color), endLinePosition(positionEnd)
{
};

void Line::setLineEnd(const vec2int& newPosition)
{
    endLinePosition = newPosition;
}

vec2int Line::getLineEnd() const
{
    return (endLinePosition);
}

} // namespace arcade