#include "IGame.hpp"

namespace arcade
{
void IGame::setWindow(std::unique_ptr<IWindow>&& newWindow) noexcept
{
    window = std::move(newWindow);
}

std::unique_ptr<IWindow>&& IGame::getWindow() noexcept
{
    return std::move(window);
}
} // namespace arcade