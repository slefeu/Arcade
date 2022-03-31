#include "AGame.hpp"

namespace arcade
{
void AGame::setWindow(std::unique_ptr<IWindow>&& newWindow) noexcept
{
    window = std::move(newWindow);
}

std::unique_ptr<IWindow>&& AGame::getWindow() noexcept
{
    return std::move(window);
}
} // namespace arcade