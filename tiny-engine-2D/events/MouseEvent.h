#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <string>

#include "Event.h"

struct MouseEvent : public Event
{
	MouseEvent(std::string button = "", int x = 0, int y = 0) : button{ button }, x{ x }, y{ y } { }

	std::string button;
	int x, y;
};
#endif