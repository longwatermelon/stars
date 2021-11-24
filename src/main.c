#include "point.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>


void render(SDL_Window* window, SDL_Renderer* rend)
{
    bool running = true;
    SDL_Event evt;

    while (running)
    {
        while (SDL_PollEvent(&evt))
        {
            switch (evt.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        SDL_RenderClear(rend);

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderPresent(rend);
    }
}


int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Stars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    render(window, rend);

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

