#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>

struct Point
{
    float x, y, z;
};

void point_render(struct Point* point, SDL_Renderer* rend);

#endif

