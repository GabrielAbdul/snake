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


/**
 * game_loop - game loop that detects and responds to
 *             inputs. Exits when "ESCAPE" key pressed.
 */
void game_loop()
{
    bool quit = false;
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
               switch(event.type)
               {
                   case SDL_QUIT:
                       quit = true;
                       break;
                   case SDL_KEYUP:
                        break;
                   case SDL_KEYDOWN:
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                                quit = true;
                                break;
                        };
                        break;
               }
        }
    }
}


/**
 * main - Entry point of program. Responsible for
 *        initialization of window and renderer objects,
 *        game loop, and cleanup of initialized objects.
 *
 * return: 0
 */
int main(void)
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


    // Initialize Game Loop
    game_loop();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

