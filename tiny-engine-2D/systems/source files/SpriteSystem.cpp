#include "SpriteSystem.h"

void SpriteSystem::init(GameObject* obj)
{
	obj->getComponent<SpriteComponent>()->sprite = sprite.load(obj->getComponent<SpriteComponent>()->path.c_str());

	sprite.draw
	(
		obj->getComponent<PositionComponent>()->x,
		obj->getComponent<PositionComponent>()->y,
		obj->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpriteComponent>()->height,
		obj->getComponent<SpriteComponent>()->sprite
	);
}

void SpriteSystem::update(GameObject* obj)
{
	sprite.draw
	(
		obj->getComponent<PositionComponent>()->x,
		obj->getComponent<PositionComponent>()->y,
		obj->getComponent<SpriteComponent>()->width,
		obj->getComponent<SpriteComponent>()->height,
		obj->getComponent<SpriteComponent>()->sprite
	);
}

void SpriteSystem::free(GameObject* obj)
{
	sprite.erase(obj->getComponent<SpriteComponent>()->sprite);
}