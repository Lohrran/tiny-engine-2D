#include "Sprite.h"

SDL_Surface* Sprite::load(const char* path)
{
	SDL_Surface* imageLoaded = NULL;
	SDL_Surface* processedImage = NULL;

	imageLoaded = SDL_LoadBMP(path);

	if (imageLoaded != NULL)
	{
		processedImage = SDL_ConvertSurface(imageLoaded, imageLoaded->format, 0);
		SDL_FreeSurface(imageLoaded);

		if (processedImage != NULL)
		{
			Uint32 colorKey = SDL_MapRGB(processedImage->format, 255, 0, 225);//Not Passing transparency to all BMP
			SDL_SetColorKey(processedImage, SDL_TRUE, colorKey);
		}
	}
	return processedImage;
}

void Sprite::draw(int x, int y, int width, int height, SDL_Surface* sprite)
{
	// Get first clip from sprite sheet
	clipRect = { 0, 0, width, height };

	// Place in the position
	spriteRect = { x, y, width, height };

	if (camera->window() != NULL)
	{
		if (camera->surface() != NULL)
		{
			SDL_BlitSurface(sprite, &clipRect, camera->surface(), &spriteRect);
		}
	}
}

void Sprite::erase(SDL_Surface* sprite)
{
	if (sprite != nullptr)
	{
		sprite = nullptr;
		SDL_FreeSurface(sprite);
	}
}