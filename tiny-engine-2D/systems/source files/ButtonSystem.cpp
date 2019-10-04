#include "ButtonSystem.h"

void ButtonSystem::init(GameObject* obj)
{
	loadAvailableButtons(obj);
}

void ButtonSystem::update(GameObject* obj)
{
	switch (keyEvent->getSDLEvent()->type)
	{
		case SDL_MOUSEBUTTONDOWN:
			switch (keyEvent->getSDLEvent()->button.button)
			{
				case SDL_BUTTON_LEFT:
					if (isMouseOver(obj, *keyEvent->getSDLEvent()))
					{
						obj->getComponent<SpriteComponent>()->sprite = obj->getComponent<ButtonComponent>()->clickedSprite;

						eventChannel->publish(new ButtonEvent(obj->getComponent<NameComponent>()->name));
					}
					break;
			}

		case SDL_MOUSEMOTION:
			if (isMouseOver(obj, *keyEvent->getSDLEvent()))
			{
				obj->getComponent<SpriteComponent>()->sprite = obj->getComponent<ButtonComponent>()->hoverSprite;
			}

			else
			{
				obj->getComponent<SpriteComponent>()->sprite = obj->getComponent<ButtonComponent>()->normalSprite;
			}
			break;
		default:
			break;
	}
}

void ButtonSystem::free(GameObject* obj)
{
	if (obj->getComponent<ButtonComponent>()->normalSprite != nullptr)
	{
		obj->getComponent<ButtonComponent>()->normalSprite = nullptr;
		SDL_FreeSurface(obj->getComponent<ButtonComponent>()->normalSprite);
	}

	if (obj->getComponent<ButtonComponent>()->hoverSprite != nullptr)
	{
		obj->getComponent<ButtonComponent>()->hoverSprite = nullptr;
		SDL_FreeSurface(obj->getComponent<ButtonComponent>()->hoverSprite);
	}

	if (obj->getComponent<ButtonComponent>()->clickedSprite != nullptr)
	{
		obj->getComponent<ButtonComponent>()->clickedSprite = nullptr;
		SDL_FreeSurface(obj->getComponent<ButtonComponent>()->clickedSprite);
	}
}

void ButtonSystem::loadAvailableButtons(GameObject* obj)
{
	if (camera->window() != NULL)
	{
		if (obj->getComponent<ButtonComponent>()->normal != "")
		{
			obj->getComponent<ButtonComponent>()->normalSprite = sprite.load(obj->getComponent<ButtonComponent>()->normal.c_str());
		}

		if (obj->getComponent<ButtonComponent>()->hover != "")
		{
			obj->getComponent<ButtonComponent>()->hoverSprite = sprite.load(obj->getComponent<ButtonComponent>()->hover.c_str());
		}

		if (obj->getComponent<ButtonComponent>()->clicked != "")
		{
			obj->getComponent<ButtonComponent>()->clickedSprite = sprite.load(obj->getComponent<ButtonComponent>()->clicked.c_str());
		}
	}
}

bool ButtonSystem::isMouseOver(GameObject* obj, SDL_Event mouse)
{
	int left = obj->getComponent<PositionComponent>()->x;
	int top = obj->getComponent<PositionComponent>()->y;
	int right = obj->getComponent<PositionComponent>()->x + obj->getComponent<ButtonComponent>()->width;
	int bottom = obj->getComponent<PositionComponent>()->y + obj->getComponent<ButtonComponent>()->height;

	if (mouse.motion.y <= bottom && mouse.motion.y >= top && mouse.motion.x <= right && mouse.motion.x >= left)
	{
		return true;
	}

	else
	{
		return false;
	}
}