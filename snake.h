#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graphics
#include <SDL2/SDL.h>

struct snake_s
{
    int pos;
    struct snake_s *next;
    struct snake_s *prev;
} snake_t;


