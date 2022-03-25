#include "AGame.hpp"

void AGame::setWindow(std::unique_ptr<AWindow> &&newWindow);
{
    window = std::move(newWindow);
};