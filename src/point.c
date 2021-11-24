#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>


void point_render(struct Point* point, SDL_Renderer* rend)
{
    if (point->z == 0.f)
        return;

    float px = point->x / point->z;
    float py = point->y / point->z;

    ++px;
    ++py;

    px *= 400.f;
    py *= 400.f;

    SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
    SDL_RenderDrawPoint(rend, (int)px, (int)py);
}

