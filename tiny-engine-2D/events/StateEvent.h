#ifndef STATEEVENT_H
#define STATEEVENT_H

//ECS
#include "Event.h"
#include "GameObject.h"

struct StateEvent : public Event
{
	StateEvent(GameObject* obj, std::string state) : obj{ obj }, state{ state } { }

	GameObject* obj;
	std::string state;
};
#endif