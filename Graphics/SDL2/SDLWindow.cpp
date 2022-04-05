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
    TTF_Init();
    SDL_CreateWindowAndRenderer(size_.x * charSize,
        size_.y * charSize,
        SDL_WINDOW_SHOWN,
        &window,
        &renderer);
    if (window == nullptr)
        throw Error("Failed to create SDL Window");
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    setTitle("Arcade");
    SDL_ShowCursor(SDL_DISABLE);
    font = TTF_OpenFont("assets/font.ttf", 21);
}

void SDLWindow::setFramerate(int newFramerate) noexcept
{
    framerate = newFramerate;
}

SDLWindow::~SDLWindow() noexcept
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void SDLWindow::display()
{
    SDL_RenderPresent(renderer);
    std::chrono::milliseconds millisec_since_epoch =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
    if (millisec_since_epoch.count() - lastDisplay.count()
        < static_cast<int>(1000.0 / static_cast<double>(framerate))) {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(
            (1000.0 / static_cast<double>(framerate))
            - static_cast<double>(
                (millisec_since_epoch.count() - lastDisplay.count())))));
    }
    lastDisplay = millisec_since_epoch;
}

void SDLWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

bool SDLWindow::insertkey(Key key, Events& event) noexcept
{
    event.key_pressed.push_back(key);
    return true;
}

bool SDLWindow::pollEvent(Events& event)
{
    SDL_Event sdlEvent;
    if (SDL_PollEvent(&sdlEvent) != 0) {
        if (sdlEvent.type == SDL_WINDOWEVENT
            && sdlEvent.window.event == SDL_WINDOWEVENT_CLOSE) {
            status = Exit;
            return true;
        }
        if (sdlEvent.type == SDL_KEYDOWN) {
            switch (sdlEvent.key.keysym.sym) {
                case SDLK_DOWN: return insertkey(Down, event);
                case SDLK_UP: return insertkey(Up, event);
                case SDLK_LEFT: return insertkey(Left, event);
                case SDLK_RIGHT: return insertkey(Right, event);
                case SDLK_HOME: return insertkey(Home, event);
                case SDLK_BACKSPACE: return insertkey(Backspace, event);
                case SDLK_DELETE: return insertkey(Delete, event);
                case SDLK_INSERT: return insertkey(Insert, event);
                case SDLK_END: return insertkey(End, event);
                case SDL_QUIT:
                case SDLK_ESCAPE:
                    status = Exit;
                    return insertkey(Escape, event);
                case SDLK_PAGEDOWN: return insertkey(PageDown, event);
                case SDLK_PAGEUP: return insertkey(PageUp, event);
                case SDLK_RETURN: return insertkey(Enter, event);
                case SDLK_0: return insertkey(Num0, event);
                case SDLK_1: return insertkey(Num1, event);
                case SDLK_2: return insertkey(Num2, event);
                case SDLK_3: return insertkey(Num3, event);
                case SDLK_4: return insertkey(Num4, event);
                case SDLK_5: return insertkey(Num5, event);
                case SDLK_6: return insertkey(Num6, event);
                case SDLK_7: return insertkey(Num7, event);
                case SDLK_8: return insertkey(Num8, event);
                case SDLK_9: return insertkey(Num9, event);
                case 'A':
                case 'a': return insertkey(A, event);
                case 'B':
                case 'b': return insertkey(B, event);
                case 'C':
                case 'c': return insertkey(C, event);
                case 'D':
                case 'd': return insertkey(D, event);
                case 'E':
                case 'e': return insertkey(E, event);
                case 'F':
                case 'f': return insertkey(F, event);
                case 'G':
                case 'g': return insertkey(G, event);
                case 'H':
                case 'h': return insertkey(H, event);
                case 'I':
                case 'i': return insertkey(I, event);
                case 'J':
                case 'j': return insertkey(J, event);
                case 'K':
                case 'k': return insertkey(K, event);
                case 'L':
                case 'l': return insertkey(L, event);
                case 'M':
                case 'm': return insertkey(M, event);
                case 'N':
                case 'n': return insertkey(N, event);
                case 'O':
                case 'o': return insertkey(O, event);
                case 'P':
                case 'p': return insertkey(P, event);
                case 'Q':
                case 'q': return insertkey(Q, event);
                case 'R':
                case 'r': return insertkey(R, event);
                case 'S':
                case 's': return insertkey(S, event);
                case 'T':
                case 't': return insertkey(T, event);
                case 'U':
                case 'u': return insertkey(U, event);
                case 'V':
                case 'v': return insertkey(V, event);
                case 'W':
                case 'w': return insertkey(W, event);
                case 'X':
                case 'x': return insertkey(X, event);
                case 'Y':
                case 'y': return insertkey(Y, event);
                case 'Z':
                case 'z': return insertkey(Z, event);
                case SDLK_SPACE: return insertkey(Space, event);
                case SDLK_F1: return insertkey(F1, event);
                case SDLK_F2: return insertkey(F2, event);
                case SDLK_F3: return insertkey(F3, event);
                case SDLK_F4: return insertkey(F4, event);
                case SDLK_F5: return insertkey(F5, event);
                case SDLK_F6: return insertkey(F6, event);
                case SDLK_F7: return insertkey(F7, event);
                default: return false;
            }
        }
    }
    return false;
}

void SDLWindow::setTitle(const std::string& newTitle)
{
    SDL_SetWindowTitle(window, newTitle.c_str());
}

void SDLWindow::setSize(const vec2int& newSize)
{
    size_ = newSize;
    SDL_SetWindowSize(window, size_.x * charSize, size_.y * charSize);
}

void SDLWindow::draw(const Line& infoLine)
{
    vec2int start = infoLine.getPosition();
    vec2int end = infoLine.getLineEnd();

    SDL_SetRenderDrawColor(renderer,
        infoLine.getColor().r,
        infoLine.getColor().g,
        infoLine.getColor().b,
        SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer,
        start.x * charSize,
        start.y * charSize,
        end.x * charSize,
        end.y * charSize);
}

void SDLWindow::draw(const Rectangle& infoRectangle)
{
    SDL_Rect r;
    vec2int position = infoRectangle.getPosition();
    vec2int size = infoRectangle.getSize();
    r.x = position.x * charSize;
    r.y = position.y * charSize;
    r.w = size.x * charSize;
    r.h = size.y * charSize;

    SDL_SetRenderDrawColor(renderer,
        infoRectangle.getColor().r,
        infoRectangle.getColor().g,
        infoRectangle.getColor().b,
        SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderDrawRect(renderer, &r);
}

void SDLWindow::draw(const Point& infoPoint)
{
    vec2int position = infoPoint.getPosition();

    draw(Rectangle(position, vec2int({1, 1}), infoPoint.getColor()));
}

void SDLWindow::draw(const Text& infoText)
{
    unsigned long stringSize = infoText.getString().size();
    SDL_Color foregroundColor = {
        infoText.getColor().r, infoText.getColor().g, infoText.getColor().b};
    SDL_Color backgroundColor = {infoText.getBackColor().r,
        infoText.getBackColor().g,
        infoText.getBackColor().b};
    SDL_Surface* surface = TTF_RenderText_Shaded(
        font, infoText.getString().c_str(), foregroundColor, backgroundColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = {infoText.getPosition().x * charSize,
        infoText.getPosition().y * charSize,
        static_cast<int>(stringSize * 10),
        charSize};
    SDL_RenderCopy(renderer, texture, nullptr, &dstrect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void SDLWindow::play(const ASound& /*sound*/)
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