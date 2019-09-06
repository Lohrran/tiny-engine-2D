#ifndef MOUSESYSTEM_H
#define MOUSESYSTEM_H

//SDL2 Library
#include <SDL.h>

//Engine
#include "RequestEvent.h"

//System
#include "Requeriment.h"

//Components
#include "MouseComponent.h"

//Events
#include "MouseEvent.h"

class MouseSystem : public Requeriment <MouseComponent>
{
	public:
		void init(GameObject* obj)override;
		void update(GameObject* obj)override;
		void free(GameObject* obj)override;

	private:
		std::shared_ptr<RequestEvent> keyEvent = RequestEvent::get();
};
#endif