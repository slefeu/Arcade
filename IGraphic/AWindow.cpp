#include "AWindow.hpp"

namespace arcade {

constexpr int AWindow::getCharSize() const
{
    return (charSize);
}

bool AWindow::getStatus() const
{
    return (status);
}

void AWindow::setStatus(const bool newStatus)
{
    status = newStatus;
}

};