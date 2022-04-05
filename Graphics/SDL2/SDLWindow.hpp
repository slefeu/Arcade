#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <chrono>
#include <thread>

#include "IWindow.hpp"

namespace arcade
{
constexpr int charSize = 21;

class SDLWindow : public IWindow
{
  public:
    SDLWindow();
    SDLWindow(const SDLWindow&) noexcept = default;
    SDLWindow(SDLWindow&&) noexcept = default;
    virtual ~SDLWindow() noexcept;

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
    Status status = Nothing;

  private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font;
    std::string title = "Arcade";
    vec2int size_ = {50, 35};
    int framerate = 120;
    std::chrono::milliseconds lastDisplay{0};

    static bool insertkey(Key, Events&) noexcept;
};
}