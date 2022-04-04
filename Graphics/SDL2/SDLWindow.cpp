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
        throw Error("Failed to init SDL2 lib");
    window = SDL_CreateWindow("Arcade",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        size_.x * charSize, size_.y * charSize,
        SDL_WINDOW_SHOWN);
    if (window == nullptr)
        throw Error("Failed to create SDL Renderer");
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface,
        NULL,
        SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_ShowCursor(SDL_DISABLE);
}

void SDLWindow::setFramerate(int framerate) noexcept
{
}

SDLWindow::~SDLWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLWindow::display()
{
    // SDL_RenderPresent(renderer);
}

void SDLWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

bool SDLWindow::pollEvent(Events&)
{
    return (false);
}

void SDLWindow::setTitle(const std::string& newTitle)
{
    SDL_SetWindowTitle(window, newTitle.c_str());
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