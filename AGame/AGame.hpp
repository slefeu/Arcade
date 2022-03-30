#pragma once

#include <memory>

#include "AWindow.hpp"
#include "Core.hpp"

namespace arcade
{
class AGame
{
  public:
    AGame() noexcept = default;
    AGame(const AGame&) noexcept = delete;
    AGame(AGame&&) noexcept = delete;
    virtual ~AGame() noexcept = default;

    AGame& operator=(const AGame& rhs) noexcept = delete;
    AGame& operator=(AGame&& rhs) noexcept = delete;

    /**
     * @brief Execute one tick of the game
     * (Call the setWindow function before calling that function)
     */
    virtual void exec(void) = 0;
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
    void setWindow(std::unique_ptr<AWindow>&&) noexcept;
    /**
     * @brief return the ownership of the window
     *        (Be careful to not exec the game after calling that
     * function)
     *
     * @return The graphique librairy that the game used
     */
    std::unique_ptr<AWindow>&& getWindow() noexcept;

  protected:
    std::unique_ptr<AWindow> window = nullptr;

  private:
};
}