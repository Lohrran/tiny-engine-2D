#include "KeyboardSystem.h"

void KeyboardSystem::init(GameObject* obj){ }

void KeyboardSystem::update(GameObject* obj)
{
	switch (keyEvent->getSDLEvent()->type)
	{
		case SDL_KEYDOWN:
			switch (keyEvent->getSDLEvent()->key.keysym.sym)
			{
				case SDLK_SPACE:
					eventChannel->publish(new KeyboardDownEvent("SPACE"));
					break;
			}
			break;
		default:
			eventChannel->publish(new KeyboardDownEvent("NONE"));
			break;
	}
}

void KeyboardSystem::free(GameObject* obj){ }