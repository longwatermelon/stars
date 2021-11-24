#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>

struct Vec2f
{
    float x, y;
};

struct Point
{
    float x, y, z;
    float length;
};

void point_render(struct Point* point, SDL_Renderer* rend);
struct Vec2f point_project(struct Point* orig);
void point_draw_trail(struct Point* point, SDL_Renderer* rend);

#endif

