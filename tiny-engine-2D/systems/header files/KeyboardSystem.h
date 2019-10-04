#ifndef KEYBOARDSYSTEM_H
#define KEYBOARDSYSTEM_H

// SDL2
#include <SDL.h>

// Engine
#include "RequestEvent.h"

// ECS 
#include "Requeriment.h"

// Component
#include "KeyboardComponent.h"

// Event
#include "KeyboardDownEvent.h"

class KeyboardSystem : public Requeriment <KeyboardComponent>
{
	public:
		void init(GameObject* obj) override;
		void update(GameObject* obj) override;
		void free(GameObject* obj) override;

	private:
		std::shared_ptr<RequestEvent> keyEvent = RequestEvent::get();
};
#endif