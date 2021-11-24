#ifndef MAIN_H
#define MAIN_H

#include "point.h"

struct Point* append_point(struct Point* pts, int* npts, struct Point p);
void render(SDL_Window* window, SDL_Renderer* rend);

#endif

