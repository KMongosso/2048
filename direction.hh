#pragma once
#include <iostream>
#include "SDL2/SDL.h"

using namespace std;

struct nombres_t{
	int val;
	SDL_Rect dest;
	SDL_Texture *nb;
};

void left(nombres_t **screen);
void right(nombres_t **screen);
void up(nombres_t **screen);
void down(nombres_t **screen);