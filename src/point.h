#ifndef POINT_H
#define POINT_H

#include <SDL2/SDL.h>

typedef struct
{
    float x, y, z;
} Vec3f;

// Literally useless but I don't want to refactor my code
struct Point
{
    Vec3f pos;
};

SDL_FPoint point_project(struct Point* orig, SDL_Point winsize, Vec3f camera);
void point_draw_trail(struct Point* point, SDL_Renderer* rend, SDL_Point winsize, Vec3f camera, Vec3f move);

#endif

