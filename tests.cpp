#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    // The window we'll be rendering to
    SDL_Window* window = NULL;

    // The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    } else {
        // Get window surface
        screenSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(screenSurface,
            NULL,
            SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);

        // Wait two seconds
        SDL_Delay(2000);
    }
}

// Destroy window
SDL_DestroyWindow(window);

// Quit SDL subsystems
SDL_Quit();

return 0;
}