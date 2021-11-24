#include "point.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>


void point_render(struct Point* point, SDL_Renderer* rend)
{
    struct Vec2f proj = point_project(point);

    SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
    SDL_RenderDrawPoint(rend, (int)proj.x, (int)proj.y);
}


struct Vec2f point_project(struct Point* orig)
{
    if (orig->z == 0.f)
        return (struct Vec2f){ .x = -1.f, .y = -1.f };

    struct Vec2f proj = {
        .x = orig->x / orig->z + 1,
        .y = orig->y / orig->z + 1
    };

    proj.x *= 400.f;
    proj.y *= 400.f;

    return proj;
}


void point_draw_trail(struct Point* point, SDL_Renderer* rend)
{
    struct Vec2f front = point_project(point);

    if (front.x == -1.f && front.y == -1.f)
        return;

    struct Point p = { .x = point->x, .y = point->y, .z = point->z - point->length };
    struct Vec2f back = point_project(&p);

    if (back.x == -1.f && back.y == -1.f)
        return;

    SDL_SetRenderDrawColor(rend, 255, 255, 0, 255);
    SDL_RenderDrawLineF(rend, front.x, front.y, back.x, back.y);
}

