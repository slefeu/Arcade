#include "AGame.hpp"

namespace arcade
{
void AGame::setWindow(std::unique_ptr<AWindow>&& newWindow) noexcept
{
    window = std::move(newWindow);
}

std::unique_ptr<AWindow>&& AGame::getWindow() noexcept
{
    return std::move(window);
}
} // namespace arcade