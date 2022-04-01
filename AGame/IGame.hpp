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
     * @return the score of the player
     */
    virtual int exec(void) = 0;
    /**
     * @brief
     *
     * @return The curent status of the game and the window
     */
    virtual Status getStatus(void) = 0;
    /**
     * @brief Give the window ownership to the game
     *        (Don't exec the game before calling that function)
     *
     * @param window The graphic librairy that the game will use
     */
    void setWindow(std::unique_ptr<IWindow>&&) noexcept;
    /**
     * @brief return the ownership of the window
     *        (Be careful to not exec the game after calling that
     * function)
     *
     * @return The graphic librairy that the game used
     */
    std::unique_ptr<IWindow>&& getWindow() noexcept;

  protected:
    std::unique_ptr<IWindow> window = nullptr;

  private:
};
}