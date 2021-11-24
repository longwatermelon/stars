#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>


void point_render(struct Point* point, SDL_Renderer* rend)
{
    if (point->z == 0.f)
        return;

    float px = point->x / point->z;
    float py = point->y / point->z;

    SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
    SDL_RenderDrawPoint(rend, (int)px, (int)py);
}

