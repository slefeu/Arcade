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

    IGame& operator=(const IGame& rhs) noexcept = delete;
    IGame& operator=(IGame&& rhs) noexcept = delete;

    /**
     * @brief Execute one tick of the game
     * (Call the setWindow function before calling that function)
     */
    virtual void exec(IWindow&, Events& event) = 0;
    /**
     * @brief Restart the game
     * 
     */
    virtual void restart() = 0;
    /**
     * @brief
     *
     * @return The curent status of the game and the window
     */
    virtual Status getStatus(void) = 0;
    /**
     * @brief Get the Score object
     *
     * @return int the value of the score
     */
    virtual int getScore() const noexcept = 0;

  protected:
  private:
};
}