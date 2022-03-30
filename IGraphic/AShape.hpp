/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** AShape
*/

#pragma once
#include "State.hpp"

namespace arcade
{
    class AShape {
        public:
            AShape() noexcept = default;
            AShape(const vec2int &, const color_uint8 &);

            AShape(const AShape &) noexcept = default;
            AShape(AShape &&) noexcept = default;
            ~AShape() noexcept = default;

            AShape &operator=(const AShape &rhs) noexcept = default;
            AShape &operator=(AShape &&rhs) noexcept = default;

            /**
             * @brief Set the Position
             * 
             */
            void setPosition(const vec2int &);
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
            void setColor(const color_uint8 &);
            /**
             * @brief Get the Color
             * 
             * @return color_uint8 
             */
            color_uint8 getColor() const;

        protected:
            vec2int shapePosition = {-1, -1};
            color_uint8 shapeColor = {0, 0, 0};

        private:
    };

    class Rectangle : public AShape {
        public:
            Rectangle() noexcept = default;
            Rectangle(
                const vec2int &, const vec2int &, const color_uint8 &, bool);
            Rectangle(const Rectangle &) noexcept = default;
            Rectangle(Rectangle &&) noexcept = default;
            ~Rectangle() noexcept = default;

            Rectangle &operator=(const Rectangle &rhs) noexcept = default;
            Rectangle &operator=(Rectangle &&rhs) noexcept = default;

            /**
             * @brief Set the Rectangle Size
             * 
             */
            void setSize(const vec2int &);
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

    class Point : public AShape {
        public:
            Point() = default;
            Point(const vec2int &, const color_uint8 &);
            ~Point() = default;
    };

    class Line : public AShape {
        public:
            Line() = default;
            Line(const vec2int &, const vec2int &, const color_uint8 &);
            ~Line() = default;

            /**
             * @brief Set the Line End object
             *
             * @param position of the end of the line
             */
            void setLineEnd(const vec2int &position);
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