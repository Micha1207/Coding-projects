/*
* cturtle.c
* Simple Turtle-like library or C Graphics.
* SEE README.md!!
* I used GitHub Copilot for help.
*
* Written by Michael (micha1207) in Visual Studio Code.
*/
#include <SDL2/SDL.h>

#ifndef CTURTLE_H
#define CTURTLE_H

typedef struct {
    int x, y;
    int pen_down;
    SDL_Renderer *renderer; 
    SDL_Color color; 
    int pen_size;
} CTurtle;

int  cturtle_init(CTurtle *cturtle, SDL_Window **window, SDL_Renderer **renderer, int hx, int hy);
void cturtle_goto(CTurtle *cturtle, int x, int y);
void cturtle_penup(CTurtle *cturtle);
void cturtle_pendown(CTurtle *cturtle);
void cturtle_cleanup(SDL_Window *window, SDL_Renderer *renderer);
void cturtle_color(CTurtle *cturtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void cturtle_bgcolor(CTurtle *cturtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void cturtle_pensize(CTurtle *cturtle, int size);

#endif 

int cturtle_init(CTurtle *cturtle, SDL_Window **window, SDL_Renderer **renderer, int hx, int hy) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 0;
    }

    *window = SDL_CreateWindow("C-Turtle Graphics", 100, 100, hx, hy, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL) {
        SDL_DestroyWindow(*window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    cturtle->x = 400;
    cturtle->y = 300;
    cturtle->pen_down = 1;
    cturtle->renderer = *renderer;
    cturtle->color = (SDL_Color){0, 0, 0, 255}; 
    cturtle->pen_size = 1;

    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
    SDL_RenderClear(*renderer);
    SDL_SetRenderDrawColor(*renderer, cturtle->color.r, cturtle->color.g, cturtle->color.b, cturtle->color.a);

    return 1;
}

void cturtle_goto(CTurtle *cturtle, int x, int y) {
    if (cturtle->pen_down) {
        SDL_SetRenderDrawColor(cturtle->renderer, cturtle->color.r, cturtle->color.g, cturtle->color.b, cturtle->color.a);
        for (int i = 0; i < cturtle->pen_size; i++) {
            SDL_RenderDrawLine(cturtle->renderer, cturtle->x, cturtle->y + i, x, y + i);
            SDL_RenderDrawLine(cturtle->renderer, cturtle->x, cturtle->y - i, x, y - i);
        }
    }
    cturtle->x = x;
    cturtle->y = y;
};

void cturtle_penup(CTurtle *cturtle) {
    cturtle->pen_down = 0;
}

void cturtle_pendown(CTurtle *cturtle) {
    cturtle->pen_down = 1;
}

void cturtle_cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void cturtle_color(CTurtle *cturtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    cturtle->color = (SDL_Color){r, g, b, a};
    SDL_SetRenderDrawColor(cturtle->renderer, r, g, b, a);
}

void cturtle_bgcolor(CTurtle *cturtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(cturtle->renderer, r, g, b, a);
    SDL_RenderClear(cturtle->renderer);
    SDL_SetRenderDrawColor(cturtle->renderer, cturtle->color.r, cturtle->color.g, cturtle->color.b, cturtle->color.a);
}

void cturtle_pensize(CTurtle *cturtle, int size) {
    cturtle->pen_size = size;
}
