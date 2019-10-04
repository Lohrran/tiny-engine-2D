#ifndef BUTTONEVENT_H
#define BUTTONEVENT_H

#include <string>

#include "Event.h"

struct ButtonEvent : public Event
{
	ButtonEvent(std::string name = "") : name{ name } { } 

	std::string name;
};
#endif