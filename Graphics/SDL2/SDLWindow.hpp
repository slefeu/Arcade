#pragma once

#include <SDL2/SDL.h>

#include "IWindow.hpp"

namespace arcade
{
class SDLWindow : public IWindow
{
  public:
    SDLWindow();
    SDLWindow(const SDLWindow&) noexcept = default;
    SDLWindow(SDLWindow&&) noexcept = default;
    virtual ~SDLWindow() noexcept = default;

    SDLWindow& operator=(const SDLWindow&) noexcept = default;
    SDLWindow& operator=(SDLWindow&&) noexcept = default;

    void display() final;
    void clear() final;
    bool pollEvent(Events&) final;
    void setTitle(const std::string&) final;
    void setSize(const vec2int&) final;
    void draw(const Line&) final;
    void draw(const Rectangle&) final;
    void draw(const Point&) final;
    void draw(const Text&) final;
    void play(const ASound&) final;
    void setFramerate(int framerate) noexcept final;
    Status getStatus() final;

  protected:
    Status status;

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::string title = "Arcade";
    vec2int size_ = {50, 35};
};
}