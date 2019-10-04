#ifndef SPRITE_H
#define SPRITE_H

//Library SDL2
#include <SDL.h>
#undef main

//Camera
#include "Camera.h"


class Sprite
{
	public:
		static SDL_Surface* load(const char* path);
		void draw(int x, int y, int width, int height, SDL_Surface* sprite);
		void erase(SDL_Surface* sprite);
	
	private:
		SDL_Rect spriteRect;
		SDL_Rect clipRect;

		std::shared_ptr<Camera> camera = Camera::get();
};
#endif