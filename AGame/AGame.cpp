#include "AGame.hpp"

namespace arcade
{
void AGame::setWindow(std::unique_ptr<AWindow>&& newWindow)
{
    window = std::move(newWindow);
};
} // namespace arcade