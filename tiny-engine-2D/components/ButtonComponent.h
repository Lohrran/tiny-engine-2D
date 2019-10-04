#ifndef BUTTONCOMPONENT_H
#define BUTTONCOMPONENT_H

#include "Component.h"
#include <string>
#include <SDL.h>

struct ButtonComponent : public Component
{
	ButtonComponent(std::string normal = "", std::string hover = "", std::string clicked = "", int width = 0, int height = 0) : 
		normal{ normal }, hover{ hover }, clicked{ clicked }, width{ width }, height{ height }, 
		normalSprite{ NULL }, hoverSprite{ NULL }, clickedSprite{ NULL } { }

	std::string normal, hover, clicked;
	int width, height;
	SDL_Surface* normalSprite;
	SDL_Surface* hoverSprite;
	SDL_Surface* clickedSprite;
};
#endif