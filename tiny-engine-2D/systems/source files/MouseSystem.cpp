#include "MouseSystem.h"

void MouseSystem::init(GameObject* obj)
{

}

void MouseSystem::update(GameObject* obj)
{
	switch (keyEvent->getSDLEvent()->type)
	{
		case SDL_MOUSEBUTTONDOWN:
			switch (keyEvent->getSDLEvent()->button.button)
			{
				case SDL_BUTTON_LEFT:
					eventChannel->publish(new MouseEvent("LEFT", keyEvent->getSDLEvent()->motion.x, keyEvent->getSDLEvent()->motion.y));
					break;
				case SDL_BUTTON_RIGHT:
					eventChannel->publish(new MouseEvent("RIGHT", keyEvent->getSDLEvent()->motion.x, keyEvent->getSDLEvent()->motion.y));
					break;
			}

		case SDL_MOUSEMOTION:
			eventChannel->publish(new MouseEvent("MOTION", keyEvent->getSDLEvent()->motion.x, keyEvent->getSDLEvent()->motion.y));
			break;
		default:
			break;
	}
}

void MouseSystem::free(GameObject* obj)
{

}