#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_DisplayMode displayMode;
    if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) {
        std::cerr << "Could not get display mode: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("ㅤ",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          displayMode.w, displayMode.h,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP | SDL_WINDOW_BORDERLESS);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Renderer could not be created:" << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;
    SDL_SetWindowOpacity(window, 0.0f);
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    std::cout << "Key pressed: " << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button) {
                        case SDL_BUTTON_LEFT:
                            std::cout << "Mouse button pressed: LEFT" << std::endl;
                            break;
                        case SDL_BUTTON_RIGHT:
                            std::cout << "Mouse button pressed: RIGHT" << std::endl;
                            break;
                        case SDL_BUTTON_MIDDLE:
                            std::cout << "Mouse button pressed: MIDDLE" << std::endl;
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
