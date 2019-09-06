#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Component.h"
#include <string>
#include <SDL.h>

struct SpriteComponent : public Component
{
	SpriteComponent(std::string path = "", int width = 0, int height = 0) : path{ path }, width{ width }, height{ height }, sprite{ NULL } { }

	std::string path;
	int width, height;
	SDL_Surface* sprite;
};
#endif