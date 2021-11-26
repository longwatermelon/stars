#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>


SDL_FPoint point_project(struct Point* orig, SDL_Point winsize, Vec3f camera)
{
    if (orig->pos.z - camera.z <= 0.f)
        return (SDL_FPoint){ .x = -1.f, .y = -1.f };

    SDL_FPoint proj = {
        .x = (orig->pos.x - camera.x) / (orig->pos.z - camera.z) + 1,
        .y = (orig->pos.y - camera.y) / (orig->pos.z - camera.z) + 1
    };

    proj.x *= (float)winsize.x / 2.f;
    proj.y *= (float)winsize.y / 2.f;

    return proj;
}


void point_draw_trail(struct Point* point, SDL_Renderer* rend, SDL_Point winsize, Vec3f camera)
{
    SDL_FPoint front = point_project(point, winsize, camera);

    if (front.x == -1.f && front.y == -1.f)
        return;

    struct Point p = { .pos = { .x = point->pos.x, .y = point->pos.y, .z = point->pos.z - point->length } };
    SDL_FPoint back = point_project(&p, winsize, camera);

    if (back.x == -1.f && back.y == -1.f)
        return;

    SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
    SDL_RenderDrawLineF(rend, front.x, front.y, back.x, back.y);
}

