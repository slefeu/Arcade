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
    ~AGame() noexcept = default;

    AGame& operator=(const AGame& rhs) noexcept = delete;
    AGame& operator=(AGame&& rhs) noexcept = delete;

    virtual void exec() = 0;
    virtual bool status() = 0;
    void setWindow(std::unique_ptr<AWindow>&&);

  protected:
    std::unique_ptr<AWindow> window = nullptr;

  private:
};
}