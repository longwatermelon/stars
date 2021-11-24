#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>

struct Point
{
    float x, y, z;
    float length;
};

SDL_FPoint point_project(struct Point* orig);
void point_draw_trail(struct Point* point, SDL_Renderer* rend);

#endif

