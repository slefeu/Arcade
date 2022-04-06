/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** IWindow
*/

#pragma once

#include <memory>

#include "AShape.hpp"
#include "ASound.hpp"
#include "Text.hpp"

namespace arcade
{
class IWindow
{
  public:
    IWindow() = default;
    virtual ~IWindow() = default;

    /**
     * @brief Display all previously drawn elements on the window
     *
     */
    virtual void display() = 0;
    /**
     * @brief Clear the previous draw
     *
     */
    virtual void clear() = 0;
    /**
     * @brief Pop the event on top of the event queue.
     *
     * @return if the queue is empty or not
     */
    virtual bool pollEvent(Events&) = 0;

    /**
     * @brief Set the Title
     *
     * @param title
     */
    virtual void setTitle(const std::string& title) = 0;
    /**
     * @brief Set the Size of the window
     *
     * @param size
     */
    virtual void setSize(const vec2int& size) = 0;
    /**
     * @brief
     *
     * @return Status The current status of the window
     */
    virtual Status getStatus() noexcept = 0;
    /**
     * @brief Set the Framerate object
     *
     */
    virtual void setFramerate(int framerate) noexcept = 0;
    /**
     * @brief Draw a drawable object
     *
     */
    virtual void draw(const Line&) = 0;
    virtual void draw(const Point&) = 0;
    virtual void draw(const Rectangle&) = 0;
    virtual void draw(const Text&) = 0;
    /**
     * @brief Play a sound
     *
     */
    virtual void play(const ASound&) = 0;
};
} // namespace arcade