#pragma once

#include <memory>

#include "IWindow.hpp"

namespace arcade
{
class IGame
{
  public:
    IGame() noexcept = default;
    IGame(const IGame&) noexcept = delete;
    IGame(IGame&&) noexcept = delete;
    virtual ~IGame() noexcept = default;

    IGame& operator=(const IGame&) noexcept = delete;
    IGame& operator=(IGame&&) noexcept = delete;

    /**
     * @brief Execute one tick of the game
     *
     */
    virtual void exec(IWindow&, Events&) = 0;
    /**
     * @brief Restart the game
     *
     */
    virtual void restart() = 0;
    /**
     * @brief
     *
     * @return The current status of the game and the window
     */
    virtual Status getStatus() noexcept = 0;
    /**
     * @brief Get the Score object
     *
     * @return int the value of the score
     */
    virtual int getScore() const noexcept = 0;
    /**
     * @brief Get the Size of the window
     *
     * @return vec2int size of the window
     */
    virtual vec2int getSize() const noexcept = 0;

  protected:
  private:
};
}