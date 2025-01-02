/*
* turtle.c
* Simple Turtle-like library or C Graphics.
* SEE README.md!!
* I used GitHub Copilot for help.
*
* Written by Michael (micha1207) in Visual Studio Code.
*/
#include <SDL2/SDL.h>

#ifndef TURTLE_H
#define TURTLE_H

typedef struct {
    int x, y;
    int pen_down;
    SDL_Renderer *renderer; 
    SDL_Color color; 
    int pen_size;
} Turtle;

int  turtle_init(Turtle *turtle, SDL_Window **window, SDL_Renderer **renderer, int hx, int hy);
void turtle_goto(Turtle *turtle, int x, int y);
void penup(Turtle *turtle);
void pendown(Turtle *turtle);
void turtle_cleanup(SDL_Window *window, SDL_Renderer *renderer);
void turtle_color(Turtle *turtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void turtle_bgcolor(Turtle *turtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void pensize(Turtle *turtle, int size);
void turtle_goto_slowly(Turtle *turtle, int x, int y, int delay_time);

#endif 

int turtle_init(Turtle *turtle, SDL_Window **window, SDL_Renderer **renderer, int hx, int hy) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 0;
    }

    *window = SDL_CreateWindow("Turtle Graphics", 100, 100, hx, hy, SDL_WINDOW_SHOWN);
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

    turtle->x = 400;
    turtle->y = 300;
    turtle->pen_down = 1;
    turtle->renderer = *renderer;
    turtle->color = (SDL_Color){0, 0, 0, 255}; 
    turtle->pen_size = 1;

    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
    SDL_RenderClear(*renderer);
    SDL_SetRenderDrawColor(*renderer, turtle->color.r, turtle->color.g, turtle->color.b, turtle->color.a);

    return 1;
}

void turtle_goto(Turtle *turtle, int x, int y) {
    if (turtle->pen_down) {
        SDL_SetRenderDrawColor(turtle->renderer, turtle->color.r, turtle->color.g, turtle->color.b, turtle->color.a);
        for (int i = 0; i < turtle->pen_size; i++) {
            SDL_RenderDrawLine(turtle->renderer, turtle->x, turtle->y + i, x, y + i);
            SDL_RenderDrawLine(turtle->renderer, turtle->x, turtle->y - i, x, y - i);
        }
    }
    turtle->x = x;
    turtle->y = y;
};

void turtle_goto_slowly(Turtle *turtle, int x, int y, int delay_time) {
    int dx = x - turtle->x;
    int dy = y - turtle->y;
    int steps = 100; 
    float x_step = dx / (float)steps;
    float y_step = dy / (float)steps;

    for (int i = 0; i < steps; i++) {
        turtle_goto(turtle, turtle->x + x_step, turtle->y + y_step);
        SDL_RenderPresent(turtle->renderer);
        SDL_Delay(delay_time);
    }
    turtle_goto(turtle, x, y); 
}

void turtle_penup(Turtle *turtle) {
    turtle->pen_down = 0;
}

void turtle_pendown(Turtle *turtle) {
    turtle->pen_down = 1;
}

void turtle_cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void turtle_color(Turtle *turtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    turtle->color = (SDL_Color){r, g, b, a};
    SDL_SetRenderDrawColor(turtle->renderer, r, g, b, a);
}

void turtle_bgcolor(Turtle *turtle, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(turtle->renderer, r, g, b, a);
    SDL_RenderClear(turtle->renderer);
    SDL_SetRenderDrawColor(turtle->renderer, turtle->color.r, turtle->color.g, turtle->color.b, turtle->color.a);
}

void turtle_pensize(Turtle *turtle, int size) {
    turtle->pen_size = size;
}
