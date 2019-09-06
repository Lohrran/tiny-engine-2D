#ifndef KEYBOARDDOWNEVENT_H
#define KEYBOARDDOWNEVENT_H

#include "Event.h"
#include <string>
struct KeyboardDownEvent : public Event
{
	KeyboardDownEvent(std::string keyboard = "") : keyboard{ keyboard } {}

	std::string keyboard;
};
#endif
