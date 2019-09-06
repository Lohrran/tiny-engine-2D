#ifndef SPRITESYSTEM_H
#define SPRITESYSTEM_H

//Library SDL2
#include <SDL.h>
#undef main

//System
#include "Requeriment.h"

//Components
#include "SpriteComponent.h"
#include "PositionComponent.h"

//Camera
#include "Camera.h"

class SpriteSystem : public Requeriment <SpriteComponent, PositionComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj)override;
		void free(GameObject* obj) override;

		static SDL_Surface* load(const char* path);

	private:
		SDL_Rect spriteRect;
		SDL_Rect clipRect;

		std::shared_ptr<Camera> camera = Camera::get();
};
#endif