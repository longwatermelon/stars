#include "point.h"
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

#define RAND_POINT (float)(rand() % 3000 - 1500) / 100.f
#define RAND_Z (float)(rand() % 70 - 30)

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

    for (int i = 0; i < 1500; ++i)
    {
        points = append_point(points, &npoints, (struct Point){
            .x = RAND_POINT,
            .y = RAND_POINT,
            .z = RAND_Z,
            .length = 1.f
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

        SDL_Point win;
        SDL_GetWindowSize(window, &win.x, &win.y);

        for (int i = 0; i < npoints; ++i)
        {
            if (points[i].z <= 1.f)
            {
                points[i].x = RAND_POINT;
                points[i].y = RAND_POINT;
                points[i].z = RAND_Z;
            }

            point_draw_trail(&points[i], rend, win);
            points[i].z -= .3f;
        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderPresent(rend);
    }

    free(points);
}


int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Stars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    srand(time(0));

    render(window, rend);

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

