#include "BoxCollisionSystem.h"

void BoxCollisionSystem::init(GameObject* obj) { }

void BoxCollisionSystem::update(GameObject* obj)
{
	for (GameObject* other : scene->gameObjects())
	{
		if (obj->entity->id != other->entity->id)
		{
			if (checkBoxCollision(obj, other))
			{
				eventChannel->publish(new CollisionEvent(obj, other));
			}
		}
	}
}

void BoxCollisionSystem::free(GameObject* obj) { }

bool BoxCollisionSystem::checkBoxCollision(GameObject* obj, GameObject* other)
{
	int obj_left = obj->getComponent<PositionComponent>()->x;
	int obj_top = obj->getComponent<PositionComponent>()->y;
	int obj_right = obj->getComponent<PositionComponent>()->x + obj->getComponent<BoxColliderComponent>()->width;
	int obj_bottom = obj->getComponent<PositionComponent>()->y + obj->getComponent<BoxColliderComponent>()->height;

	int other_left = other->getComponent<PositionComponent>()->x;
	int other_top = other->getComponent<PositionComponent>()->y;
	int other_right = other->getComponent<PositionComponent>()->x + other->getComponent<BoxColliderComponent>()->width;
	int other_bottom = other->getComponent<PositionComponent>()->y + other->getComponent<BoxColliderComponent>()->height;

	if (obj_bottom <= other_top)
	{
		return false;
	}

	else if (obj_top >= other_bottom)
	{
		return false;
	}

	else if (obj_right <= other_left)
	{
		return false;
	}

	else if (obj_left >= other_right)
	{
		return false;
	}

	else
	{
		return true;
	}
}