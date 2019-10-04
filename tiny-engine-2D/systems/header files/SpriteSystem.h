#ifndef SPRITESYSTEM_H
#define SPRITESYSTEM_H

// Engine
#include "Sprite.h"

// System
#include "Requeriment.h"

// Components
#include "SpriteComponent.h"
#include "PositionComponent.h"

// Camera
#include "Camera.h"

class SpriteSystem : public Requeriment <SpriteComponent, PositionComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj)override;
		void free(GameObject* obj) override;

	private:
		Sprite sprite;

		std::shared_ptr<Camera> camera = Camera::get();
};
#endif