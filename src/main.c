#include "point.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>


struct Point* append_point(struct Point* pts, int* npts, struct Point p)
{
    pts = realloc(pts, sizeof(struct Point) * ++*npts);
    pts[*npts - 1] = p;
    return pts;
}


void render(SDL_Window* window, SDL_Renderer* rend)
{
    bool running = true;
    SDL_Event evt;

    struct Point* points = 0;
    int npoints = 0;

    for (int i = 0; i < 20; ++i)
    {
        points = append_point(points, &npoints, (struct Point){
            .x = (float)(rand() % 200 - 100) / 100.f,
            .y = (float)(rand() % 200 - 100) / 100.f,
            .z = 5.f
        });
    }

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

        for (int i = 0; i < npoints; ++i)
        {
            point_render(&points[i], rend);
            points[i].z -= 0.01f;
        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderPresent(rend);
    }
}


int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Stars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    srand(time(0));

    render(window, rend);

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

