#include "AWindow.hpp"

namespace arcade
{
Status AWindow::getStatus()
{
    Status tmp = status;

    if (status < Exit)
        status = Nothing;
    return tmp;
}
};