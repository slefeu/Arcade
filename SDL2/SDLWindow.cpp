#include "SDLWindow.hpp"
#include "Error.hpp"

namespace arcade
{
extern "C" std::unique_ptr<IWindow> createLib()
{
    return (std::make_unique<SDLWindow>());
}

SDLWindow::SDLWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw(Error("Failed to init SDL2 lib"));
    if (SDL_CreateWindowAndRenderer(size_.x, size_.y, 0, &window, &renderer) < 0)
        throw(Error("Failed to create SDL Renderer"));
    SDL_SetWindowTitle(window, "Titre");
    SDL_ShowCursor(SDL_DISABLE);
}

void SDLWindow::display()
{

}

void SDLWindow::clear()
{

}

bool SDLWindow::pollEvent(Events&)
{
    return (false);
}

void SDLWindow::setTitle(const std::string&)
{

}

void SDLWindow::setSize(const vec2int&)
{

}

void SDLWindow::draw(const Line&)
{

}

void SDLWindow::draw(const Rectangle&)
{

}

void SDLWindow::draw(const Point&)
{

}

void SDLWindow::draw(const Text&)
{

}

void SDLWindow::play(const ASound&)
{

}

Status SDLWindow::getStatus()
{
    Status tmp = status;

    if (status < Exit)
        status = Nothing;
    return tmp;
}
} // namespace arcade