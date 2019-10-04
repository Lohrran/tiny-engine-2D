#ifndef BUTTONSYSTEM_H
#define BUTTONSYSTEM_H

// SDL2 Library
#include <SDL.h>

// Engine
#include "RequestEvent.h"
#include "Camera.h"
#include "Sprite.h"

// ECS
#include "Requeriment.h"

// Components
#include "PositionComponent.h"
#include "NameComponent.h"
#include "ButtonComponent.h"
#include "SpriteComponent.h"

// Events
#include "ButtonEvent.h"

class ButtonSystem : public Requeriment <PositionComponent, NameComponent, ButtonComponent, SpriteComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

	private:
		void loadAvailableButtons(GameObject* obj);
		bool isMouseOver(GameObject* obj, SDL_Event mouse);

		Sprite sprite;

		std::shared_ptr<Camera> camera = Camera::get();
		std::shared_ptr<RequestEvent> keyEvent = RequestEvent::get();
};
#endif