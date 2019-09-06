#ifndef COLLISIONEVENT_H
#define COLLISIONEVENT_H

//ECS
#include "Event.h"
#include "GameObject.h"

struct CollisionEvent : public Event
{
	CollisionEvent(GameObject* obj, GameObject* other) : obj{ obj }, other{ other } { }

	GameObject* obj;
	GameObject* other;
};
#endif