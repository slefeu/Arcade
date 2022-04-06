/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Shape
*/

#pragma once
#include "Utils.hpp"

namespace arcade
{
class Shape
{
  public:
    Shape() noexcept = default;
    Shape(const vec2int&, const color_uint8&);

    Shape(const Shape&) noexcept = default;
    Shape(Shape&&) noexcept = default;
    ~Shape() noexcept = default;

    Shape& operator=(const Shape& rhs) noexcept = default;
    Shape& operator=(Shape&& rhs) noexcept = default;

    /**
     * @brief Set the Position
     *
     */
    void setPosition(const vec2int&);
    /**
     * @brief Get the Position
     *
     * @return vec2int
     */
    vec2int getPosition() const;
    /**
     * @brief Set the Color
     *
     */
    void setColor(const color_uint8&);
    /**
     * @brief Get the Color
     *
     * @return color_uint8
     */
    color_uint8 getColor() const;

  protected:
    vec2int shapePosition = {-1, -1};
    color_uint8 shapeColor = {0, 0, 0};
};

class Rectangle : public Shape
{
  public:
    Rectangle() noexcept = default;
    /**
     * @brief Construct a new Rectangle object
     *
     * @param position
     * @param size
     * @param color
     * @param filled is the rectangle filled or empty
     */
    Rectangle(const vec2int& position,
        const vec2int& size,
        const color_uint8& color = {255, 255, 255},
        bool filled = true);
    Rectangle(const Rectangle&) noexcept = default;
    Rectangle(Rectangle&&) noexcept = default;
    ~Rectangle() noexcept = default;

    Rectangle& operator=(const Rectangle& rhs) noexcept = default;
    Rectangle& operator=(Rectangle&& rhs) noexcept = default;

    /**
     * @brief Set the Rectangle Size
     *
     */
    void setSize(const vec2int&);
    /**
     * @brief Get the Rectangle Size
     *
     * @return vec2int
     */
    vec2int getSize() const;
    /**
     * @brief Set if the Rectangle is filled or not
     *
     */
    void setFillValue(bool);
    /**
     * @brief Get if the Rectangle is filled or not
     *
     * @return true if filled
     * @return false if not
     */
    bool getFillValue() const;

  private:
    bool isFilled = true;
    vec2int size = {0, 0};
};

class Point : public Shape
{
  public:
    Point() = default;
    /**
     * @brief Construct a new Point object
     *
     * @param position
     * @param color
     */
    Point(const vec2int& position, const color_uint8& color = {255, 255, 255});
    Point(const Point& other) noexcept = default;
    Point(Point&& other) noexcept = default;
    ~Point() noexcept = default;

    Point& operator=(const Point& rhs) noexcept = default;
    Point& operator=(Point&& rhs) noexcept = default;
};

class Line : public Shape
{
  public:
    Line() = default;
    /**
     * @brief Construct a new Line object
     *
     * @param firstPosition
     * @param lastPosition
     * @param color
     */
    Line(const vec2int& firstPosition,
        const vec2int& lastPosition,
        const color_uint8& color = {255, 255, 255});
    Line(const Line& other) noexcept = default;
    Line(Line&& other) noexcept = default;
    ~Line() noexcept = default;

    Line& operator=(const Line& rhs) noexcept = default;
    Line& operator=(Line&& rhs) noexcept = default;

    /**
     * @brief Set the Line End object
     *
     * @param position of the end of the line
     */
    void setLineEnd(const vec2int& position);
    /**
     * @brief Get the Line End
     *
     * @return vec2int end's line position
     */
    vec2int getLineEnd() const;

  private:
    vec2int endLinePosition = {0, 0};
};
} // namespace arcade