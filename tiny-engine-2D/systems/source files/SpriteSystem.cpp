#include "SpriteSystem.h"

void SpriteSystem::init(GameObject* obj)
{
	clipRect =
	{
		0,
		0,
		obj->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpriteComponent>()->height
	};//Get First Clip From Sprite Sheet
	
	spriteRect =
	{
		obj->getComponent<PositionComponent>()->x,
		obj->getComponent<PositionComponent>()->y,
		obj->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpriteComponent>()->height
	};

	if (camera->window() != NULL)
	{	
		obj->getComponent<SpriteComponent>()->sprite = load(obj->getComponent<SpriteComponent>()->path.c_str());
		if (camera->surface() != NULL)
		{
			SDL_BlitSurface(obj->getComponent<SpriteComponent>()->sprite, &clipRect, camera->surface(), &spriteRect);
		}
	}
}

void SpriteSystem::update(GameObject* obj)
{
	clipRect =
	{
		0,
		0,
		obj->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpriteComponent>()->height
	};//Get First Clip From Sprite Sheet

	spriteRect =
	{
		obj->getComponent<PositionComponent>()->x,
		obj->getComponent<PositionComponent>()->y,
		obj->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpriteComponent>()->height
	};

	SDL_BlitSurface(obj->getComponent<SpriteComponent>()->sprite, &clipRect, camera->surface(), &spriteRect);
}

void SpriteSystem::free(GameObject* obj)
{
	if (obj->getComponent<SpriteComponent>()->sprite != nullptr)
	{
		obj->getComponent<SpriteComponent>()->sprite = nullptr;
		SDL_FreeSurface(obj->getComponent<SpriteComponent>()->sprite);
	}	
}

SDL_Surface* SpriteSystem::load(const char* path)
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