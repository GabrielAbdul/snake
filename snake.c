#include "snake.h"

#ifdef WINDOWED

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

#else

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#endif 

#define BLACK 0x00
#define GREEN 0xff
#define ALPHA 255

int main()
{

    // Declare Window and Reder Objects
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_INIT_VIDEO < 0) {
        fprintf(stderr, "ERROR: SDL_INIT_VIDEO");
    }
    
    // Initialize Window Object
    window = SDL_CreateWindow(
            "Snake",
            WINDOW_X,
            WINDOW_Y,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_BORDERLESS
        );

    if (!window)
    {
        fprintf(stderr, "ERROR: SDL_CreateWindow Failed!");
    }

    // Initialize Renderer Object
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        fprintf(stderr, "ERROR: SDL_CreateRenderer Failed!");
    }

    // Update Window Color
    SDL_SetRenderDrawColor(renderer, BLACK, GREEN, BLACK, ALPHA);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(2000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
